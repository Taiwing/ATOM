void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}

void	ft_putendl(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_sort(char **v)
{
	char	*str;
	char	**p;

	while (*++v)
	{
		str = *v;
		p = v;
		while (*++p)
		{
			if (ft_strcmp(str, *p) > 0)
			{
				*v-- = *p;
				*p = str;
				break;
			}
		}
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	ft_sort(argv);
	while (*++argv)
		ft_putendl(*argv);
	return (0);
}
