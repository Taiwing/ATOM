/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:07:36 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 17:07:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_legal(char c, char *charset)
{
	while (*charset && *charset != c)
		charset++;
	return (*charset == 0);
}

void	split(char *str, char *charset, int size, char ***clean)
{
	int		l;
	int		i;
	char	*ptr;

	ptr = 0;
	size++;
	while (*str && !is_legal(*str, charset))
		str++;
	l = 0;
	while (str[l] && is_legal(str[l], charset))
		l++;
	if (l)
	{
		ptr = (char *)malloc(l + 1);
		i = 0;
		while (*str && l--)
			ptr[i++] = *str++;
		ptr[i] = '\0';
		split(str, charset, size, clean);
	}
	else
		*clean = (char **)malloc(size * sizeof(char *));
	(*clean)[--size] = ptr;
}

char	**ft_split(char *str, char *charset)
{
	char	**clean;

	split(str, charset, 0, &clean);
	return (clean);
}
