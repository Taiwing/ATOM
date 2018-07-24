#include "libft/libft.h"
#include "ft_foreach.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int *tab;

  i = 1;
  tab = (int *)malloc(sizeof(int) * (argc-1));

  while(i < argc)
  {
    tab[i-1] = ft_atoi(argv[i]);
    i++;
  }

  ft_foreach(tab, argc-1, &ft_putnbr);
  ft_putchar('\n');

  return 0;
}
