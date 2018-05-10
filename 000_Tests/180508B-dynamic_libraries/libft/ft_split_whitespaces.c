#include "libft.h"

static int ft_get_split_size(char *str);
static char *ft_cut_string(char *str, int *cur);
static int ft_get_cut_size(char *str, int *start);

char **ft_split_whitespaces(char *str)
{
  int i;
  int cur;
  int size;
  char **split;

  i = 0;
  cur = 0;
  size = ft_get_split_size(str);
  split = malloc(sizeof(char*) * size);
  
  while(i < size)
  {
    split[i] = ft_cut_string(&str[cur], &cur);
    i++;
  }

  return split;
}

static int ft_get_split_size(char *str)
{
  int i;
  int size;
  int white;

  i = 0;
  size = 0;
  white = 1;

  while(str[i])
  {
    white = ((str[i] > 8 && str[i] < 12) || str[i] == 32) ? 1 : 0;
    size = (!white) ? size+1 : size;
    while(str[i] && !white)
    {
      i++;
      white = ((str[i] > 8 && str[i] < 12) || str[i] == 32) ? 1 : 0;
    }
    i++;
  }

  return size+1;
}

static char *ft_cut_string(char *str, int *cur)
{
  int i;
  int size;
  int start;
  char *cut;

  i = 0;
  size = ft_get_cut_size(str, &start);
  cut = (size == 1) ? 0 : (char *)malloc(size);

  while(i < size && cut != 0)
  {
    cut[i] = i == size-1 ? '\0' : str[start+i];
    i++;
  }

  *cur += (start+size-1);

  return cut;
}

static int ft_get_cut_size(char *str, int *start)
{
  int i;
  int size;
  int white;

  i = 0;
  size = 0;
  white = 1;

  while(str[i] && white)
  {
    white = ((str[i] > 8 && str[i] < 12) || str[i] == 32) ? 1 : 0;
    size = white || str[i] == 0 ? 0 : 1;
    i++;
  }

  *start = i-1;

  while(str[i] && !white)
  {
    white = ((str[i] > 8 && str[i] < 12) || str[i] == 32) ? 1 : 0;
    size = (!white) ? size+1 : size;
    i++;
  }

  return size+1;
}
