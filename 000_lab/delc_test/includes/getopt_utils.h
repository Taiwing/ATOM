/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 04:54:44 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/11 06:48:35 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_UTILS_H
# define GETOPT_UTILS_H

# include "stddef.h"

typedef	unsigned char	t_uchar;

char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);

#endif
