/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:09:37 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/11 06:35:15 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H


typedef struct		s_opt
{
	const char		*name;
	int				has_arg;
	int				*flag;
	int				val;
}					t_opt;


enum e_order {DEFAULT = 0, LEAVE, PERMUTE, PASS};


typedef struct		s_optdata
{
	int				optind;
	int				optopt;
	int				opterr;
	char			*optarg;
	t_opt			*longopts;
	int				lopts_len;
	int				*longindex;
	char			*optstring;
	int				order;
	int				longonly;
	int				first_nonopt;
	int				last_nonopt;
	char			*nextchar;
}					t_optdata;

void				init_getopt(t_optdata *data, char *optstring,
								t_opt *longopts, int *longindex);
int					ft_getopt(int argc, char **argv, t_optdata *data);
int					ft_getopt_long(int argc, char **argv, t_optdata *data);
int					ft_getopt_long_only(int argc, char **argv, t_optdata *data);

#endif
