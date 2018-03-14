#include "libft/libft.h"
#include "ft_print_memory.h"

static void ft_print_addr(int addrVal);
static void ft_print_hex(char *ptr, int l);
static void ft_print_char(char *ptr, int l);

void *ft_print_memory(void *addr, unsigned int size)
{
  int i;
  int j;
  int l;
  char *ptr;

  i = 0;
  ptr = addr;

  while(i < size)
  {
    l = (size-1) - i >= 16 ? 16 : (size-1) - i;
    ft_print_addr(*(int *)&ptr[i]);
    ft_print_hex(&ptr[i], l);
    ft_print_char(&ptr[i], l);
    i += 16;
  }

  return addr;
}

static void ft_print_addr(int addrVal)
{
  int p;

  p = 8;

  while(addrVal < ft_pow(16, p-1))
  {
    ft_putchar('0');
    p--;
  }

  ft_putnbr_base(addrVal, "0123456789abcdef");
  ft_putchar(':');
  ft_putchar(' ');
}

static void ft_print_hex(char *ptr, int l)
{
  int i;
  int p;

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
    if(!((i+1)%2))
      ft_putchar(' ');
    i++;
  }
}

static void ft_print_char(char *ptr, int l)
{
  int i;

  i = 0;

  ft_putchar(' ');

  while(i < l)
  {
    if(ptr[i] > 31 && ptr[i] < 127)
      ft_putchar(ptr[i]);
    else
      ft_putchar('.');
    i++;
  }

  ft_putchar('\n');
}
