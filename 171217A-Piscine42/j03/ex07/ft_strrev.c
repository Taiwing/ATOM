#include "libft/libft.h"
#include "ft_strrev.h"

char *ft_strrev(char *str)
{
  int i;
  int j;
  char c;

  i = 0;
  j = ft_strlen(str);

  while(i < j)
  {
    c = str[i];
    str[i] = str[j - 1];
    str[j - 1] = c;
    j--;
    i++;
  }

  return str;
}
