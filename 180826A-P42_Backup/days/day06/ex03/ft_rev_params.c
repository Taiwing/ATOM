/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:53:10 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 14:31:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

int	main(int argc, char **argv)
{
	while (argc - 1 > 0)
	{
		while (*argv[argc - 1])
			ft_putchar(*argv[argc - 1]++);
		ft_putchar('\n');
		argc--;
	}
	return (0);
}
