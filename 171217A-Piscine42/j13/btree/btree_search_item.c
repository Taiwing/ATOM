#include "ft_btree.h"

static void ft_search_btree(t_btree *root, void *data_ref, int (*cmpf)(void *, void *), void **ptr);

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
  void *ptr;

  ptr = NULL;
  ft_search_btree(root, data_ref, cmpf, &ptr);

  return ptr;
}

static void ft_search_btree(t_btree *root, void *data_ref, int (*cmpf)(void *, void *), void **ptr)
{
  if(root->left)
    ft_search_btree(root->left, data_ref, cmpf, ptr);
  if(root->item && ((*cmpf)(root->item, data_ref) > 0) && *ptr == NULL)
    *ptr = root->item;
  if(root->right)
    ft_search_btree(root->right, data_ref, cmpf, ptr);
}
