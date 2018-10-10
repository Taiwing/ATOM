/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:51:19 by yforeau           #+#    #+#             */
/*   Updated: 2018/10/09 01:51:20 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	return (ft_strcat(ft_strcpy(ft_strnew(size), s1), s2));
}
