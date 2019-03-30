/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:54 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/09 13:00:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_whitespaces(char *str)
{
	static int	size = 0;
	int			l;
	char		*p;
	char		**tb;

	p = 0;
	tb = 0;
	size = size == -1 ? 1 : size + 1;
	while (*str && (*str == 32 || (*str > 8 && *str < 12)))
		str++;
	l = 0;
	while (str[l] && !(str[l] == 32 || (str[l] > 8 && str[l] < 12)))
		l++;
	if (l && !(p = strndup(str, l)))
		size = -1;
	if (size != -1 && !(tb = p ? ft_split_whitespaces(str + l) :
		(char **)malloc(size * sizeof(char *))))
		size = -1;
	if (size == -1 && p)
		free(p);
	else if (size != -1)
		tb[--size] = p;
	return (tb);
}
