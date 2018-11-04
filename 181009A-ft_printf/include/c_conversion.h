/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 21:00:39 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/04 19:23:47 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_CONVERSION_H
# define C_CONVERSION_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include "params.h"
# include "fetch.h"

char	*c_conversion(va_list cur, va_list ref, t_params *conv);

#endif
