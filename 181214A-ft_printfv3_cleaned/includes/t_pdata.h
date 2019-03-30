/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:56:33 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/15 21:24:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PDATA_H
# define T_PDATA_H

# define BLOCK_SIZE 256

# include <stddef.h>

typedef struct	s_pdata
{
	char		*buf;
	char		sbuf[BLOCK_SIZE];
	char		*abuf;
	size_t		bufsize;
	int			n;
}				t_pdata;

void			init_buf(t_pdata *data);
void			add_to_buf(t_pdata *data, char *add, int c, size_t size);
void			print_buf(t_pdata *data, int fd);

#endif
