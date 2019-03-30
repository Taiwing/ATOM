/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xa.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 03:26:30 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 04:16:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_XA_H
# define GET_XA_H

# include "lsconfig.h"

void	get_xattracl(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
void	get_xattr_only(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
void	get_acl_only(char *path, t_lsfdata *lsf, t_lsconfig *cfg);
void	get_all_xattracl(char *path, t_lsfdata *lsf, t_lsconfig *cfg);

#endif
