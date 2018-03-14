#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_strncmp.h"

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }

  int ret;
  int ret2;

  ret = ft_strncmp(argv[1], argv[2], ft_atoi(argv[3]));
  ret2 = strncmp(argv[1], argv[2], ft_atoi(argv[3]));

  printf("ft_strncmp: %d\n", ret);
  printf("strncmp: %d\n", ret2);

  return EXIT_SUCCESS;
}
