#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valmap[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

typedef struct node
{
	struct node *parent;
	struct node *child[26];
	int score; /*records the final score of the word if the node ends a word*/
	int word; /*bool indicating if this letter ends a word or not*/
}	node;

node *create_node(node *parent);
int ind(char l); /*gets the index 0-25 of the letter l*/
void add_word(node *root, char *W); /*adds a word to the tree*/
int *use_letter(int *l, int i, int d); /*returns the array given minus the letter of the node entered*/
node *find_max(node *root, int *oldl, int depth, int score, int il); /*gets the node with the best score (NULL if exhausted l before leaf)*/
char *ft_strrev(char *str);
char *get_word(node *root, int *l); /*returns the answer*/

/*TEST*/
void print_tree(node *root, char l);

int main()
{
  int N;
  scanf("%d", &N); fgetc(stdin);
	node *root = create_node(NULL);
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
	int *l = (int *)malloc(7 * sizeof(int));
	for(int i = 0; i < 7; i++)
		l[i] = ind(LETTERS[i]);

	int min, tmp;
	for(int i = 0; i < 7; i++)
	{
		min = i;
		for(int j = i+1; j < 7; j++)
			min = l[j] < l[i] ? j : min;
		tmp = l[min];
		l[min] = l[i];
		l[i] = tmp;
	}

	print_tree(root, 0);

  printf("%s\n", get_word(root, l));

  return 0;
}

node *create_node(node *parent)
{
	node *nd = (node *)malloc(sizeof(node));
	nd->parent = parent;
	for(int i = 0; i < 26; i++)
		nd->child[i] = NULL;
	nd->score = 0;
	nd->word = 0;
	return nd;
}

int ind(char l)
{
	return (int)l-97;
}

void add_word(node *root, char *W)
{
	if(W[0] < 97 || W[0] > 122)
	{
		root->word = 1;
		return;
	}
	else
	{
		int l = ind(W[0]);
		root->child[l] = !(root->child[l]) ? create_node(root) : root->child[l];
		add_word(root->child[l], &W[1]);
	}
}

int *use_letter(int *l, int i, int d)
{
	int *new_l = (int *)malloc(d * sizeof(int));
	int k = 0;
	for(int j = 0; j < d; j++)
	{
		if(l[j] == i) k++;
		new_l[j] = l[k];
		k++;
	}
	return new_l;
}

node *find_max(node *root, int *oldl, int depth, int score, int il)
{
	node *best = NULL;
	int *l = use_letter(oldl, il, depth);
	score += valmap[il];

	if(root->word && !l)
	{
		best = root;
		best->score = score;
	}
	else
	{
		node **max = (node **)malloc(depth * sizeof(node *));
		for(int i = 0; i < depth; i++)
			max[i] = root->child[l[i]] ? find_max(root->child[l[i]], l, depth-1, score, l[i]) : NULL;
		free(l);

		best = root->word ? root : best;
		for(int i = 0; i < depth; i++)
			best = !best || (max[i] && best->score < max[i]->score) ? max[i] : best;
	}

	return best;
}

char *ft_strrev(char *str)
{
  int i;
  int j;
  char c;

  i = 0;
  j = 0;
	for(; str[j]; j++);

  while(i < j)
  {
    c = str[i];
    str[i] = str[j - 1];
    str[j - 1] = c;
    j--;
    i++;
  }

  return str;
}

char *get_word(node *root, int *l)
{
	char *word = (char *)malloc(8 * sizeof(char));

	node **max = (node **)malloc(7 * sizeof(node *));
	for(int i = 0; i < 7; i++)
		max[i] = root->child[l[i]] ? find_max(root->child[l[i]], l, 6, 0, l[i]) : NULL;
	free(l);

	node *wmax = NULL;
	for(int i = 0; i < 7; i++)
		wmax = !wmax || wmax->score < max[i]->score ? max[i] : wmax;

	node *p;
	for(int i = 0; wmax; i++)
	{
		p = wmax->parent;
		int j = 0;
		for(; p && p->child[j] != wmax; j++);
		word[i] = p ? (char)(j+97) : '\0';
		wmax = p;
	}

	ft_strrev(word);

	return word;
}

void print_tree(node *root, char l)
{
	printf()
	for(int i = 0; i < 26; i++)
	{
		if(root->child[i])
			print_tree(root->child[i]);
	}
}
