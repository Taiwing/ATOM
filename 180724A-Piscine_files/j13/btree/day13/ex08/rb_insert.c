#include "ft_btree_rb.h"

void rb_repair_case3(t_rb_node *n)
{
  t_rb_node *p = parent(n);
  t_rb_node *g = grandparent(n);

  if(n == g->left->right)
  {
    rotate_left(p);
    n = n->left;
  }
  else if(n == g->right->left)
  {
    rotate_right(n);
    n = n->right;
  }
  if(n == p->left)
    rotate_right(g);
  else
    rotate_left(g);
  p->color = RB_BLACK;
  g->color = RB_RED;
}

void rb_repair_tree(t_rb_node *n)
{
  if(parent(n) == 0)
    n->color = RB_BLACK;
  else if(parent(n)->color == RB_RED && uncle(n)->color == RB_RED)
  {
    parent(n)->color = RB_BLACK;
    uncle(n)->color = RB_BLACK;
    grandparent(n)->color = RB_RED;
    rb_repair_tree(grandparent(n));
  }
  else if(parent(n)->color == RB_RED && uncle(n)->color == RB_BLACK)
    rb_repair_case3(n);
}

void rb_find_place(t_rb_node **root, t_rb_node *p, t_rb_node *n, int (*cmpf)(void *, void *))
{
  if(!(*root))
  {
    *root = n;
    (*root)->color = RB_RED;
    (*root)->parent = p;
  }
  else if((*cmpf)(n->data, (*root)->data) < 0)
    rb_find_place(&((*root)->left), (*root), n, cmpf);
  else
    rb_find_place(&((*root)->right), (*root), n, cmpf);
}


void rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *))
{
  t_rb_node *n;

	n = btree_create_node(data, 0);
  rb_find_place(root, (*root)->parent, n, cmpf);
  rb_repair_tree(n);
  *root = n;
  while(parent(*root) != 0)
    *root = parent(*root);
}
