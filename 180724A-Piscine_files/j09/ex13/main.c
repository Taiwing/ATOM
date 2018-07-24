#include "ft_compact.h"
#include "libft/libft.h"
#include <stdlib.h>

int main(void)
{
  int i;
  int length;
  char *tab[20];
  char *words[10];

  words[0] = ft_strdup("Et");
  words[1] = ft_strdup("mon");
  words[2] = ft_strdup("cul");
  words[3] = ft_strdup("c'est");
  words[4] = ft_strdup("du");
  words[5] = ft_strdup("poulet");
  words[6] = ft_strdup("ou");
  words[7] = ft_strdup("c'est");
  words[8] = ft_strdup("du");
  words[9] = ft_strdup("teflon ?");

  i = 0;

  while(i < 20)
  {
    if(i%2)
      tab[i] = 0;
    else
      tab[i] = words[i/2];
    i++;
  }

  ft_putstr("TABLE 1:\n");
  i = 0;
  while(i < 20)
  {
    if(tab[i])
    {
      ft_putstr(tab[i]);
      ft_putchar('\n');
    }
    else
      ft_putchar('\n');
    i++;
  }

  length = ft_compact(tab, 20);

  ft_putstr("\nlength: ");
  ft_putnbr_base(length, "0123456789");
  ft_putchar('\n');

  ft_putstr("\nTABLE 2:\n");
  ft_print_words_tables(tab);

  return 0;
}
