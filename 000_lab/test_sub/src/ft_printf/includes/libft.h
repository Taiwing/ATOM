/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:54:59 by yforeau           #+#    #+#             */
/*   Updated: 2018/12/20 00:15:15 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>

int						ft_atoi_forward(char **nptr);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);

#endif
