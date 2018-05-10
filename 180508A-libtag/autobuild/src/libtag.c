#include "include/libtag.h"

tagout *tagmain(glob_optarg *glo)
{
	tagout *out = glo->flags & LCALL ? (tagout *)salloc(sizeof(tagout)) : NULL;

	if(glo->flags & OPT_QUERY
		|| glo->flags & OPT_UNTAGGED
		|| glo->flags & OPT_TAGGED)
		tagqtu(glo, out);
	if(glo->flags & OPT_SET) 										 tags(glo);
	if(glo->flags & OPT_DELETE) 								 tagd(glo);
	if(glo->flags & OPT_GET) 								 tagg(glo, out);
	if(glo->flags & OPT_LIST) 							 tagl(glo, out);
	if(glo->flags & OPT_SAVE) 								 tag_save(glo);
	if(glo->flags & OPT_RESTORE) 						tag_restore(glo);

	return out;
}
