/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_cast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:54:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 20:54:15 by yforeau          ###   ########.fr       */
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
	else if (*f == 'p' || *f == 'P')
	{
		conv->cast |= (C_LONG | C_UNSIGNED);
		conv->flags |= F_HASH;
		conv->type = *f == 'p' ? 'x' : 'X';
	}
	else if (*f)
		conv->type = *f;
	return (*f ? f : NULL);	
}

char	*get_cast(char *f, t_params *conv)
{
	f--;
	while (*f == 'h' || *f == 'l' || *f == 'j' || *f == 'z')
	{
		if (*f == 'h' && conv->cast | C_SHORT == 0)
			conv->cast |= C_SHORT;
		else if (*f == 'h')
		{
			conv->cast |= C_CHAR;
			conv->cast ^= C_SHORT;
		}
		else if (*f == 'l' && conv->cast | C_LONG == 0)
			conv->cast |= C_LONG;
		else if (*f == 'l')
		{
			conv->cast |= C_LONG_LONG;
			conv->cast ^= C_LONG;
		}
		else if (*f == 'j')
			conv->cast |= C_INTMAX_T;
		else if (*f == 'z')
			conv->cast |= C_SIZE_T;
		f--;
	}
	return (f);
}


