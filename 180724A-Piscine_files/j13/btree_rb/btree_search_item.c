#include "ft_btree_rb.h"

static void ft_search_btree(t_rb_node *root, void *data_ref, int (*cmpf)(void *, void *), void **ptr);

void *btree_search_data(t_rb_node *root, void *data_ref, int (*cmpf)(void *, void *))
{
  void *ptr;

  ptr = NULL;
  ft_search_btree(root, data_ref, cmpf, &ptr);

  return ptr;
}

static void ft_search_btree(t_rb_node *root, void *data_ref, int (*cmpf)(void *, void *), void **ptr)
{
  if(root->left)
    ft_search_btree(root->left, data_ref, cmpf, ptr);
  if(root->data && ((*cmpf)(root->data, data_ref) > 0) && *ptr == NULL)
    *ptr = root->data;
  if(root->right)
    ft_search_btree(root->right, data_ref, cmpf, ptr);
}
