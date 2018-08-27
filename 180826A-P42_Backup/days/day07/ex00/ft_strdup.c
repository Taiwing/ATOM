/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:05:46 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 17:05:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*dup;

	l = 0;
	while (src[l])
		l++;
	dup = (char *)malloc((l + 1) * sizeof(char));
	i = -1;
	while (dup && ++i <= l)
		dup[i] = src[i];
	return (dup);
}
