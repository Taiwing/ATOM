/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:26:16 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 10:26:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CONVERSION_H
# define P_CONVERSION_H
# include <stdarg.h>
# include "ft_itoa_cast.h"
# include "libft.h"
# include "params.h"
# include "fetch.h"

char	*p_conversion(va_list cur, va_list ref, t_params *conv);

#endif
