#include "include/libtag.h"

int main(int argc, char *argv[])
{
	glob_optarg *glo = getoptarg(argc, argv);
	tagmain(glo);
	return 0;
}
