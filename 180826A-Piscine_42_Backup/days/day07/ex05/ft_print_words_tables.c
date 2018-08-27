/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:07:07 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/08 17:07:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int	i;

	while (*tab)
	{
		i = 0;
		while ((*tab)[i])
			ft_putchar((*tab)[i++]);
		ft_putchar('\n');
		tab++;
	}
}
