int	ft_sqrt(int nb)
{
	int	r;

	r = 0;
	while (++r < nb / 2 && r < 46340)
	{
		if (r * r == nb)
			break;
	}
	return (r * r == nb ? r : 0);
}
