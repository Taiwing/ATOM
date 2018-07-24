#ifndef FT_PRINT_COMBN_H
# define FT_PRINT_COMBN_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_alloc_2D_array.h"

void ft_print_combn(int n);

void ft_comb_values(int comb[], int n);
int ft_are_comb_numbers_different(int comb[], int n);
int ft_is_valid(int comb[], int **bank, int n);
int ft_is_comb_null(int **bank, int i, int n);
void ft_save_comb(int **bank, int comb[], int i, int n);
int ft_is_matching(int **bank, int comb[], int n, int c[3]);
void ft_print_bank(int **bank, int n);

#endif
