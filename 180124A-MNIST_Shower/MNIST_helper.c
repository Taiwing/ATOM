#include "MNIST_helper.h"

void load_MNIST_bitmap(ALLEGRO_BITMAP **handy_number, int index, int test)
{
  unsigned char map[28][28];

  if((*handy_number))
    al_destroy_bitmap(*handy_number);
  *handy_number = al_create_bitmap(28, 28);
  load_MNIST_data(index, map, test);
  al_lock_bitmap(*handy_number, al_get_bitmap_format(*handy_number), ALLEGRO_LOCK_WRITEONLY);
  al_set_target_bitmap(*handy_number);
  for(int i = 0; i < 28; i++)
    for(int j = 0; j < 28; j++)
      al_put_pixel(j, i, al_map_rgb(255-map[i][j], 255-map[i][j], 255-map[i][j])); /*map[y][x]*/
  al_unlock_bitmap(*handy_number);
}

void load_MNIST_data(int index, unsigned char map[28][28], int test)
{
  FILE *images;
  if(test)
    images = fopen("MNIST/t10k-images.idx3-ubyte", "rb");
  else
    images = fopen("MNIST/train-images.idx3-ubyte", "rb");
  fseek(images, 16+(index * (28*28)), SEEK_SET);
  fread(map, 28, 28, images);
  fclose(images);
}

void show_MNIST_labels(int *index, int test)
{
  int magic;
  int items;
  unsigned char buffer[4];
  unsigned char lab;
  FILE *labels;

  if(test)
    labels = fopen("MNIST/t10k-labels.idx1-ubyte", "rb");
  else
    labels = fopen("MNIST/train-labels.idx1-ubyte", "rb");
  fread(buffer, sizeof(int), 2, labels);
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
    fseek(labels, 8+(*index), SEEK_SET);
    fread(&lab, 1, 1, labels);
    printf("label %d: %d\n", *index, lab);
  }

  fclose(labels);
}
