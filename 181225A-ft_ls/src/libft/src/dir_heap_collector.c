/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_heap_collector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:19:51 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 18:22:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>

void			*dir_heap_collector(void *ptr, int hs_do)
{
	static void		**dir_heap_stack = NULL;
	static size_t	size = 0;
	static size_t	i = 0;

	if (hs_do == HS_ADD)
	{
		if (!(dir_heap_stack = check_heap_size(dir_heap_stack, &size, i)))
		{
			closedir((DIR *)ptr);
			ft_putstr_fd("dir_heap_collector error: no space left\n", 2);
			frexit();
		}
		else
			dir_heap_stack[i++] = ptr;
	}
	else if (hs_do == HS_GET)
		return (get_heap_ptr(dir_heap_stack, &i, ptr));
	else if (hs_do == HS_FREE)
	{
		while (i > 0)
			closedir((DIR *)dir_heap_stack[--i]);
		free(dir_heap_stack);
	}
	return (NULL);
}
