#include "ft_display_file.h"

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    if(argc == 1)
      write(1, "File name missing.\n", 19);
    else if(argc > 2)
      write(1, "Too many arguments.\n", 20);
    return 1;
  }

  ft_display_file(argv[1]);

  return 0;
}
