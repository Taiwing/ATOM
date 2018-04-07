#ifndef UTILS_H
#define UTILS_H

#include <sys/types.h>			/*for the size_t type*/
#include <sys/stat.h>				/*to check if current file is directory or not*/
#include <stdlib.h>
#include <string.h>

int isdir(const char *file);
char **split_list(char *list, size_t l);
void sort_wordtab(char **tab);

#endif
