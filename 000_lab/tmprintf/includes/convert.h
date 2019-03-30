/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:55:40 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 13:37:15 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include <stdarg.h>
# include "ft_itoa_cast.h"
# include "p_conversion.h"
# include "lp_conversion.h"
# include "c_conversion.h"
# include "lc_conversion.h"
# include "s_conversion.h"
# include "ls_conversion.h"
# include "format_str.h"
# include "params.h"
# include "fstr.h"

void	convert(t_fstr *s, va_list cur, va_list ref, t_params *conv);

#endif
