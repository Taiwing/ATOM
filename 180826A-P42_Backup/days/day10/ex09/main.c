/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:16:19 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 01:12:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_op.h"

void	do_op(int a, t_op_func f, int b)
{
	if (f == &ft_usage)
		(*f)(a, b);
	else if (b == 0 && (f == &ft_div || f == &ft_mod))
	{
		ft_putstr("Stop : ");
		ft_putstr(f == &ft_div ? "division " : "modulo ");
		ft_putstr("by zero\n");
	}
	else
	{
		ft_putnbr((*f)(a, b));
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		do_op(ft_atoi(argv[1]), get_op(argv[2]), ft_atoi(argv[3]));
	return (0);
}
