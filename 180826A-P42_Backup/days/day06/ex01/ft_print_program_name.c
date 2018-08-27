/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:37:43 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 15:40:25 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

int	main(int argc, char **argv)
{
	argc = 0;
	while (**argv)
		ft_putchar(*(*argv)++);
	ft_putchar('\n');
	return (0);
}
