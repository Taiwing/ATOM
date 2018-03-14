#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
  int n;
  scanf("%d", &n);

  int *prices = (int *)malloc(n * sizeof(int));
  int maxloss = 0;

  for(int i = 0; i < n; i++)
    scanf("%d", &prices[i]);

  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      maxloss = (prices[j] - prices[i]) < maxloss ? (prices[j] - prices[i]) : maxloss;

  printf("%d\n", maxloss);

  return 0;
}
