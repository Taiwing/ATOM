#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elem
{
  int n;
  struct elem *next;
} elem;

typedef struct list
{
  int c;
  elem *first;
} list;

elem *create_elem(int n);
list *init_list(int R);
void digitify(list *ls);
void add_count(list *ls);
void print_list(list *ls);

int main()
{
  int R;
  scanf("%d", &R);
  int L;
  scanf("%d", &L);

  list *ls = init_list(R);


  for(int i = 1; i < L; i++)
  {
    //digitify(ls);
    add_count(ls);
  }

  print_list(ls);

  return 0;
}

elem *create_elem(int n)
{
  elem *new = (elem *)malloc(sizeof(elem));
  new->n = n;
  new->next = NULL;
  return new;
}


list *init_list(int R)
{
  list *ls = (list *)malloc(sizeof(list));
  ls->c = 1;
  ls->first = create_elem(R);
  return ls;
}

void digitify(list *ls)
{
  int val, n;
  elem *ptr = ls->first, *new, *next = ptr->next;

  while(ptr)
  {
    val = ptr->n;
    while(val > 9)
    {
      n = val % 10;
      val /= 10;
      new = create_elem(n);
      new->next = next;
      next = new;
      if(val < 10)
      {
        ptr->n = val;
        ptr->next = next;
      }
      (ls->c)++;
    }
    ptr = ptr->next;
  }
}

void add_count(list *ls)
{
  elem *ptr = ls->first, *tmp, *new, *prec = NULL;
  int val, c;

  while(ptr)
  {
    val = ptr->n;
    tmp = ptr;
    c = 0;
    while(tmp && tmp->n == val)
    {
      c++;
      tmp = tmp->next;
    }
    new = create_elem(c);
    if(ls->first == ptr)
      ls->first = new;
    else
      prec->next = new;
    for(int i = 0; i < c-1; i++)
    {
      tmp = ptr;
      ptr = ptr->next;
      free(tmp);
      (ls->c)--;
    }
    new->next = ptr;
    prec = ptr;
    ptr = ptr->next;
    (ls->c)++;
  }
}

void print_list(list *ls)
{
  elem *ptr = ls->first;

  while(1)
  {
    printf("%d", ptr->n);
    if(ptr->next)
      printf(" ");
    else
    {
      printf("\n");
      break;
    }
    ptr = ptr->next;
  }
}
