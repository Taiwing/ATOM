/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:56:21 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/23 16:56:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <errno.h>

void	ft_puterr(char *str);
void	print_arg_error(int argc, char **argv);
void	print_file_error(char *file);

#endif
