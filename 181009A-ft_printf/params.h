/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:30 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/29 21:07:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
#ifndef PARAMS_H
# define PARAMS_H

# define C_UNSIGNED		0x01
# define C_DEFAULT		0x02
# define C_CHAR			0x04
# define C_SHORT		0x08
# define C_LONG			0x10
# define C_LONG_LONG	0x20
# define C_SIZE_T		0x40
# define C_INTMAX_T		0x80

typedef struct	s_params
{
		char	type;
		char	cast;
		int		arg;
		int		flags;
		int		field_width;
		int		precision;
		
		char	*soc;
		char	*eoc;
}				t_params;

#endif
