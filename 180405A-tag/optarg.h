#ifndef OPTARG_H
#define OPTARG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>			/*for access*/
#include <getopt.h>			/*for getopt_long*/
#include <errno.h>			/*to check errno in filerrck*/
#include "version.h"
#include "xattr_max.h"	/*limits of xattr values*/

#define CMD_LINE_OPTIONS "s:d:glv:raq:tuh"
#define CMD_LINE_SPEC1 "{-s name} [-v value] files..."
#define CMD_LINE_SPEC2 "{-d name} files..."
#define CMD_LINE_SPEC3 "{-g} files..."

#define OPT_SET 				0x01
#define OPT_DELETE 			0x02
#define OPT_GET 				0x04
#define OPT_LIST				0x08
#define OPT_VALUE 			0x10
#define OPT_RECURSIVE		0x20
#define OPT_ALL					0x40
#define OPT_QUERY				0x80
#define OPT_TAGGED			0x100
#define OPT_UNTAGGED		0x200

char *progname;

typedef struct glob_optarg
{
	int flags;
	char *name;
	char *value;
	char *query;
	int fc;
	char **files;
} glob_optarg;

glob_optarg *getoptarg(int argc, char *argv[]);
int filerrck(char *file, int tag_mode);

#endif
