/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:55:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/17 11:26:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define GNL_BUFF_SIZE 32

typedef struct	s_gnl
{
	int			fd;
	char		*trail;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
