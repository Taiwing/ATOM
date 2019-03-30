/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:56:11 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/28 10:43:19 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int m = ft_printf("mine: %hhld\n", 128);
	int o = printf("orig: %hhld\n", 128);
	ft_printf("m = %d\no = %d\n", m, o);
	m = ft_printf("mine: %hhlu\n", 128);
	o = printf("orig: %hhlu\n", 128);
	ft_printf("m = %d\no = %d\n", m, o);
	m = ft_printf("mine: %hld\n", 128);
	o = printf("orig: %hld\n", 128);
	ft_printf("m = %d\no = %d\n", m, o);
	ft_printf("sufysiyf%.15cdsfysyof\n");
	printf("sufysiyf%.15cdsfysyof\n");
	return (0);
}
