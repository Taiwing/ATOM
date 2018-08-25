#include "ft_hexdump.h"

void ft_hexdump(int C, int fc, char **fv)
{
  int i[4];
  char buffer[16];

  i[0] = 0;
  i[2] = 16;
  i[3] = 0;
  if(C)
    ft_hexmem_ASCII(fc, fv, i, buffer);
  else
    ft_hexmem(fc, fv, i, buffer);
  ft_putchar('\n');
}

void ft_hexmem_ASCII(int fc, char **fv, int i[4], char buffer[16])
{
  while(i[0] < fc)
  {
    i[1] = open(fv[i[0]], O_RDONLY);
    while(i[2] == 16)
    {
      i[2] = read(i[1], buffer, 16);
      while(i[2] < 16 && i[0] != (fc-1))
      {
        i[0]++;
        close(i[1]);
        i[1] = open(fv[i[0]], O_RDONLY);
        i[2] += read(i[1], &buffer[i[2]], 16-i[2]);
      }
      ft_print_byte(i[3], 1);
      ft_print_hex(buffer, i[2]);
      ft_print_char(buffer, i[2]);
      i[3] += i[2];
    }
    close(i[1]);
    i[0]++;
  }
  ft_print_byte(i[3], 1);
}

void ft_hexmem(int fc, char **fv, int i[4], char buffer[16])
{
  while(i[0] < fc)
  {
    i[1] = open(fv[i[0]], O_RDONLY);
    while(i[2] == 16)
    {
      i[2] = read(i[1], buffer, 16);
      while(i[2] < 16 && i[0] != (fc-1))
      {
        i[0]++;
        close(i[1]);
        i[1] = open(fv[i[0]], O_RDONLY);
        i[2] += read(i[1], &buffer[i[2]], 16-i[2]);
      }
      ft_print_byte(i[3], 0);
      ft_print_hex2(buffer, i[2]);
      i[3] += i[2];
    }
    close(i[1]);
    i[0]++;
  }
  ft_print_byte(i[3], 0);
}
