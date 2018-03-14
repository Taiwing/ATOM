#include "ft_btree.h"

static void ft_max_finder(t_btree *root, int *maxr, int *maxl);

int btree_level_count(t_btree *root)
{
  int maxr;
  int maxl;
  int max;

  maxr = 0;
  maxl = 0;
  ft_max_finder(root, &maxr, &maxl);
  max = (maxr - maxl) >= 0 ? maxr : maxl;

  return max;
}

static void ft_max_finder(t_btree *root, int *maxr, int *maxl)
{
  int loc_maxr;
  int loc_maxl;

  if(maxr)
  {
    loc_maxr = (*maxr)+1;
    loc_maxl = loc_maxr;
  }
  else if(maxl)
  {
    loc_maxl = (*maxl)+1;
    loc_maxr = loc_maxl;
  }

  if(root->left)
    ft_max_finder(root->left, NULL, &loc_maxl);
  if(root->right)
    ft_max_finder(root->right, &loc_maxr, NULL);

  if(maxr)
    *maxr = (loc_maxr - loc_maxl) >= 0 ? loc_maxr : loc_maxl;
  if(maxl)
    *maxl = (loc_maxr - loc_maxl) >= 0 ? loc_maxr : loc_maxl;
}
