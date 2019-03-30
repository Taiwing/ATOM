/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:52:48 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/23 06:13:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FILE_DATA_H
# define GET_FILE_DATA_H

# include "lsconfig.h"

int	get_file_data_one(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp);
int	get_file_data_columns(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp);
int	get_file_data_long(char *path, t_lsfdata *lsf,
		t_lsconfig *cfg, struct dirent *fp);

#endif
