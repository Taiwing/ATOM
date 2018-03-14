#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct link;

typedef struct list
{
  struct link *first;
} list;

typedef struct node
{
  int ID;
  struct node *next;
  int ibc; /*number of odes it is influenced by*/
  list *infby; /*list of nodes this one is influenced by*/
	int itc; /*number of node it influences*/
	list *inftow; /*list of nodes this one influences*/
} node;

typedef struct link
{
  node *n;
  struct link *next;
} link;

/*tree structure*/
int comp(const void *a, const void *b);
int sort_list(int *node_list, int nc, int (*comp)(const void *a, const void *b));
void clean_list(int **link_list, int n, int *node_list, int nc);
node **init_tree(int n);
node *insert_node(node **tree, int ID); /*inserts the new node at the right place in the tree*/
list *init_list(node *linked); /*creates a new link list and adds the given node to it*/
void insert_link(list *links, node *linked); /*insert a new link in the given link list*/
void generate_links(node *x, node *y); /*creates the link lists if need be and adds the new link to both nodes*/
void build_tree(node **tree, int xi, int yi); /*adds the new nodes and links to the tree*/

/*solution*/
int longest_path(node **tree, int nc);
void ft_max_finder(node *root, int *max, int n);

int main()
{
  int n; // the number of relationships of influence
  scanf("%d", &n);

	int **link_list = (int **)malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++)
		link_list[i] = (int *)malloc(2 * sizeof(int));
	int *node_list = (int *)malloc((n*2) * sizeof(int));
	int nc = 0; /*node count*/

  for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &link_list[i][0], &link_list[i][1]);
		for(int j = 0; j < 2; j++, nc++)
			node_list[nc] = link_list[i][j];
	}

	nc = sort_list(node_list, nc, comp);
	clean_list(link_list, n, node_list, nc);

		/*TEST*/
		printf("\nnode list:\n");
		for(int i = 0; i < nc; i++)
			printf("%d ", node_list[i]);
		printf("\n\nlink_list:\n");
		for(int i = 0; i < n; i++)
			printf("%d %d\n", link_list[i][0], link_list[i][1]);

	node **tree = init_tree(nc);
	for(int i = 0; i < n; i++)
	  if(link_list[i][0] != link_list[i][1]) /*probably useless*/
		  build_tree(tree, link_list[i][0], link_list[i][1]);

  // The number of people involved in the longest succession of influences
  printf("%d\n", longest_path(tree, nc));

  return 0;
}

int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int sort_list(int *node_list, int nc, int (*comp)(const void *a, const void *b))
{
	qsort(node_list, nc, sizeof(int), comp);
	int val = node_list[0];
	int iv = 0; /*place of last val in the list*/
	for(int i = 0; i < nc; i++)
	{
		if(val != node_list[i])
		{
			val = node_list[i];
			iv++;
			node_list[iv] = val;
		}
	}
	return iv+1;
}

void clean_list(int **link_list, int n, int *node_list, int nc)
{
	for(int i = 0; i < nc; i++)
		if(node_list[i] != i)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < 2; k++)
					link_list[j][k] = link_list[j][k] == node_list[i] ? i : link_list[j][k];
}

node **init_tree(int nc)
{
  node **tree = (node **)malloc(nc * sizeof(node *));
  for(int i = 0; i < nc; i++)
    tree[i] = NULL;
  return tree;
}

node *insert_node(node **tree, int ID)
{
  node *nd = (node *)malloc(sizeof(node));
  nd->ID = ID;
  nd->ibc = 0;
	nd->itc = 0;
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
	if(!(x->itc))
		x->inftow = init_list(y);
	else
		insert_link(x->inftow, y);
	(x->itc)++;

  if(!(y->ibc))
    y->infby = init_list(x);
  else
    insert_link(y->infby, x);
  (y->ibc)++;
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

int longest_path(node **tree, int nc)
{
	int path = 1;

	for(int i = 0; i < nc; i++)
	{
		if(!(tree[i]->ibc) && tree[i]->itc)
		{
			int *max = (int *)malloc(tree[i]->itc * sizeof(int));
			for(int j = 0; j < tree[i]->itc; j++)
				max[j] = 1;
			ft_max_finder(tree[i], max, tree[i]->itc);
			for(int j = 0; j < tree[i]->itc; j++)
				path = max[j] > path ? max[j] : path;
		}
	}

	return path;
}

void ft_max_finder(node *root, int *max, int n)
{
  link *ptr = n ? root->inftow->first : NULL;
  int *loc_max = (int *)malloc(n * sizeof(int));

  for(int i = 0; i < n; i++)
    loc_max[i] = (*max)+1;

  for(int i = 0; i < n; i++)
  {
    ft_max_finder(ptr->n, &loc_max[i], ptr->n->itc);
    ptr = ptr ? ptr->next : ptr;
  }

  for(int i = 0; i < n; i++)
    *max = loc_max[i] > *max ? loc_max[i] : *max;
}
