/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:26:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/07 14:42:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int			l;
	char		*cpy;
	char		**tb;
	static int	i = 0;

	if (!s)
		return (NULL);
	i++;
	while (*s == c)
		s++;
	l = 0;
	while (s[l] && s[l] != c)
		l++;
	cpy = l ? ft_strncpy(ft_strnew(l + 1), s, l) : NULL;
	tb = l ? ft_strsplit(s + l, c) : (char **)malloc(i * sizeof(char *));
	tb[--i] = cpy;
	return (tb);
}
