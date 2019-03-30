/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:06:08 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/23 20:17:01 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		strcmp_void(void *s1, void *s2)
{
	return (ft_strcmp((char *)s1, (char *)s2));
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int		main(int argc, char **argv)
{
	t_list	*lst;

	(void)argc;
	lst = NULL;
	while (*argv)
	{
		ft_lst_push_back(&lst, *argv, ft_strlen(*argv) + 1);
		++argv;
	}
	ft_lst_quicksort(lst, argc, strcmp_void);
	print_list(lst);
	return (0);
}
