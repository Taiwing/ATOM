#include "data_helper.h"

void get_data(char *name, data_set **training_data, data_set **test_data, int train_s, int test_s)
{
  if(!ft_strcmp(name, "handy") || !ft_strcmp(name, "handy_s") || !ft_strcmp(name, "handy_s-9456") || !ft_strcmp(name, "handy_s-9416") || !ft_strcmp(name, "new_handy_s"))
    get_MNIST_data_set(training_data, test_data);
  else if(!ft_strcmp(name, "424"))
    get_424_data_set(training_data, test_data, train_s, test_s);
  else if(!ft_strcmp(name, "16N3") || !ft_strcmp(name, "16N3_s"))
    get_16N3_data_set(training_data, test_data, train_s, test_s);
  else if(!ft_strcmp(name, "16N3C") || !ft_strcmp(name, "16N3C_s"))
    get_16N3C_data_set(training_data, test_data, train_s, test_s);
}

void get_424_data_set(data_set **training, data_set **test, int train_s, int test_s)
{
  srand(time(NULL));

  int found;

  *training = (data_set *)malloc(sizeof(data_set));
  (*training)->data = (double **)malloc(train_s * sizeof(double *));
  (*training)->expout = (double **)malloc(train_s * sizeof(double *));
  for(int i = 0; i < train_s; i++)
  {
    (*training)->data[i] = (double *)malloc(4 * sizeof(double));
    found = 0;
    for(int j = 0; j < 4; j++)
    {
      if(!found && j < 3)
        (*training)->data[i][j] = rand()%2;
      else if(!found && j == 3)
        (*training)->data[i][j] = 1;
      found = (*training)->data[i][j] == 1 ? 1 : found;
    }
    (*training)->expout[i] = (double *)malloc(4 * sizeof(double));
    for(int j = 0; j < 4; j++)
      (*training)->expout[i][j] = (*training)->data[i][j];
  }
  (*training)->set_size = train_s;
  (*training)->I_size = 4;
  (*training)->O_size = 4;

  *test = (data_set *)malloc(sizeof(data_set));
  (*test)->data = (double **)malloc(test_s * sizeof(double *));
  (*test)->expout = (double **)malloc(test_s * sizeof(double *));
  for(int i = 0; i < test_s; i++)
  {
    (*test)->data[i] = (double *)malloc(4 * sizeof(double));
    found = 0;
    for(int j = 0; j < 4; j++)
    {
      if(!found && j < 3)
        (*test)->data[i][j] = rand()%2;
      else if(!found && j == 3)
        (*test)->data[i][j] = 1;
      found = (*test)->data[i][j] == 1 ? 1 : found;
    }
    (*test)->expout[i] = (double *)malloc(4 * sizeof(double));
    for(int j = 0; j < 4; j++)
      (*test)->expout[i][j] = (*test)->data[i][j];
  }
  (*test)->set_size = test_s;
  (*test)->I_size = 4;
  (*test)->O_size = 4;
}

void get_16N3_data_set(data_set **training, data_set **test, int train_s, int test_s)
{
  srand(time(NULL));
  int val;

  *training = (data_set *)malloc(sizeof(data_set));
  (*training)->data = (double **)malloc(train_s * sizeof(double *));
  (*training)->expout = (double **)malloc(train_s * sizeof(double *));
  for(int i = 0; i < train_s; i++)
  {
    (*training)->data[i] = (double *)malloc(16 * sizeof(double));
    val = rand()%8;
    switch(val)
    {
      case 0: for(int j = 0; j < 16; j++) (*training)->data[i][j] = !(j%5) ? 1 : 0;
        break;
      case 1: for(int j = 0; j < 16; j++) (*training)->data[i][j] = !(j%3) && j!=0 && j!=15 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j>7 && j<12 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==2 || j==6 || j==10 || j==14 ? 1 : 0;
        break;
      case 4: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==1 || j==9 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==5 || j==6 || j==9 || j==10 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 16; j++) (*training)->data[i][j] = 1;
        break;
      case 7: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==1 || j==3 || j==5 || j==7 ? 1 : 0;
        break;
    }
    (*training)->expout[i] = (double *)malloc(3 * sizeof(double));
    switch(val)
    {
      case 0: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = 0;
        break;
      case 1: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==2 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==1 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==0 ? 0 : 1;
        break;
      case 4: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==0 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==1 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==2 ? 0 : 1;
        break;
      case 7: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = 1;
        break;
    }
  }
  (*training)->set_size = train_s;
  (*training)->I_size = 16;
  (*training)->O_size = 3;

  *test = (data_set *)malloc(sizeof(data_set));
  (*test)->data = (double **)malloc(test_s * sizeof(double *));
  (*test)->expout = (double **)malloc(test_s * sizeof(double *));
  for(int i = 0; i < test_s; i++)
  {
    (*test)->data[i] = (double *)malloc(16 * sizeof(double));
    val = rand()%8;
    switch(val)
    {
      case 0: for(int j = 0; j < 16; j++) (*test)->data[i][j] = !(j%5) ? 1 : 0;
        break;
      case 1: for(int j = 0; j < 16; j++) (*test)->data[i][j] = !(j%3) && j!=0 && j!=15 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j>7 && j<12 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==2 || j==6 || j==10 || j==14 ? 1 : 0;
        break;
      case 4: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==1 || j==9 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==5 || j==6 || j==9 || j==10 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 16; j++) (*test)->data[i][j] = 1;
        break;
      case 7: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==1 || j==3 || j==5 || j==7 ? 1 : 0;
        break;
    }
    (*test)->expout[i] = (double *)malloc(3 * sizeof(double));
    switch(val)
    {
      case 0: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = 0;
        break;
      case 1: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==2 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==1 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==0 ? 0 : 1;
        break;
      case 4: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==0 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==1 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==2 ? 0 : 1;
        break;
      case 7: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = 1;
        break;
    }
  }
  (*test)->set_size = test_s;
  (*test)->I_size = 16;
  (*test)->O_size = 3;

  /*for(int i = 0; i < test_s; i++)
  {
    printf("input:\n");
    for(int j = 0; j < 16; j+=4)
      printf("%d%d%d%d\n", (int)(*test)->data[i][j], (int)(*test)->data[i][j+1], (int)(*test)->data[i][j+2], (int)(*test)->data[i][j+3]);
    printf("expout: %d%d%d\n", (int)(*test)->expout[i][0], (int)(*test)->expout[i][1], (int)(*test)->expout[i][2]);
  }*/
}

void get_16N3C_data_set(data_set **training, data_set **test, int train_s, int test_s)
{
  srand(time(NULL));
  int val;
  int C;

  *training = (data_set *)malloc(sizeof(data_set));
  (*training)->data = (double **)malloc(train_s * sizeof(double *));
  (*training)->expout = (double **)malloc(train_s * sizeof(double *));
  for(int i = 0; i < train_s; i++)
  {
    (*training)->data[i] = (double *)malloc(16 * sizeof(double));
    val = rand()%8;
    switch(val)
    {
      case 0: for(int j = 0; j < 16; j++) (*training)->data[i][j] = !(j%5) ? 1 : 0;
        break;
      case 1: for(int j = 0; j < 16; j++) (*training)->data[i][j] = !(j%3) && j!=0 && j!=15 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j>7 && j<12 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==2 || j==6 || j==10 || j==14 ? 1 : 0;
        break;
      case 4: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==1 || j==9 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==5 || j==6 || j==9 || j==10 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 16; j++) (*training)->data[i][j] = 1;
        break;
      case 7: for(int j = 0; j < 16; j++) (*training)->data[i][j] = j==1 || j==3 || j==5 || j==7 ? 1 : 0;
        break;
    }
    C = rand()%16;
    (*training)->data[i][C] = (*training)->data[i][C] == 1 ? 0 : 1;
    (*training)->expout[i] = (double *)malloc(3 * sizeof(double));
    switch(val)
    {
      case 0: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = 0;
        break;
      case 1: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==2 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==1 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==0 ? 0 : 1;
        break;
      case 4: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==0 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==1 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = j==2 ? 0 : 1;
        break;
      case 7: for(int j = 0; j < 3; j++) (*training)->expout[i][j] = 1;
        break;
    }
  }
  (*training)->set_size = train_s;
  (*training)->I_size = 16;
  (*training)->O_size = 3;

  *test = (data_set *)malloc(sizeof(data_set));
  (*test)->data = (double **)malloc(test_s * sizeof(double *));
  (*test)->expout = (double **)malloc(test_s * sizeof(double *));
  for(int i = 0; i < test_s; i++)
  {
    (*test)->data[i] = (double *)malloc(16 * sizeof(double));
    val = rand()%8;
    switch(val)
    {
      case 0: for(int j = 0; j < 16; j++) (*test)->data[i][j] = !(j%5) ? 1 : 0;
        break;
      case 1: for(int j = 0; j < 16; j++) (*test)->data[i][j] = !(j%3) && j!=0 && j!=15 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j>7 && j<12 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==2 || j==6 || j==10 || j==14 ? 1 : 0;
        break;
      case 4: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==1 || j==9 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==5 || j==6 || j==9 || j==10 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 16; j++) (*test)->data[i][j] = 1;
        break;
      case 7: for(int j = 0; j < 16; j++) (*test)->data[i][j] = j==1 || j==3 || j==5 || j==7 ? 1 : 0;
        break;
    }
    C = rand()%16;
    (*test)->data[i][C] = (*test)->data[i][C] == 1 ? 0 : 1;
    (*test)->expout[i] = (double *)malloc(3 * sizeof(double));
    switch(val)
    {
      case 0: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = 0;
        break;
      case 1: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==2 ? 1 : 0;
        break;
      case 2: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==1 ? 1 : 0;
        break;
      case 3: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==0 ? 0 : 1;
        break;
      case 4: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==0 ? 1 : 0;
        break;
      case 5: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==1 ? 0 : 1;
        break;
      case 6: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = j==2 ? 0 : 1;
        break;
      case 7: for(int j = 0; j < 3; j++) (*test)->expout[i][j] = 1;
        break;
    }
  }
  (*test)->set_size = test_s;
  (*test)->I_size = 16;
  (*test)->O_size = 3;

  /*for(int i = 0; i < test_s; i++)
  {
    printf("input:\n");
    for(int j = 0; j < 16; j+=4)
      printf("%d%d%d%d\n", (int)(*test)->data[i][j], (int)(*test)->data[i][j+1], (int)(*test)->data[i][j+2], (int)(*test)->data[i][j+3]);
    printf("expout: %d%d%d\n", (int)(*test)->expout[i][0], (int)(*test)->expout[i][1], (int)(*test)->expout[i][2]);
  }*/
}
