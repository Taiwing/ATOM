#include "libft/libft.h"
#include "ft_any.h"

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    ft_putstr("ERROR: wrong number of arguments\n");
    return 1;
  }

  int i;
  int out;
  char **tab;

  i = 1;
  tab = (char **)malloc(argc * sizeof(char *));

  while(i < argc)
  {
    tab[i-1] = i == (argc-1) ? 0 : ft_strdup(argv[i]);
    i++;
  }

  i = 0;
  out = ft_any(tab, &ft_str_is_numeric);

  if(out)
    ft_putstr("There is at least one numeric string in the list.\n");
  else
    ft_putstr("There isn't any numeric string in the list.\n");

  return 0;
}
