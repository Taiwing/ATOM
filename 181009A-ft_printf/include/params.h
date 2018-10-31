/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:53:30 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/31 23:24:58 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
#ifndef PARAMS_H
# define PARAMS_H

# define F_HASH					0x01
# define F_ZERO					0x02
# define F_MINUS				0x04
# define F_SPACE				0x08
# define F_PLUS					0x10

# define C_DEFAULT				0x01
# define C_UNSIGNED				0x02
# define C_SHORT				0x04
# define C_LONG					0x08
# define C_LONG_LONG			0x10

# define T_CHAR					0x20
# define T_SIZE_T				0x40
# define T_INTMAX_T				0x80
# define T_INT					0x100
# define T_WINT_T				0x200
# define T_WCHAR_T_P			0x400
# define T_CHAR_P				0x800

typedef unsigned int			t_uint;
typedef short int				t_shint;
typedef unsigned short int		t_ushint;
typedef long int				t_lint;
typedef unsigned long int		t_ulint;
typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;
typedef unsigned char			t_uchar;

typedef struct					s_params
{
		char					type;
		char					cast;
		int						arg;
		int						flags;
		t_lint					field_width;
		t_lint					precision;
		char					*soc;
		char					*eoc;
}								t_params;

#endif
