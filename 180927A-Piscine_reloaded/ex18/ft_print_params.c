/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:33:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:33:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
