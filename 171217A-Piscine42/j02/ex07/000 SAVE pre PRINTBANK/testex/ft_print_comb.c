#include "ft_print_comb.h"

void ft_print_comb(void)
{
  int bank[10000][4]; /*is gonna store legal combinaisons*/
  int comb[4]; /*comb tested*/

  comb[0] = 0;
  comb[1] = 0;
  comb[2] = 0;
  comb[3] = 0;

  while(comb[0] < 10)
  {
    while(comb[1] < 10)
    {
      while(comb[2] < 10)
      {
        while(comb[3] < 10)
        {
          if(comb[0] != comb[1] && comb[0] != comb[2] && comb[0] != comb[3] && comb[1] != comb[2] && comb[1] != comb[3] && comb[2] != comb[3])
          {
            ft_printing_comb(ft_is_valid(comb, bank), comb);
          }
          comb[3]++;
        }
        comb[3] = 0;
        comb[2]++;
      }
      comb[2] = 0;
      comb[1]++;
    }
    comb[1] = 0;
    comb[0]++;
  }

  printf("\n");
}

int ft_is_valid(int comb[4], int bank[10000][4])
{
  int c[3]; /*counters*/

  c[0] = 0;
  while(1) /*infinite loop*/
  {
    if(bank[c[0]][0] == 0 && bank[c[0]][1] == 0 && bank[c[0]][2] == 0 && bank[c[0]][3] == 0) /*if we're on a NULL comb*/
    {
      bank[c[0]][0] = comb[0];
      bank[c[0]][1] = comb[1]; /*we save the legal unrecuring comb in the bank*/
      bank[c[0]][2] = comb[2];
      bank[c[0]][3] = comb[3];
      return 1; /*then we quit the loop*/
    }
    c[1] = 0;
    c[2] = 0;
    while(c[2] < 4)
    {
      if(bank[c[0]][c[2]] == comb[0] || bank[c[0]][c[2]] == comb[1]
         || bank[c[0]][c[2]] == comb[2] || bank[c[0]][c[2]] == comb[3]) /*if there is a match*/
        c[1]++;
      c[2]++;
    }
    if(c[1] == 4)
      return 0; /*we stop the loop if the comb is already in the comBank*/
    c[0]++;
  }
}

void ft_printing_comb(int valid, int comb[4])
{
  if(valid)
    printf("%d%d%d%d, ", comb[0], comb[1], comb[2], comb[3]); /*we print the comb*/
}
