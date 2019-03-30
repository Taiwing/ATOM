/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:24:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/25 18:48:04 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "t_farg.h"
# include "t_pdata.h"
# include "t_params.h"

void	convert(t_pdata *data, t_farg *args, t_params *conv, char **fmt);

#endif
