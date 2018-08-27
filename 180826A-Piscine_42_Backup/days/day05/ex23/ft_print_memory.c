/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:22:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 19:27:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_hexnb(long long int nbr, char *base)
{
	if (nbr / 16)
		print_hexnb(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
}

void	ft_print_addr(long long int addr)
{
	long long int p;

	p = 0x10000000;
	while (addr < p)
	{
		ft_putchar('0');
		p >>= 4;
	}
	print_hexnb(addr, "0123456789abcdef");
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_hex(char *ptr, int l)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < l)
		{
			if (ptr[i] < 16)
				ft_putchar('0');
			print_hexnb((long long int)ptr[i], "0123456789abcdef");
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (!((i + 1) % 2))
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_char(char *ptr, int l)
{
	int i;

	i = 0;
	ft_putchar(' ');
	while (i < l)
	{
		if (ptr[i] > 31 && ptr[i] < 127)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				l;
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = addr;
	while (i < size)
	{
		l = size - i >= 16 ? 16 : size - i;
		ft_print_addr((long long int)(ptr + i));
		ft_print_hex(&ptr[i], l);
		ft_print_char(&ptr[i], l);
		i += 16;
	}
	return (addr);
}
