#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum posxy {Y, X};

typedef struct robot
{
	int pos[2];
	char dir;
	char prio[4];
	int breaker;
}	robot;

robot *init_robot(int *start);
int *get_start(char **map, int L, int C);
void inverter(char prio[4]);
int **get_tp(char **map, int L, int C);
void teleporter(int pos[2], int **tp);
char try_move(char dir, int pos[2], int breaker, char **map);
int move(robot *bender, char dir, char **map, int tp[2][2]);

int main()
{
  int L;
  int C;
  scanf("%d%d", &L, &C); fgetc(stdin);
	char **map = (char **)malloc(L * sizeof(char *));
	for(int i = 0; i < L; i++)
	{
		map[i] = (char *)malloc(C * sizeof(char));
		fgets(map[i], C, stdin);
	}

	robot *bender = init_robot(get_start(map, L, C));
	int **tp = get_tp(map, L, C);
	int end = 0;

	while(!end)
	{
		char dir = '\0';
		if(bender->dir)
		{
			dir = try_move(bender->dir, bender->pos, bender->breaker, map);
			if(!dir) bender->dir = '\0';
		}
		for(int i = 0; i < 4 && !dir; i++)
			dir = try_move(bender->prio[i], bender->pos, bender->breaker, map);

		if(dir)
		{
			end = move(bender, dir, map, tp);
			//add_dir(dir, moves); /*chained list of every moves done*/
		}
		else
			printf("LOOP\n");
	}

  printf("answer\n");

  return 0;
}

robot *init_robot(int *start)
{
	robot *bender = (robot *)malloc(sizeof(robot));
	bender->pos[X] = start[X];
	bender->pos[Y] = start[Y];
	bender->dir = '\0';
	bender->prio[0] = 'S';
	bender->prio[1] = 'E';
	bender->prio[2] = 'N';
	bender->prio[3] = 'W';
	free(start);
	return bender;
}

int *get_start(char **map, int L, int C)
{
	int *start = (int *)malloc(2 * sizeof(int));
	int out = 0;
	for(int i = 0; i < L && !out; i++)
		for(int j = 0; j < C && !out; j++)
			if(map[i][j] == '@')
			{
				start[Y] = i;
				start[X] = j;
				out = 1;
			}
	return start;
}

void inverter(char prio[4])
{
	char tmp;
	tmp = prio[0];
	prio[0] = prio[3];
	prio[3]	= tmp;
	tmp = prio[1];
	prio[1] = prio[2];
	prio[2] = tmp;
}

int **get_tp(char **map, int L, int C)
{
	int **tp = NULL;
	int l = 0;
	for(int i = 0; i < L && l < 2; i++)
		for(int j = 0; j < C && l < 2; j++)
			if(map[i][j] == 'T')
			{
				if(!tp)
				{
					tp = (int **)malloc(2 * sizeof(int *));
					for(int k = 0; k < 2; k++)
						tp[k] = (int *)malloc(2 * sizeof(int));
				}
				tp[l][Y] = i;
				tp[l][X] = j;
				l++;
			}
	return tp;
}

char try_move(char dir, int pos[2], int breaker, char **map)
{
	char ret = '\0';
	int x,y;

	switch(dir)
	{
		case 'S': x = pos[X]; y = pos[Y]+1;
			break;
		case 'E': x = pos[X]+1; y = pos[Y];
			break;
		case 'N': x = pos[X]; y = pos[Y]-1;
			break;
		case 'W': x = pos[X]-1; y = pos[Y];
			break;
	}

	switch(map[y][x])
	{
		case '#':
			break;
		case 'X': ret = breaker ? dir : ret;
			break;
		default: ret = dir;
			break;
	}

	return ret;
}

int move(robot *bender, char dir, char **map, int tp[2][2])
{
	int end = 0;

	

	return end;
}
