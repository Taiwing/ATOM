#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_convert_base.h"

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int i;
  char *nbr;

  i = 0;
  nbr = ft_convert_base(argv[1], argv[2], argv[3]);

  while(i < 8)
  {
    ft_putnbr_base((int)nbr[i], "0123456789");
    ft_putchar('.');
    i++;
  }
  ft_putchar('\n');

  ft_putstr(nbr);
  ft_putchar('\n');

  return EXIT_SUCCESS;
}
