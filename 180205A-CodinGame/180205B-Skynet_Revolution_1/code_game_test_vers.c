#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int incomplete(int *exit_map, int N);
void map(int *exit_map, int N, int **link_arr, int L);
void find_path(int lnk[2], int *exit_map, int N, int **link_arr, int L);

int main()
{
  int N; // the total number of nodes in the level, including the gateways
  int L; // the number of links
  int E; // the number of exit gateways
  scanf("%d%d%d", &N, &L, &E);
  int **link_arr = (int **)malloc(L * sizeof(int *));
  for(int i = 0; i < L; i++)
  {
    link_arr[i] = (int *)malloc(2 * sizeof(int));
    int N1; // N1 and N2 defines a link between these nodes
    int N2;
    scanf("%d%d", &N1, &N2);
    link_arr[i][0] = N1;
    link_arr[i][1] = N2;
  }
  int *exit_arr = (int *)malloc(E * sizeof(int));
  for(int i = 0; i < E; i++)
  {
    int EI; // the index of a gateway node
    scanf("%d", &EI);
    exit_arr[i] = EI;
  }
  int *exit_map = (int *)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++) /*we start by indexing the exits*/
  {
    exit_map[i] = -1;
    for(int j = 0; j < E && exit_map[i] == -1; j++)
      exit_map[i] = exit_arr[j] == i ? 0 : exit_map[i];
  }

  map(exit_map, N, link_arr, L);
  int lnk[2];

  // game loop
  while (1)
  {
    int SI; // The index of the node on which the Skynet agent is positioned this turn
    scanf("%d", &SI);
    lnk[0] = SI;
    lnk[1] = SI;

    /*FIND THE SHORTEST PATH BETWEEN THE VIRUS AND AN EXIT*/
    find_path(lnk, exit_map, N, link_arr, L);

    /*THEN SEVER THE NEAREST LINK FROM THE NODE*/
    printf("%d %d\n", lnk[0], lnk[1]);
  }

  return 0;
}

int incomplete(int *exit_map, int N)
{
  int ret = 0;

  for(int i = 0; i < N && !ret; i++)
    ret = exit_map[i] == -1 ? 1 : ret;

  return ret;
}

void map(int *exit_map, int N, int **link_arr, int L)
{
  while(incomplete(exit_map, N)) /*then we start from the exits and fill exit_map while it is incomplete*/
  {
    for(int i = 0; i < N; i++)
    {
      if(exit_map[i] != -1)
      {
        for(int j = 0; j < L; j++)
        {
          if(link_arr[j][0] == i && exit_map[link_arr[j][1]] == -1)
            exit_map[link_arr[j][1]] = exit_map[i] + 1;
          else if(link_arr[j][1] == i && exit_map[link_arr[j][0]] == -1)
            exit_map[link_arr[j][0]] = exit_map[i] + 1;
        }
      }
    }
    printf("exit_map:");
    for(int i = 0; i < N; i++)
      printf(" %d", exit_map[i]);
    printf("\n");
    /*char bull;
    scanf("%c", &bull);*/
  }
}

void find_path(int lnk[2], int *exit_map, int N, int **link_arr, int L) /*DOESN'T WORK YET*/
{
  printf("\nLINKS:\n");
  while(lnk[0] == lnk[1]) /*while the link hasn't been found*/
  {
    for(int i = 0; i < L; i++) /*gets the node with the smallest exit_value (the closest from exit)*/
    {
      if(link_arr[i][0] == lnk[0])
       lnk[1] = lnk[0] == lnk[1] || exit_map[link_arr[i][1]] < exit_map[lnk[1]] ? link_arr[i][1] : lnk[1];
      else if(link_arr[i][1] == lnk[0])
       lnk[1] = lnk[0] == lnk[1] || exit_map[link_arr[i][0]] < exit_map[lnk[1]] ? link_arr[i][0] : lnk[1];
    }
    printf("%d %d\n", lnk[0], lnk[1]);
    lnk[0] = exit_map[lnk[1]] != 0 ? lnk[1] : lnk[0];
  }
  printf("END_LINKS\n\n");
}
