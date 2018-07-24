#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 100;
  int f = 0;
  while(x > 0)
  {
    f += (x - 1);
    x--;
  }
  printf("f = %d\n", f);
  return EXIT_SUCCESS;
}
