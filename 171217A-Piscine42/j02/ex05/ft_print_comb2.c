#include "ft_print_comb2.h"

void ft_print_comb2(void)
{
  int bk[5000][2][2];
  int comb[2][2];

  comb[0][0] = 0;

  while(comb[0][0] < 10)
  {
    comb[0][1] = 0;
    while(comb[0][1] < 10)
    {
      comb[1][0] = 0;
      while(comb[1][0] < 10)
      {
        comb[1][1] = 0;
        while(comb[1][1] < 10)
        {
          ft_printing_comb(ft_is_valid(comb, bk), comb);
          comb[1][1]++;
        }
        comb[1][0]++;
      }
      comb[0][1]++;
    }
    comb[0][0]++;
  }
}

int ft_is_valid(int comb[2][2], int bk[5000][2][2])
{
  if(!(comb[0][0] == comb[1][0] && comb[0][1] == comb[1][1])) /*if the two numbers are different*/
  {
    if(!ft_is_in_bank(comb, bk)) /*and the comb isn't already in the bank*/
      return 1;
  }

  return 0;
}

int ft_is_in_bank(int comb[2][2], int bk[5000][2][2])
{
  int c;

  c = 0;

  while(1)
  {
    if(bk[c][0][0] == 0 && bk[c][0][1] == 0
       && bk[c][1][0] == 0 && bk[c][1][1] == 0)
    {
      bk[c][0][0] = comb[0][0];
      bk[c][0][1] = comb[0][1]; /*we save the legal comb in the bank*/
      bk[c][1][0] = comb[1][0];
      bk[c][1][1] = comb[1][1];
      return 0;
    }
    if((bk[c][0][0] == comb[0][0] && bk[c][0][1] == comb[0][1]
       && bk[c][1][0] == comb[1][0] && bk[c][1][1] == comb[1][1])
       || (bk[c][0][0] == comb[1][0] && bk[c][0][1] == comb[1][1]
       && bk[c][1][0] == comb[0][0] && bk[c][1][1] == comb[0][1]))
      return 1;
    c++;
  }
}

void ft_printing_comb(int valid, int comb[2][2])
{
  if(valid)
  {
    printf("%d%d %d%d", comb[0][0], comb[0][1], comb[1][0], comb[1][1]); /*we print the comb*/
    if(!(comb[0][0] == 9 && comb[0][1] == 8
       && comb[1][0] == 9 && comb[1][1] == 9))
      printf(", ");
    else
      printf("\n");
  }
}
