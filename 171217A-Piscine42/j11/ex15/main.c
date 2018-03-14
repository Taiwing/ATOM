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
  t_list *first1;
  t_list *first2;
  t_list *ptr;

  first1 = ft_list_push_params(argc, argv);

  ft_putstr("BASIC ORDER:\n");
  ft_list_foreach(first1, &ft_putdata);

  first2 = ft_list_push_params(argc, argv);
  ft_list_reverse_fun(first2);

  ft_putstr("\nREVERSE:\n");
  ft_list_foreach(first2, &ft_putdata);

  ft_list_merge(&first1, first2);

  ft_putstr("\nBOTH IN ONE:\n");
  ft_list_foreach(first1, &ft_putdata);

  ft_list_sort(&first1, &ft_strcmp);

  ft_putstr("\nSORTED:\n");
  ft_list_foreach(first1, &ft_putdata);

  ft_list_clear(&first1);

  return 0;
}
