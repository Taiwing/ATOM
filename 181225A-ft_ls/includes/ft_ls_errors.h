/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:41:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 09:08:56 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_ERRORS_H
# define FT_LS_ERRORS_H

# include "lsconfig.h"

void	put_opendir_error(char *path, t_lsconfig *cfg);
void	add_error(char *path, t_lsconfig *cfg);
void	print_errors(t_lsconfig *cfg);

#endif
