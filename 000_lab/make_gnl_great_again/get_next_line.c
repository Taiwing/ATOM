/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:55:35 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/11 12:09:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/******************************************************************************/

char	*ft_strchr3(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	return (*s == c ? (char *)s : NULL);
}

void	*ft_memset3(void *s, int c, size_t n)
{
	char	*m;

	m = (char *)s;
	while (n--)
		*m++ = c;
	return (s);
}

void	ft_bzero3(void *s, size_t n)
{
	ft_memset3(s, 0, n);
}

void	*ft_memalloc3(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero3(ptr, size);
	return (ptr);
}

char	*ft_strnew3(size_t size)
{
	return ((char *)ft_memalloc3(size + 1));
}

char	*ft_strncpy3(char *d, const char *s, size_t n)
{
	char	*dest;

	dest = d;
	while (n && *s)
	{
		*d++ = *s++;
		n--;
	}
	ft_bzero3(d, n);
	return (dest);
}

char	*ft_strsub3(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = ft_strnew3(len);
	if (!s || !new)
		return (NULL);
	return (ft_strncpy3(new, s + start, len));
}

void	ft_memdel3(void **ap)
{
	if (!ap)
		return ;
	if (*ap)
		free(*ap);
	*ap = NULL;
}

char	*ft_strcut3(char **s, size_t start, size_t l)
{
	char	*cut;

	cut = l > 0 ? ft_strsub3(*s, start, l) : NULL;
	ft_memdel3((void **)s);
	return (cut);
}

size_t	ft_strlen3(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

void	*ft_memcpy3(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strcpy3(char *d, const char *s)
{
	return ((char *)ft_memcpy3((void *)d, (const void *)s, ft_strlen3(s) + 1));
}

char	*ft_strncat3(char *dest, const char *src, size_t n)
{
	char	*d;

	d = ft_strchr3(dest, 0);
	while (n-- && *src)
		*d++ = *src++;
	*d = 0;
	return (dest);
}

char	*ft_stradd3(char **base, char *str, size_t l)
{
	char	*new;

	new = ft_strcpy3(ft_strnew3(ft_strlen3(*base) + l + 1), *base);
	ft_strncat3(new, str, l);
	ft_memdel3((void **)base);
	return (new);
}

char	*ft_strndup3(const char *s, size_t n)
{
	char	*new;

	if (!(new = ft_strnew3(n)))
		return (NULL);
	return (ft_strncpy3(new, s, n));
}

/******************************************************************************/

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
		if (cur->trail)
			*line = ft_strcut3(&(cur->trail), 0, ft_strlen3(cur->trail));
		else
			*line = NULL;
		if (!*line)
		{
			ft_lst_remove_if(lst, (void *)&(cur->fd), ft_isfd);
			free(cur);
		}
	}
	else if (r > 0)
	{
		if (cur->trail)
			cur->trail = ft_stradd3(&(cur->trail), buf, r);
		else
			cur->trail = ft_strndup3(buf, r);
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

	cur = ft_get_trail(fd, &lst);
	/*****GOOD*****/
	if ((eol = cur->trail ? ft_strchr3(cur->trail, 10) : NULL))
	{
		l = eol - cur->trail;
		*line = ft_strsub3(cur->trail, 0, l);
		cur->trail = ft_strcut3(&(cur->trail), l + 1, ft_strlen3(eol) - 1);
	}
	/*****GOOD*****/
	else if ((r = ft_read_file(cur, line, &lst)) == -1)
		return (-1);
	else if (r > 0)
		return (get_next_line(fd, line));
	return (*line != NULL);
}
