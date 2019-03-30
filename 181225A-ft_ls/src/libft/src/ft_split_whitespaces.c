/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 12:19:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_whitespaces(char *str)
{
	static int	size = 0;
	int			l;
	char		*p;
	char		**tb;

	if (!str)
		return (NULL);
	p = NULL;
	tb = NULL;
	size = size == -1 ? 1 : size + 1;
	while (*str && (*str == 32 || (*str > 8 && *str < 12)))
		++str;
	l = 0;
	while (str[l] && !(str[l] == 32 || (str[l] > 8 && str[l] < 12)))
		++l;
	if (l && !(p = ft_strndup(str, l)))
		size = -1;
	if (size != -1 && !(tb = p ? ft_split_whitespaces(str + l) :
		(char **)ft_secmalloc(size * sizeof(char *))))
		size = -1;
	if (size == -1 && p)
		free(heap_collector(p, HS_GET));
	else if (size != -1)
		tb[--size] = p;
	return (tb);
}
