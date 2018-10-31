/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:55:58 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/31 14:02:55 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fetch.h"

/*
** fetch() uses the va_list macros to fetch arguments
** it is given an index n that if superior to 0 will
** look for the nth argument in the list by creating
** a temporary copy of the list given as a reference
** if it n is equal to 0 it will simply perform take
** the argument of the ref, therby modifying it
** the result is placed a the location given by ptr
*/

void	fetch(va_list ref, int n, int cast, void *ptr)
{
	va_list	tmp;

	if (n < 0)
		return ;
	else if (n > 0)
	{
		va_copy(tmp, ref);
		while (--n)
			va_arg(tmp, void);
		get_val(tmp, cast, ptr);
		va_end(tmp);
	}
	else if (n == 0)
		get_val(ref, cast, ptr);
}

void	get_val(va_list tmp, int cast, void *ptr)
{
	if (cast & T_INT)
		cast_int(tmp, cast, ptr);
	else if (cast == T_CHAR)
		*(char *)ptr = va_arg(tmp, char);
	else if (cast == T_CHAR | C_UNSIGNED)
		*(t_uchar *)ptr = va_arg(tmp, t_uchar);
	else if (cast == T_SIZE_T)
		*(ssize_t *)ptr = va_arg(tmp, ssize_t);
	else if (cast == T_SIZE_T | C_UNSIGNED)
		*(size_t *)ptr = va_arg(tmp, size_t);
	else if (cast == T_INTMAX_T)
		*(intmax_t *)ptr = va_arg(tmp, intmax_t);
	else if (cast == T_INTMAX_T | C_UNSIGNED)
		*(uintmax_t *)ptr = va_arg(tmp, uintmax_t);
	else if (cast == T_WINT_T)
		*(wint_t *)ptr = va_arg(tmp, wint_t);
	else if (cast == T_WCHAR_T_P)
		*(wchar_t **)ptr = va_arg(tmp, wchar_t *);
	else if (cast == T_CHAR_P)
		*(char **)ptr = va_arg(tmp, char *);
}

void	cast_int(va_list, int cast, void *ptr)
{
	if (cast == T_INT)
		*(int *)ptr = va_arg(tmp, int);
	else if (cast == T_INT | C_UNSIGNED)
		*(t_uint *)ptr = va_arg(tmp, t_uint);
	else if (cast == T_INT | C_SHORT)
		*(t_shint *)ptr = va_arg(tmp, t_shint);
	else if (cast == T_INT | C_SHORT | C_UNSIGNED)
		*(t_ushint *)ptr = va_arg(tmp, t_ushint);
	else if (cast == T_INT | C_LONG)
		*(t_lint *)ptr = va_arg(tmp, t_lint);
	else if (cast == T_INT | C_LONG | C_UNSIGNED)
		*(t_ulint *)ptr = va_arg(tmp, t_ulint);
	else if (cast == T_INT | C_LONG_LONG)
		*(t_llint *)ptr = va_arg(tmp, t_llint);
	else if (cast == T_INT | C_LONG_LONG | C_UNSIGNED)
		*(t_ullint *)ptr = va_arg(tmp, t_ullint);
}
