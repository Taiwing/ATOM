#include "ft_takes_place.h"

void ft_takes_place(int hour)
{
  int hour2;
  char ap[2];

  ap[0] = hour > 11 ? 'P' : 'A';
  if(hour == 11 || hour == 23)
    ap[1] = ap[0] == 'P' ? 'A' : 'P';
  else
    ap[1] = ap[0];
  hour = hour > 12 ? hour-12 : hour;
  hour = hour == 0 ? 12 : hour;
  hour2 = hour == 12 ? 1 : hour+1;

  printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %c.M. AND %d.00 %c.M.\n", hour, ap[0], hour2, ap[1]);
}
