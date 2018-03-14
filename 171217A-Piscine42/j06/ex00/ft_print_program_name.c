#include "libft/libft.h"

int main(int argc, char **argv)
{
  int i;

  i = 0;

  while(argv[0][i])
  {
    ft_putchar(argv[0][i]);
    i++;
  }

  ft_putchar('\n');

  return 1;
}
