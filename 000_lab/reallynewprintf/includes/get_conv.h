/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:12 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/16 19:04:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CONV_H
# define GET_CONV_H

# include <stdarg.h>
# include "t_params.h"

int	get_conv(char **fmt, va_list cur, va_list ref, t_params *conv);

#endif
