/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:04:30 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/16 19:06:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FLAGS_H
# define GET_FLAGS_H

# include <stdarg.h>
# include "t_params.h"

//# include "fetch.h"
//# include "libft.h"

/*
** TODO: add ft_atoi_forward to libft and remake fetch
*/

//# include "ft_atoi_forward.h"

int	get_flags(char **fmt, va_list cur, va_list ref, t_params *conv);

#endif
