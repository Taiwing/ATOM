#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

int		main(int argc, char **argv)
{
	int c;
	int digit_optind = 0;

	while (1) {
		int this_option_optind = optind ? optind : 1;
		int option_index = 0;
		static struct option long_options[] =
		{
			{"add", 1, 0, 0},
			{"append", 0, 0, 0},
			{"delete", 1, 0, 0},
			{"verbose", 0, 0, 0},
			{"create", 1, 0, 'c'},
			{"file", 1, 0, 0},
			{0, 0, 0, 0}
		};

		c = getopt_long_only(argc, argv, "abc:d:012",
				long_options, &option_index);
		if (c == -1)
			break;

		switch (c) {
			case 0:
				printf("option %s", long_options[option_index].name);
				if (optarg)
					printf(" avec argument %s", optarg);
				printf("\n");
				break;

			case '0':
			case '1':
			case '2':
				if (digit_optind != 0 && digit_optind != this_option_optind)
					printf("chiffre dans deux arguments.\n");
				digit_optind = this_option_optind;
				printf("option %c\n", c);
				break;

			case 'a':
				printf("option a\n");
				break;

			case 'b':
				printf("option b\n");
				break;

			case 'c':
				printf("option c de valeur '%s'\n", optarg);
				break;

			case 'd':
				printf("option d de valeur '%s'\n", optarg);
				break;

			case '?':
				break;

			default:
				printf("?? caractère de code 0%o ??\n", c);
		}
	}

	if (optind < argc) {
		printf("Arguments ne constituant pas des options : ");
		while (optind < argc)
			printf("%s ", argv[optind++]);
		printf("\n");
	}

	exit(EXIT_SUCCESS);
}
