#include "ft_btree_rb.h"

void rotate_right(t_rb_node *n)
{
  t_rb_node *m;

  /*rotation*/
  m = n->left;
  n->left = m->right;
  m->right = n;
  m->parent = n->parent;
  n->parent = m;

  /*update links*/
  if(n->left)
    n->left->parent = n;
  if(m->parent)
  {
    if(m->parent->left == n)
      m->parent->left = m;
    else
      m->parent->right = m;
  }
}
