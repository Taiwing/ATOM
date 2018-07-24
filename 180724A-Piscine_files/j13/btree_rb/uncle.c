#include "ft_btree_rb.h"

t_rb_node *uncle(t_rb_node *n)
{
  t_rb_node *p = parent(n);
  if(!p)
    return 0;
  else
    return sibling(p);
}
