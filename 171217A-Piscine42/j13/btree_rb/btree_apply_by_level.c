#include "ft_btree_rb.h"

static void **ft_get_level(t_rb_node *root, int level, int *size);
static int ft_is_first_elem(int i);
static void ft_get_level_size(t_rb_node *root, int level, int *size);
static void ft_get_level_datas(t_rb_node *root, int level, void **tab, int *pos);

void btree_apply_by_level(t_rb_node *root, void (*applyf)(void *data, int current_level, int is_first_elem))
{
  int i;
  int curlvl;
  int lvlsize;
  void **level;

  curlvl = 0;
  lvlsize = 0;
  level = ft_get_level(root, curlvl, &lvlsize);

  while(level)
  {
    i = 0;
    while(i < lvlsize)
    {
      (*applyf)(level[i], curlvl, ft_is_first_elem(i));
      i++;
    }
    free(level);
    curlvl++;
    lvlsize = 0;
    level = ft_get_level(root, curlvl, &lvlsize);
  }
}

static void **ft_get_level(t_rb_node *root, int level, int *size)
{
  int pos;
  void **tab;

  pos = 0;
  ft_get_level_size(root, level, size);
  if((*size) != 0)
  {
    tab = (void **)malloc(sizeof(void *) * (*size));
    ft_get_level_datas(root, level, tab, &pos);
    return tab;
  }

  return NULL;
}

static void ft_get_level_size(t_rb_node *root, int level, int *size)
{
  if(level == 0)
    (*size)++;
  else if(level > 0)
  {
    if(root->left)
      ft_get_level_size(root->left, level-1, size);
    if(root->right)
      ft_get_level_size(root->right, level-1, size);
  }
}

static void ft_get_level_datas(t_rb_node *root, int level, void **tab, int *pos)
{
  if(level == 0)
  {
    tab[(*pos)] = root->data;
    *pos = (*pos)+1;
  }
  else if(level > 0)
  {
    if(root->left)
      ft_get_level_datas(root->left, level-1, tab, pos);
    if(root->right)
      ft_get_level_datas(root->right, level-1, tab, pos);
  }
}

static int ft_is_first_elem(int i)
{
  if(!i)
    return 1;
  else
    return 0;
}
