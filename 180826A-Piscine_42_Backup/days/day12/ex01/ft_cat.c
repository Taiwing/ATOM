/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:29:33 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 08:17:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putfile(char *name)
{
	int		fd;
	int		br;
	char	buffer[256];

	fd = name ? open(name, O_RDONLY) : 0;
	if (errno != 0)
	{
		ft_putstr("cat: ");
		ft_putstr(name);
		ft_putstr(errno == EACCES ? ": Permission denied.\n"
							: ": No such file or directory\n");
		errno = 0;
		return ;
	}
	while ((br = read(fd, (void *)buffer, 256)) > 0)
		write(1, buffer, br);
	if (fd)
		close(fd);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*++argv)
			ft_putfile(*argv);
	}
	else
		ft_putfile(0);
	return (0);
}
