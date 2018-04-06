#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>			/*for getopt*/
#include <sys/types.h>	/*for the size_t type*/
#include <attr/xattr.h>	/*for extended attributes functions*/

#define CMD_LINE_OPTIONS "s:v:r:lh"	/*set remove list value help*/
#define CMD_LINE_SPEC1 "{-s name} [-v value] files..."
#define CMD_LINE_SPEC2 "{-r name} files..."
#define CMD_LINE_SPEC3 "{-l} [files...]"

#define OPT_SET 		0x01
#define OPT_REMOVE 	0x02
#define OPT_LIST 		0x04
#define OPT_VALUE 	0x08

typedef struct glob_optarg
{
	int flags;
	char *name;
	char *value;
	int fc;
	char **files;
} glob_optarg;

int opterrck(int c, int flags, char *progname);
void help(char *progname);
void gloerrck(glob_optarg *glo, char *progname);
void printx(char *path);

void print_bits(size_t const size, void const * const ptr);

int main(int argc, char *argv[])
{
	int c;
	glob_optarg glo;
	glo.flags = 0;

	while((c = getopt(argc, argv, CMD_LINE_OPTIONS)) != -1
				&& !opterrck(c, glo.flags, argv[0]))
	{
		switch(c)
		{
			case 's': glo.flags |= OPT_SET; glo.name = optarg;
			break;
			case 'r': glo.flags |= OPT_REMOVE; glo.name = optarg;
			break;
			case 'l': glo.flags |= OPT_LIST;
			break;
			case 'v': glo.flags |= OPT_VALUE; glo.value = optarg;
			break;
			case 'h': help(argv[0]); return EXIT_SUCCESS;
			break;
			case '?': return EXIT_FAILURE;
			break;
		}
	}

	glo.files = argv + optind;
	glo.fc = argc - optind;
	gloerrck(&glo, argv[0]);

	for(int i = 0; i < glo.fc; i++)
		printf("%s\n", glo.files[i]);

	print_bits(sizeof(int), &(glo.flags));
	/*printx(argv[1]);*/

	return 0;
}

int opterrck(int c, int flags, char *progname)
{
	int new_flag, err = 0;

	switch(c)
	{
		case 's': new_flag = OPT_SET;
			break;
		case 'r': new_flag = OPT_REMOVE;
			break;
		case 'l': new_flag = OPT_LIST;
			break;
		case 'v': new_flag = OPT_VALUE;
			break;
	}

	if(flags & new_flag)
		err = 1; /*double option*/
	else if((flags << (sizeof(int)*8-3)) && (new_flag << (sizeof(int)*8-3)))
		err = 2; /*more than one core option (s, r or l)*/
	else if((flags >> 1) && (new_flag & OPT_VALUE))
		err = 3; /*value option used with an onther option than set*/

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

void help(char *progname)
{
	printf("%s -- view, create and modify file tags\n", progname);
	printf("Usage: %s %s\n", progname, CMD_LINE_SPEC1);
	printf("       %s %s\n", progname, CMD_LINE_SPEC2);
	printf("       %s %s\n", progname, CMD_LINE_SPEC3);
	printf(
"Options: -s, --set=name          set named tag\n"
"         -v, --value=val         set the tag value to val\n"
"         -r, --remove=name       remove named tag\n"
"         -l, --list              list every tag in given files or folders,\n"
"                                 or in current directory by default\n"
"         -h, --help              this help text\n");
}

void gloerrck(glob_optarg *glo, char *progname)
{
	int err = 0;
	/*char *f;*/

	if((glo->flags & OPT_VALUE) && !(glo->flags & OPT_SET))
		err = 1; /*'value' option provided without 'set'*/
	else if(glo->fc == 0 && !(glo->flags & OPT_LIST))
		err = 2; /*no target specified*/
	/*TODO: LATER ADD FILE CHECKING, FOR NOW LET XATTR DEAL WITH IT*/
	/*else if((f = file_err(glo->files, glo->fc)))
		err = 3; target file or folder doesn't exist*/

	if(err)
	{
		switch(err)
		{
			case 1: printf("%s: 'value' option provided without 'set'\n",
										progname);
				break;
			case 2: printf("%s: no target specified\n", progname);
				break;
			case 3: printf("%s: target file or folder doesn't exist\n",
										progname);
				break;
		}
		exit(EXIT_FAILURE);
	}
}

void printx(char *path)
{
	char *list = (char *)malloc(1024), *p, *v = (char *)malloc(512);
	size_t n = listxattr(path, list, 1024), lv;

	printf("# file: %s\n", path);
	for(p = list; p < list+n; p += strlen(p)+1)
	{
		printf("%s", p);
		lv = getxattr(path, p, (void *)v, 512);
		if(lv)
			printf("=\"%s\"", v);
		puts("");
		memset((void *)v, 0, lv); /*resets the v buffer to 0*/
	}
}

void print_bits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for(i = size-1; i >= 0; i--)
	{
		for(j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}
