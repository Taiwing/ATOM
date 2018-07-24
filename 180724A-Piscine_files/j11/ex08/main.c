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

  i = 0;
  ptr = first;

  while(i < argc)
  {
    ft_putstr(ptr->data);
    ft_putchar('\n');
    ptr = ptr->next;
    i++;
  }

  ft_list_reverse(&first);

  ft_putstr("\n\nREVERSE:\n");

  i = 0;
  ptr = first;

  while(i < argc)
  {
    ft_putstr(ptr->data);
    ft_putchar('\n');
    ptr = ptr->next;
    i++;
  }

  ft_list_clear(&first);

  return 0;
}
