#include "ft_prints.h"

void ft_print_byte(int byte, int ascii)
{
  int p;

  p = 8;
  while(byte < ft_pow(16, --p) && p > 0)
    ft_putchar('0');
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
      ft_putstr("  ");
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
    if(i + 1 < l)
    {
      if(ptr[i + 1] < 16)
        ft_putchar('0');
      ft_putnbr_base(ptr[i + 1], "0123456789abcdef");
    }
    else if(l % 2)
      ft_putstr("00");
    if(ptr[i] < 16)
      ft_putchar('0');
    ft_putnbr_base(ptr[i], "0123456789abcdef");
    ft_putchar(' ');
    i += 2;
  }
  ft_putchar('\n');
}

void ft_print_char(char *ptr, int l)
{
  ft_putstr(" |");
  while(l--)
  {
  	ft_putchar(*ptr > 31 && *ptr < 127 ? *ptr : '.');
    ptr++;
  }
  ft_putstr("|\n");
}
