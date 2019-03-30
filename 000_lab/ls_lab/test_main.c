/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 07:30:24 by yforeau           #+#    #+#             */
/*   Updated: 2019/01/17 12:15:24 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*modearg[3] = {
	"normie",
	"long",
	"longonly"
};

void	fnormie(int argc, char **argv)
{
	int			c[2];
	int			digit_optind = 0;
	t_optdata	data;
	char		**argv2 = (char **)malloc((argc + 1) * sizeof(char *));
	int			i = -1;
	while (++i <= argc)
		argv2[i] = argv[i];
	init_getopt(&data, "ab::c:d:0123456789", 0, 0);
	while (1)
	{
		int	this_option_optind[2];
		this_option_optind[0] = optind ? optind : 1;
		this_option_optind[1] = data.optind ? data.optind : 1;
		if (this_option_optind[0] != this_option_optind[1])
		{
			ft_dprintf(2, "error: different optind on this option\n");
			ft_dprintf(2, "orig = %d\nmine = %d\n",
					this_option_optind[0], this_option_optind[1]);
		}
		c[0] = getopt (argc, argv, "ab::c:d:0123456789");
		c[1] = ft_getopt(argc, argv2, &data);
		if (c[0] != c[1])
		{
			ft_dprintf(2, "error: different return values\n");
			ft_dprintf(2, "orig = %d\nmine = %d\n", c[0], c[1]);
		}
		if (optarg != data.optarg)
		{
			ft_dprintf(2, "error: different optarg values\n");
			ft_dprintf(2, "orig = %s\nmine = %s\n", optarg, data.optarg);
		}
		if (c[0] == -1 || c[1] == -1)
			break;
		switch (*c)
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (digit_optind != 0 && digit_optind != *this_option_optind)
					ft_printf("digits occur in two different argv-elements.\n");
				digit_optind = *this_option_optind;
				ft_printf ("option %c\n", *c);
				break;
			case 'a':
				ft_printf ("option a\n");
				break;
			case 'b':
				if (optarg)
					ft_printf ("option b with value '%s'\n", optarg);
				else
					ft_printf ("option b without any value\n");
				break;
			case 'c':
				ft_printf ("option c with value '%s'\n", optarg);
				break;
			case '?':
				break;
			default:
				ft_printf ("?? getopt returned character code 0%o ??\n", *c);
		}
	}
	if (optind < argc)
	{
		ft_printf ("orig: non-option ARGV-elements: ");
		while (optind < argc)
			ft_printf ("%s ", argv[optind++]);
		ft_printf ("\n");
	}
	if (data.optind < argc)
	{
		ft_printf ("mine: non-option ARGV-elements: ");
		while (data.optind < argc)
			ft_printf ("%s ", argv[data.optind++]);
		ft_printf ("\n");
	}
}

void	flong(int argc, char **argv)
{
	int			c[2];
	int			this_option_optind[2] = {0, 0};
	int			longindex[2];
	int			digit_optind = 0;
	t_optdata	data;
	char		**argv2 = (char **)malloc((argc + 1) * sizeof(char *));
	int			i = -1;
	struct option	long_options[] = {
		{"add", 1, 0, 0},
		{"append", 0, 0, 0},
		{"aaaaaaa", 0, 0, 0},
		{"delete", 2, 0, 0},
		{"verbose", 0, 0, 0},
		{"create", 1, 0, 'c'},
		{"file", 1, 0, 0},
		{0, 0, 0, 0}
	};
	t_opt			longopts[] = {
		{"add", 1, 0, 0},
		{"append", 0, 0, 0},
		{"aaaaaaa", 0, 0, 0},
		{"delete", 2, 0, 0},
		{"verbose", 0, 0, 0},
		{"create", 1, 0, 'c'},
		{"file", 1, 0, 0},
		{0, 0, 0, 0}
	};
	while (++i <= argc)
		argv2[i] = argv[i];
	init_getopt(&data, "abc:d::012", longopts, longindex + 1);
	while (1)
	{
		this_option_optind[0] = optind ? optind : 1;
		this_option_optind[1] = data.optind ? data.optind : 1;
		if (this_option_optind[0] != this_option_optind[1])
		{
			ft_dprintf(2, "error: different optind on this option\n");
			ft_dprintf(2, "orig = %d\nmine = %d\n",
					this_option_optind[0], this_option_optind[1]);
		}
		c[0] = getopt_long(argc, argv, "abc:d::012", long_options, longindex);
		c[1] = ft_getopt_long(argc, argv2, &data);
		if (c[0] != c[1])
		{
			ft_dprintf(2, "error: different return values\n");
			ft_dprintf(2, "orig = %d\nmine = %d\n", c[0], c[1]);
		}
		if (optarg != data.optarg)
		{
			ft_dprintf(2, "error: different optarg values\n");
			ft_dprintf(2, "orig = %s\nmine = %s\n", optarg, data.optarg);
		}
		if (c[0] == -1 || c[1] == -1)
			break;
		switch (*c)
		{
			case 0:
				ft_printf("option %s", long_options[longindex[0]].name);
				if (longindex[0] != longindex[1])
				{
					ft_dprintf(2, "error: different return values\n");
					ft_dprintf(2, "orig = %d\nmine = %d\n", c[0], c[1]);
				}
				if (optarg)
					ft_printf(" with argument %s", optarg);
				ft_printf("\n");
				break;
			case '0':
			case '1':
			case '2':
				if (digit_optind != 0 && digit_optind != *this_option_optind)
					ft_printf ("digits occur in two different argv-elements.\n");
				digit_optind = *this_option_optind;
				ft_printf ("option %c\n", *c);
				break;
			case 'a':
				ft_printf ("option a\n");
				break;
			case 'b':
				ft_printf ("option b\n");
				break;
			case 'c':
				ft_printf ("option c with value '%s'\n", optarg);
				break;
			case '?':
				break;
			default:
				ft_printf ("?? getopt returned character code 0%o ??\n", *c);
		}
	}
	if (optind < argc)
	{
		ft_printf ("orig: non-option ARGV-elements: ");
		while (optind < argc)
			ft_printf ("%s ", argv[optind++]);
		ft_printf ("\n");
	}
	if (data.optind < argc)
	{
		ft_printf ("mine: non-option ARGV-elements: ");
		while (data.optind < argc)
			ft_printf ("%s ", argv[data.optind++]);
		ft_printf ("\n");
	}
}

void	flongonly(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("lol2\n");
}

void	(*fp[3])(int argc, char **argv) = {
	fnormie,
	flong,
	flongonly
};

int		main(int argc, char **argv)
{
	int		mode;
	if (argc < 2)
	{
		ft_dprintf(2,
				"%s: missing_argument 'normie' 'long' or 'longonly'\n", *argv);
		return (1);
	}
	mode = -1;
	while (++mode < 3)
	{
		if (!strcmp(argv[1], modearg[mode]))
			break;
	}
	if (mode == 3)
	{
		ft_dprintf(2,
				"%s: '%s' argument is invalid\n", *argv, argv[1]);
		return (1);
	}
	--argc;
	++argv;
	fp[mode](argc, argv);
	return (0);
}
