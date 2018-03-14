#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strstr.h"

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  char *str;

  str = ft_strstr(argv[1], "yoann");

  if(str[0] != '\0')
    printf("str: %s\n", str);
  else
    printf("no match\n");

  return EXIT_SUCCESS;
}
