/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:58:37 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/30 19:56:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "utils.h"

static void		move_arg(char **argv, int i_arr, int j_bit, int end)
{
	int		one;
	char	*cpy;

	one = (i_arr * 32) + j_bit;
	while (one < end)
	{
		cpy = argv[one];
		argv[one] = argv[one + 1];
		argv[++one] = cpy;
	}
}

static void		push_args_back(char **argv, unsigned int *historic, int end)
{
	int	i_arr;
	int	j_bit;

	while (end && (historic[end >> 5] & (1 << (end & MASK_32))))
		--end;
	i_arr = 0;
	while (end && i_arr > -1)
	{
		i_arr = end >> 5;
		j_bit = end & MASK_32;
		while (i_arr > -1 && !(historic[i_arr] & (1 << j_bit)))
		{
			i_arr = --j_bit < 0 ? i_arr - 1 : i_arr;
			j_bit = (j_bit + 32) & MASK_32;
		}
		if (i_arr > -1 && (historic[i_arr] & (1 << j_bit)))
		{
			move_arg(argv, i_arr, j_bit, end--);
			historic[i_arr] &= ~(1 << j_bit);
		}
	}
}

static int		not_an_option(char **argv, const char *optstring,
							t_varopts *vars, char *cur)
{
	if (*optstring == '-' || !ft_strncmp(optstring, ":-", 2))
	{
		if (!cur || !ft_strcmp(cur, "--"))
			push_args_back(argv, vars->historic, vars->optind - !cur);
		else if (cur == argv[vars->optind])
		{
			vars->historic[vars->optind >> 5] |= 1 << (vars->optind & MASK_32);
			++vars->optind;
			return (1);
		}
		else
			return (1);
	}
	return (-1);
}

static int		set_opt(char **argv, const char *optstring,
					t_varopts *vars, char **cur)
{
	char	*opt;

	if (!(opt = ft_strchr(optstring, **cur)) || *opt == '-' || *opt == ':')
	{
		vars->optopt = !**cur ? '-' : **cur;
		*cur = !**cur ? *cur - 1 : *cur;
		return ('?');
	}
	else if (opt[1] == ':')
	{
		if (opt[2] == ':')
			vars->optarg = *(*cur + 1) ? *cur + 1 : vars->optarg;
		else
		{
			vars->optarg = *(*cur + 1) ? *cur + 1 : argv[++vars->optind];
			if (!vars->optarg || !*vars->optarg)
			{
				if (!vars->optarg)
					--vars->optind;
				vars->optopt = **cur;
				return (*optstring == ':' ? ':' : '?');
			}
		}
	}
	return (*opt);
}

int				ft_getopt(char **argv, const char *optstring, t_varopts *vars)
{
	static char	*nextchar = NULL_CHAR;
	char		*cur;
	int			opt;

	vars->optarg = NULL;
	cur = *nextchar ? nextchar : argv[vars->optind];
	if (!cur || (!*nextchar && *cur != '-') || !ft_strcmp(cur, "--"))
		return (not_an_option(argv, optstring, vars, cur));
	cur += (!*nextchar);
	opt = set_opt(argv, optstring, vars, &cur);
	nextchar = vars->optarg == cur + 1 ? NULL_CHAR : cur + 1;
	vars->optind += cur ? (*nextchar == 0) : 0;
	return (opt);
}
