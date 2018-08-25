#include "ft_btree.h"

static void ft_get_level_size(t_btree *root, int level, int *size)
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

static void ft_get_level_items(t_btree *root, int level, void **tab, int *pos)
{
  if(level == 0)
    tab[(*pos)++] = root->item;
  else if(level > 0)
  {
    if(root->left)
      ft_get_level_items(root->left, level-1, tab, pos);
    if(root->right)
      ft_get_level_items(root->right, level-1, tab, pos);
  }
}

static void **ft_get_level(t_btree *root, int level, int *size)
{
  int pos;
  void **tab;

  pos = 0;
  ft_get_level_size(root, level, size);
  if((*size) != 0)
  {
    tab = (void **)malloc(sizeof(void *) * (*size));
    ft_get_level_items(root, level, tab, &pos);
    return tab;
  }
  return NULL;
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
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
    i = -1;
    while(++i < lvlsize)
      (*applyf)(level[i], curlvl, !i);
    free(level);
    lvlsize = 0;
    level = ft_get_level(root, ++curlvl, &lvlsize);
  }
}
