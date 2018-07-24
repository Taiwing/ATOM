#include "libft/libft.h"
#include "ft_is_sort.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int *in;

  i = 1;
  in = (int *)malloc(sizeof(int) * (argc-1));

  while(i < argc)
  {
    in[i-1] = ft_atoi(argv[i]);
    i++;
  }

  if(ft_is_sort(in, argc-1, &ft_nbrcmp))
    ft_putstr("The list is sorted.\n");
  else
    ft_putstr("The list isn't sorted.\n");

  return 0;
}
