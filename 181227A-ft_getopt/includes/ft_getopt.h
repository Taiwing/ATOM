/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:09:37 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/30 19:21:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

/*
** t_opt is the structure storing long options informations
** name is the option name (without '--').
** has_arg can have 3 values: 0, 1 and 2; which correspond
** respectively to NO_ARG, REQUIRED_ARG and OPTIONAL_ARG
** if flag not NULL, it is where val is stored (getopt returns
** 0 instead of val.
** val is the value identifying the option (it can be the character
** of the short option or another int, if it doesnt correspond to a
** short option for example).
*/

typedef struct		s_opt
{
	const char		*name;
	int				has_arg;
	int				*flag;
	int				val;
}					t_opt;

/*
** t_varopts stores different values needed for option parsing.
** optind is the index of the current option in argv.
** optopt is the character of an unknown short option.
** optarg is the argument of the current option.
** historic is only needed if the '-' flag set is set.
** it stores if an argv element contains at least a valid option
** or an argument to an option (1 is an option, 0 is a regular
** argument) in a 32bit unsigned int array (the array is declared
** by the user and must be large enough to store every argv element
** status [argc / 32 + (argc % 32 != 0) long]). The MASK_32 will be
** used to get argc % 32 and optind >> 5 to get argc / 32. It is
** used to move every non-option argument at the end of argv when
** it is done with option parsing.
** longopts is the t_opt array of long options.
** longindex is the index of the current long option in longopts.
*/

typedef struct		s_varopts
{
	int				optind;
	int				optopt;
	char			*optarg;
	unsigned int	*historic;
	t_opt			*longopts;
	int				*longindex;
}					t_varopts;

# define MASK_32	0x0000001f
# define NULL_CHAR	"\0"

void				init_varopts(t_varopts *vars, t_opt *longopts,
									int *longindex, unsigned int *historic);

int					ft_getopt(char **argv, const char *optstring,
								t_varopts *vars);

#endif
