#include "ft_btree_rb.h"

t_rb_node *sibling(t_rb_node *n)
{
  t_rb_node *p = parent(n);
  if(!p)
    return 0;
  else if(p->left == n)
    return p->right;
  else
    return p->left;
}
