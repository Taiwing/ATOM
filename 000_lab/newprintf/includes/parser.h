/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:26:02 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 10:26:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include "libft.h"
# include "get_conv.h"
# include "convert.h"
# include "fstr.h"

t_fstr	*parser(char **fmt, va_list cur, va_list ref);

#endif
