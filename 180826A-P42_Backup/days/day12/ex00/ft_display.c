/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 07:01:41 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 07:16:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putdata(char *buffer, ssize_t br)
{
	write(1, buffer, br);
}

int		main(int argc, char **argv)
{
	int		fd;
	ssize_t	br;
	char	buffer[1024];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((br = read(fd, (void *)buffer, 1024)))
			ft_putdata(buffer, br);
		close(fd);
	}
	return (0);
}
