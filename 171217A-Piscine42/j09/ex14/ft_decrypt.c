#include "ft_decrypt.h"

static t_perso **ft_fill_tab(char *str, int size, int end);
static t_perso *ft_get_params(char *str, int *cur);
static void ft_get_name(char *str, t_perso *perso, int *cur);
static int ft_loc_atoi(char *str, int l);

t_perso **ft_decrypt(char *str)
{
  return ft_fill_tab(str, 0, 0);
}

static t_perso **ft_fill_tab(char *str, int size, int end)
{
  t_perso **tab;
  t_perso *perso;
  int cur;

  if(!str[0] && end)
    return (t_perso **)malloc(size * sizeof(t_perso *));
  else if(!str[0])
    {
      tab = ft_fill_tab(str, size+1, 1);
      tab[size] = 0;
    }
  else
  {
    perso = ft_get_params(str, &cur);
    size = perso ? size+1 : size;
    tab = ft_fill_tab(&str[cur], size, 0);
    tab[size-1] = perso ? perso : tab[size-1];
  }

  return tab;
}

static t_perso *ft_get_params(char *str, int *cur)
{
  t_perso *perso;
  char *strAge;
  int i;

  *cur = 0;
  i = 0;

  while(str[*cur] && str[*cur] != '|')
    (*cur)++;

  perso = *cur ? (t_perso *)malloc(sizeof(t_perso)) : 0;

  if(perso)
  {
    strAge = (char *)malloc((*cur)+1);
    while(i <= (*cur))
    {
      strAge[i] = i < (*cur) ? str[i] : '\0';
      i++;
    }
    perso->age = ft_loc_atoi(strAge, (*cur));
    ft_get_name(str, perso, cur);
  }

  return perso;
}

static void ft_get_name(char *str, t_perso *perso, int *cur)
{
  char *strName;
  int length;
  int i;

  i = (*cur)+1;

  while(str[(*cur)] && str[(*cur)] != ';')
    (*cur)++;

  length = (*cur)-i;
  strName = (char *)malloc(length);
  *cur = i;

  while((*cur) <= i+length-1)
  {
    strName[(*cur)-i] = ((*cur)-i) < (i+length-1) ? str[(*cur)] : '\0';
    (*cur)++;
  }

  *cur = str[(*cur)] == '\0' ? *cur : (*cur)+1;
  perso->name = strName;
}

static int ft_loc_atoi(char *str, int l)
{
  int n[5];

  n[0] = 0;
  n[2] = l-1;
  n[3] = n[2];

  while(n[3] >= 0)
  {
    if(str[n[3]] != '-')
    {
      n[1] = str[n[3]] - 48;
      n[4] = n[2] - n[3];
      while(n[4] > 0)
      {
        n[1] *= 10;
        n[4]--;
      }
      n[0] += n[1];
    }
    else
      n[0] *= -1;
    n[3]--;
  }

  return n[0];
}
