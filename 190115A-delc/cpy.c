/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:01:14 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/15 22:01:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void function(void);
int a = 1;
int fucktion(int a)
{
	printf("/*this looks like a comment*/\n\"\"this too: /**/\n");
	return (a * 2);
}
int	main(void)
{
	a = -1;
	 fucktion(a);
	fucktion(a);
	return (0);
}
