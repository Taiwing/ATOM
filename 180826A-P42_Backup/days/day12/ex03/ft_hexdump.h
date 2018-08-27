/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:05:40 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:05:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H
# include "ft_prints.h"

void	ft_hexdump(int c, int fc, char **fv);
void	ft_hexmem_ascii(int fc, char **fv, int i[4], char buffer[16]);
void	ft_hexmem(int fc, char **fv, int i[4], char buffer[16]);

#endif
