#include "optarg.h"

static int opterrck(int c, int flags);
static void help(void);
static void gloerrck(glob_optarg *glo);

struct option longopts[] = {
	{ "set",				1, 0, 's'},
	{ "delete",			1, 0, 'd'},
	{ "get",				0, 0, 'g'},
	{ "value",			1, 0, 'v'},
	{ "recursive",	0, 0, 'r'},
	{ "all",				0, 0, 'a'},
	{ "query",			1, 0, 'q'},
	{ "help",				0, 0, 'h'},
	{NULL, 					0, 0,  0 }
};

glob_optarg *getoptarg(int argc, char *argv[])
{
	glob_optarg *glo = (glob_optarg *)malloc(sizeof(glob_optarg));

	int c, indopt;
	glo->flags = 0;
	glo->value = NULL;
	glo->query = NULL;

	while((c = getopt_long(argc, argv, CMD_LINE_OPTIONS, longopts,
				&indopt)) != -1 && !opterrck(c, glo->flags))
	{
		switch(c)
		{
			case 's': glo->flags |= OPT_SET; glo->name = optarg;
				break;
			case 'd': glo->flags |= OPT_DELETE; glo->name = optarg;
				break;
			case 'g': glo->flags |= OPT_GET;
				break;
			case 'v': glo->flags |= OPT_VALUE; glo->value = optarg;
				break;
			case 'r': glo->flags |= OPT_RECURSIVE;
				break;
			case 'a': glo->flags |= OPT_ALL;
				break;
			case 'q': glo->flags |= OPT_QUERY; glo->query = optarg;
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
	int new_flag = 0, err = 0, help = 0;

	switch(c)
	{
		case 's': new_flag = OPT_SET;
			break;
		case 'd': new_flag = OPT_DELETE;
			break;
		case 'g': new_flag = OPT_GET;
			break;
		case 'v': new_flag = OPT_VALUE;
			break;
		case 'r': new_flag = OPT_RECURSIVE;
			break;
		case 'a': new_flag = OPT_ALL;
			break;
		case 'q': new_flag = OPT_QUERY;
			break;
		case 'h': help = 1;
			break;
	}

	if(!new_flag && !help)
		err = 1; /*invalid option*/
	else if(flags & new_flag)
		err = 2; /*double option*/
	else if((flags << (sizeof(int)*8-3)) && (new_flag << (sizeof(int)*8-3)))
		err = 3; /*more than one core option (s, d or l)*/
	else if(((flags & ~OPT_SET) << (sizeof(int)*8-3)) && (new_flag & OPT_VALUE))
		err = 4; /*value option used with delete or get*/

	if(err)
	{
		switch(err)
		{
			case 1:
				fprintf(stderr, "%s: invalid options\n", progname);
				break;
			case 2:
				fprintf(stderr, "%s: '-%c' option can only be used once\n",
								progname, (char)c);
				break;
			case 3:
				fprintf(stderr, "%s: 'set', 'remove' and 'get' options"
								" must be used separately\n", progname);
				break;
			case 4:
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
"         -g, --get               get every tag and their value\n"
"                                 by files or folders\n"
"         -r, --recursive         execute tag functions recursively\n"
"         -a, --all               execute tag functions on directories too\n"
"         -q, --query=expr        search through tags\n"
"         -h, --help              this help text\n");
}

static void gloerrck(glob_optarg *glo)
{
	int err = 0;

	if((glo->flags & OPT_VALUE) && !(glo->flags & OPT_SET))
		err = 1;
	else if(glo->fc == 0)
		err = 2;
	else if(glo->name && strlen(glo->name) > XATTR_NAME_MAX)
		err = 3;
	else if(glo->value && strlen(glo->value) >= XATTR_SIZE_MAX)
		err = 4;

	if(err)
	{
		switch(err)
		{
			case 1: fprintf(stderr, "%s: 'value' option provided without 'set'\n",
										progname);
				break;
			case 2: fprintf(stderr, "%s: no target specified\n", progname);
				break;
			case 3: fprintf(stderr, "%s: attribute name too long\n", progname);
				break;
			case 4: fprintf(stderr, "%s: attribute value too long\n", progname);
				break;
		}
		exit(EXIT_FAILURE);
	}
}

int filerrck(char *file, int tag_mode)
{
	if(access(file, (tag_mode & (OPT_GET+OPT_QUERY)) ? R_OK : W_OK))
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
