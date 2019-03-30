/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:23:17 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/17 16:25:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include "t_pdata.h"
# include "t_params.h"

void	parser(t_pdata *data, char **fmt, va_list cur, va_list ref);

#endif
