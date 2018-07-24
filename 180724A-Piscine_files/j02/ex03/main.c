#include "ft_is_negative.h"

int main(int argc, char **argv)
{
  if(argc < 2) /*if there isn't a parameter in the command*/
  {
    printf("ERROR: wrong number of arguments\n");
    return EXIT_FAILURE;
  }
  else
    ft_is_negative(atoi(argv[1])); /*tests the first argument*/

  return EXIT_SUCCESS;
}
