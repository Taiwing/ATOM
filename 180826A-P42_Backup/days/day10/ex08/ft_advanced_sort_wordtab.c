/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:16:54 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/15 20:46:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*ptr;

	if (!tab || !cmp)
		return ;
	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if ((*cmp)(tab[i], tab[i + 1]) > 0)
		{
			ptr = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = ptr;
			i = -1;
		}
		i++;
	}
}
