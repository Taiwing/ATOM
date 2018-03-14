#include "libft/libft.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong arguments\n");
    exit(EXIT_FAILURE);
  }

  char *str = ft_strdup(argv[1]);
  ft_putstr(ft_strrev(str));
  ft_putchar('\n');

  int i = 5;
  char buffer[256];
  ft_itoa(i, buffer, 2);
  ft_putstr(buffer);
  ft_putchar('\n');
}
