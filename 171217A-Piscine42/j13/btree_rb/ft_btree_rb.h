#ifndef FT_RB_NODE_H
#define FT_RB_NODE_H
#include <stdlib.h>

enum e_rb_color
{
  RB_BLACK,
  RB_RED
};

typedef struct s_rb_node
{
  struct s_rb_node *parent;
  struct s_rb_node *left;
  struct s_rb_node *right;
  void *data;
  enum e_rb_color color;
} t_rb_node;

t_rb_node *btree_create_node(void *data, t_rb_node *parent);
t_rb_node *parent(t_rb_node *n);
t_rb_node *grandparent(t_rb_node *n);
t_rb_node *sibling(t_rb_node *n);
t_rb_node *uncle(t_rb_node *n);
void rotate_left(t_rb_node *n);
void rotate_right(t_rb_node *n);
void btree_apply_prefix(t_rb_node *root, void (*applyf)(void *));
void btree_apply_infix(t_rb_node *root, void (*applyf)(void *));
void btree_apply_suffix(t_rb_node *root, void (*applyf)(void *));
void *btree_search_data(t_rb_node *root, void *data_ref, int (*cmpf)(void *, void *));
int btree_level_count(t_rb_node *root);
void btree_apply_by_level(t_rb_node *root, void (*applyf)(void *data, int current_level, int is_first_elem));
void rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *));
/*void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *));*/

#endif
