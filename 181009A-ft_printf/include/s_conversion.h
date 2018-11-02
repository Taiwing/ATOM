/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:22:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/01 21:23:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CONVERSION_H
# define S_CONVERSION_H
# include <stdarg.h>
# include "libft.h"
# include "params.h"
# include "fetch.h"

char	*s_conversion(va_list cur, va_list ref, t_params *conv);

#endif
