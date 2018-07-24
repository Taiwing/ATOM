#include "libft/libft.h"
#include "ft_concat_params.h"

int main(int argc, char **argv)
{
  char *concat;

  concat = ft_concat_params(argc, argv);

  ft_putstr(concat);
  ft_putchar('\n');

  return 0;
}
