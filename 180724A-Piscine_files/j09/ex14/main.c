#include "ft_decrypt.h"
#include "libft/libft.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    ft_putstr("ERROR: wrong numer of arguments\n");
    return 1;
  }

  int i;
  t_perso **tab;

  i = 0;
  tab = ft_decrypt(argv[1]);

  while(tab[i])
  {
    ft_putstr("age: ");
    ft_putnbr_base(tab[i]->age, "0123456789");
    ft_putstr("\nname: ");
    ft_putstr(tab[i]->name);
    ft_putchar('\n');
    i++;
  }

  return 0;
}
