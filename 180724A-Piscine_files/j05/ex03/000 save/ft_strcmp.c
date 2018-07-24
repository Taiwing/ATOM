#include "libft/libft.h"
#include "ft_strcmp.h"

int ft_strcmp(char *s1, char *s2)
{
  if(s1[0] == 0 || s2[0] == 0 || (s1[0] - s2[0]) != 0)
    return s1[0] - s2[0];
  else
    return s1[0] - s2[0] + ft_strcmp(&s1[1], &s2[1]);
}
