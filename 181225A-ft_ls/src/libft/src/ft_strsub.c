/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:27:46 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:17:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = ft_strnew(len);
	if (!s || !new)
	{
		if (new)
			free(heap_collector(new, HS_GET));
		return (NULL);
	}
	return (ft_strncpy(new, s + start, len));
}
