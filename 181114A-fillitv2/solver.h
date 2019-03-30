/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:27:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/14 16:31:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

typedef struct	s_data
{
	int			tc;
	int			*tetros;
	int			l;
	char		**square;
}				t_data;

int				get_square(int tc, int *tetros, char ***square);

#endif
