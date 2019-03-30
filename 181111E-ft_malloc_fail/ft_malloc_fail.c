/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 22:00:20 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/11 23:18:16 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc_fail.h"
#define	PRINT	1
#define	FAIL_NB	50

static void	putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void		*ft_malloc_fail(size_t size)
{
	static int	set_null = 0;
	int			fail;	

	if (!set_null)
	{
		srand(time(NULL));
		set_null = 1;
	}
	fail = (rand() % FAIL_NB) + 1;
	if (fail == FAIL_NB)
	{
		if (PRINT)
			putstr("Sending failing malloc...\n");
		return (NULL);
	}
	else
		return (malloc(size));
}
