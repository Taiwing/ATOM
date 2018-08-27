/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:18:43 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 17:18:44 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_ARGUMENTS_H
# define FT_GET_ARGUMENTS_H
# include "ft_utils.h"

void	ft_get_arguments(int *c, int *fc, char **fv, char **av);
int		ft_is_c_option(char *str);
int		ft_does_file_exist(char *file);

#endif
