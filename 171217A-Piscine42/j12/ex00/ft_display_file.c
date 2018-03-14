#include "ft_display_file.h"

void ft_display_file(char *file)
{
  int fd;
  int bytes;
  char buffer[100];

  bytes = 1;
  fd = open(file, O_RDONLY);

  while(bytes)
  {
    bytes = read(fd, buffer, 100);
    write(1, buffer, bytes);
  }

  close(fd);
}
