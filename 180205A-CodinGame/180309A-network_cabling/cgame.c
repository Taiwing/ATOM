#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

void sort(int **map, int N);  /*sorts the points in increasing order or Y and X values (in that order)*/
int median(int **map, int N); /*get the median of the Y distribution*/
int min_X(int **map, int N);  /*gets the leftest point of the map*/
int max_X(int **map, int N);  /*gets the rightest point of the map*/

int main()
{
  srand(time(NULL)); /*for the QuickSelect function*/

  int N;
  scanf("%d", &N);
  int **map = (int **)malloc(N * sizeof(int *));
  for(int i = 0; i < N; i++)
    map[i] = (int *)malloc(2 * sizeof(int));
  for(int i = 0; i < N; i++)
  {
    int X;
    int Y;
    scanf("%d%d", &X, &Y);
    map[i][0] = X;
    map[i][1] = Y;
  }

  /*first calculate the median of the Y values*/
  sort(map, N);
  int med = median(map, N);

    /*TEST*/
    /*printf("\nmap:\n");
    for(int i = 0; i < N; i++)
      printf("%d %d\n", map[i][0], map[i][1]);*/
    printf("\nmed = %d\n", med);

  /*then the distance between the two points of the median segment*/
  int minX, maxX, medl;
  minX = min_X(map, N);
  maxX = max_X(map, N);
  medl = abs(maxX-minX);

    /*TEST*/
    printf("\nminX = %d\nmaxX = %d\n", minX, maxX);
    printf("med_length = %d\n", medl);

  /*then from the houses to the median*/
  long long int total = medl;

    /*TEST*/
    printf("\nconnexions:\n");

  for(int i = 0; i < N; i++)
  {
    total += abs(map[i][1] - med);
      /*TEST*/
      printf("map[%d][1] - med = abs(%d - %d) = %d\n", i, map[i][1], med, abs(map[i][1] - med));
  }

    /*TEST*/
    printf("\ntotal = %lli\n", total);

  /*then add what must be added if some houses of equal X values are on the same side*/
  /*of the median line (meaning they are on top of one and other)*/
  /*which means keeping track of the number of "used conexions"*/
  /*(X values that are already occupied by a connexion or a house)*/

  // Write an action using printf(). DON'T FORGET THE TRAILING \n
  // To debug: fprintf(stderr, "Debug messages...\n");

  //printf("answer\n");

  return 0;
}

void sort(int **map, int N)
{
  int tmp;

  for(int i = 0; i < N-1; i++)
    for(int j = i+1; j < N; j++)
      if(map[j][1] < map[i][1] || (map[j][1] == map[i][1] && map[j][0] < map[i][0]))
        for(int k = 0; k < 2; k++)
        {
          tmp = map[j][k];
          map[j][k] = map[i][k];
          map[i][k] = tmp;
        }
}

int median(int **map, int N)
{
  return (N % 2 ? map[N/2][1] : (map[N/2-1][1] + map[N/2][1]) / 2);
}

int min_X(int **map, int N)
{
  int minX;

  for(int i = 0; i < N; i++)
    minX = !i || map[i][0] < minX ? map[i][0] : minX;

  return minX;
}

int max_X(int **map, int N)
{
  int maxX;

  for(int i = 0; i < N; i++)
    maxX = !i || map[i][0] > maxX ? map[i][0] : maxX;

  return maxX;
}
