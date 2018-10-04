#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft.h"

typedef struct	s_gnl
{
	int		fd;
	char	*trail;
}				t_gnl;

int	get_next_line(const int fd, char **line);

#endif
