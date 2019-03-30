/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:36:46 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/07 14:48:43 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PRINT_H
# define LS_PRINT_H

# include "lsconfig.h"

void	ls_print_dir(t_lsconfig *cfg, char *dirname);
void	ls_print_file_one(t_lsfdata *lsf, t_lsconfig *cfg);
void	ls_print_file_columns(t_lsfdata *lsf, t_lsconfig *cfg);
void	ls_print_file_long(t_lsfdata *lsf, t_lsconfig *cfg);
void	ls_print_file_long_g(t_lsfdata *lsf, t_lsconfig *cfg);
void	ls_print_file_long_o(t_lsfdata *lsf, t_lsconfig *cfg);
void	ls_print_file_long_go(t_lsfdata *lsf, t_lsconfig *cfg);

#endif
