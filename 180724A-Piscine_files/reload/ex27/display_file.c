#include <unistd.h>
#include <fcntl.h>

void	ft_writestr(char *str, int out)
{
	while (*str)
		write(out, str++, 1);
}

int		main(int argc, char *argv[])
{
	int 	fd;
	size_t 	size;
	char 	buffer[256];

	if (argc != 2)
	{
		if (argc == 1)
			ft_writestr("File name missing.\n", 2);
		else
			ft_writestr("Too many arguments.\n", 2);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	while ((size = read(fd, buffer, 255)))
	{
		buffer[size] = 0;
		ft_writestr(buffer, 1);
	}
	close(fd);
	return 0;
}
