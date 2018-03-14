#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

/*TODO: struct functions*/
struct link;

typedef struct list /*is gonna store the links in the nodes in increasing order*/
{
  struct link *first; /*linked node with the smallest ID*/
} list;

typedef struct node /*represents the nodes of the tree*/
{
  int ID;
  int lcount; /*number of links*/
  //int *steps; /*array of steps by links*/
  //int stepmax; /*biggest number of steps till the end of the net throught the links*/ /*or the distance from this node to the farthest node*/
  list *links;
  struct node *prec; /*preceding node in the tree (preceding ID)*/
  struct node *next; /*next node in the tree (next ID)*/
} node;

typedef struct link /*element of the link list*/
{
  node *n;
  struct link *next;
} link;

typedef struct tree /*stores the nodes in a list (smallest ID first)*/
{
  int ncount; /*number of nodes*/
  node *first; /*node with the lowest ID*/
  node *last; /*node with the highest ID*/
} tree;

/*tree structure*/
tree *init_tree(void); /*generates the tree*/
int node_exists(tree *tr, int ID); /*checks if the requested node exists*/
node *get_node(tree *tr, int ID); /*returns the node corresponding to the given ID*/
void insert_node(tree *tr, int ID); /*inserts the new node at the right place in the tree*/
list *init_list(node *linked); /*creates a new link list and adds the given node to it*/
void insert_link(list *links, node *linked); /*insert a new link in the given link list*/
void generate_links(int xi, int yi, tree *tr); /*creates the link lists if need be and adds the new link to both nodes*/
void build_tree(tree *tr, int xi, int yi); /*adds the new nodes and links to the tree*/

/*solution*/ /*TODO: adapt to this type of tree*/
int shortest_path(node *root);
void ft_max_finder(node *root, int *max, int n, int pID);

int main()
{
  tree *tr = init_tree();

  int n; // the number of adjacency relations
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int xi; // the ID of a person which is adjacent to yi
    int yi; // the ID of a person which is adjacent to xi
    scanf("%d%d", &xi, &yi);
    build_tree(tr, xi, yi);
  }

  // Write an action using printf(). DON'T FORGET THE TRAILING \n
  // To debug: fprintf(stderr, "Debug messages...\n");

  // The minimal amount of steps required to completely propagate the advertisement

    /*TEST*/
    int ni[3] = {0, 8, 15};
    node *ptr;
    link *lk;

    printf("\nncount: %d\n", tr->ncount);

    for(int i = 0; i < 3; i++)
    {
      ptr = get_node(tr, ni[i]);
      lk = ptr->links->first;
      printf("\nLINKS NODE %d:\n", ptr->ID);
      for(int j = 0; j < ptr->lcount; j++)
      {
        printf("%d ", lk->n->ID);
        lk = lk->next;
      }
      printf("\n");
    }

  printf("\nresult: %d\n", shortest_path(get_node(tr, 0)));

  return 0;
}

tree *init_tree(void)
{
  tree *tr = (tree *)malloc(sizeof(tree));
  tr->ncount = 0;
  tr->first = NULL;
  return tr;
}

int node_exists(tree *tr, int ID)
{
  node *ptr = tr->first;

  while(ptr && ptr->ID != ID)
    ptr = ptr->next;

  if(!ptr)
    return 0;
  else
    return 1;
}

node *get_node(tree *tr, int ID) /*assumes that the node exists*/
{
  node *ptr = tr->first;

  while(ptr->ID != ID)
    ptr = ptr->next;

  return ptr;
}

void insert_node(tree *tr, int ID)
{
  node *nd = (node *)malloc(sizeof(node));
  nd->ID = ID;
  nd->lcount = 0; /*the list isn't yet created*/
  node *ptr = tr->first;

  while(ptr && (ptr->ID < ID))
    ptr = ptr->next;

  if(!ptr && !(tr->ncount))
  {
    tr->first = nd;
    tr->last = nd;
    nd->prec = NULL;
    nd->next = NULL;
  }
  else if(!ptr)
  {
    nd->prec = tr->last;
    nd->next = NULL;
    tr->last->next = nd;
    tr->last = nd;
  }
  else
  {
    nd->prec = ptr->prec;
    nd->next = ptr;
    if(ptr->prec)
      ptr->prec->next = nd;
    else
      tr->first = nd;
    ptr->prec = nd;
  }

  (tr->ncount)++;
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

void generate_links(int xi, int yi, tree *tr)
{
  node *xy[2];
  xy[0] = get_node(tr, xi);
  xy[1] = get_node(tr, yi);

  for(int i = 0; i < 2; i++)
  {
    //int j = !i ? 1 : 0;

    if(!(xy[i]->lcount))
      xy[i]->links = init_list(xy[!i]);
    else
      insert_link(xy[i]->links, xy[!i]);

    (xy[i]->lcount)++;
  }
}

void build_tree(tree *tr, int xi, int yi)
{
  if(!node_exists(tr, xi))
    insert_node(tr, xi);
  if(!node_exists(tr, yi))
    insert_node(tr, yi);

  generate_links(xi, yi, tr);
}

int shortest_path(node *root)
{
  /*array of lcount length (one for every node linked)*/
  /*that's gonna count the number of levels by node till a tree leaf*/
  int *max = (int *)malloc((root->lcount) * sizeof(int));
  for(int i = 0; i < root->lcount; i++)
    max[i] = 0;

  for(int i = 0; i < root->lcount; i++)
    ft_max_finder(root, &max[i], root->lcount, root->ID);

    /*TEST*/
    /*printf("\nNODE %d:\n", root->ID);
    for(int i = 0; i < root->lcount; i++)
      printf("%d ", max[i]);*/

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

void ft_max_finder(node *root, int *max, int n, int pID) /*TODO*/
{
  link *ptr = root->links->first;
  int *loc_max = (int *)malloc(n * sizeof(int));

  for(int i = 0; i < n; i++)
    loc_max[i] = (*max)+1;

      /*TEST*/
      /*printf("\nNODE: %d\n", root->ID);
      printf("lcount: %d\n", root->lcount);
      printf("loc_max: %d\n", (*max));*/

  for(int i = 0; i < n; i++)
  {
    if(ptr && ptr->n->ID == pID)
      ptr = ptr->next;
    ft_max_finder(ptr->n, &loc_max[i], ptr->n->lcount-1, root->ID);
    ptr = ptr ? ptr->next : ptr;
  }

  for(int i = 0; i < n; i++)
    *max = loc_max[i] > *max ? loc_max[i] : *max;

  switch(root->ID)
  {
    case 0:
      printf("NODE %d: max = %d\n", root->ID, *max);
      printf("loc_max: ");
      for(int i = 0; i < n ; i++)
        printf("%d ", loc_max[i]);
      printf("\n");
    case 1:
      printf("NODE %d: max = %d\n", root->ID, *max);
    case 8:
      printf("NODE %d: max = %d\n", root->ID, *max);
    case 15:
      printf("NODE %d: max = %d\n", root->ID, *max);
  }
}
