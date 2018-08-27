#include <unistd.h>
#include <stdlib.h>

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

int		main(int argc, char **argv)
{
	char	**tab;
	char	*first;
	
	if (argc > 1 && argv[1] && argv[1][0])
	{
		tab = ft_split_whitespaces(argv[1]);
		first = *tab++;
		if (first)
		{
			while (*tab)
			{
				ft_putstr(*tab++);
				ft_putstr(" ");
			}
			ft_putstr(first);
		}
	}
	ft_putstr("\n");
	return (0);
}
