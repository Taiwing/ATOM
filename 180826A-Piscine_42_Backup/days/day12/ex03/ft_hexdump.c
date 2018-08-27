/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:06:00 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:15:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include <errno.h>

int		sec_open(char *file, int flag)
{
	int	ret;

	ret = open(file, flag);
	if (ret < 1 || errno)
	{
		ft_puterr("hexdump: ");
		ft_puterr(file);
		ft_puterr(": No such file or directory\n");
		errno = 0;
	}
	return (ret < 1 ? 0 : ret);
}

void	ft_hexdump(int c, int fc, char **fv)
{
	int		i[4];
	char	buffer[16];

	i[0] = -1;
	i[2] = 16;
	i[3] = 0;
	if (c)
		ft_hexmem_ascii(fc, fv, i, buffer);
	else
		ft_hexmem(fc, fv, i, buffer);
	ft_putchar('\n');
}

void	ft_hexmem_ascii(int fc, char **fv, int i[4], char buffer[16])
{
	while (++i[0] < fc)
	{
		i[1] = sec_open(fv[i[0]], O_RDONLY);
		while (i[2] == 16 && i[1] > 0)
		{
			i[2] = read(i[1], buffer, 16);
			while (i[2] < 16 && i[0] != (fc - 1))
			{
				close(i[1]);
				i[1] = sec_open(fv[++i[0]], O_RDONLY);
				i[2] += read(i[1], buffer + i[2], 16 - i[2]);
			}
			if (i[2])
			{
				ft_print_byte(i[3], 1, 0);
				ft_print_hex(buffer, i[2]);
				ft_print_char(buffer, i[2]);
			}
			i[3] += i[2];
		}
		close(i[1]);
	}
	ft_print_byte(i[3], 1, 1);
}

void	ft_hexmem(int fc, char **fv, int i[4], char buffer[16])
{
	while (++i[0] < fc)
	{
		i[1] = sec_open(fv[i[0]], O_RDONLY);
		while (i[2] == 16 && i[1] > 0)
		{
			i[2] = read(i[1], buffer, 16);
			while (i[2] < 16 && i[0] != (fc - 1))
			{
				close(i[1]);
				i[1] = sec_open(fv[++i[0]], O_RDONLY);
				i[2] += read(i[1], buffer + i[2], 16 - i[2]);
			}
			if (i[2])
			{
				ft_print_byte(i[3], 0, 0);
				ft_print_hex2(buffer, i[2]);
				ft_putchar('\n');
			}
			i[3] += i[2];
		}
		close(i[1]);
	}
	ft_print_byte(i[3], 0, 1);
}
