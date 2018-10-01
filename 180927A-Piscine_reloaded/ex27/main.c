#include <fcntl.h>
#include <unistd.h>

void	ft_putfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		rd;
	char	buf[1024];

	if (argc != 2)
	{
		ft_putfd(argc < 2 ? "File name missing.\n" : "Too many arguments.\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((rd = read(fd, buf, 1023)) > 0)
	{
		buf[rd] = 0;
		ft_putfd(buf, 1);
	}
	return (0);
}
