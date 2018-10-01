void	ft_foreach(int *tab, int length, void(*f)(int))
{
	if (!f || !tab || length < 1)
		return ;
	while (length--)
		f(*tab++);
}
