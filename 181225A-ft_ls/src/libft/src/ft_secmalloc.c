/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:17:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 18:24:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	frexit(void)
{
	heap_collector(NULL, HS_FREE);
	acl_heap_collector(NULL, HS_FREE);
	dir_heap_collector(NULL, HS_FREE);
	exit(EXIT_FAILURE);
}

void	*ft_secmalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		frexit();
	heap_collector(ptr, HS_ADD);
	return (ptr);
}
