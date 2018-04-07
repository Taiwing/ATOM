#include "optarg.h"

static int opterrck(int c, int flags);
static void help(void);
static void gloerrck(glob_optarg *glo);

glob_optarg *getoptarg(int argc, char *argv[])
{
	glob_optarg *glo = (glob_optarg *)malloc(sizeof(glob_optarg));

	int c;
	glo->flags = 0;
	glo->value = NULL;

	while((c = getopt(argc, argv, CMD_LINE_OPTIONS)) != -1
				&& !opterrck(c, glo->flags))
	{
		switch(c)
		{
			case 's': glo->flags |= OPT_SET; glo->name = optarg;
				break;
			case 'd': glo->flags |= OPT_DELETE; glo->name = optarg;
				break;
			case 'l': glo->flags |= OPT_LIST;
				break;
			case 'v': glo->flags |= OPT_VALUE; glo->value = optarg;
				break;
			case 'r': glo->flags |= OPT_RECURSIVE;
				break;
			case 'a': glo->flags |= OPT_ALL;
				break;
			case 'h': help(); exit(EXIT_SUCCESS);
				break;
			case '?': exit(EXIT_FAILURE);
				break;
		}
	}

	glo->files = argv + optind;
	glo->fc = argc - optind;
	gloerrck(glo);

	return glo;
}

static int opterrck(int c, int flags)
{
	int new_flag, err = 0;

	switch(c)
	{
		case 's': new_flag = OPT_SET;
			break;
		case 'd': new_flag = OPT_DELETE;
			break;
		case 'l': new_flag = OPT_LIST;
			break;
		case 'v': new_flag = OPT_VALUE;
			break;
		case 'r': new_flag = OPT_RECURSIVE;
			break;
		case 'a': new_flag = OPT_ALL;
			break;
	}

	if(flags & new_flag)
		err = 1; /*double option*/
	else if((flags << (sizeof(int)*8-3)) && (new_flag << (sizeof(int)*8-3)))
		err = 2; /*more than one core option (s, d or l)*/
	else if(((flags & ~OPT_SET) << (sizeof(int)*8-3)) && (new_flag & OPT_VALUE))
		err = 3; /*value option used with delete or list*/

	if(err)
	{
		switch(err)
		{
			case 1:
				fprintf(stderr, "%s: '-%c' option can only be used once\n",
								progname, (char)c);
				break;
			case 2:
				fprintf(stderr, "%s: 'set', 'remove' and 'list' options"
								" must be used separately\n", progname);
				break;
			case 3:
				fprintf(stderr, "%s: 'value' option can only be used with"
								" 'set' option\n", progname);
				break;
		}
		exit(EXIT_FAILURE);
	}

	return err;
}

static void help(void)
{
	printf("%s %s -- organize and search files by tags\n",
					progname, TAG_VERSION);
	printf("Usage: %s %s\n", progname, CMD_LINE_SPEC1);
	printf("       %s %s\n", progname, CMD_LINE_SPEC2);
	printf("       %s %s\n", progname, CMD_LINE_SPEC3);
	printf(
"Options: -s, --set=name          set named tag\n"
"         -v, --value=val         set the tag value to val\n"
"         -d, --delete=name       delete named tag\n"
"         -l, --list              list every tag in given files or folders\n"
"         -r, --recursive         execute tag functions recursively\n"
"         -a, --all               execute tag functions on directories too\n"
"         -h, --help              this help text\n");
}

static void gloerrck(glob_optarg *glo)
{
	int err = 0;

	if((glo->flags & OPT_VALUE) && !(glo->flags & OPT_SET))
		err = 1; /*'value' option provided without 'set'*/
	else if(glo->fc == 0)
		err = 2; /*no target specified*/

	if(err)
	{
		switch(err)
		{
			case 1: fprintf(stderr, "%s: 'value' option provided without 'set'\n",
										progname);
				break;
			case 2: fprintf(stderr, "%s: no target specified\n", progname);
				break;
		}
		exit(EXIT_FAILURE);
	}
}

int filerrck(char *file, int tag_mode)
{
	if(access(file, (tag_mode & OPT_LIST) ? R_OK : W_OK))
	{
		switch(errno)
		{
			case EACCES: fprintf(stderr, "%s: %s: permission denied\n",
													progname, file);
				break;
			case ENOENT: fprintf(stderr, "%s: %s: file doesn't exist\n",
													progname, file);
				break;
			default: fprintf(stderr, "%s: %s: file couldn't be accessed\n",
													progname, file);
				break;
		}
		return 1;
	}
	return 0;
}
