#include "include/main.h"
#include "include/optarg.h"
#include "include/tag.h"

int main(int argc, char *argv[])
{
	glob_optarg *glo = getoptarg(argc, argv);

	if(glo->flags & OPT_QUERY
		|| glo->flags & OPT_UNTAGGED
		|| glo->flags & OPT_TAGGED)
		tagqtu(glo);
	if(glo->flags & OPT_SET) 								 tags(glo);
	if(glo->flags & OPT_DELETE) 						 tagd(glo);
	if(glo->flags & OPT_GET) 								 tagg(glo);
	if(glo->flags & OPT_LIST) 							 tagl(glo);
	if(glo->flags & OPT_SAVE) 					 tag_save(glo);
	if(glo->flags & OPT_RESTORE) 			tag_restore(glo);

	return 0;
}
