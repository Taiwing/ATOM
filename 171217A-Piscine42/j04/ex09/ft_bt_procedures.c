#include "ft_bt_procedures.h"

int ft_reject(int queens[8])
{
  int i;
  int j;

  i = 0;

  while(i < 8 && queens[i] != 0)
  {
    j = 0;
    while(j < 8 && queens[j] != 0)
    {
      if((queens[i] == queens[j] && i != j)
         || (queens[i] - queens[j] == i - j && i != j)
         || (queens[i] - queens[j] == ((i - j) * -1) && i != j))
        return 1;
      j++;
    }
    i++;
  }

  return 0;
}

int ft_accept(int queens[8])
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
         || (queens[i] - queens[j] == ((i - j) * -1) && i != j)
         || (queens[i] == 0)
         || (queens[j] == 0))
        return 0;
      j++;
    }
    i++;
  }

  return 1;
}

void ft_first(int queens[8], int subQueens[8])
{
  int i;
  int j;

  i = 0;
  j = 0;

  while(i < 8 && queens[i] != 0)
    i++;

  if(i < 8)
  {
    while(j < 8)
    {
      subQueens[j] = queens[j];
      j++;
    }
    subQueens[i]++;
  }

  while(j < 8)
  {
    subQueens[j] = 0;
    j++;
  }
}

void ft_next(int subQueens[8])
{
  int i;
  int j;

  i = 0;
  j = 0;

  while(i < 8 && subQueens[i] != 0)
    i++;

  if(subQueens[i - 1] < 8)
    subQueens[i - 1]++;
  else
  {
    while(j < 8)
    {
      subQueens[j] = 0;
      j++;
    }
  }
}

void ft_print_solution(int queens[8])
{
  int i;

  i = 0;

  while(i < 8)
  {
    ft_putchar(48 + queens[i]);
    i++;
  }

  ft_putchar('\n');
}
