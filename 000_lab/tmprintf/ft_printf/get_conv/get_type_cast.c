/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:54:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 15:50:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_type_cast.h"

char	*get_type(char *f, t_params *conv)
{
	while (*f && *f != 'd' && *f != 'D' && *f != 'i' && *f != 'o' && *f != 'O'
			&& *f != 'u' && *f != 'U' && *f != 'x' && *f != 'X' && *f != 'c'
			&& *f != 'C' && *f != 's' && *f != 'S' && *f != 'p' && *f != 'P'
			&& *f != '%')
		f++;
	if (*f == 'D' || *f == 'O' || *f == 'U')
	{
		conv->cast |= *f == 'D' ? C_LONG : C_LONG | C_UNSIGNED;
		conv->type = *f + 32;
	}
	else if (*f == 'u' || *f == 'o' || *f == 'x' || *f == 'X')
	{
		conv->cast |= C_UNSIGNED;
		conv->type = *f;
	}
	else if (*f)
		conv->type = *f == 'i' ? 'd' : *f;
	return (f);
}

char	*get_cast(char *f, t_params *conv)
{
	char	c;

	c = conv->cast;
	f--;
	while (*f == 'h' || *f == 'l' || *f == 'j' || *f == 'z')
	{
		if (*f == 'h' && !(conv->cast & C_SHORT) && !(c & C_LONG))
			conv->cast |= C_SHORT;
		else if (*f == 'h' && !(c & C_LONG))
			conv->cast = (conv->cast | T_CHAR) & ~C_SHORT;
		else if (*f == 'l' && !(conv->cast & C_LONG))
			conv->cast |= C_LONG;
		else if (*f == 'l')
			conv->cast = (conv->cast | C_LONG_LONG) & ~C_LONG;
		else if (*f == 'j' && !(c & C_LONG))
			conv->cast |= T_INTMAX_T;
		else if (*f == 'j')
			conv->cast |= T_INTMAX_T;
		else if (*f == 'z')
			conv->cast |= (c & C_LONG) ? C_UNSIGNED : T_SIZE_T;
		f--;
	}
	return (f);
}

int		check_type_cast(t_params *conv)
{
	unsigned char	c;

	conv->cast ^= !conv->cast || !(conv->cast ^ C_UNSIGNED) ? C_DEFAULT : 0;
	c = conv->cast & ~C_UNSIGNED;
	if (conv->type == 'c' || conv->type == 's')
	{
		conv->type = conv->cast == C_LONG ? conv->type - 32 : conv->type;
		if (conv->cast == C_LONG || conv->cast == C_DEFAULT)
			return (1);
	}
	else if ((conv->type == 'C' || conv->type == 'S')
			&& conv->cast == C_DEFAULT)
		return (1);
	else if ((conv->type && conv->type != '%' && conv->type != 'C'
			&& conv->type != 'S') && (c == C_DEFAULT || c == C_SHORT
			|| c == C_LONG || c == C_LONG_LONG || c == T_SIZE_T
			|| c == T_INTMAX_T || c == T_CHAR))
		return (1);
	else if (conv->type == '%' && conv->cast == C_DEFAULT)
		return (1);
	if (conv->type == '%' || !*(conv->eoc))
		conv->eoc = conv->eoc - 1;
	conv->soc = conv->soc - 1;
	conv->type = 0;
	return (0);
}
