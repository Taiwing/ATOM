/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:06:38 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/05 12:44:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_FILES_H
# define LIST_FILES_H

# include "lsconfig.h"
# include "libft.h"
# include <dirent.h>

void	list_files_hide_off(t_lsconfig *cfg, t_lsddata *lsd, int *len);
void	list_files_hide_on(t_lsconfig *cfg, t_lsddata *lsd, int *len);

#endif
