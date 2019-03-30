/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 21:45:26 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 21:45:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_CONVERSION_H
# define LS_CONVERSION_H
# include <stdarg.h>
# include "libft.h"
# include "params.h"
# include "fetch.h"

char	*ls_conversion(va_list cur, va_list ref, t_params *conv);

#endif
