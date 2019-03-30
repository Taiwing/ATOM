/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_fetch.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:03:23 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 22:07:28 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_FETCH_H
# define FT_ITOA_FETCH_H

# include <inttypes.h>
# include <stddef.h>
# include <stdarg.h>

char	*ft_itoa_us_int(va_list cur, va_list ref, t_params *conv, int cast);
char	*ft_itoa_us_lint(va_list cur, va_list ref, t_params *conv, int cast);
char	*ft_itoa_us_llint(va_list cur, va_list ref, t_params *conv, int cast);
char	*ft_itoa_us_size(va_list cur, va_list ref, t_params *conv, int cast);
char	*ft_itoa_us_intmax(va_list cur, va_list ref, t_params *conv, int cast);

#endif
