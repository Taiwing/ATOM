/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:40:37 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/01 14:38:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_CAST_H
# define FT_ITOA_CAST_H
# include <stdarg.h>
# include <stdlib.h>
# include "params.h"
# include "libft.h"

extern char	g_bstr[2][17];

char		*ft_itoa_cast(va_list cur, va_list ref, t_params *conv);

char		*ft_itoa_int(int n);
char		*ft_itoa_shint(t_shint n);
char		*ft_itoa_lint(t_lint n);
char		*ft_itoa_llint(t_llint n);
char		*ft_itoa_ssize_t(ssize_t n);
char		*ft_itoa_intmax_t(intmax_t n);
char		*ft_itoa_char(char n);

char		*ft_itoa_base_uint(t_uint n, int base, int maj);
char		*ft_itoa_base_ushint(t_ushint n, int base, int maj);
char		*ft_itoa_base_ulint(t_ulint n, int base, int maj);
char		*ft_itoa_base_ullint(t_ullint n, int base, int maj);
char		*ft_itoa_base_size_t(size_t n, int base, int maj);
char		*ft_itoa_base_uintmax_t(uintmax_t n, int base, int maj);
char		*ft_itoa_base_uchar(t_uchar n, int base, int maj);

#endif
