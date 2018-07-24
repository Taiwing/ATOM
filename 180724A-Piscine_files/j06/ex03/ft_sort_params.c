#include "libft/libft.h"
#include <string.h>

static void ft_sort_params(int c, char *v[], char *max);
static void ft_print_param(char *arg);
static char *ft_find_max(int c, char *v[], char *top);

int main(int argc, char *argv[])
{
  if(argc > 1)
    ft_sort_params(argc - 1, &argv[1], 0);

  return 1;
}

static void ft_sort_params(int c, char *v[], char *max)
{
  max = ft_find_max(c, v, max);

  if(!max)
    return;
  else
    ft_sort_params(c, v, max);

  if(max)
    ft_print_param(max);
}

static void ft_print_param(char *arg)
{
  int i;

  i = 0;

  while(arg[i])
  {
    ft_putchar(arg[i]);
    i++;
  }
  ft_putchar('\n');
}

static char *ft_find_max(int c, char *v[], char *top)
{
  int i;
  char *max;

  i = 0;
  max = !top ? v[0] : 0;

  while(i < c)
  {
    if(!top || ft_strcmp(top, v[i]) > 0)
    {
      if(!max)
        max = v[i];
      else if(ft_strcmp(v[i], max) > 0)
        max = v[i];
    }
    i++;
  }

  return max;
}
