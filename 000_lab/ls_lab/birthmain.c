/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   birthmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:39:40 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/26 19:39:49 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
#ifdef _DARWIN_FEATURE_64_BIT_INODE
	printf("YAAAAAAAAAAAAAAY !!!!!!!!!!\n");
#elif
	printf(":(\n");
#endif
	return (0);
}
