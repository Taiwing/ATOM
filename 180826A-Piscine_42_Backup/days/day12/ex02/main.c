/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:59:03 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 16:59:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "error.h"
#include "ft_tail.h"

int	main(int argc, char **argv)
{
	int	c;

	c = 0;
	if (argc < 4 || ft_strcmp(argv[1], "-c") || !(c = ft_atoi(argv[2])))
	{
		print_arg_error(argc, argv);
		return (1);
	}
	ft_tail(argc - 3, argv + 3, c);
	return (0);
}
