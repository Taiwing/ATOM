#ifndef UTILS_H
#define UTILS_H

#include <sys/types.h>			/*for the size_t type*/
#include <sys/stat.h>				/*to check if current file is directory or not*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>					/*for opendir and readdir*/
#include "info.h"

/*malloc wrapper with pointer checker, and exit on failure*/
void *salloc(size_t size);

int isdir(const char *file);
int f_exists(const char *file);
char **split_list(char *list, size_t l);
void sort_wordtab(char **tab);
void walloc(void ***buf, size_t *bufsize, int *l);
void backspace(char *array, size_t elem_size, int length, int start, int n);
int cmp(const void *p1, const void *p2);
void get_files(char *dir, char ***files, int *fc, size_t *size, int r, int a);
void rmbs(char *str, size_t n);
int is_quoted(char *str, size_t l);

/*stores 16 pointers on a 64 bits sytem and 32 on a 32 bits*/
#define CHUNK_SIZE 1024

#endif
