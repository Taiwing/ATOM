#include "include/main.h"
#include "include/optarg.h"
#include "include/tag.h"

int main(int argc, char *argv[])
{
	glob_optarg *glo = getoptarg(argc, argv);

	if(glo->flags & OPT_QUERY)			tagq(glo);
	if(glo->flags & OPT_TAGGED)			tagt(glo);
	if(glo->flags & OPT_UNTAGGED)		tagu(glo);
	if(glo->flags & OPT_SET) 				tags(glo);
	if(glo->flags & OPT_DELETE) 		tagd(glo);
	if(glo->flags & OPT_GET) 				tagg(glo);
	if(glo->flags & OPT_LIST) 			tagl(glo);

	return 0;
}
