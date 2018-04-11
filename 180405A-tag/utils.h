#ifndef UTILS_H
#define UTILS_H

#include <sys/types.h>			/*for the size_t type*/
#include <sys/stat.h>				/*to check if current file is directory or not*/
#include <stdlib.h>
#include <string.h>

int isdir(const char *file);
char **split_list(char *list, size_t l);
void sort_wordtab(char **tab);
void high_water_alloc(void ***buf, size_t *bufsize, int *l);

/*stores 16 pointers on a 64 bits sytem and 32 on a 32 bits*/
#define CHUNK_SIZE 1024

#endif
