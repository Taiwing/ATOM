/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:24:01 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/04 11:25:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	if (*str == 0)
		return (1);
	else if (*str > 64 && *str < 91)
		return (ft_str_is_uppercase(str + 1));
	return (0);
}