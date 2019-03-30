#include <strings.h>
#include <stdio.h>
#include "ft_getopt.h"
#include "utils.h"

char	optstring[] = "-a:b::cdefghij:";

int		main(int argc, char **argv)
{
	int				opt;
	int				debug;
	t_varopts		vars;
	unsigned int	hist[2048];

	(void)argc;
	bzero(hist, ((argc >> 5) + 1) * sizeof(unsigned int));
	init_varopts(&vars, 0, 0, hist);
	debug = 0;
	while ((opt = ft_getopt(argv, optstring, &vars)) > 0)
	{
		switch (opt)
		{
			case 'a':
			case 'j':
				printf("\noption '%c' called with '%s' in argument.\n", opt, vars.optarg);
				break;
			case 'b':
				if (vars.optarg)
					printf("\noption 'b' called with '%s' in argument.\n", vars.optarg);
				else
					printf("\noption 'b' called without any argument.\n");
				break;
			case 'd':
				if (debug)
					printf("\noption 'd' has been called: debugging will be turned off.\n");
				else
					printf("\noption 'd' has been called: debugging information will be printed.\n");
				debug = debug ? 0 : 1;
				break;
			case 'c':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
				printf("\noption '%c' has been called.\n", opt);
				break;
			case '?':
				if (vars.optopt == 'a' || vars.optopt == 'j')
					printf("\nerror: option '%c' needs an argument.\n", vars.optopt);
				else
					printf("\nerror: '%c' is not a valid option.\n", vars.optopt);
				break;
			case ':':
				printf("\nerror: option '%c' needs an argument.\n", vars.optopt);
				break;
			default:
				if (opt == 1 && (*optstring == '-' || !ft_strncmp(optstring, ":-", 2)))
					printf("\n'%s' is just a regular argument, move along, move along.\n", argv[vars.optind - 1]);
				else
					printf("\nExcuse me... WTFFFFFFFFFFF ?!?!!???\n");
				break;
		}
		if (debug)
		{
			printf("opt: %c, %d\n", opt, opt);
			printf("optind: %d\n", vars.optind);
			printf("optopt: %c\n", vars.optopt);
			printf("optarg: %s\n", vars.optarg);
		}
	}
	printf("argv:");
	while (*argv)
		printf(" %s", *argv++);
	printf("\n");
	return (0);
}
