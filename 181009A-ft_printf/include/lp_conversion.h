/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:36:36 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/03 13:36:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LP_CONVERSION_H
# define LP_CONVERSION_H
# include <stdarg.h>
# include "ft_itoa_cast.h"
# include "libft.h"
# include "params.h"
# include "fetch.h"

char	*lp_conversion(va_list cur, va_list ref, t_params *conv);

#endif
