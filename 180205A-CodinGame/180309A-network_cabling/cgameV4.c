#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

int QuickSelect(int *A, int n, int k); /*selects quickly the kth biggest element in A*/
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

  /*then the distance between the two points of the median segment*/
  int minX, maxX, medl;
  minX = min_X(map, N);
  maxX = max_X(map, N);
  medl = abs(maxX-minX);

  /*then from the houses to the median*/
  long long int total = medl;

  for(int i = 0; i < N; i++)
    total += abs(map[i][1] - med);

  printf("%lli\n", total);

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
