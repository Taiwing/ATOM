#include "ft_print_numbers.h"

void ft_print_numbers(void)
{
  int num;

  num = 0;

  while(num < 10)
  {
    printf("%d", num); /*prints the current number*/
    num++; /*number incrementation*/
  }

  printf("\n");
}
