#include "MNIST_helper.h"

void get_MNIST_data_set(data_set **training, data_set **test) /*TODO: TEST WITH OTHER VALUES THAN 2550*/
{
  int label;
  unsigned char map[28][28];

  *training = (data_set *)malloc(sizeof(data_set));
  (*training)->data = (double **)malloc(60000 * sizeof(double *));
  (*training)->expout = (double **)malloc(60000 * sizeof(double *));
  for(int i = 0; i < 60000; i++)
  {
    (*training)->data[i] = (double *)malloc(784 * sizeof(double));
    load_MNIST_data(i, map, 0);
    for(int j = 0; j < 28; j++)
      for(int k = 0; k < 28; k++)
        (*training)->data[i][(j*28)+k] = (double)map[j][k] / 6000;
    (*training)->expout[i] = (double *)malloc(10 * sizeof(double));
    label = get_MNIST_label(i, 0);
    for(int j = 0; j < 10; j++)
      (*training)->expout[i][j] = j == label ? 1 : 0;
  }
  (*training)->set_size = 60000;
  (*training)->I_size = 784;
  (*training)->O_size = 10;

  *test = (data_set *)malloc(sizeof(data_set));
  (*test)->data = (double **)malloc(10000 * sizeof(double *));
  (*test)->expout = (double **)malloc(10000 * sizeof(double *));
  for(int i = 0; i < 10000; i++)
  {
    (*test)->data[i] = (double *)malloc(784 * sizeof(double));
    load_MNIST_data(i, map, 1);
    for(int j = 0; j < 28; j++)
      for(int k = 0; k < 28; k++)
        (*test)->data[i][(j*28)+k] = (double)map[j][k] / 6000;
    (*test)->expout[i] = (double *)malloc(10 * sizeof(double));
    label = get_MNIST_label(i, 1);
    for(int j = 0; j < 10; j++)
      (*test)->expout[i][j] = j == label ? 1 : 0;
  }
  (*test)->set_size = 10000;
  (*test)->I_size = 784;
  (*test)->O_size = 10;
}

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
  int items;
  unsigned char buffer[4];
  unsigned char lab;
  FILE *labels;

  if(test)
  {
    labels = fopen("MNIST/t10k-labels.idx1-ubyte", "rb");
    items = 10000;
  }
  else
  {
    labels = fopen("MNIST/train-labels.idx1-ubyte", "rb");
    items = 60000;
  }
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
    for(int i = 0; i < (*index)+1; i++)
      fread(&lab, 1, 1, labels);
    printf("label %d: %d\n", *index, lab);
  }

  fclose(labels);
}

int get_MNIST_label(int index, int test)
{
  unsigned char lab;
  FILE *labels;

  if(test)
    labels = fopen("MNIST/t10k-labels.idx1-ubyte", "rb");
  else
    labels = fopen("MNIST/train-labels.idx1-ubyte", "rb");
  fseek(labels, 8+index, SEEK_SET);
  fread(&lab, 1, 1, labels);
  fclose(labels);

  return (int)lab;
}
