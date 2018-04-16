#include "main.h"
#include "optarg.h"
#include "tag.h"

int main(int argc, char *argv[])
{
	progname = argv[0];
	glob_optarg *glo = getoptarg(argc, argv);

	if(glo->flags & OPT_QUERY)		tagq(glo);
	if(glo->flags & OPT_SET) 			tags(glo);
	if(glo->flags & OPT_DELETE) 	tagd(glo);
	if(glo->flags & OPT_GET) 			tagg(glo);

	return 0;
}
