/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:45:48 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/31 17:51:39 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FLAGS_H
# define GET_FLAGS_H
# include <stdarg.h>
# include "params.h"
# include "fetch.h"
# include "ft_atoi_forward.h"

int	get_flags(char *eof, va_list cur, va_list ref, t_params *conv);

#endif
