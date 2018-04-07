#include "tag.h"

/*glob var for access in rec_rmx function*/
char *name;
int opt_all;

static int rec_rmx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tagd(glob_optarg *glo)
{
	name = glo->name;
	opt_all = (glo->flags & OPT_ALL);

	for(int i = 0; i < glo->fc; i++)
		if(!filerrck(glo->files[i], OPT_DELETE))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_rmx, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				removexattr(glo->files[i], glo->name);
		}
}

static int rec_rmx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		removexattr(fpath, name);
	return 0;
}
