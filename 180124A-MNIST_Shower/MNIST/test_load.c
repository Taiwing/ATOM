#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "libft/libft.h"

void al_load_MNIST_image(int index);
void show_MNIST_labels(int *index);

int main(int argc, char *argv[])
{
  if(argc > 2 || (argc == 2  && (!ft_str_is_numeric(argv[1]) || ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 9999)))
  {
    ft_putstr("Error: wrong arguments\n");
    return -1;
  }

  int index;

  if(argc == 2)
  {
    index = ft_atoi(argv[1]);
    show_MNIST_labels(&index);
  }
  else
    show_MNIST_labels(NULL);


  return 0;
}

void show_MNIST_labels(int *index)
{
  int magic;
  int items;
  unsigned char buffer[4];
  unsigned char lab;

  FILE *labels = fopen("t10k-labels.idx1-ubyte", "rb");
  fread(buffer, sizeof(int), 1, labels);
  magic = (int)buffer[3] | (int)buffer[2]<<8 | (int)buffer[1]<<16 | (int)buffer[0]<<24; /*reverse int because of cpu bullshit*/
  printf("magic number: %d\n", magic);
  fread(buffer, sizeof(int), 1, labels);
  items = (int)buffer[3] | (int)buffer[2]<<8 | (int)buffer[1]<<16 | (int)buffer[0]<<24; /*reverse int because of cpu bullshit*/
  printf("numer of items: %d\n", items);
  if(!index)
  {
    for(int i = 0; i < items/4; i++)
    {
      fread(buffer, sizeof(int), 1, labels);
      for(int j = 0; j < 4; j++)
        printf("label %d: %d\n", (i*4)+j, buffer[j]);
    }
  }
  else
  {
    for(int i = 0; i < (*index)+1; i++)
      fread(&lab, 1, 1, labels);
    printf("label %d: %d\n", *index, lab);
  }
}
