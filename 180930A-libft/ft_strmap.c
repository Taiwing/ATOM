/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:52:03 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:52:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		l;
	char	*map;

	l = ft_strlen(s);
	map = ft_strnew(l + 1);
	while (l--)
		map[l] = f(s[l]);
	return (map);	
}
