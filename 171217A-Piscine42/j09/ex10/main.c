#include "libft/libft.h"
#include "ft_scrambler.h"

int main(int argc, char *argv[])
{
  if(argc != 5)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int ***a;
  int *b;
  int *******c;
  int ****d;

  a = malloc(sizeof(int***));
  *a = malloc(sizeof(int**));
  **a = malloc(sizeof(int*));

  b = malloc(sizeof(int*));

  c = malloc(sizeof(int*******));
  *c = malloc(sizeof(int******));
  **c = malloc(sizeof(int*****));
  ***c = malloc(sizeof(int****));
  ****c = malloc(sizeof(int***));
  *****c = malloc(sizeof(int**));
  ******c = malloc(sizeof(int*));

  d = malloc(sizeof(int****));
  *d = malloc(sizeof(int***));
  **d = malloc(sizeof(int**));
  ***d = malloc(sizeof(int*));


  ***a = ft_atoi(argv[1]);
  *b = ft_atoi(argv[2]);
  *******c = ft_atoi(argv[3]);
  ****d = ft_atoi(argv[4]);

  ft_scrambler(a, b, c, d);

  ft_putnbr_base(***a, "0123456789");
  ft_putchar('\n');
  ft_putnbr_base(*b, "0123456789");
  ft_putchar('\n');
  ft_putnbr_base(*******c, "0123456789");
  ft_putchar('\n');
  ft_putnbr_base(****d, "0123456789");
  ft_putchar('\n');

  return 0;
}
