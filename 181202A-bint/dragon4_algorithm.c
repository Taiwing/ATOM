/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon4_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:58:00 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/12 17:04:42 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dragon4.h"
#include "bint.h"
#include "bint_mathconsts.h"
#include "log_and_ceil.h"

static int	scale_val(t_bint scale, t_bint scaled_val, t_fltinf *info)
{
	int		digit_exp;
	t_u32	tmp[BINT_SIZE];

	bintinit(tmp, 0);
	bintinit(scale, 0);
	bintinit(scaled_val, 0);
	bintset(info->mantissa, scaled_val);
	smult2_bint(scaled_val);
	if (info->exp > 0)
		shiftleft_bint(scaled_val, info->exp);
	pow2_bint(scale, info->exp > 0 ? 1 : 1 - info->exp);
	digit_exp = ft_ceil((((int)info->log2 + info->exp) * LOG10_2) - 0.69);
	if (info->conv == 'f')
		digit_exp = digit_exp <= -info->prec ? 1 - info->prec : digit_exp;
	if (digit_exp > 0)
		multpow10_bint(tmp, scale, digit_exp);
	else if (digit_exp < 0)
		multpow10_bint(tmp, scaled_val, -digit_exp);
	if (digit_exp)
		bintcpy(tmp, digit_exp > 0 ? scale : scaled_val);
	if (bintcmp(scaled_val, scale) >= 0)
		++digit_exp;
	else
		smult10_bint(scaled_val);
	return (digit_exp);
}

static char	*ftostr(t_bint scale, t_bint scaled_val,
		t_fltinf *info, char *cur_digit)
{
	t_u32	shift;
	t_u32	hi_block;
	int		cutoff_exp;

	cutoff_exp = info->digit_exp < 0 && info->conv == 'e' ?
		info->digit_exp - info->prec - 1 : -info->prec;
	hi_block = scale[scale[0] & NBR_LENGTH];
	if (hi_block < 8 || hi_block > 429496729)
	{
		shift = (32 + 27 - logbase2_32(hi_block)) % 32;
		shiftleft_bint(scale, shift);
		shiftleft_bint(scaled_val, shift);
	}
	while (1)
	{
		--info->digit_exp;
		info->digit = divmod_max9_bint(scaled_val, scale);
		if (!(scaled_val[0] & NBR_LENGTH) || (info->digit_exp == cutoff_exp))
			break ;
		*cur_digit++ = (char)(48 + info->digit);
		smult10_bint(scaled_val);
	}
	smult2_bint(scaled_val);
	return (cur_digit);
}

static char	*round_up9(char *cur_digit, char *buf, int *exp10)
{
	while (1)
	{
		if (cur_digit == buf)
		{
			*cur_digit++ = '1';
			++(*exp10);
			break ;
		}
		--cur_digit;
		if (*cur_digit != '9')
		{
			*cur_digit = *cur_digit + 1;
			++cur_digit;
			break ;
		}
	}
	return (cur_digit);
}

int			float_conversion(char *buf, int *exp10, t_fltinf *info)
{
	t_u32	scaled_val[BINT_SIZE];
	t_u32	scale[BINT_SIZE];
	char	*cur_digit;
	int		round_down;
	int		cmp;

	info->digit_exp = scale_val(scale, scaled_val, info);
	*exp10 = info->digit_exp - 1;
	cur_digit = ftostr(scale, scaled_val, info, buf);
	cmp = bintcmp(scaled_val, scale);
	round_down = cmp < 0;
	if (!cmp)
		round_down = (info->digit & 1) == 0;
	if (round_down)
		*cur_digit++ = (char)(48 + info->digit);
	else if (info->digit < 9)
		*cur_digit++ = (char)(48 + info->digit + 1);
	else
		cur_digit = round_up9(cur_digit, buf, exp10);
	return ((int)(cur_digit - buf));
}
