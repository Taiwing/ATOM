/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:31:38 by yforeau           #+#    #+#             */
/*   Updated: 2018/08/06 17:22:31 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		while (*ptr && !((*ptr > 96 && *ptr < 123) || (*ptr > 64 && *ptr < 91)
				|| (*ptr > 47 && *ptr < 58)))
			ptr++;
		*ptr = *ptr > 96 && *ptr < 123 ? *ptr - 32 : *ptr;
		ptr++;
		while (*ptr && ((*ptr > 96 && *ptr < 123) || (*ptr > 64 && *ptr < 91)
				|| (*ptr > 47 && *ptr < 58)))
		{
			*ptr = *ptr > 64 && *ptr < 91 ? *ptr + 32 : *ptr;
			ptr++;
		}
	}
	return (str);
}
