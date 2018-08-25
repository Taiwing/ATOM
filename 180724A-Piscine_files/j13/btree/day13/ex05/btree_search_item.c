#include "ft_btree.h"

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
  void *ptr;

  ptr = NULL;
	if(root->left && ptr == NULL)
		ptr = btree_search_item(root->left, data_ref, cmpf);
  if(root->item && (*cmpf)(root->item, data_ref) == 0 && ptr == NULL)
    ptr = root->item;
  if(root->right && ptr == NULL)
    ptr = btree_search_item(root->right, data_ref, cmpf);
  return ptr;
}
