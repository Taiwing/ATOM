/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:35:51 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/22 19:15:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_SORT_H
# define LS_SORT_H

# include "libft.h"

int		strcmp_file_names(void *f1, void *f2);
int		strcmp_file_names_rev(void *f1, void *f2);
void	sort_ascii(t_list *lst, t_lsconfig *cfg, int len);
int		cmp_file_sizes(void *f1, void *f2);
int		cmp_file_sizes_rev(void *f1, void *f2);
int		cmp_file_modif(void *f1, void *f2);
int		cmp_file_modif_rev(void *f1, void *f2);
int		cmp_file_access(void *f1, void *f2);
int		cmp_file_access_rev(void *f1, void *f2);
int		cmp_file_creation(void *f1, void *f2);
int		cmp_file_creation_rev(void *f1, void *f2);
void	sort_size_or_time(t_list *lst, t_lsconfig *cfg, int len);

#endif
