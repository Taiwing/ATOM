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
	/*else if (*lst != ptr)
		ft_lst_move_front(lst, ptr)*/
	return ((t_gnl *)ptr->content);
}

static char		*ft_strcut(char **s, size_t start, size_t l)
{
	char	*cut;

	cut = l > 0 ? ft_strsub(*s, start, l) : NULL;
	ft_memdel((void **)s);
	return (cut);
}

static char		*ft_stradd(char **base, char *str, size_t l)
{
	char	*new;

	new = ft_strcpy(ft_strnew(ft_strlen(*base) + l + 1), *base);
	ft_strncat(new, str, l);
	ft_memdel((void **)base);
	return (new);
}

//static int		ft_read_file(int fd, t_gnl *cur)

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
	{
		*line = ft_strcut(&(cur->trail), 0, ft_strlen(cur->trail));
		if (!*line)
			ft_lst_remove_if(&lst, (void *)&fd, ft_isfd);
	}
	else
	{
		cur->trail = ft_stradd(&(cur->trail), buf, r);
		return (get_next_line(fd, line));
	}
	return (*line != NULL);
}
