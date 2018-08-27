/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 08:16:45 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/12 09:35:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_OP_H
# define GET_OP_H
# include "ops.h"

typedef struct	s_op
{
	char		*symb;
	t_op_func	f;
}				t_op;

t_op_func		get_op(char *opstr);

#endif
