/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:38:11 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/26 15:55:36 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_OPTIONS_H
# define LS_OPTIONS_H

# include "lsconfig.h"

# define OPTSTRING	"RSUadefglortu1@"

extern void	(* const g_set_opt[256])(t_lsconfig *cfg);

void				set_up_r(t_lsconfig *cfg);	/*ok*/
void				set_up_s(t_lsconfig *cfg);	/*ok*/
void				set_up_u(t_lsconfig *cfg);	/*ok*/
void				set_a(t_lsconfig *cfg);		/*ok*/
void				set_d(t_lsconfig *cfg);		/*ok*/
void				set_e(t_lsconfig *cfg);
void				set_f(t_lsconfig *cfg);		/*ok*/
void				set_g(t_lsconfig *cfg);		/*ok*/
void				set_l(t_lsconfig *cfg);		/*ok*/
void				set_o(t_lsconfig *cfg);		/*ok*/
void				set_r(t_lsconfig *cfg);		/*ok*/
void				set_t(t_lsconfig *cfg);		/*ok*/
void				set_u(t_lsconfig *cfg);		/*ok*/
void				set_1(t_lsconfig *cfg);		/*ok*/
void				set_at(t_lsconfig *cfg);
void				usage(t_lsconfig *cfg);		/*ok*/

#endif
