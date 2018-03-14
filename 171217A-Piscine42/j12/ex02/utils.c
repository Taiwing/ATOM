#include "utils.h"

int ft_get_startX(char *file, int c)
{
  int fd;
  int rd;
  int start;
  int length;
  char buffer[100];

  length = 0;

  fd = open(file, O_RDONLY);
  while((rd = read(fd, buffer, 100)))
    length += rd;
  start = (length - c) > 0 ? (length - c) : 0;
  close(fd);

  return start;
}

int ft_get_startL(char *file, int *l)
{
  int i[5];
  char buffer[100];
  int lineBytes[11];

  i[3] = 0;
  *l = 0;

  i[1] = open(file, O_RDONLY);
  while((i[2] = read(i[1], buffer, 100)))
  {
    (*l) += i[2];
    i[0] = 0;
    while(i[0] < i[2])
    {
      i[3] = buffer[i[0]] == '\n' ? i[3]+1 : i[3];
      if(buffer[i[0]] == '\n')
        ft_add_line_byte(i[3], i[0]+((*l)-i[2]), lineBytes);
      i[0]++;
    }
  }
  i[4] = i[3] <= 10 ? 0 : (lineBytes[0])+1;
  close(i[1]);

  return i[4];
}

void ft_add_line_byte(int lc, int byte, int lineBytes[10])
{
  int i = 0;

  if(lc <= 11)
    lineBytes[lc-1] = byte;
  else
  {
    while(i < 10)
    {
      lineBytes[i] = lineBytes[i+1];
      i++;
    }
    lineBytes[10] = byte;
  }
}

void ft_print_name(char *name, int c)
{
  int i;

  i = 0;

  if(!c)
    write(1, "==> ", 4);
  else
    write(1, "\n==> ", 5);

  while(name[i])
  {
    write(1, &name[i], 1);
    i++;
  }

  write(1, " <==\n", 5);
}
