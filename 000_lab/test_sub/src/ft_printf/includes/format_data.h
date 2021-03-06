/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:10:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/18 13:56:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_DATA_H
# define FORMAT_DATA_H

# include "t_params.h"
# include "t_pdata.h"

enum	e_fdat {SPAD, ZPAD, SIGN, HEX};

void	format_data(t_pdata *d, t_pdata *l, t_params *conv, int size);

#endif
