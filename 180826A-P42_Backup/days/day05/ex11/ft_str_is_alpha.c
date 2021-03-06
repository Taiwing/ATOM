/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:54:11 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/04 11:08:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	if (!str || *str == 0)
		return (1);
	if (*str && ((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
		return (ft_str_is_alpha(str + 1));
	return (0);
}
