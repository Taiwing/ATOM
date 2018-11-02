/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 12:18:56 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/02 15:24:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LC_CONVERSION_H
# define LC_CONVERSION_H
# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>
# include "params.h"
# include "fetch.h"

char	*lc_conversion(va_list cur, va_list ref, t_params *conv);

#endif
