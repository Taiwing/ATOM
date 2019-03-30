/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_collector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:15:49 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 18:30:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/acl.h>

const size_t	g_hs_sizes[4] = {
	0xffff, 0xffffffff, 0xffffffffffff
};

static void		**alloc_heap_stack(size_t *size)
{
	void	**ptr;
	int		j;

	j = -1;
	while (++j < 3 && g_hs_sizes[j] <= *size)
		;
	if (j == 3)
		return (NULL);
	if (!(ptr = (void **)malloc(g_hs_sizes[j] * sizeof(void *))))
	{
		heap_collector(NULL, HS_FREE);
		acl_heap_collector(NULL, HS_FREE);
		return (NULL);
	}
	*size = g_hs_sizes[j];
	return (ptr);
}

void			**check_heap_size(void **heap_stack, size_t *size, size_t i)
{
	void	**ptr;
	size_t	old_size;

	if (i < *size)
		return (heap_stack);
	else if (!*size)
		return (alloc_heap_stack(size));
	else
	{
		old_size = *size;
		ptr = alloc_heap_stack(size);
		if (ptr && heap_stack)
		{
			ft_memcpy(ptr, heap_stack, old_size);
			free(heap_stack);
		}
		return (ptr);
	}
}

void			*get_heap_ptr(void **heap_stack, size_t *i, void *ptr)
{
	size_t	j;

	if (heap_stack && ptr && *i)
	{
		j = *i;
		while (j > 0 && heap_stack[--j] != ptr)
			;
		if (ptr == heap_stack[j])
		{
			--(*i);
			heap_stack[j] = j == *i ? NULL : heap_stack[*i];
			return (ptr);
		}
	}
	if (ptr)
	{
		ft_putstr_fd("heap_collector error: invalid pointer\n", 2);
		frexit();
	}
	return (NULL);
}

void			*heap_collector(void *ptr, int hs_do)
{
	static void		**heap_stack = NULL;
	static size_t	size = 0;
	static size_t	i = 0;

	if (hs_do == HS_ADD)
	{
		if (!(heap_stack = check_heap_size(heap_stack, &size, i)))
		{
			free(ptr);
			ft_putstr_fd("heap_collector error: no space left\n", 2);
			frexit();
		}
		else
			heap_stack[i++] = ptr;
	}
	else if (hs_do == HS_GET)
		return (get_heap_ptr(heap_stack, &i, ptr));
	else if (hs_do == HS_FREE)
	{
		while (i > 0)
			free(heap_stack[--i]);
		free(heap_stack);
	}
	return (NULL);
}

void			*acl_heap_collector(void *ptr, int hs_do)
{
	static void		**acl_heap_stack = NULL;
	static size_t	size = 0;
	static size_t	i = 0;

	if (hs_do == HS_ADD)
	{
		if (!(acl_heap_stack = check_heap_size(acl_heap_stack, &size, i)))
		{
			acl_free(ptr);
			ft_putstr_fd("acl_heap_collector error: no space left\n", 2);
			frexit();
		}
		else
			acl_heap_stack[i++] = ptr;
	}
	else if (hs_do == HS_GET)
		return (get_heap_ptr(acl_heap_stack, &i, ptr));
	else if (hs_do == HS_FREE)
	{
		while (i > 0)
			acl_free(acl_heap_stack[--i]);
		free(acl_heap_stack);
	}
	return (NULL);
}
