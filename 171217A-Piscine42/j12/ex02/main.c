#include "ft_tail.h"
#include "ft_get_arguments.h"

int main(int argc, char **argv)
{
  int c;
  int fc;
  char **fv;

  c = 0;
  fc = argc;
  fv = (char **)malloc(argc * sizeof(char *));

  if(!ft_get_arguments(&c, &fc, fv, argv))
  {
    write(1, "error: wrong arguments\n", 23);
    return 1;
  }

  ft_tail(c, fc, fv);

  free(fv);

  return 0;
}
