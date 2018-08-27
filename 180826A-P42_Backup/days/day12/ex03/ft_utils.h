/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:03:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:03:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_pow(int a, int b);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *str);
void	ft_putnbr_base(int nbr, char *bas);

#endif
