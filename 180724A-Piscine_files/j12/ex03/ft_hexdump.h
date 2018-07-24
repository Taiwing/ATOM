#ifndef FT_HEXDUMP_H
#define FT_HEXDUMP_H
#include "ft_prints.h"

void ft_hexdump(int C, int fc, char **fv);
void ft_hexmem_ASCII(int fc, char **fv, int i[4], char buffer[16]);
void ft_hexmem(int fc, char **fv, int i[4], char buffer[16]);

#endif
