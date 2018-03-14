#include "libft/libft.h"
#include "ft_eight_queens_puzzle.h"
#include <stdio.h>

int ft_eight_queens_puzzle(void)
{
  int queens[8] = {1};
  int nbr = 0;

  while(queens[0] < 9)
  {
    if(ft_is_pos_legal(queens))
    {
      nbr++;
      printf("%d%d%d%d%d%d%d%d\n", queens[0], queens[1], queens[2], queens[3], queens[4], queens[5], queens[6], queens[7]);
    }
    ft_queen_values(queens);
  }

  return nbr;
}

int ft_is_pos_legal(int queens[8])
{
  int i;
  int j;

  i = 0;

  while(i < 8)
  {
    j = 0;
    while(j < 8)
    {
      if((queens[i] == queens[j] && i != j)
         || (queens[i] - queens[j] == i - j && i != j)
         || (queens[i] - queens[j] == ((i - j) * -1) && i != j))
        return 0;
      j++;
    }
    i++;
  }

  return 1;
}

void ft_queen_values(int queens[8])
{
  int i;

  i = 7;

  while(i > -1)
  {
    if(queens[i] < 9)
    {
      queens[i]++;

      if(i != 0)
      {
        if(queens[i] == 9)
        {
          queens[i] = 1;
        }
        else
          break;
      }
    }

    i--;
  }
}
