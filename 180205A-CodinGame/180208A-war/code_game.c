#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum battle {PAT, ONE, TWO};
enum values {C2 = 2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK, CA};

typedef struct card
{
  char *value;
  int owner;
  struct card *next;
} card;

typedef struct stack
{
  int size;
  card *first;
} stack;

stack *init_stack(int size, card *first);
card *create_card(char *value);
void add_card(stack *st, card *ca, int owner);
card *get_top_card(stack *st);
int battle(stack *deck1, stack *deck2);
int get_value(card *ca);
void add_battle_stack(stack *battle_stack, stack *deckW, int wp);
int war(stack *battle_stack, stack *deck1, stack *deck2);
char *ft_strdup(const char *s);

int main()
{
  stack *deck1 = init_stack(0, NULL);
  stack *deck2 = init_stack(0, NULL);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    char cardp1[4];
    scanf("%s", cardp1);
    add_card(deck1, create_card(cardp1), ONE);
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    char cardp2[4];
    scanf("%s", cardp2);
    add_card(deck2, create_card(cardp2), TWO);
  }

  int bat;

  /*game loop*/
  for(int i = 1; (bat = battle(deck1, deck2)); i++)
  {
    if(deck1->size && !(deck2->size))
    {
      printf("%d %d\n", ONE, i);
      break;
    }
    else if(deck2->size && !(deck1->size))
    {
      printf("%d %d\n", TWO, i);
      break;
    }
  }

  if(!bat)
    printf("PAT\n");

  return 0;
}

stack *init_stack(int size, card *first)
{
  stack *st = (stack *)malloc(sizeof(stack));
  st->size = size;
  st->first = first;

  return st;
}

card *create_card(char *value)
{
  card *ca = (card *)malloc(sizeof(card));
  ca->value = ft_strdup(value);
  ca->next = NULL;

  return ca;
}

void add_card(stack *st, card *ca, int owner)
{
  ca->owner = owner;
  card *ptr = st->first;

  if(!ptr)
  {
    st->first = ca;
    ca->next = NULL;
  }
  else
  {
    while(ptr->next)
      ptr = ptr->next;
    ptr->next = ca;
    ca->next = NULL;
  }

  (st->size)++;
}

card *get_top_card(stack *st)
{
  card *ca = st->first;

  if(st->size > 0)
  {
    st->first = ca->next;
    (st->size)--;
  }

  return ca;
}

int battle(stack *deck1, stack *deck2)
{
  stack *battle_stack = init_stack(0, NULL);
  card *cap1 = get_top_card(deck1);
  card *cap2 = get_top_card(deck2);
  add_card(battle_stack, cap1, ONE);
  add_card(battle_stack, cap2, TWO);
  int p1 = get_value(cap1);
  int p2 = get_value(cap2);

  while(p1 == p2)
  {
    if(deck1->size && deck2->size && war(battle_stack, deck1, deck2))
    {
      cap1 = get_top_card(deck1);
      cap2 = get_top_card(deck2);
      add_card(battle_stack, cap1, ONE);
      add_card(battle_stack, cap2, TWO);
      p1 = get_value(cap1);
      p2 = get_value(cap2);
    }
    else
      return PAT;
  }

  if(p1 > p2)
  {
    add_battle_stack(battle_stack, deck1, ONE);
    return ONE;
  }
  else
  {
    add_battle_stack(battle_stack, deck2, TWO);
    return TWO;
  }
}

int get_value(card *ca)
{
  switch(ca->value[0])
  {
    case '2': return C2;
      break;
    case '3': return C3;
      break;
    case '4': return C4;
      break;
    case '5': return C5;
      break;
    case '6': return C6;
      break;
    case '7': return C7;
      break;
    case '8': return C8;
      break;
    case '9': return C9;
      break;
    case '1': return C10;
      break;
    case 'J': return CJ;
      break;
    case 'Q': return CQ;
      break;
    case 'K': return CK;
      break;
    case 'A': return CA;
      break;
    default:  return 0;
      break;
  }
}

void add_battle_stack(stack *battle_stack, stack *deckW, int wp)
{
  stack *st1 = init_stack(0, NULL);
  stack *st2 = init_stack(0, NULL);
  card *ca = NULL;

  while(battle_stack->size)
  {
    ca = get_top_card(battle_stack);
    if(ca->owner == ONE)
      add_card(st1, ca, wp);
    else if(ca->owner == TWO)
      add_card(st2, ca, wp);
  }
  free(battle_stack);

  while(st1->size)
    add_card(deckW, get_top_card(st1), wp);
  free(st1);
  while(st2->size)
    add_card(deckW, get_top_card(st2), wp);
  free(st2);
}

int war(stack *battle_stack, stack *deck1, stack *deck2)
{
  for(int i = 0; i < 3; i++)
  {
    add_card(battle_stack, get_top_card(deck1), ONE);
    add_card(battle_stack, get_top_card(deck2), TWO);
    if(!(deck1->size) || !(deck2->size))
      return 0;
  }

  return 1;
}

char *ft_strdup(const char *s)
{
  char *d = malloc(strlen(s) + 1);
  if(d == NULL)
    return NULL;
  strcpy(d, s);
  return d;
}
