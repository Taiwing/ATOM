/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:16:19 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/15 16:07:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "get_op.h"

void	do_op(int a, t_op_func f, int b)
{
	if (!f)
		ft_putstr("0\n");
	else if (b == 0 && (f == &div || f == &mod))
	{
		ft_putstr("Stop : ");
		ft_putstr(f == &div ? "division " : "modulo ");
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
