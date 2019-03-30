/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:08:09 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/06 17:23:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DIRS_H
# define LIST_DIRS_H

# include "lsconfig.h"

char	*build_path(const char *old_path, const char *dirname);
void	list_dir(t_lsconfig *cfg, const char *path, const char *dirname);
void	list_first_dir(t_lsconfig *cfg);

#endif
