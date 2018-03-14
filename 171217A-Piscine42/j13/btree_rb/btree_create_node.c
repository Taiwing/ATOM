#include "ft_btree_rb.h"

t_rb_node *btree_create_node(void *data, t_rb_node *parent)
{
  t_rb_node *node;

  node = (t_rb_node *)malloc(sizeof(t_rb_node));
  node->data = data;
  node->parent = parent;
  node->left = 0;
  node->right = 0;

  if(!parent)
    node->color = RB_BLACK;

  return node;
}
