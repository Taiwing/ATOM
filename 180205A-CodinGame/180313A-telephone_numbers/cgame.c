#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
  struct node *child[10];
} node;

typedef struct tree
{
  node *root;
  int c;
} tree;

node *create_node();
tree *init_tree();
void add_phone(tree *tr, char telephone[21]);

int main()
{
  tree *tr = init_tree();

  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    char telephone[21];
    scanf("%s", telephone);
    add_phone(tr, telephone);
  }

  // The number of elements (referencing a number) stored in the structure.
  printf("%d\n", tr->c);

  return 0;
}

node *create_node()
{
  node *nd = (node *)malloc(sizeof(node));
  for(int i = 0; i < 10; i++)
    nd->child[i] = NULL;
  return nd;
}

tree *init_tree()
{
  tree *tr = (tree *)malloc(sizeof(tree));
  tr->root = create_node();
  tr->c = 0;
  return tr;
}

void add_phone(tree *tr, char telephone[21])
{
  node *nd = tr->root;
  int n;

  for(int i = 0; telephone[i]; i++)
  {
    n = telephone[i] - 48;
    if(!(nd->child[n]))
    {
      nd->child[n] = create_node();
      (tr->c)++;
    }
    nd = nd->child[n];
  }
}
