#include "ft_btree_rb.h"

void rotate_left(t_rb_node *n)
{
  t_rb_node *m;

  /*rotation*/
  m = n->right;
  n->right = m->left;
  m->left = n;
  m->parent = n->parent;
  n->parent = m;

  /*update links*/
  if(n->right)
    n->right->parent = n;
  if(m->parent)
  {
    if(m->parent->right == n)
      m->parent->right = m;
    else
      m->parent->left = m;
  }
}
