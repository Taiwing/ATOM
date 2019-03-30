/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:35:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/29 19:42:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (*s == c ? (char *)s : 0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	t_uchar	c1;
	t_uchar	c2;

	c1 = (t_uchar)*s1;
	c2 = (t_uchar)*s2;
	return (c1 && c2 && c1 == c2 ? ft_strcmp(s1 + 1, s2 + 1) : c1 - c2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_uchar	c1;
	t_uchar	c2;

	c1 = (t_uchar)*s1;
	c2 = (t_uchar)*s2;
	if (!n)
		return (0);
	else if (c1 != c2 || c1 == 0 || c2 == 0)
		return (c1 - c2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
