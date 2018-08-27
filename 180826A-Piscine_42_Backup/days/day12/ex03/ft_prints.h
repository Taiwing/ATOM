/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:04:52 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:04:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTS_H
# define FT_PRINTS_H
# include "ft_utils.h"

void	ft_print_byte(int byte, int ascii, int last);
void	ft_print_hex(char *ptr, int l);
void	ft_print_hex2(char *ptr, int l);
void	ft_print_char(char *ptr, int l);

#endif
