/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconfig.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:24:02 by yforeau           #+#    #+#             */
/*   Updated: 2019/03/07 17:35:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSCONFIG_H
# define LSCONFIG_H

# include "lsfdata.h" 		/*for the function pointers*/

/*
** t_lsprint is used to gather the field size of
** each printed data while the listing is done
*/
typedef struct		s_lsprint
{
	/*only for P_LONG*/
	long long int	total;
	long int		links_max;
	long long int	bytes_max;
	int				links_field;
	int				bytes_field;
	int				user_field;
	int				group_field;
	/*only for P_COLUMNS*/
	int				list_len;
	int				name_max;
	int				line_c;
	int				line_w;
	int				col_c;
	int				col_w;
	int				word_count;
	int				col_count;
	char			*buf;
	int				size;
	int				malloced;
}					t_lsprint;

/*
** 't_lsconfig' is the configuration structure of ls. It stores the ls config,
** and the function pointers that will be executed.
** Each 'mode' has 0 as default value, except for 'sortmode' and 'dirmode'.
*/
typedef struct		s_lsconfig
{
	int				dirmode;
	int				hide;
	int				reverse;
	int				sortmode;
	int				timemode;
	int				printmode;
	int				fieldmode;
	int				show_ext;
	int				show_acl;
	char			**args;
	int				args_len;
	t_lsprint		lsp;
	int				term_width;
	int				new_line;
	t_list			*ls_bank;
	t_list			*ls_errors;
	t_pbuf			buf;
	int				ret;
	void			(*get_arguments)(struct s_lsconfig *cfg);
	int				(*get_file_data)(char *path, t_lsfdata *lsf,
					struct s_lsconfig *cfg, struct dirent *fp);
	int				(*get_arg_data)(char *path, t_lsfdata *lsf,
					struct s_lsconfig *cfg);
	void			(*list_files)(struct s_lsconfig *cfg,
								t_lsddata *lsd, int *len);
	void			(*ls_first_dir)(struct s_lsconfig *cfg);
	void			(*ls_dir)(struct s_lsconfig *cfg,
					const char *path, const char *dirname);
	void			(*dir_recurse)(struct s_lsconfig *cfg, t_lsddata *lsd);
	void			(*sortf)(t_list *lst, struct s_lsconfig *cfg, int len);
	int				(*cmp)(void *, void *);		/*comp function for quicksort*/
	int				(*cmp2)(void *, void *);	/*if is sort time or size*/
	void			(*ls_print_file)(t_lsfdata *lsf, struct s_lsconfig *cfg);
	void			(*get_time)(char *time_str, t_lsfdata *lsf);
	void			(*get_xa)(char *path, t_lsfdata *lsf,
								struct s_lsconfig *cfg);
}					t_lsconfig;

/*These are the possible values of 'dirmode'*/
enum				e_dirmode {D_AS_FILE = 0, D_DEFAULT, D_RECURSIVE};

/*These are the possible values of 'sortmode' (the default is S_ASCII).*/
enum				e_sortmode {S_NO_SORT = 0, S_ASCII, S_SIZE, S_TIME};

/*These are the possible values of 'timemode'.*/
enum				e_timemode {T_MODIF = 0, T_ACCESS, T_CREATION};

/*These are the possible values of 'printmode'.*/
enum				e_printmode {P_COLUMNS = 0, P_ONE, P_LONG};

/*
** Each of the following values is stored in a bit of 'fieldmode'.
*/
# define F_GROUP	0x01	/*g option*/
# define F_OWNER	0x02	/*o option*/

void				init_lsconfig(t_lsconfig *cfg);

#endif
