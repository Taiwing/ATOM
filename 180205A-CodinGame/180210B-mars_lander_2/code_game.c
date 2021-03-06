#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power};

int surf_H(int x, int **surface); //gets the height of the surface at the point x
int obstacle(int shuttle_x, int shuttle_y, int **surface, int target[2], char dir); /*REDUCE EXEC TIME*/
int rotate(int shuttle_x, int shuttle_y, int ob_x, int ob_y);

int main()
{
  int N; //the number of points used to draw the surface of Mars.
  scanf("%d", &N);
  int **surface = (int **)malloc(N * sizeof(int *));
  for(int i = 0; i < N; i++)
  {
    surface[i] = (int *)malloc(2 * sizeof(int));
    scanf("%d%d", &(surface[i][X]), &(surface[i][Y]));
  }

  int f_data[7]; //flight_data containing all the parameters needed
  int landing_zone[2]; //X1 and X2 corresponding to the flat zone of at least 1000m
  int ob; //stores the nearest obstacle X
  int target[2]; //stores the highest point between the shuttle and the next obstacle or landing_zone
  int rot;

  for(int i = 1; i < N; i++) //defines the landing_zone
  {
    if(surface[i-1][Y] == surface[i][Y] && (surface[i][X] - surface[i-1][X]) >= 1000)
    {
      landing_zone[0] = surface[i-1][X];
      landing_zone[1] = surface[i][X];
      break;
    }
  }

  //game loop
  while(1)
  {
    scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power]);

    if(f_data[X] >= landing_zone[0]+10 && f_data[X] <= landing_zone[1]-10) //if the shuttle is above the landing_zone
    {
      //landing procedure
      if(f_data[vSpeed] < -39)
        printf("0 4\n");
      else
        printf("0 0\n");
    }
    else if(f_data[X] < landing_zone[0]+10) //if the landing_zone in on the right
    {
      ob = obstacle(f_data[X], f_data[Y], surface, landing_zone, 'r');
      if(ob == -1) //if the shuttle is above every point between the landing_zone and itself including the landing_zone
        printf("-89 4");
      else
      {
        while(ob != -1)
        {
          target[0] = ob;
          target[1] = ob;
          rot = rotate(f_data[X], f_data[Y], ob, surf_H(ob, surface)+10);
          //simulate trajectory at rot angle (eg: hypothenuse)
          /*TEST*/
          ob = -1;
        }
        printf("%d 4", rot);
      }
    }
    else if(f_data[X] > landing_zone[1]-10) //if the landing_zone in on the left
    {
      ob = obstacle(f_data[X], f_data[Y], surface, landing_zone, 'l');
      if(ob == -1) //if the shuttle is above every point between the landing_zone and itself including the landing_zone
        printf("89 4");
      else
      {
        while(ob != -1)
        {
          target[0] = ob;
          target[1] = ob;
          rot = rotate(f_data[X], f_data[Y], ob, surf_H(ob, surface)+10);
          //simulate trajectory at rot angle (eg: hypothenuse)
          /*TEST*/
          ob = -1;
        }
        printf("%d 4", rot);
      }
    }
  }

  return 0;
}

int surf_H(int x, int **surface)
{
  int y, i;

  for(i = 0; surface[i][X] < x; i++);

  if(surface[i][X] == x || surface[i][Y] == surface[i-1][Y])
    y = surface[i][Y];
  else
    y = surface[i-1][Y] + (((surface[i][Y] - surface[i-1][Y]) / (surface[i][X] - surface[i-1][X])) * (x - surface[i-1][X]));

  return y;
}

int obstacle(int shuttle_x, int shuttle_y, int **surface, int target[2], char dir) //returns the highest point between the shuttle and l_zone
{
  int max = -1;

  switch(dir)
  {
    case 'r':
      for(int i = shuttle_x; i <= target[0]; i++)
        max = surf_H(i, surface) > shuttle_y && (max == -1 || surf_H(i, surface) > surf_H(max, surface)) ? i : max;
      break;
    case 'l':
      for(int i = shuttle_x; i >= target[1]; i--)
        max = surf_H(i, surface) > shuttle_y && (max == -1 || surf_H(i, surface) > surf_H(max, surface)) ? i : max;
      break;
  }

  return max;
}

int rotate(int shuttle_x, int shuttle_y, int ob_x, int ob_y)
{
  double O = ob_y - shuttle_y;
  double A = shuttle_x - ob_x;
  return atan(O/A);
}
