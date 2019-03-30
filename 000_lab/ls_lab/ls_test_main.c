/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_test_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:09:56 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/24 16:21:53 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	DIR *dir = opendir(argv[1]);
	struct dirent *rfile;

	(void)argc;
	while ((rfile = readdir(dir)))
	{
		printf("%s", rfile->d_name);
		printf(" %hhu\n", rfile->d_type);
	}
	return (0);
}
