#include "ft_hexdump.h"
#include "ft_get_arguments.h"

int main(int argc, char *argv[])
{
  int C;
  int fc;
  char **fv;

  C = 0;
  fc = argc;
  fv = (char **)malloc(argc * sizeof(char *));

  if(!ft_get_arguments(&C, &fc, fv, argv))
  {
    ft_putstr("error: unable to open file\n");
    return 1;
  }

  ft_hexdump(C, fc, fv);

  return 0;
}
