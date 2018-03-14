#include "libft/libft.h"
#include "ft_split.h"
#include <stdlib.h>

static char **ft_fill_tab(char *str, char* charset, int *size);
static int ft_get_strpos(char *str, char *charset, int *l);
static void ft_get_string(char *elem, char *str, int cur, int l);
static int ft_separator(char *str, char *charset, int l);

char **ft_split(char *str, char *charset)
{
  int size;
  char **tab;

  size = 0;
  tab = ft_fill_tab(str, charset, &size);
  tab[size] = 0;

  return tab;
}

static char **ft_fill_tab(char *str, char* charset, int *size)
{
  int i;
  int l;
  int cur;
  char *elem;
  char **tab;

  cur = ft_get_strpos(str, charset, &l);

  if(cur < 0)
    return (char **)malloc((*size)+1 * sizeof(char*));
  else
  {
    (*size)++;
    i = (*size)-1;
    elem = (char *)malloc(l+1);
    ft_get_string(elem, str, cur, l);
    tab = ft_fill_tab(&str[cur+l], charset, size);
    tab[i] = elem;
    return tab;
  }
}

static int ft_get_strpos(char *str, char *charset, int *l)
{
  int i;
  int cur;
  int sepl;

  i = 0;
  sepl = 0;

  while(charset[sepl])
    sepl++;

  while(str[i] && ft_separator(&str[i], charset, sepl))
    i+=sepl;

  cur = !str[i] ? -1 : i;

  while(str[i] && !ft_separator(&str[i], charset, sepl))
    i++;

  *l = i-cur;

  return cur;
}

static int ft_separator(char *str, char *charset, int l)
{
  int i;

  i = 0;

  while(i < l)
  {
    if(str[i] != charset[i])
      return 0;
    i++;
  }

  return 1;
}

static void ft_get_string(char *elem, char *str, int cur, int l)
{
  int i;

  i = 0;

  while(i <= l)
  {
    elem[i] = (i == l) ? '\0' : str[cur+i];
    i++;
  }
}
