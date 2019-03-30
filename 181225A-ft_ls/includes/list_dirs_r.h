/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs_r.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:52:54 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 13:13:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DIRS_R_H
# define LIST_DIRS_R_H

# include "lsconfig.h"

void	list_dir_r(t_lsconfig *cfg, const char *path, const char *dirname);
void	list_first_dir_r(t_lsconfig *cfg);
void	dir_recursion_hide_on(t_lsconfig *cfg, t_lsddata *lsd);
void	dir_recursion_hide_off(t_lsconfig *cfg, t_lsddata *lsd);

#endif
