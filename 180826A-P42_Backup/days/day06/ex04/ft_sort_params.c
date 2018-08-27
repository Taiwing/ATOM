/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:53:10 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 15:41:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? ft_strcmp(s1 + 1, s2 + 1) : *s1 - *s2);
}

void	ft_sort(int c, char **v)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	while (i < c)
	{
		j = i + 1;
		while (j < c)
		{
			if (ft_strcmp(v[i], v[j]) > 0)
			{
				ptr = v[i];
				v[i] = v[j];
				v[j] = ptr;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_sort(argc - 1, ++argv);
	while (*argv)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
		argv++;
	}
	return (0);
}
