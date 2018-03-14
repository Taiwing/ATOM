#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum upDown {UP, DOWN};
enum priceVar {P, V};

int main()
{
  int n;
  scanf("%d", &n);

  int **prices = (int **)malloc(n * sizeof(int *));
  for(int i = 0; i < n; i++)
    prices[i] = (int *)malloc(2 * sizeof(int));
  int maxloss = 0;
  int ml[2] = {-1}; /*maxloss values coordinates*/

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &prices[i][P]);
    prices[i][V] = i == 0 || prices[i-1][P] < prices[i][P] ? UP : DOWN;
  }


  for(int i = 0; i < n; i++)
  {
    if(prices[i][V] == UP && (ml[0] == -1 || prices[i][P] > prices[ml[0]][P]))
      for(int j = i+1; j < n; j++)
      {
        if((prices[j][P] - prices[i][P]) < maxloss)
        {
          maxloss = prices[j][P] - prices[i][P];
          ml[0] = i;
          ml[1] = j;
        }
      }
  }

  printf("%d\n", maxloss);

  return 0;
}
