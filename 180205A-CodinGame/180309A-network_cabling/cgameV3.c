#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

int QuickSelect(int *A, int n, int k);
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
  int *Ymap = (int *)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++)
    Ymap[i] = map[i][1];

  int med;
  if(N%2)
    med = QuickSelect(Ymap, N, N/2);
  else
  {
    int *Ymap2 = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
      Ymap2[i] = Ymap[i];
    med = (QuickSelect(Ymap, N, (N/2)) + QuickSelect(Ymap2, N, (N/2)-1))/2;
  }

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

int QuickSelect(int *A, int n, int k)
{
  /*let r be chosen uniformly at random in the range 0 to length(A)*/
  int r = rand() % n;
  int pivot = A[r];
  /*let A1, A2 be new arrays*/
  int *A1 = (int *)malloc((n-1) * sizeof(int));
  int *A2 = (int *)malloc((n-1) * sizeof(int));
  int n1 = 0, n2 = 0, n3 = 0;

  /*split into a pile A1 of small elements and A2 of big elements*/
  for(int i = 0; i < n; i++)
  {
    if(A[i] < pivot)
    {
      A1[n1] = A[i];
      n1++;
    }
    else if(A[i] > pivot)
    {
      A2[n2] = A[i];
      n2++;
    }
    else
      n3++;
  }

    /*TEST*/
    printf("\nQS():\n");
    printf("A =");
    for(int i = 0; i < n; i++)
      printf(" %d", A[i]);
    printf("\nn = %d\nk = %d\nr = %d\npivot = %d\n", n, k, r, pivot);
    printf("A1 =");
    for(int i = 0; i < n1; i++)
      printf(" %d", A1[i]);
    if(!n1) printf("@");
    printf("\nn1 = %d\n", n1);
    printf("A2 =");
    for(int i = 0; i < n2; i++)
      printf(" %d", A2[i]);
    if(!n2) printf("@");
    printf("\nn2 = %d\n", n2);
    printf("n3 = %d\n", n3);
    if(k < n1) printf("\nk < n1 = %d < %d\n", k, n1);
    else if(k >= n1+n3)
    {
      printf("\nk >= n1+n3 = %d >= %d\n", k, n1+n3);
      printf("k - (n1+n3) = %d - (%d+%d) = %d - %d = %d\n", k, n1, n3, k, n1+n3, k-(n1+n3));
    }
    else printf("return pivot = %d\n", pivot);

  free(A);

  if(k < n1) /*if it's in the pile of small elements*/
  {
    free(A2);
    return QuickSelect(A1, n1, k);
  }
  else if(k >= n1+n3) /*if it's in the pile of big elements*/
  {
    free(A1);
    return QuickSelect(A2, n2, k - (n1+n3));
  }
  else
  {
    free(A1);
    free(A2);
    return pivot;
  }
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
