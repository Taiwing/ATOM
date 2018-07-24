#include "libft/libft.h"
#include "ft_rot42.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  ft_putstr(ft_rot42(argv[1]));
  ft_putchar('\n');

  return 0;
}
