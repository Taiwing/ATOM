#include "libft/libft.h"
#include "ft_btree.h"

void ft_putstr_VOID(void *str);
int ft_strcmp_VOID(void *str1, void *str2);
void ft_fiiiiiirst(void *item, int current_level, int is_first_elem);
void ft_str_fiiiiiirst(char *item, int current_level, int is_first_elem);

int main(void)
{
  char *str;
  t_btree *root;

  root = btree_create_node("F");
  root->left = btree_create_node("B");
  root->right = btree_create_node("G");
  root->left->left = btree_create_node("A");
  root->left->right = btree_create_node("D");
  root->right->right = btree_create_node("I");
  root->left->right->left = btree_create_node("C");
  root->left->right->right = btree_create_node("E");
  root->right->right->left = btree_create_node("H");

  btree_insert_data(&root, "D", &ft_strcmp_VOID);
  btree_insert_data(&root, "D", &ft_strcmp_VOID);

  ft_putstr("APPLY BY LVL:");
  btree_apply_by_level(root, &ft_fiiiiiirst);
  ft_putstr("\n\n");

  ft_putstr("PREFIX:\n");
  btree_apply_prefix(root, &ft_putstr_VOID);

  ft_putstr("\n\nINFIX:\n");
  btree_apply_infix(root, &ft_putstr_VOID);

  ft_putstr("\n\nSUFFIX:\n");
  btree_apply_suffix(root, &ft_putstr_VOID);

  ft_putstr("\n\nSEARCH:\n");
  str = (char *)btree_search_item(root, "A", &ft_strcmp_VOID);

  if(str)
    ft_putstr(str);

  ft_putstr("\n\nBIGGEST BRANCH: ");
  ft_putnbr(btree_level_count(root));
  ft_putchar('\n');
  return 0;
}

void ft_putstr_VOID(void *str)
{
  ft_putstr(str);
}

int ft_strcmp_VOID(void *str1, void *str2)
{
  return ft_strcmp(str1, str2);
}

void ft_fiiiiiirst(void *item, int current_level, int is_first_elem)
{
  ft_str_fiiiiiirst(item, current_level, is_first_elem);
}

void ft_str_fiiiiiirst(char *item, int current_level, int is_first_elem)
{
  if(is_first_elem)
    ft_putchar('\n');
  ft_putstr(item);
  ft_putnbr(current_level);
  if(is_first_elem)
    ft_putchar('F');
  ft_putchar(' ');
}
