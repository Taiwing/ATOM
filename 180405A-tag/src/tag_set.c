#include "include/tag.h"

/*glob var for access in rec_setx function*/
char *name, *value = NULL;
size_t vallen = 0;
int opt_all;

static int rec_setx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf);

void tags(glob_optarg *glo)
{
	name = (char *)salloc(strlen(glo->name)+LU+1);
	strcpy(name, USER); /*adding "user." prefix*/
	strcat(name, glo->name); /*and the name of the tag*/
	if(glo->value)
	{
		vallen = strlen(glo->value)+1;		/*one byte is added for the format byte*/
		value = (char *)salloc(vallen+1);		/*one byte is added for the null_byte*/
		value[0] = check_format(glo->value, vallen-1);	/*format byte is defined*/
		strcpy(value+1, glo->value);	/*value is copied*/
	}
	opt_all = (glo->flags & OPT_ALL);

	for(int i = 0; i < glo->fc; i++)
		if(!filerrck(glo->files[i], OPT_SET))
		{
			if(glo->flags & OPT_RECURSIVE && isdir(glo->files[i]))
				nftw(glo->files[i], rec_setx, 20, 0);
			else if(opt_all || !isdir(glo->files[i]))
				setxattr(glo->files[i], name, value, vallen, 0);
		}

	free(name);
}

static int rec_setx(const char *fpath, const struct stat *sb,
											int tflag, struct FTW *ftwbuf)
{
	if(S_ISREG(sb->st_mode) || opt_all)
		setxattr(fpath, name, value, vallen, 0);
	return 0;
}
