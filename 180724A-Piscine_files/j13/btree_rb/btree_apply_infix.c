#include "ft_btree_rb.h"

void btree_apply_infix(t_rb_node *root, void (*applyf)(void *))
{
  if(root->left)
    btree_apply_infix(root->left, applyf);
  if(root->data)
    (*applyf)(root->data);
  if(root->right)
    btree_apply_infix(root->right, applyf);
}
