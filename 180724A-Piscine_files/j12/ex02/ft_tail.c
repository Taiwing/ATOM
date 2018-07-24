#include "ft_tail.h"

void ft_tail(int c, int fc, char **fv)
{
  if(c)
    ft_get_X_last_bytes(c, fc, fv);
  else
    ft_get_10_last_lines(fc, fv);
}

void ft_get_X_last_bytes(int c, int fc, char **fv)
{
  int i[4];
  char buffer[100];

  i[0] = 0;

  while(i[0] < fc)
  {
    if(fc > 1)
      ft_print_name(fv[i[0]], i[0]);
    i[3] = ft_get_startX(fv[i[0]], c);
    i[2] = open(fv[i[0]], O_RDONLY);
    i[1] = 0;
    while(i[1] < i[3]+c)
    {
      if(i[1] < i[3])
        read(i[2], buffer, 1);
      else
        write(1, buffer, read(i[2], buffer, 100));
      i[1] = i[1] < i[3] ? i[1]+1 : i[1]+i[3];
    }
    close(i[2]);
    i[0]++;
  }
}

void ft_get_10_last_lines(int fc, char **fv)
{
  int i[5];
  char buffer[100];

  i[0] = 0;

  while(i[0] < fc)
  {
    if(fc > 1)
      ft_print_name(fv[i[0]], i[0]);
    i[3] = ft_get_startL(fv[i[0]], &i[4]);
    i[2] = open(fv[i[0]], O_RDONLY);
    i[1] = 0;
    while(i[1] < i[4])
    {
      if(i[1] < i[3])
        read(i[2], buffer, 1);
      else
        write(1, buffer, read(i[2], buffer, 100));
      i[1] = i[1] < i[3] ? i[1]+1 : i[1]+100;
    }
    close(i[2]);
    i[0]++;
  }
}
