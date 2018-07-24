#include "ft_bt.h"

void ft_bt(int queens[8])
{
  if(ft_reject(queens))
    return;
  if(ft_accept(queens))
    ft_print_solution(queens);

  int subQueens[8];
  ft_first(queens, subQueens);

  while(!ft_is_queens_null(subQueens))
  {
    ft_bt(subQueens);
    ft_next(subQueens);
  }
}

int ft_is_queens_null(int queens[8])
{
  int i;

  i = 0;

  while(i < 8)
  {
    if(queens[i] != 0)
      return 0;
    i++;
  }

  return 1;
}
