#include "ft_print_reverse_alphabet.h"

void ft_print_reverse_alphabet(void)
{
  char c;

  c = 122; /*letter z*/

  while(c > 96) /*until c == 'a'*/
  {
    printf("%c", c); /*prints the current character*/
    c--; /*character decrementation*/
  }

  printf("\n");
}
