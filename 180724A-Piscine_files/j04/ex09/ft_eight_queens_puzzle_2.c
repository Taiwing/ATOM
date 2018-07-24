#include "libft/libft.h"
#include "ft_eight_queens_puzzle_2.h"
#include "ft_bt.h"

void ft_eight_queens_puzzle_2(void)
{
  int queens[8];
  int i;

  i = 0;
  while(i < 8)
  {
    queens[i] = 0;
    i++;
  }

  ft_bt(queens);
}
