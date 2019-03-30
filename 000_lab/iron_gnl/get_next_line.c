/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:55:35 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/11 17:38:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_isfd(void *fd, void *content)
{
	return (*(int *)fd != ((t_gnl *)content)->fd);
}

void			rm_cur(t_list **lst, t_gnl *cur)
{
	ft_lst_remove_if(lst, (void *)&(cur->fd), ft_isfd);
	free(cur);
}

static t_gnl	*ft_get_trail(int fd, t_list **lst)
{
	t_list	*ref;
	t_list	*ptr;
	t_gnl	new;

	ref = *lst;
	ptr = ft_lst_find(*lst, (void *)&fd, ft_isfd);
	if (!ptr)
	{
		new.fd = fd;
		new.trail = NULL;
		ft_lst_push_front(lst, (void *)&new, sizeof(t_gnl));
		ptr = *lst;
		if (ptr == ref)
			return (NULL);
	}
	else
		ft_lst_move_front(lst, ptr);
	return ((t_gnl *)ptr->content);
}

static int		ft_read_file(t_gnl *cur, char **line, t_list **lst)
{
	int		r;
	size_t	l;
	char	buf[BUFF_SIZE];

	if (!(r = read(cur->fd, buf, BUFF_SIZE)))
	{
		l = cur->trail ? ft_strlen(cur->trail) : 0;
		if ((*line = ft_strcut(&(cur->trail), 0, l)) && l > 0)
			r = -1;
		if (!*line)
			rm_cur(lst, cur);
	}
	else if (r > 0)
	{
		if (cur->trail)
			cur->trail = ft_stradd(&(cur->trail), buf, r);
		else
			cur->trail = ft_strndup(buf, r);
		r = !cur->trail ? -1 : r;
	}
	return (r);
}

int	get_next_line(const int fd, char **line)
{
	int				r;
	size_t			l;
	char			*eol;
	t_gnl			*cur;
	static t_list	*lst = NULL;

	r = 0;
	cur = ft_get_trail(fd, &lst);
	if (cur && (eol = cur->trail ? ft_strchr(cur->trail, 10) : NULL))
	{
		l = ft_strlen(eol) - 1;
		if (!(*line = ft_strsub(cur->trail, 0, eol - cur->trail)) ||
			(!(cur->trail = ft_strcut(&(cur->trail), eol - cur->trail + 1, l))
			&& l > 0))
			r = -1;
	}
	else if (!cur || (r = ft_read_file(cur, line, &lst)) == -1)
		;
	else if (r > 0)
		return (get_next_line(fd, line));
	if (r == -1 && cur)
		rm_cur(&lst, cur);
	return (r == -1 || !cur ? -1 : *line != NULL);
}
