/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fetch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:21:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 22:05:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_itoa_us_int(va_list cur, va_list ref, t_params *conv, int cast)
{
	int				si;
	unsigned int	ui;
	int				b;

	if (cast == T_INT)
	{
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&si);
		return (si ? ft_itoa_int(si) : NULL);
	}
	else
	{
		b = conv->type == 'o' ? 8 : 10;
		b = conv->type == 'x' || conv->type == 'X' ? 16 : b;
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&ui);
		return (ui ? ft_itoa_base_uint(ui, b, conv->type == 'X') : NULL);
	}
}


char	*ft_itoa_us_lint(va_list cur, va_list ref, t_params *conv, int cast)
{
	long int			si;
	long unsigned int	ui;
	int					b;

	if (cast == (T_INT | C_LONG))
	{
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&si);
		return (si ? ft_itoa_lint(si) : NULL);
	}
	else
	{
		b = conv->type == 'o' ? 8 : 10;
		b = conv->type == 'x' || conv->type == 'X' ? 16 : b;
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&ui);
		return (ui ? ft_itoa_base_ulint(ui, b, conv->type == 'X') : NULL);
	}
}


char	*ft_itoa_us_llint(va_list cur, va_list ref, t_params *conv, int cast)
{
	long long int			si;
	long long unsigned int	ui;
	int						b;

	if (cast == (T_INT | C_LONG_LONG))
	{
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&si);
		return (si ? ft_itoa_llint(si) : NULL);
	}
	else
	{
		b = conv->type == 'o' ? 8 : 10;
		b = conv->type == 'x' || conv->type == 'X' ? 16 : b;
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&ui);
		return (ui ? ft_itoa_base_ullint(ui, b, conv->type == 'X') : NULL);
	}
}


char	*ft_itoa_us_size(va_list cur, va_list ref, t_params *conv, int cast)
{
	ssize_t	si;
	size_t	ui;
	int		b;

	if (cast == T_SIZE_T)
	{
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&si);
		return (si ? ft_itoa_ssize_t(si) : NULL);
	}
	else
	{
		b = conv->type == 'o' ? 8 : 10;
		b = conv->type == 'x' || conv->type == 'X' ? 16 : b;
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&ui);
		return (ui ? ft_itoa_base_size_t(ui, b, conv->type == 'X') : NULL);
	}
}


char	*ft_itoa_us_intmax(va_list cur, va_list ref, t_params *conv, int cast)
{
	intmax_t	si;
	uintmax_t	ui;
	int			b;

	if (cast == T_INTMAX_T)
	{
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&si);
		return (si ? ft_itoa_intmax_t(si) : NULL);
	}
	else
	{
		b = conv->type == 'o' ? 8 : 10;
		b = conv->type == 'x' || conv->type == 'X' ? 16 : b;
		fetch(conv->arg ? ref : cur, conv->arg, cast, (void *)&ui);
		return (ui ? ft_itoa_base_uintmax_t(ui, b, conv->type == 'X') : NULL);
	}
}


