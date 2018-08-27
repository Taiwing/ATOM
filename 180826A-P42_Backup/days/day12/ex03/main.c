/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:03:28 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:03:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"
#include "ft_get_arguments.h"

int	main(int argc, char *argv[])
{
	int		c;
	int		fc;
	char	**fv;

	c = 0;
	fc = argc;
	fv = (char **)malloc(argc * sizeof(char *));
	ft_get_arguments(&c, &fc, fv, argv);
	ft_hexdump(c, fc, fv);
	return (0);
}
