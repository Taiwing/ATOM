/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:17:13 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/12 12:58:32 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_mul(int a, int b);
int	ft_div(int a, int b);
int	ft_mod(int a, int b);

typedef int(*t_op_func)(int, int);

#endif
