#ifndef FT_BT_PROCEDURES_H
#define FT_BT_PROCEDURES_H
#include "libft/libft.h"

int ft_reject(int queens[8]);
int ft_accept(int queens[8]);
void ft_first(int queens[8], int subQueens[8]);
void ft_next(int subQueens[8]);
void ft_print_solution(int queens[8]);

#endif
