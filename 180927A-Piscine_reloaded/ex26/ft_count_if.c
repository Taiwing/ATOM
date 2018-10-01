int		ft_count_if(char **tab, int(*f)(char*))
{
	int	c;

	c = 0;
	while (tab && f && *tab)
		c += (f(*tab++) == 1);
	return (c);
}
