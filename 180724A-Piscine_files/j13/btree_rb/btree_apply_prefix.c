#include "ft_btree_rb.h"

void btree_apply_prefix(t_rb_node *root, void (*applyf)(void *))
{
  if(root->data)
    (*applyf)(root->data);
  if(root->left)
    btree_apply_prefix(root->left, applyf);
  if(root->right)
    btree_apply_prefix(root->right, applyf);
}
