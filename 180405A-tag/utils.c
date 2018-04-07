#include "utils.h"

int isdir(const char *file)
{
	struct stat file_stat;
	stat(file, &file_stat);
	return S_ISDIR(file_stat.st_mode);
}

char **split_list(char *list, size_t l)
{
	int n = 0, j = 0;

	for(int i = 0; i < l; i++)
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
