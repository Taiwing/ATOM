#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "libft.h"

int		get_next_line(int fd, char **line);

int		*get_fds(int l, char **files)
{
	int	i;
	int	*fds;

	fds = (int *)malloc(l * sizeof(int));
	i = 0;
	while (*files)
		fds[i++] = open(*files++, O_RDONLY);
	return (fds); 
}

int		reading(int *rs, int l)
{
	int	r;

	r = 0;
	while (l--)
	{
		if (rs[l] < 0)
			return (0);
		r += rs[l];
	}
	return (r);
}

int		main(int argc, char **argv)
{
	int		i;
	int		l;
	int		nb;
	int		*rs;
	int		*fds;
	char	*line;

	if (argc < 2)
	{
		while (get_next_line(0, &line) > 0)
			printf("\"%s\"\n", line);
		return (0);
	}
	srand(time(NULL));
	l = argc - 1;
	fds = get_fds(l, ++argv);
	rs = (int *)malloc(l * sizeof(int));
	for (int j = 0; j < l; j++)
		rs[j] = 1;
	line = NULL;
	while (reading(rs, l))
	{
		i = rand() % l;
		nb = (rand() % 6) + 1;
		if (rs[i] > 0)
		{
			printf("\n%s: r = %d, i = %d, nb = %d\n", argv[i], rs[i], i, nb);
			while (nb-- && (rs[i] = get_next_line(fds[i], &line)) > 0)
				printf("\"%s\"\n", line);
		}
	}
	return (0);
}
