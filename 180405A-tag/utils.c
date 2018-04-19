#include "utils.h"

int isdir(const char *file)
{
	struct stat file_stat;
	stat(file, &file_stat);
	return S_ISDIR(file_stat.st_mode);
}

char **split_list(char *list, size_t l)
{
	unsigned int n = 0, j = 0;

	for(unsigned int i = 0; i < l; i++)
		n += list[i] == '\0' ? 1 : 0;

	char **splitl = (char **)malloc((n+1) * sizeof(char *));

	for(char *p = list; p < list+l; p += strlen(p)+1, j++)
		strcpy((splitl[j] = (char *)malloc(strlen(p)+1)), p);
	splitl[j] = NULL;

	return splitl;
}

void sort_wordtab(char **tab)
{
  char *ptr;

	for(int i = 0; tab[i]; i++)
	{
		for(int j = i; tab[j]; j++)
			if(strcmp(tab[i], tab[j]) > 0)
			{
				ptr = tab[i];
				tab[i] = tab[j];
				tab[j] = ptr;
			}
	}
}

/*really cool function to make a resizable array of pointers*/
void high_water_alloc(void ***buf, size_t *bufsize, int *l)
{
	*l = (*l) + 1;
	size_t newsize = (*l) * sizeof(void *);
	if(*bufsize < newsize)
	{
		void **newbuf;
		newsize = (newsize + CHUNK_SIZE-1) & ~(CHUNK_SIZE-1);
		newbuf = realloc(*buf, newsize);
		*buf = newbuf;
		*bufsize = newsize;
	}
}

/*erases n elements from start in any array*/
/*by shitfing its content to the left*/
void backspace(char *array, size_t elem_size, int length, int start, int n)
{
	char *p = (char *)malloc(elem_size);

	n = n > start+1 ? start+1 : n;

	for(int i = start+1; i < length; i++)
	{
		/*copy the element to be moved*/
		for(unsigned int j = 0; j < elem_size; j++)
			p[j] = array[i * elem_size + j];

		/*paste the copied element n places before it*/
		for(unsigned int j = 0; j < elem_size; j++)
			array[(i-n) * elem_size + j] = p[j];
	}

	memset(array+((length-n)*elem_size), 0, n*elem_size);
}

/*only useful for qsort*/
int cmp(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}

void get_files(char *dir, char ***files, int *fc, int r, int a)
{
	DIR *dp = opendir(dir);
	struct dirent *ep;
	size_t size = (*fc) * sizeof(char *);

	while((ep = readdir(dp)))
	{
		if(strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
		{
			char *name = (char *)malloc(strlen(ep->d_name)+strlen(dir)+2);
			name = strcpy(name, dir);
			strcat(name, "/");
			strcat(name, ep->d_name);
			if(a || ep->d_type != DT_DIR)
			{
				high_water_alloc((void ***)files, &size, fc);
				(*files)[*fc-1] = strcpy((char *)malloc(strlen(name)), name);
			}
			if(r && ep->d_type == DT_DIR)
			get_files(name, files, fc, r, a);
			free(name);
		}
	}

	closedir(dp);
	qsort(*files, *fc, sizeof(char *), cmp);
}
