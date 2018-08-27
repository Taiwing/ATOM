#include "sort.h"
#include "utils.h"

void	ft_sort_next(char ***next)
{
	while (*next)
		ft_sortalpha(*next++);
}

void	ft_sortlen(char **tab)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		j = i + 1;
		while (tab[j] && ft_strlcmp(tab[i], tab[j]) <= 0)
			j++;
		if (tab[j])
		{
			str = tab[i];
			tab[i] = tab[j];
			tab[j] = str;
			i = -1;
		}
		i++;	
	}
}

void    ft_sortalpha(char **tab)
{
	int     i;
	int     j;
	char    *str;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		j = i + 1;
		while (tab[j] && ft_strccmp(tab[i], tab[j]) <= 0)
			j++;
		if (tab[j])
		{
			str = tab[i];
			tab[i] = tab[j];
			tab[j] = str;
			i = -1;
		}
		i++;
	}
}
