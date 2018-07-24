#include "ft_btree_rb.h"

void btree_apply_suffix(t_rb_node *root, void (*applyf)(void *))
{
  if(root->left)
    btree_apply_suffix(root->left, applyf);
  if(root->right)
    btree_apply_suffix(root->right, applyf);
  if(root->data)
    (*applyf)(root->data);
}
