#include "get_next_line.h"

char	*ft_strcut(char **s, size_t start, size_t l)
{
	char	*cut;

	cut = l > 0 ? ft_strsub(*s, start, l) : NULL;
	ft_memdel((void **)s);
	return (cut);
}

int	get_next_line(const int fd, char **line)
{
	int			r;
	char		*eol;
	char		buf[BUFF_SIZE];
	static char	*trail = NULL; /*TODO replace by a list to handle fds*/

	if ((eol = ft_strchr(trail, 10)))
	{
		*line = ft_strsub(trail, 0, eol - trail);
		trail = ft_strcut(&trail, eol - trail + 1, ft_strlen(eol) - 1);
	}
	else if ((r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	else if (r == 0)
		*line = ft_strcut(&trail, 0, ft_strlen(trail));
	else
	{
		eol = ft_strcpy(ft_strnew(ft_strlen(trail) + r + 1), trail);
		ft_strncat(eol, buf, r);
		ft_memdel((void **)&trail);
		trail = eol;
		return (get_next_line(fd, line));
	}
	return (*line != NULL);
}
