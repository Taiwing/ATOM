int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb < 0 || nb > 12 ? 0 : 1;
	while (nb > 0)
		res *= nb--;
	return	(res);
}
