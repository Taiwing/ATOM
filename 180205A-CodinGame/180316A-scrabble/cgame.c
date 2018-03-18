#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valmap[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

typedef struct node
{
	struct node *parent;
	struct node *child[26];
}	node;

node *create_node(node *parent);
void add_word(node *root, char W[31]);

int main()
{
  int N;
  scanf("%d", &N); fgetc(stdin);
	node *root = create_node(NULL);
	node *max = NULL;
  for(int i = 0; i < N; i++)
	{
		int j = 0;
    char W[31];
    fgets(W, 31, stdin);
		while(W[j] && W[j] != '\n')
			j++;
		if(j <= 7)
			add_word(root, W);
  }
  char LETTERS[9];
  fgets(LETTERS, 9, stdin);

  printf("invalid word\n");

  return 0;
}

node *create_node(node *parent)
{
	node *nd = (node *)malloc(sizeof(node));
	nd->parent = parent;
	for(int i = 0; i < 26; i++)
		nd->child[i] = NULL;
	return nd;
}
