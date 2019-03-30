/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:05:51 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/14 21:07:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_INT_DATA_H
# define FORMAT_INT_DATA_H

#include "t_pdata.h"
#include "t_params.h"

void	int_format(t_params *conv, t_pdata *l, int fdat[4], int *size);

#endif
