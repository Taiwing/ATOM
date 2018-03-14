#include "alloc_2D_array.h"

char **alloc_2D_array(int w, int h)
{
  int i;
  char** words;
  words = malloc(w * sizeof(char*));

  if(words == NULL)
  {
    printf("ERROR: out of memory\n");
  }

  i = 0;

  while(i < w)
  {
    words[i] = malloc(h * sizeof(char));

    if(words[i] == NULL)
      exit(EXIT_FAILURE);

    i++;
  }

  return words;
}
