#include "utils.h"

void	ft_putnext(char ***next)
{
	while (*next)
		ft_show_tab(*next++);
}

char	***next_level(char **tab)
{
	static int  size = 0;
	char        ***next;
	char        **new;
	int         i;
	int         l;
	int			length;

	size++;
	new = 0;
	length = *tab ? ft_strlen(*tab) : 0;
	l = 0;
	while (tab[l] && ft_strlen(tab[l]) == length)
		l++;
	if (l)
	{
		new = (char **)malloc((l + 1) * sizeof(char *));
		i = 0;
		while (i < l)
			new[i++] = *tab++;
		new[i] = 0;
	}
	next = l ? next_level(tab) : (char ***)malloc(size * sizeof(char **));
	next[--size] = new;
	return (next);	
}

void	ft_show_tab(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab++);
		ft_putstr(*tab ? " " : "\n");
	}
}

int		ft_strlen(char *str)
{
	int		l;

	l = 0;
	while(str[l])
		l++;
	return (l);
}

int		ft_strccmp(char *s1, char *s2)
{
	return (*s1 && *s2 && MIN(*s1) == MIN(*s2) ? ft_strccmp(s1 + 1, s2 + 1) : MIN(*s1) - MIN(*s2));
}

int		ft_strlcmp(char *s1, char *s2)
{
	return (ft_strlen(s1) - ft_strlen(s2));
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	**ft_split_whitespaces(char *str)
{
	static int	size = 0;
	char		**tab;
	char		*cpy;
	int			i;
	int			l;

	size++;
	cpy = 0;
	while ((*str > 8 && *str < 12) || *str == 32)
		str++;
	l = 0;
	while (str[l] && !((str[l] > 8 && str[l] < 12) || str[l] == 32))
		l++;
	if (l)
	{
		cpy = (char *)malloc(l + 1);
		i = 0;
		while (i < l)
			cpy[i++] = *str++;
		cpy[i] = 0;
	}
	tab = l ? ft_split_whitespaces(str) : (char **)malloc(size * sizeof(char *));
	tab[--size] = cpy;
	return (tab);
}
