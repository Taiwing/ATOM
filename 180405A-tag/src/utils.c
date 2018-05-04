#include "include/utils.h"

void *salloc(size_t size)
{
	void *ptr = malloc(size);

	if(!ptr)
	{
		fprintf(stderr, "%s: out of memory\n", PROGNAME);
		exit(EXIT_FAILURE);
	}

	return ptr;
}

int isdir(const char *file)
{
	struct stat file_stat;
	stat(file, &file_stat);
	return S_ISDIR(file_stat.st_mode);
}

int f_exists(const char *file)
{
	struct stat file_stat;

	if(stat(file, &file_stat) == -1)
		return 0;
	else
		return 1;
}

char **split_list(char *list, size_t l)
{
	unsigned int n = 0, j = 0;

	for(unsigned int i = 0; i < l; i++)
		n += list[i] == '\0' ? 1 : 0;

	char **splitl = (char **)salloc((n+1) * sizeof(char *));

	for(char *p = list; p < list+l; p += strlen(p)+1, j++)
		strcpy((splitl[j] = (char *)salloc(strlen(p)+1)), p);
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
/*walloc is called each time an element is added to the array*/
/*it needs an element counter and a size_t to hold its size*/
/*it increments the element counter, and reallocates if needed*/
/*then it changes the size value if a new chunk is allocated*/
/*w means water (yes, it's a poetic function name)*/
void walloc(void ***buf, size_t *bufsize, int *l)
{
	*l = (*l) + 1;
	size_t newsize = (*l) * sizeof(void *);
	if((*bufsize) < newsize)
	{
		void **newbuf;
		newsize = (newsize + CHUNK_SIZE-1) & ~(CHUNK_SIZE-1);
		newbuf = realloc(*buf, newsize);
		if(!newbuf)
		{
			fprintf(stderr, "%s: out of memory\n", PROGNAME);
			exit(EXIT_FAILURE);
		}
		*buf = newbuf;
		*bufsize = newsize;
	}
}

/*erases n elements from start in any array*/
/*by shitfing its content to the left*/
/*if the array given is really a string, then the null-byte*/
/*must be included in the length parameter*/
void backspace(char *array, size_t elem_size, int length, int start, int n)
{
	char *p = (char *)salloc(elem_size);

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
	free(p);
}

/*only useful for qsort*/
int cmp(const void *p1, const void *p2)
{
	return strcmp(*(char **)p1, *(char **)p2);
}

void get_files(char *dir, char ***files, int *fc, size_t *size, int r, int a)
{
	DIR *dp = opendir(dir);
	struct dirent *ep;

	if(!dp) return; /*if opendir failed, stop function*/

	while((ep = readdir(dp)))
	{
		if(strcmp(ep->d_name, ".") != 0 && strcmp(ep->d_name, "..") != 0)
		{
			char *name = (char *)salloc(strlen(ep->d_name)+strlen(dir)+2);
			name = strcpy(name, dir);
			strcat(name, "/");
			strcat(name, ep->d_name);
			if(a || ep->d_type != DT_DIR)
			{
				walloc((void ***)files, size, fc);
				(*files)[*fc-1] = strcpy((char *)salloc(strlen(name)+1), name);
			}
			if(r && ep->d_type == DT_DIR)
				get_files(name, files, fc, size, r, a);
			free(name);
		}
	}

	closedir(dp);
	qsort(*files, *fc, sizeof(char *), cmp);
}

/*removes BS from str (Back Slashes of course)*/
void rmbs(char *str, size_t n)
{
	for(char *p = str; p < str+n; p++)
	{
		if(*p == '\\')
		{
			backspace(str, sizeof(char), n+1, p-str, 1);
			p++;
		}
	}
}

int is_quoted(char *str, size_t l)
{
	if((str[0] == '\'' || str[0] == '"') && str[0] == str[l-1])
		return 1;
	else
		return 0;
}
