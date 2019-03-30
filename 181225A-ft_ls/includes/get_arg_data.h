/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:18:45 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/05 20:16:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ARG_DATA_H
# define GET_ARG_DATA_H

# include "lsconfig.h"

int	get_arg_data_one(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
int	get_arg_data_columns(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
int	get_arg_data_long(char *path, t_lsfdata *lsf, t_lsconfig *cfg);

#endif
