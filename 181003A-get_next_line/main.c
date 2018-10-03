#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int		get_next_line(int fd, char **line);

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0)
		return (1);
	i = 0;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
		printf("line %d: \"%s\"\n", ++i, line);
	return (0);
}
