#include "libft.h"

static int ft_get_size(char **tab, char *sep);
static void ft_fill_tab(char **tab, char *sep, char *str);

char *ft_join(char **tab, char *sep)
{
  int size;
  char *str;

  size = ft_get_size(tab, sep);
  str = (char *)malloc(size);
  ft_fill_tab(tab, sep, str);

  return str;
}

static int ft_get_size(char **tab, char *sep)
{
  int i;
  int j;
  int s;
  int size;

  i = 0;
  s = 0;
  size = 0;

  while(sep[s])
    s++;

  while(tab[i])
  {
    j = 0;
    while(tab[i][j])
      j++;
    size = tab[i+1] ? size+j+s : size+j+1;
    i++;
  }

  return size;
}

static void ft_fill_tab(char **tab, char *sep, char *str)
{
  int i[4];

  i[0] = 0;
  i[3] = 0;

  while(tab[i[0]])
  {
    i[1] = 0;
    while(tab[i[0]][i[1]])
    {
      str[i[3]] = tab[i[0]][i[1]];
      i[1]++;
      i[3]++;
    }
    i[2] = 0;
    while(tab[i[0]+1] && sep[i[2]])
    {
      str[i[3]] = sep[i[2]];
      i[2]++;
      i[3]++;
    }
    i[0]++;
  }

  str[i[3]] = '\0';
}
