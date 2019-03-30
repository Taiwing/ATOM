/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_cast.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:24:58 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/15 10:25:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TYPE_CAST_H
# define GET_TYPE_CAST_H
# include "params.h"

char	*get_type(char *f, t_params *conv);
char	*get_cast(char *f, t_params *conv);
int		check_type_cast(t_params *conv);

#endif
