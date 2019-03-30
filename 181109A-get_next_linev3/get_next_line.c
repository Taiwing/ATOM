/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:55:35 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/10 09:58:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
		ft_lst_move_front(lst, ptr);
	return ((t_gnl *)ptr->content);
}

static int		ft_read_file(t_gnl *cur, char **line, t_list **lst)
{
	int		r;
	char	buf[BUFF_SIZE];

	if (!(r = read(cur->fd, buf, BUFF_SIZE)))
	{
		*line = ft_strcut(&(cur->trail), 0, ft_strlen(cur->trail));
		if (!*line)
		{
			ft_lst_remove_if(lst, (void *)&(cur->fd), ft_isfd);
			free(cur);
		}
	}
	else if (r > 0)
		cur->trail = ft_stradd(&(cur->trail), buf, r);
	return (r);
}

int	get_next_line(const int fd, char **line)
{
	int				r;
	size_t			l;
	char			*eol;
	t_gnl			*cur;
	static t_list	*lst = NULL;

	cur = ft_get_trail(fd, &lst);
	if ((eol = cur->trail ? ft_strchr(cur->trail, 10) : NULL))
	{
		l = eol - cur->trail;
		*line = ft_strsub(cur->trail, 0, l);
		cur->trail = ft_strcut(&(cur->trail), l + 1, ft_strlen(eol) - 1);
	}
	else if ((r = ft_read_file(cur, line, &lst)) == -1)
		return (-1);
	else if (r > 0)
		return (get_next_line(fd, line));
	return (*line != NULL);
}
