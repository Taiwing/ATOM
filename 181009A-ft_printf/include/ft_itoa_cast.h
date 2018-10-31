/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cast.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 00:40:37 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/01 00:42:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_CAST_H
# define FT_ITOA_CAST_H
# include <stdarg.h>
# include <stdlib.h>
# include "params.h"

char	*ft_itoa_cast(va_list cur, va_list ref, t_params *conv);

#endif
