#include "libft/libft.h"
#include "ft_concat_params.h"
#include "ft_split_whitespaces.h"

int main(int argc, char **argv)
{
  int i;
  char *concat;
  char buffer[200];
  char **split;

  i = 0;
  concat = ft_concat_params(argc, argv);
  ft_strcpy(buffer, concat);
  ft_strcat(buffer, "\n\n\n\n\n\n\0");
  split = ft_split_whitespaces(buffer);

  while(split[i])
  {
    ft_putstr(split[i]);
    ft_putchar('\n');
    i++;
  }

  return 0;
}
