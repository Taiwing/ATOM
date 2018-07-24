#include "libft/libft.h"
#include "ft_max.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int max;
  int *tab;

  i = 0;
  tab = (int *)malloc((argc-1) * sizeof(int));

  while(i < argc-1)
  {
    tab[i] = ft_atoi(argv[i+1]);
    i++;
  }

  max = ft_max(tab, argc-1);

  ft_putstr("max: ");
  ft_putnbr_base(max, "0123456789");
  ft_putchar('\n');

  return 0;
}
