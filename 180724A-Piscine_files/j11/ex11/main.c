#include "libft/libft.h"
#include "ft_list.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  t_list *first;
  t_list *ptr;

  first = ft_list_push_params(argc, argv);

  ft_putstr("BASIC ORDER:\n");
  ft_list_foreach_if(first, &ft_putdata, "boobs", &ft_strcmp);

  ft_list_reverse(&first);

  ft_putstr("\nREVERSE:\n");
  ft_list_foreach_if(first, &ft_putdata, "boobs", &ft_strcmp);

  ft_putstr("\nSEARCH: ");
  ft_putdata(ft_list_find(first, "boobs", &ft_strcmp)->data);

  ft_list_clear(&first);

  return 0;
}
