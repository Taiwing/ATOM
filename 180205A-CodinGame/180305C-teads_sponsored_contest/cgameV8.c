#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct link;

typedef struct list /*is gonna store the links in the nodes in increasing order*/
{
  struct link *first; /*linked node with the smallest ID*/
} list;

typedef struct node /*represents the nodes of the tree*/
{
  int ID;
  int lcount; /*number of links*/
  list *links;
  struct node *prec; /*preceding node in the tree (preceding ID)*/
  struct node *next; /*next node in the tree (next ID)*/
} node;

typedef struct link /*element of the link list*/
{
  node *n;
  struct link *next;
} link;

/*tree structure*/
node **init_tree(int n); /*generates the tree*/
node *insert_node(node **tree, int ID); /*inserts the new node at the right place in the tree*/
list *init_list(node *linked); /*creates a new link list and adds the given node to it*/
void insert_link(list *links, node *linked); /*insert a new link in the given link list*/
void generate_links(node *x, node *y); /*creates the link lists if need be and adds the new link to both nodes*/
void build_tree(node **tree, int xi, int yi); /*adds the new nodes and links to the tree*/

/*solution*/
int shortest_path(node *root);
void ft_max_finder(node *root, int *max, int n, int pID);

int main()
{
  int n; // the number of adjacency relations
  scanf("%d", &n);
  node **tree = init_tree(n);
  for(int i = 0; i < n; i++)
  {
    int xi; // the ID of a person which is adjacent to yi
    int yi; // the ID of a person which is adjacent to xi
    scanf("%d%d", &xi, &yi);
    build_tree(tree, xi, yi);
  }

  printf("%d\n", shortest_path(tree[0]));

  return 0;
}

node **init_tree(int n)
{
  node **tree = (node **)malloc((n+1) * sizeof(node *));
  for(int i = 0; i < n+1; i++)
    tree[i] = NULL;
  return tree;
}

node *insert_node(node **tree, int ID)
{
  node *nd = (node *)malloc(sizeof(node));
  nd->ID = ID;
  nd->lcount = 0; /*the list isn't yet created*/
  tree[ID] = nd;

  return nd;
}

list *init_list(node *linked)
{
  list *links = (list *)malloc(sizeof(list));
  links->first = (link *)malloc(sizeof(link));
  links->first->n = linked;
  links->first->next = NULL;
  return links;
}

void insert_link(list *links, node *linked)
{
  link *lk = (link *)malloc(sizeof(link));
  lk->n = linked;
  int ID = linked->ID;
  link *ptr = links->first;

  if(ptr->n->ID > ID)
  {
    lk->next = ptr;
    links->first = lk;
  }
  else
  {
    while(ptr->next && (ptr->next->n->ID < ID))
      ptr = ptr->next;

    lk->next = ptr->next;
    ptr->next = lk;
  }
}

void generate_links(node *x, node *y)
{
  node *xy[2];
  xy[0] = x;
  xy[1] = y;

  for(int i = 0; i < 2; i++)
  {
    if(!(xy[i]->lcount))
      xy[i]->links = init_list(xy[!i]);
    else
      insert_link(xy[i]->links, xy[!i]);

    (xy[i]->lcount)++;
  }
}

void build_tree(node **tree, int xi, int yi)
{
  node *x, *y;
  x = tree[xi];
  y = tree[yi];

  if(!x)
    x = insert_node(tree, xi);
  if(!y)
    y = insert_node(tree, yi);

  generate_links(x, y);
}


int shortest_path(node *root)
{
  /*array of lcount length (one for every node linked)*/
  /*that's gonna count the number of levels by node till a tree leaf*/
  int *max = (int *)malloc((root->lcount) * sizeof(int));
  for(int i = 0; i < root->lcount; i++)
    max[i] = 0;

  ft_max_finder(root, max, root->lcount, root->ID);

  int max_val = 0;
  int max_val2 = 0;
  int mi = -1;
  int path = 0;

  for(int i = 0; i < root->lcount; i++)
  {
    if(max[i] > max_val)
    {
      max_val = max[i];
      mi = i;
    }
  }

  for(int i = 0; i < root->lcount; i++)
    max_val2 = max[i] > max_val2 && i != mi ? max[i] : max_val2;

  path = max_val + max_val2;
  path = path % 2 ? path/2 + 1 : path/2;

  return path;
}

void ft_max_finder(node *root, int *max, int n, int pID)
{
  link *ptr = root->links->first;
  int *loc_max = (int *)malloc(n * sizeof(int));

  for(int i = 0; i < n; i++)
    loc_max[i] = (*max)+1;

  for(int i = 0; i < n; i++)
  {
    if(ptr && ptr->n->ID == pID)
      ptr = ptr->next;
    ft_max_finder(ptr->n, &loc_max[i], ptr->n->lcount-1, root->ID);
    ptr = ptr ? ptr->next : ptr;
  }

  if(root->ID != 0)
    for(int i = 0; i < n; i++)
      *max = loc_max[i] > *max ? loc_max[i] : *max;
  else
    for(int i = 0; i < n; i++)
      max[i] = loc_max[i];
}
