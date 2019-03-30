/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 01:48:53 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/08 15:37:22 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char **base, char *str, size_t l)
{
	char	*new;

	new = ft_strcpy(ft_strnew(ft_strlen(*base) + l), *base);
	ft_strncat(new, str, l);
	ft_memdel((void **)base);
	return (new);
}
