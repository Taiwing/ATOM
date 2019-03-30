/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:05:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 20:13:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pdata.h"
#include "libft.h"

void	init_buf(t_pdata *data)
{
	data->buf = data->sbuf;
	ft_bzero((void *)data->sbuf, BLOCK_SIZE);
	data->abuf = NULL;
	data->bufsize = BLOCK_SIZE;
	data->n = 0;
}

void	add_to_buf(t_pdata *data, char *add, int c, size_t size)
{
	char	*newbuf;
	size_t	newsize;

	newsize = data->n + size + 1;
	if (data->bufsize < newsize)
	{
		newsize = (newsize + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);
		if (!(newbuf = (char *)ft_memalloc(newsize)))
		{
			data->n = -1;
			return ;
		}
		ft_memcpy((void *)newbuf, (void *)data->buf, data->n);
		free(data->abuf);
		data->abuf = newbuf;
		data->bufsize = newsize;
		data->buf = data->abuf ? data->abuf : data->sbuf;	
	}
	if (add)
		ft_memcpy((void *)(data->buf + data->n), (void *)add, size);
	else
		ft_memset((void *)(data->buf + data->n), c, size);
	data->n += size;
}

void	print_buf(t_pdata *data)
{
	if (data->n > 0)
		write(1, data->buf, data->n);
	free(data->abuf);
}
