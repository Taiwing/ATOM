#include "ft_print_alphabet.h"

void ft_print_alphabet(void)
{
  char c;

  c = 97; /*letter a*/

  while(c < 123) /*while c != 'z'*/
  {
    printf("%c", c); /*prints the current character*/
    c++; /*character incrementation*/
  }

  printf("\n");
}
