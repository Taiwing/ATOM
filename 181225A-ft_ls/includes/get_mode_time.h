/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode_time.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:35:32 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 05:57:06 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MODE_TIME_H
# define GET_MODE_TIME_H

# include "lsconfig.h"

void	get_mode_str(char *mode_str, unsigned long int mode, int xattr_acl);
void	get_time_modif(char *time_str, t_lsfdata *lsf);
void	get_time_access(char *time_str, t_lsfdata *lsf);
void	get_time_creation(char *time_str, t_lsfdata *lsf);

#endif
