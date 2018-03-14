#include "ft_prints.h"

void ft_print_byte(int byte, int ascii)
{
  int p;

  p = 8;

  while(byte < ft_pow(16, p-1) && p > 1)
  {
    ft_putchar('0');
    p--;
  }

  ft_putnbr_base(byte, "0123456789abcdef");
  ft_putchar(' ');
  if(ascii)
    ft_putchar(' ');
}

void ft_print_hex(char *ptr, int l)
{
  int i;

  i = 0;

  while(i < 16)
  {
    if(i < l)
    {
      if(ptr[i] < 16)
        ft_putchar('0');
      ft_putnbr_base(ptr[i], "0123456789abcdef");
    }
    else
    {
      ft_putchar(' ');
      ft_putchar(' ');
    }
    if(i == 7)
      ft_putchar(' ');
    ft_putchar(' ');
    i++;
  }
}

void ft_print_hex2(char *ptr, int l)
{
  int i;

  i = 0;

  while(i < l)
  {
    if(i+1 < l)
    {
      if(ptr[i+1] < 16)
        ft_putchar('0');
      ft_putnbr_base(ptr[i+1], "0123456789abcdef");
    }
    else if(l%2)
      ft_putstr("00");
    if(ptr[i] < 16)
      ft_putchar('0');
    ft_putnbr_base(ptr[i], "0123456789abcdef");
    ft_putchar(' ');
    i+=2;
  }

  ft_putchar('\n');
}

void ft_print_char(char *ptr, int l)
{
  int i;

  i = 0;

  ft_putstr(" |");

  while(i < l)
  {
    if(ptr[i] > 31 && ptr[i] < 127)
      ft_putchar(ptr[i]);
    else
      ft_putchar('.');
    i++;
  }

  ft_putstr("|\n");
}
