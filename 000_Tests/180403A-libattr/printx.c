#include <stdio.h>
#include <stdlib.h>
#include <string.h>			/*for strlen*/
#include <sys/types.h>	/*for the size_t type*/
#include <attr/xattr.h>	/*for extended attributes functions*/

int main(int argc, char *argv[])
{
	if(argc != 2)
		return EXIT_FAILURE;

	char *list = (char *)malloc(1024), *p;
	size_t n = listxattr(argv[1], list, 1024);

	for(p = list; p < list+n; p += strlen(list))
		printf("%s\n", list);

	return 0;
}
