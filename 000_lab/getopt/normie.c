#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

int	main(int argc, char *argv[])
{
	int flags, opt;
	int nsecs, tfnd;

	nsecs = 0;
	tfnd = 0;
	flags = 0;
	printf("BEFORE optind = %d\n", optind);
	while ((opt = getopt(argc, argv, ":?nt:")) != -1) {
		switch (opt) {
			case 'n':
				flags = 1;
				break;
			case 't':
				nsecs = atoi(optarg);
				tfnd = 1;
				break;
			case ':':
			case 'b':
				printf("option '%c' has been called with ", opt);
				printf("%s\n", optarg ? optarg : "no argument");
				break;
			default:
				printf("tttttt... it is a bit shit what youre giving me boy: '%c' is not a valid option\n", opt);
		}
		printf("AFTER opt %c:\noptind = %d\noptarg = %s\n\n", opt, optind, optarg);
		printf("BEFORE optind = %d\n", optind);
	}
	if (argc == 1)
		printf("opt %c:\noptind = %d\noptarg = %s\n\n", opt, optind, optarg);

	printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", flags, tfnd, nsecs, optind);

	if (optind >= argc) {
		fprintf(stderr, "Expected argument after options\n");
		exit(EXIT_FAILURE);
	}

	printf("name argument = %s\n", argv[optind]);

	/* Other code omitted */

	return (0);
}
