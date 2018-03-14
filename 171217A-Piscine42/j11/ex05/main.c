#include "libft/libft.h"
#include "ft_list.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  t_list *first;

  first = ft_list_push_params(argc, argv);

  ft_putstr(first->data);
  ft_putchar('\n');
  ft_putstr(first->next->data);
  ft_putchar('\n');
  ft_putnbr(ft_list_size(first));
  ft_putchar('\n');
  ft_putstr(ft_list_last(first)->data);
  ft_putchar('\n');

  return 0;
}
