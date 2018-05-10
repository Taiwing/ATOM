#include "include/optarg.h"

static int opterrck(int c, int flags);
static void help(void);
static void gloerrck(glob_optarg *glo);
static void valerrck(char *val);
static void starf(glob_optarg *glo);
static int get_flag(char c);

struct option longopts[] = {
	{ "set",				1, 0, 's'},
	{ "delete",			1, 0, 'd'},
	{ "get",				0, 0, 'g'},
	{ "list",				0, 0, 'l'},
	{ "save",				0, 0, 'S'},
	{ "restore",		1, 0, 'R'},
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
		glo->flags |= get_flag(c);
		switch(c)
		{
			case 's':
			case 'd': glo->name = optarg;						break;
			case 'R': glo->backup = optarg;					break;
			case 'v': glo->value = optarg;					break;
			case 'q': glo->query = optarg;					break;
			case 'h': help(); exit(EXIT_SUCCESS);		break;
			case '?': exit(EXIT_FAILURE);						break;
		}
	}

	glo->files = argv + optind;
	glo->fc = argc - optind;
	gloerrck(glo);
	valerrck(glo->value);

	/*if no path is given, '*' is assumed*/
	if(glo->fc == 0 && !(glo->flags & OPT_RESTORE))
		starf(glo);

	return glo;
}

static int opterrck(int c, int flags)
{
	int err = 0, new_flag = get_flag(c), help = c == 'h' ? 1 : 0;

	if(!new_flag && !help)
		err = 1; /*invalid option*/
	else if(flags & new_flag)
		err = 2; /*double option*/
	else if((flags << (sizeof(int)*8-6)) && (new_flag << (sizeof(int)*8-6)))
		err = 3; /*more than one core option (s, d, g, l, S or R)*/
	else if(((flags & ~OPT_SET) << (sizeof(int)*8-6)) && (new_flag & OPT_VALUE))
		err = 4; /*value option used with delete, get or list*/
	else if(flags >> 10 && new_flag >> 10)
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
				fprintf(stderr, "%s: core options must be used separately (see the"
								" manual for more informations)\n", PROGNAME);
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
"         -l, --list              print a list of every tag present in\n"
"                                 given path and the number of files tagged\n"
"         -S, --save              dump every tag and their values in a\n"
"                                 backup file\n"
"         -R, --restore=backup    reset every tag present in the backup to\n"
"                                 their respective files\n"
"         -r, --recursive         execute tag functions recursively\n"
"         -a, --all               execute tag functions on directories too\n"
"         -q, --query=expr        search tags with logical operators and\n"
"                                 print the results or feeds them to 'set',\n"
"                                 'delete' or 'get'\n"
"         -t, --tagged            list every tagged file, and print the\n"
"                                 results or feed them to 'set', 'delete'\n"
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
	else if((glo->flags & OPT_RESTORE) && !f_exists(glo->backup))
		err = 2;
	else if(glo->name && strlen(glo->name) > XATTR_NAME_MAX)
		err = 3;
	else if(glo->value && strlen(glo->value) >= XATTR_SIZE_MAX-2)
		err = 4;

	if(err)
	{
		switch(err)
		{
			case 1: fprintf(stderr, "%s: 'value' option provided without 'set'\n",
										PROGNAME);
				break;
			case 2: fprintf(stderr, "%s: backup file '%s' not found\n",
										PROGNAME, glo->backup);
				break;
			case 3: fprintf(stderr, "%s: tag name too long\n", PROGNAME);
				break;
			case 4: fprintf(stderr, "%s: tag value too long\n", PROGNAME);
				break;
		}
		exit(EXIT_FAILURE);
	}
}

static void valerrck(char *val)
{
	int err = 0;

	if(val)
	{
		size_t l = strlen(val);
		char *p = NULL;
		switch(check_format(val, l))
		{
			case INT:
				err = int64ovf(val, l);
				break;
			case DATE:
				for(p = val; *p != '-' || p == val; p++);
				l = (size_t)(p-val);
				err = int64ovf(val, l);
				if(err == 0)
				{
					int64_t y = ato64i(val, l);
					int m = 0, d = 0;
					for(int i = 0; i < 2; i++)
						m += (p[i+1]-48)*(i == 0 ? 10 : 1);
					for(int i = 0; i < 2; i++)
						d += (p[i+4]-48)*(i == 0 ? 10 : 1);
					err = check_date(y, m, d);
				}
				break;
		}
	}

	if(err)
	{
		switch(err)
		{
			case 1: fprintf(stderr, "%s: value entered caused integer overflow\n",
										PROGNAME);
				break;
			case 2: fprintf(stderr, "%s: month in date value is not valid\n",
										PROGNAME);
				break;
			case 3: fprintf(stderr, "%s: day in date value is not valid\n",
										PROGNAME);
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

static void starf(glob_optarg *glo)
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

static int get_flag(char c)
{
	switch(c)
	{
		case 's': return OPT_SET;						break;
		case 'd': return OPT_DELETE;				break;
		case 'g': return OPT_GET;						break;
		case 'l': return OPT_LIST;					break;
		case 'S': return OPT_SAVE;					break;
		case 'R': return OPT_RESTORE;				break;
		case 'v': return OPT_VALUE;					break;
		case 'r': return OPT_RECURSIVE;			break;
		case 'a': return OPT_ALL;						break;
		case 'q': return OPT_QUERY;					break;
		case 't': return OPT_TAGGED; 				break;
		case 'u': return OPT_UNTAGGED; 			break;
		default: 	return 0; 								break;
	}
}
