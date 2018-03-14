#ifndef FT_PRINT_COMB2_H
# define FT_PRINT_COMB2_H
# include <stdio.h>
# include <stdlib.h>

void ft_print_comb2(void);
int ft_is_valid(int comb[2][2], int bk[5000][2][2]);
int ft_is_in_bank(int comb[2][2], int bk[5000][2][2]);
void ft_printing_comb(int valid, int comb[2][2]);

#endif
