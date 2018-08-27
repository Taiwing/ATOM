/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:06:36 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 23:19:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*cat;

	size = 0;
	i = (0 * argc-- * (int)(argv++));
	while (i < argc)
	{
		j = 0;
		while (argv[i][j++])
			size++;
		i++;
	}
	cat = (char *)malloc(size + argc);
	i = 0;
	while (*argv)
	{
		while (**argv)
			cat[i++] = *(*argv)++;
		cat[i] = i < size + argc - 1 ? '\n' : '\0';
		argv++;
		i++;
	}
	return (cat);
}
