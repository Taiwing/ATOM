/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:26:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/14 07:27:21 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	static int	i = 0;
	int			l;
	char		*cpy;
	char		**tb;

	if (!s)
		return (NULL);
	tb = NULL;
	cpy = NULL;
	i = i == -1 ? 1 : i + 1;
	while (*s == c)
		s++;
	l = 0;
	while (s[l] && s[l] != c)
		l++;
	if (l && !(cpy = ft_strndup(s, l)))
		i = -1;
	if (i != -1 && !(tb = cpy ? ft_strsplit(s + l, c)
		: (char **)malloc(i * sizeof(char *))))
		i = -1;
	if (i == -1 && cpy)
		free(cpy);
	else if (i != -1)
		tb[--i] = cpy;
	return (tb);
}
