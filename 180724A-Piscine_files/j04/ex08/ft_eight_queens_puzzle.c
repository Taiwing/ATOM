#include "libft/libft.h"
#include "ft_eight_queens_puzzle.h"
#include "ft_bt.h"
#include <stdio.h>

int ft_eight_queens_puzzle(void)
{
  int queens[8];
  int nbr;
  int i;

  nbr = 0;
  i = 0;
  while(i < 8)
    queens[i++] = 0;

  ft_bt(queens, &nbr);

  return nbr;
}
