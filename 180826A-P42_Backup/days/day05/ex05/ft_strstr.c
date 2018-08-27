/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 09:51:18 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/07 18:14:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		l;
	char	*needle;

	l = 0;
	while (to_find[l])
		l++;
	while (*str && *to_find)
	{
		needle = to_find;
		while (*str && *needle && *str == *needle)
		{
			str++;
			needle++;
		}
		if (*needle == '\0')
			return (str - l);
		else
			str -= needle - to_find;
		if (*str == '\0')
			return (0);
		str++;
	}
	return (l ? 0 : str);
}
