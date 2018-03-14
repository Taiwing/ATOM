#include "libft/libft.h"
#include "ft_convert_base.h"
#include <stdlib.h>

static int ft_is_base_valid(char *base);
static int ft_is_nbr_valid(char *str, char *base);
static int ft_int_conversion(char *str, int l, char *base, int b);
static int ft_locpow(int a, int b);
static char *ft_alloc_str(int nbr, int base, int *size);
static void ft_get_size(int nbr, int base, int *size);
static void ft_base_conversion(char *str, int nbr, char *base, int b);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
  int b[2];
  int l;
  int n;
  int size;
  char *str;

  b[0] = ft_is_base_valid(base_from);
  b[1] = ft_is_base_valid(base_to);
  l = ft_is_nbr_valid(nbr, base_from);

  if(!b[0] || !b[1] || !l)
    return NULL;
  else
  {
    n = ft_int_conversion(nbr, l, base_from, b[0]);
    str = ft_alloc_str(n, b[1], &size);
    str[size] = '\0';
    str[0] = (n < 0) ? '-' : str[0];
    n = (n < 0) ? n*-1 : n;
    ft_base_conversion(&str[size-1], n, base_to, b[1]);
  }

  return str;
}

static int ft_is_base_valid(char *base)
{
  int b;
  int i;
  int err;

  b = 0;
  i = 0;
  err = 0;

  while(base[b] && !err)
  {
    i = 0;
    while(i <= b && !err)
    {
      err = (base[i]==base[b] && i!=b) || base[i]==43 || base[i]==45 ? 1 : 0;
      i++;
    }
    b++;
  }

  if(b <= 1 || err)
    return 0;
  else
    return b;
}

static int ft_is_nbr_valid(char *str, char *base)
{
  int i;
  int j;
  int err;

  i = 0;
  err = 0;

  while(str[i])
  {
    j = 0;
    while(base[j])
    {
      err = str[i]==base[j]||(str[i]==43 && i==0)||(str[i]==45 && i==0) ? 0 : 1;
      if(!err)
        break;
      j++;
    }
    if(err)
      break;
    i++;
  }

  err = !err ? i : 0;

  return err;
}

static int ft_int_conversion(char *str, int l, char *base, int b)
{
  int i;
  int j;
  int nbr;

  i = l-1;
  nbr = 0;

  while(i >= 0)
  {
    j = 0;
    while(base[j])
    {
      if(str[i] == base[j])
        break;
      j++;
    }
    if(j < b)
      nbr += j * ft_locpow(b, l-(i+1));
    else if(str[i] == 45)
      nbr *= -1;
    i--;
  }

  return nbr;
}

static int ft_locpow(int a, int b)
{
  if(!b)
    return 1;
  else
    return a * ft_locpow(a, b-1);
}

static char *ft_alloc_str(int nbr, int base, int *size)
{
  *size = nbr < 0 ? 1 : 0;

  if(*size == 1)
    ft_get_size(nbr*-1, base, size);
  else
    ft_get_size(nbr, base, size);

  return (char *)malloc(*size+1);
}

static void ft_get_size(int nbr, int base, int *size)
{
  if(nbr/base == 0)
    (*size)++;
  else
  {
    (*size)++;
    ft_get_size(nbr/base, base, size);
  }
}

static void ft_base_conversion(char *str, int nbr, char *base, int b)
{
  static int i = 0;

  if(nbr/b == 0)
    str[0] = base[nbr%b];
  else
  {
    str[0] = base[nbr%b];
    ft_base_conversion(&str[-1], nbr/b, base, b);
  }
}
