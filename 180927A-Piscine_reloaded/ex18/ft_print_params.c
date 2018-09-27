void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	(void)argc;
	while (*++argv)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
	}
	return (0);
}
