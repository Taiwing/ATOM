#include "include/optarg.h"

static int opterrck(int c, int flags);
static void help(void);
static void gloerrck(glob_optarg *glo);

struct option longopts[] = {
	{ "set",				1, 0, 's'},
	{ "delete",			1, 0, 'd'},
	{ "get",				0, 0, 'g'},
	{ "list",				0, 0, 'l'},
	{ "value",			1, 0, 'v'},
	{ "recursive",	0, 0, 'r'},
	{ "all",				0, 0, 'a'},
	{ "query",			1, 0, 'q'},
	{ "tagged",			0, 0, 't'},
	{ "untagged",		0, 0, 'u'},
	{ "help",				0, 0, 'h'},
	{NULL, 					0, 0,  0 }
};

glob_optarg *getoptarg(int argc, char *argv[])
{
	glob_optarg *glo = (glob_optarg *)salloc(sizeof(glob_optarg));

	int c, indopt;
	glo->flags = 0;
	glo->name = NULL;
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
			case 'l': glo->flags |= OPT_LIST;
				break;
			case 'v': glo->flags |= OPT_VALUE; glo->value = optarg;
				break;
			case 'r': glo->flags |= OPT_RECURSIVE;
				break;
			case 'a': glo->flags |= OPT_ALL;
				break;
			case 'q': glo->flags |= OPT_QUERY; glo->query = optarg;
				break;
			case 't': glo->flags |= OPT_TAGGED;
				break;
			case 'u': glo->flags |= OPT_UNTAGGED;
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
	if(glo->fc == 0) /*if no path is given, '*' is assumed*/
	{
		char *cwd = get_current_dir_name();
		int l = strlen(cwd);
		size_t file_size = 0;
		glo->files = NULL;
		get_files(cwd, &(glo->files),
							&(glo->fc), &file_size,
							glo->flags & OPT_RECURSIVE,
							glo->flags & OPT_ALL);
		glo->flags &= ~OPT_RECURSIVE; /*removes recursive option*/
		for(int i = 0; i < glo->fc; i++) /*removes the path*/
			glo->files[i] += l+1;
		free(cwd);
	}

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
		case 'l': new_flag = OPT_LIST;
			break;
		case 'v': new_flag = OPT_VALUE;
			break;
		case 'r': new_flag = OPT_RECURSIVE;
			break;
		case 'a': new_flag = OPT_ALL;
			break;
		case 'q': new_flag = OPT_QUERY;
			break;
		case 't': new_flag = OPT_TAGGED;
			break;
		case 'u': new_flag = OPT_UNTAGGED;
			break;
		case 'h': help = 1;
			break;
	}

	if(!new_flag && !help)
		err = 1; /*invalid option*/
	else if(flags & new_flag)
		err = 2; /*double option*/
	else if((flags << (sizeof(int)*8-4)) && (new_flag << (sizeof(int)*8-4)))
		err = 3; /*more than one core option (s, d, g or l)*/
	else if(((flags & ~OPT_SET) << (sizeof(int)*8-4)) && (new_flag & OPT_VALUE))
		err = 4; /*value option used with delete, get or list*/
	else if(flags >> 7 && new_flag >> 7)
		err = 5; /*query, tagged and/or untagged options used together*/

	if(err)
	{
		switch(err)
		{
			case 1:
				fprintf(stderr, "%s: invalid options\n", PROGNAME);
				break;
			case 2:
				fprintf(stderr, "%s: '-%c' option can only be used once\n",
								PROGNAME, (char)c);
				break;
			case 3:
				fprintf(stderr, "%s: 'set', 'remove', 'get' and 'list' options"
								" must be used separately\n", PROGNAME);
				break;
			case 4:
				fprintf(stderr, "%s: 'value' option can only be used with"
								" 'set' option\n", PROGNAME);
				break;
			case 5:
				fprintf(stderr, "%s: 'query', 'tagged' and 'untagged' options"
								" must be used separately\n", PROGNAME);
				break;
		}
		exit(EXIT_FAILURE);
	}

	return err;
}

static void help(void)
{
	printf("%s %s -- organize and search files by tags\n",
					PROGNAME, VERSION);
	printf("Usage: %s %s\n", PROGNAME, CMD_LINE_SPEC1);
	printf("       %s %s\n", PROGNAME, CMD_LINE_SPEC2);
	printf("       %s %s\n", PROGNAME, CMD_LINE_SPEC3);
	printf(
"Options: -s, --set=name          set named tag\n"
"         -v, --value=val         set the tag value to val\n"
"         -d, --delete=name       delete named tag\n"
"         -g, --get               get every tag and their value\n"
"                                 by files or folders\n"
"         -l, --list              prints a list of every tag present in\n"
"                                 given path and the number of files tagged\n"
"         -r, --recursive         execute tag functions recursively\n"
"         -a, --all               execute tag functions on directories too\n"
"         -q, --query=expr        search tags with logical operators and\n"
"                                 prints the results or feeds them to 'set',\n"
"                                 'delete' or 'get'\n"
"         -t, --tagged            lists every tagged file, and prints the\n"
"                                 results or feeds them to 'set', 'delete'\n"
"                                 or 'get' (this option is useless with\n"
"                                 'delete' and 'get', because they already\n"
"                                 target tagged files only)\n"
"         -u, --untagged          same as 'tagged' but with untagged files\n"
"         -h, --help              this help text\n");
}

static void gloerrck(glob_optarg *glo)
{
	int err = 0;

	if((glo->flags & OPT_VALUE) && !(glo->flags & OPT_SET))
		err = 1;
	else if(glo->name && strlen(glo->name) > XATTR_NAME_MAX)
		err = 2;
	else if(glo->value && strlen(glo->value) >= XATTR_SIZE_MAX)
		err = 3;

	if(err)
	{
		switch(err)
		{
			case 1: fprintf(stderr, "%s: 'value' option provided without 'set'\n",
										PROGNAME);
				break;
			case 2: fprintf(stderr, "%s: attribute name too long\n", PROGNAME);
				break;
			case 3: fprintf(stderr, "%s: attribute value too long\n", PROGNAME);
				break;
		}
		exit(EXIT_FAILURE);
	}
}

int filerrck(char *file, int tag_mode)
{
	if(access(file, (tag_mode & (OPT_SET+OPT_DELETE)) ? W_OK : R_OK))
	{
		switch(errno)
		{
			case EACCES: fprintf(stderr, "%s: %s: permission denied\n",
													PROGNAME, file);
				break;
			case ENOENT: fprintf(stderr, "%s: %s: file doesn't exist\n",
													PROGNAME, file);
				break;
			default: fprintf(stderr, "%s: %s: file couldn't be accessed\n",
													PROGNAME, file);
				break;
		}
		return 1;
	}
	return 0;
}
