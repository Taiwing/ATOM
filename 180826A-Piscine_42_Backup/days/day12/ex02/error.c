/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:57:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 16:57:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "utils.h"

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	print_arg_error(int argc, char **argv)
{
	ft_puterr("tail: ");
	if (argc < 4)
		ft_puterr("not enough arguments\n");
	else if (ft_strcmp(argv[1], "-c"))
		ft_puterr("option \"c\" not present\n");
	else
	{
		ft_puterr("incorrect number of bytes: \"");
		ft_puterr(argv[2]);
		ft_puterr("\"\n");
	}
}

void	print_file_error(char *file)
{
	if (errno == EACCES)
	{
		ft_puterr("tail: ");
		ft_puterr(file);
		ft_puterr(": Permission denied\n");
	}
	else
	{
		ft_puterr("tail: ");
		ft_puterr(file);
		ft_puterr(": No such file or directory\n");
	}
	errno = 0;
}
