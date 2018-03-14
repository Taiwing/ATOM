#include "ft_cat.h"

static void ft_display(char *file);
static void ft_get_input(char buffer[30000]);

void ft_cat(int fc, char *av[])
{
  int i;
  char buffer[30000];

  i = 0;

  while(!fc)
    ft_get_input(buffer);

  while(i < fc)
  {
    ft_display(av[i+1]);
    i++;
  }
}

static void ft_display(char *file)
{
  int fd;
  int bytes;
  char buffer[30000];

  bytes = 1;
  fd = open(file, O_RDONLY);

  while(bytes)
  {
    bytes = read(fd, buffer, 30000);
    write(1, buffer, bytes);
  }

  close(fd);
}

static void ft_get_input(char buffer[30000])
{
  int i;

  i = 0;

  while(1)
  {
    read(0, &buffer[i], 1);
    if(buffer[i] == '\n')
      break;
    i++;
  }

  write(1, buffer, i+1);
}
