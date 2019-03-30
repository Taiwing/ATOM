/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:24:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/16 20:27:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <stdarg.h>
# include "t_pdata.h"
# include "t_params.h"

void	convert(t_pdata *data, va_list cur, va_list ref, t_params *conv);

#endif
