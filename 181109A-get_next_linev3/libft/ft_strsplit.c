/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:26:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/08 18:44:53 by yforeau          ###   ########.fr       */
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
	if (l && !(cpy = ft_strnew(l)))
		return (NULL);
	cpy = l ? ft_strncpy(cpy, s, l) : NULL;
	if (!(tb = l ? ft_strsplit(s + l, c) : (char **)malloc(i * sizeof(char *))))
	{
		i = 0;
		return (NULL);
	}
	tb[--i] = cpy;
	return (tb);
}
