/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:02:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/16 00:49:27 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	char	*ptr;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ptr = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = ptr;
			i = -1;
		}
		i++;
	}
}
