/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 03:17:21 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/15 20:41:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	while (tab && f && *tab)
	{
		if ((*f)(*tab++) == 1)
			return (1);
	}
	return (0);
}
