/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:12:44 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 14:49:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAGON4_H
# define DRAGON4_H

# define LOG10_2 0.30102999566398119521373889472449

/*
** Sign, exp and mantissa are defined by extracting theses values
** from the given float or double. Log2 is the numbers of bits of
** the mantissa, prec is the precision wanted to print the float.
** Digit_exp is the power of ten of the first digit of the float.
** Digit is the current digit during the conversion.
*/

typedef struct			s_bitd
{
	unsigned long int	mantissa;
	unsigned int		exponent: 15;
	unsigned int		sign: 1;
}						t_bitd;

typedef struct			s_fltinf
{
	unsigned int		sign;
	int					exp;
	long unsigned int	mantissa;
	unsigned int		log2;
	int					prec;
	int					digit_exp;
	int					conv;
	unsigned int		digit;
}						t_fltinf;

int						float_conversion(char *buf, int *exp10, t_fltinf *info);
int						dragon4_f(long double d, int prec,
									char *buf, int *exp10);
int						dragon4_e(long double d, int prec,
									char *buf, int *exp10);

#endif
