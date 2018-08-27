/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:07:24 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:09:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_arguments.h"

void	ft_get_arguments(int *c, int *fc, char **fv, char **av)
{
	int	i;
	int	ac;

	i = 1;
	ac = *fc;
	*fc = 0;
	while (i < ac)
	{
		if (ft_is_c_option(av[i]))
			*c = 1;
		else
		{
			fv[(*fc)] = av[i];
			(*fc)++;
		}
		i++;
	}
}

int		ft_is_c_option(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i == 2 && str[0] == '-' && str[1] == 'C');
}

int		ft_does_file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	close(fd);
	return (fd > 0);
}
