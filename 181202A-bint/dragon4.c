/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:00:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 16:37:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dragon4.h"
#include "log_and_ceil.h"

int			dragon4_f(long double d, int prec, char *buf, int *exp10)
{
	t_bitd		*bd;
	t_fltinf	info;

	bd = (t_bitd *)&d;
	info.sign = bd->sign;
	info.exp = bd->exponent ? (int)bd->exponent - 16446 : -16447;
	info.mantissa = bd->mantissa;
	if (info.mantissa == 0)
	{
		*buf = '0';
		*exp10 = 0;
		return (1);
	}
	info.log2 = bd->exponent ? 64 : logbase2_64(bd->mantissa);
	info.prec = prec;
	info.digit_exp = 0;
	info.digit = 0;
	info.conv = 'f';
	return (float_conversion(buf, exp10, &info));
}

int			dragon4_e(long double d, int prec, char *buf, int *exp10)
{
	t_bitd		*bd;
	t_fltinf	info;

	bd = (t_bitd *)&d;
	info.sign = bd->sign;
	info.exp = bd->exponent ? (int)bd->exponent - 16446 : -16447;
	info.mantissa = bd->mantissa;
	if (info.mantissa == 0)
	{
		*buf = '0';
		*exp10 = 0;
		return (1);
	}
	info.log2 = bd->exponent ? 64 : logbase2_64(bd->mantissa);
	info.prec = prec;
	info.digit_exp = 0;
	info.digit = 0;
	info.conv = 'e';
	return (float_conversion(buf, exp10, &info));
}
