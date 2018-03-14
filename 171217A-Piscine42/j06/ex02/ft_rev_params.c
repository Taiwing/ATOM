#include "libft/libft.h"

int main(int argc, char **argv)
{
  int i;
  int j;

  i = argc - 1;

  while(i > 0)
  {
    j = 0;
    while(argv[i][j])
    {
      ft_putchar(argv[i][j]);
      j++;
    }
    ft_putchar('\n');
    i--;
  }

  return 1;
}
