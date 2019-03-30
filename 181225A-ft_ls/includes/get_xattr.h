/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xattr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:14:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/03 04:15:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_XATTR_H
# define GET_XATTR_H

# include "lsconfig.h"

int	get_xattr(char *path, t_lsfdata *lsf, t_lsconfig *cfg);

#endif
