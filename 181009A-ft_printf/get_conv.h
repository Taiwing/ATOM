/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:49 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 20:53:52 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONV_H
# define GET_CONV_H
# include <stdarg.h>
# include "params.h"
# include "get_type_cast.h"

void	get_conv(char **fmt, va_list cur, va_list ref, t_params *conv);

#endif
