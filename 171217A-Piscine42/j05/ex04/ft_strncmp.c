#include "libft/libft.h"
#include "ft_strncmp.h"

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
  if(n == 0)
    return 0;
  if(s1[0] == 0 || s2[0] == 0 || (s1[0] - s2[0]) != 0)
    return s1[0] - s2[0];
  else
    return s1[0] - s2[0] + ft_strncmp(&s1[1], &s2[1], n-1);
}
