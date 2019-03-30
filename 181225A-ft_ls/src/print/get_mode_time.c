/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:39:00 by yforeau           #+#    #+#             */
/*   Updated: 2019/02/14 08:52:38 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsfdata.h"

void	get_mode_str(char *mode_str, unsigned long int mode, int xattr_acl)
{
	int		i;
	char	type[14] = " pc d b - l s";

	if (!xattr_acl)
		mode_str[10] = ' ';
	else
		mode_str[10] = xattr_acl == 1 ? '+' : '@';
	mode_str[11] = '\0';
	i = -1;
	while (++i < 3)
	{
		mode_str[9 - (i * 3)] = mode & 1 ? 'x' : '-';
		mode_str[8 - (i * 3)] = mode & 2 ? 'w' : '-';
		mode_str[7 - (i * 3)] = mode & 4 ? 'r' : '-';
		mode >>= 3;
	}
	mode_str[3] = mode & 4 ? 'S' + ((mode_str[3] == 'x') * 32) : mode_str[3];
	mode_str[6] = mode & 2 ? 'S' + ((mode_str[6] == 'x') * 32) : mode_str[6];
	mode_str[9] = mode & 1 ? 'T' + ((mode_str[9] == 'x') * 32) : mode_str[9];
	mode >>= 3;
	mode_str[0] = type[mode & 15];
}

void	get_time_modif(char *time_str, t_lsfdata *lsf)
{
	long int	now;
	long int	diff;
	char		*buf;

	now = time(NULL);
	buf = ctime(&lsf->stats.st_mtime);
	diff = now - lsf->stats.st_mtime;
	if (diff > 15552000 || diff < 0)
	{
		ft_strncpy(time_str, buf + 4, 7);
		time_str[7] = ' ';
		ft_strncpy(time_str + 8, buf + 20, 4);
		time_str[12] = '\0';
	}
	else
	{
		ft_strncpy(time_str, buf + 4, 12);
		time_str[12] = '\0';
	}
}

void	get_time_access(char *time_str, t_lsfdata *lsf)
{
	long int	now;
	long int	diff;
	char		*buf;

	now = time(NULL);
	buf = ctime(&lsf->stats.st_atime);
	diff = now - lsf->stats.st_atime;
	if (diff > 15552000 || diff < 0)
	{
		ft_strncpy(time_str, buf + 4, 7);
		time_str[7] = ' ';
		ft_strncpy(time_str + 8, buf + 20, 4);
		time_str[12] = '\0';
	}
	else
	{
		ft_strncpy(time_str, buf + 4, 12);
		time_str[12] = '\0';
	}
}

void	get_time_creation(char *time_str, t_lsfdata *lsf)
{
	long int	now;
	long int	diff;
	char		*buf;

	now = time(NULL);
	buf = ctime(&lsf->stats.st_birthtime);
	diff = now - lsf->stats.st_birthtime;
	if (diff > 15552000 || diff < 0)
	{
		ft_strncpy(time_str, buf + 4, 7);
		time_str[7] = ' ';
		ft_strncpy(time_str + 8, buf + 20, 4);
		time_str[12] = '\0';
	}
	else
	{
		ft_strncpy(time_str, buf + 4, 12);
		time_str[12] = '\0';
	}
}

