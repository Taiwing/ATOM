#include "libft/libft.h"
#include "ft_strstr.h"

char *ft_strstr(char *str, char *to_find)
{
  int i;
  int j;
  int found;

  i = 0;

  while(1)
  {
    if(str[i] == to_find[0])
    {
      j = 0;
      while(to_find[j] != '\0')
      {
        found = str[i+j] == to_find[j] ? 1 : 0;
        if(!found)
          break;
        j++;
      }
    }

    if(str[i] == '\0' || found)
      return &str[i];

    i++;
  }
}
