#include "libft/libft.h"
#include "ft_atoi_base.h"

static int ft_is_nbr_valid(char *str, char *base);
static int ft_is_base_valid(char *base);
static int ft_conversion(char *str, int l, char *base, int b);
static int ft_pow(int a, int b);

int ft_atoi_base(char *str, char *base)
{
  int b;
  int l;

  b = ft_is_base_valid(base);
  l = ft_is_nbr_valid(str, base);

  if(!b || !l)
    return 0;
  else
    return ft_conversion(str, l, base, b);
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

static int ft_conversion(char *str, int l, char *base, int b)
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
      nbr += j * ft_pow(b, l-(i+1));
    else if(str[i] == 45)
      nbr *= -1;
    i--;
  }

  return nbr;
}

static int ft_pow(int a, int b)
{
  if(!b)
    return 1;
  else
    return a * ft_pow(a, b-1);
}
