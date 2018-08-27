/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:54 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 17:08:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	split(char *str, int size, char ***no_white)
{
	int		l;
	int		i;
	char	*ptr;

	ptr = 0;
	size++;
	while (*str && (*str == 32 || (*str > 8 && *str < 12)))
		str++;
	l = 0;
	while (str[l] && !(str[l] == 32 || (str[l] > 8 && str[l] < 12)))
		l++;
	if (l)
	{
		ptr = (char *)malloc(l + 1);
		i = 0;
		while (*str && l--)
			ptr[i++] = *str++;
		ptr[i] = '\0';
		split(str, size, no_white);
	}
	else
		*no_white = (char **)malloc(size * sizeof(char *));
	(*no_white)[--size] = ptr;
}

char	**ft_split_whitespaces(char *str)
{
	char	**no_white;

	split(str, 0, &no_white);
	return (no_white);
}
