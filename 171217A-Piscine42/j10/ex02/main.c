#include "libft/libft.h"
#include "ft_map.h"

int ft_times2(int nbr);

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int *in;
  int *out;

  i = 1;
  in = (int *)malloc(sizeof(int) * (argc-1));

  while(i < argc)
  {
    in[i-1] = ft_atoi(argv[i]);
    i++;
  }

  out = ft_map(in, argc-1, &ft_times2);
  i = 0;

  while(i < argc-1)
  {
    ft_putnbr(out[i]);
    ft_putchar('\n');
    i++;
  }

  return 0;
}

int ft_times2(int nbr)
{
  return nbr*2;
}
