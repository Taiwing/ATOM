#include "libft/libft.h"
#include "ft_takes_place.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
  }

  ft_takes_place(ft_atoi(argv[1]));

  return 0;
}
