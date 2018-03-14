#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  const char *orig_str = "im_gonna_plant";
  /*const char *buffer = malloc(sizeof(orig_str));

  for(int i = 0; 1; i++)
  {
    buffer[i] = orig_str[i];
    if(!buffer[i]) break;
  }*/

  char *new_str = malloc(sizeof(orig_str));

  int i = 0;

  while(1)
  {
    new_str[i] = orig_str[i];
    if(!new_str[i]) break;
    i++;
  }


  free((char *)orig_str);
  printf("%s\n", new_str);

  return 0;
}
