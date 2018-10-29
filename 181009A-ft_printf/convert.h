/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:55:40 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 20:55:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include <stdarg.h>
# include "params.h"
# include "fstr.h"

void	convert(t_fstr *s, va_list cur, va_list ref, t_params *conv);

#endif
