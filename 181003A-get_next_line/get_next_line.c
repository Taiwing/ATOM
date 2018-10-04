#include "get_next_line.h"

static int		ft_isfd(void *fd, void *content)
{
	return (*(int *)fd != ((t_gnl *)content)->fd);
}

static t_gnl	*ft_get_trail(int fd, t_list **lst)
{
	t_list	*ptr;
	t_gnl	*new;

	ptr = ft_lst_find(*lst, (void *)&fd, ft_isfd);
	if (!ptr)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		new->fd = fd;
		new->trail = NULL;
		ft_lst_push_front(lst, (void *)new, sizeof(t_gnl));
		ptr = *lst;	
	}
	return ((t_gnl *)ptr->content);
}

static char		*ft_strcut(char **s, size_t start, size_t l)
{
	char	*cut;

	cut = l > 0 ? ft_strsub(*s, start, l) : NULL;
	ft_memdel((void **)s);
	return (cut);
}

int	get_next_line(const int fd, char **line)
{
	int				r;
	char			*eol;
	t_gnl			*cur;
	char			buf[BUFF_SIZE];
	static t_list	*lst = NULL;

	cur = ft_get_trail(fd, &lst);
	if ((eol = ft_strchr(cur->trail, 10)))
	{
		*line = ft_strsub(cur->trail, 0, eol - cur->trail);
		cur->trail = ft_strcut(&(cur->trail), eol - cur->trail + 1, ft_strlen(eol) - 1);
	}
	else if ((r = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	else if (r == 0)
		*line = ft_strcut(&(cur->trail), 0, ft_strlen(cur->trail));
	else
	{
		eol = ft_strcpy(ft_strnew(ft_strlen(cur->trail) + r + 1), cur->trail);
		ft_strncat(eol, buf, r);
		ft_memdel((void **)&(cur->trail));
		cur->trail = eol;
		return (get_next_line(fd, line));
	}
	return (*line != NULL);
}
