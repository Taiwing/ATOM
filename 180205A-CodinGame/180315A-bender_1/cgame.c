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

typedef struct elem
{
	char move;
	int pos[2];
	struct elem *next;
} elem;

typedef struct list
{
	elem *first;
	int **bm; /*is gonna store the number of times bender walked on an area of the map*/
}	list;

robot *init_robot(int *start);
int *get_start(char **map, int L, int C);
void inverter(char prio[4]);
int **get_tp(char **map, int L, int C);
void teleporter(int pos[2], int **tp);
char try_move(char dir, int pos[2], int breaker, char **map);
int move(robot *bender, char dir, char **map, int **tp);
list *init_list(int L, int C);
void add_move(char dir, int pos[2], list *moves);
void print_moves(list *moves);
int loop(list *moves, int x, int y);

int main()
{
  int L;
  int C;
  scanf("%d%d", &L, &C); fgetc(stdin);
	char **map = (char **)malloc(L * sizeof(char *));
	for(int i = 0; i < L; i++)
	{
		char row[102];
		fgets(row, 102, stdin);
		map[i] = (char *)malloc(C * sizeof(char));
		for(int j = 0; j < C; j++)
			map[i][j] = row[j];
	}

	robot *bender = init_robot(get_start(map, L, C));
	list *moves = init_list(L, C);
	int **tp = get_tp(map, L, C);
	int end = 0;

	while(!end)
	{
		char dir = '\0';
		if(bender->dir)
			dir = try_move(bender->dir, bender->pos, bender->breaker, map);
		for(int i = 0; i < 4 && !dir; i++)
			dir = try_move(bender->prio[i], bender->pos, bender->breaker, map);
		bender->dir = dir;
		if(dir)
		{
			add_move(dir, bender->pos, moves);
			end = move(bender, dir, map, tp);
			if(end)
				print_moves(moves);
		}

		if(!dir || loop(moves, bender->pos[X], bender->pos[Y]))
		{
			printf("LOOP\n");
			end = 1;
		}
	}

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

void teleporter(int pos[2], int **tp)
{
	for(int i = 0; i < 2; i++)
		if(pos[X] == tp[i][X] && pos[Y] == tp[i][Y])
		{
			pos[X] = tp[!i][X];
			pos[Y] = tp[!i][Y];
			break;
		}
}

char try_move(char dir, int pos[2], int breaker, char **map)
{
	char ret;
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
		case '#': ret = '\0';
			break;
		case 'X':
			if(breaker)
			{
				ret = dir;
				map[y][x] = ' ';
			}
			else
				ret = '\0';
			break;
		default: ret = dir;
			break;
	}

	return ret;
}

int move(robot *bender, char dir, char **map, int **tp)
{
	int end = 0;

	switch(dir)
	{
		case 'S': (bender->pos[Y])++;
			break;
		case 'E': (bender->pos[X])++;
			break;
		case 'N': (bender->pos[Y])--;
			break;
		case 'W': (bender->pos[X])--;
			break;
	}

	switch(map[bender->pos[Y]][bender->pos[X]])
	{
		case '$': end = 1;
			break;
		case 'S': bender->dir = 'S';
			break;
		case 'E': bender->dir = 'E';
			break;
		case 'N': bender->dir = 'N';
			break;
		case 'W': bender->dir = 'W';
			break;
		case 'B':	bender->breaker = bender->breaker ? 0 : 1;
			break;
		case 'I': inverter(bender->prio);
			break;
		case 'T': teleporter(bender->pos, tp);
			break;
	}

	return end;
}

list *init_list(int L, int C)
{
	list *moves = (list *)malloc(sizeof(list));
	moves->first = NULL;
	moves->bm = (int **)malloc(L * sizeof(int *));
	for(int i = 0; i < L; i++)
	{
		moves->bm[i] = (int *)malloc(C * sizeof(int));
		for(int j = 0; j < C; j++)
			moves->bm[i][j] = 0;
	}
	return moves;
}

void add_move(char dir, int pos[2], list *moves)
{
	elem *ptr = moves->first;

	if(!ptr)
	{
		moves->first = (elem *)malloc(sizeof(elem));
		moves->first->move = dir;
		moves->first->pos[X] = pos[X];
		moves->first->pos[Y] = pos[Y];
		moves->first->next = NULL;
	}
	else
	{
		while(ptr->next)
			ptr = ptr->next;
		ptr->next = (elem *)malloc(sizeof(elem));
		ptr->next->move = dir;
		ptr->next->pos[X] = pos[X];
		ptr->next->pos[Y] = pos[Y];
		ptr->next->next = NULL;
	}

	moves->bm[pos[Y]][pos[X]]++;
}

void print_moves(list *moves)
{
	elem *ptr = moves->first;
	while(ptr)
	{
		switch(ptr->move)
		{
			case 'S': printf("SOUTH\n");
				break;
			case 'E': printf("EAST\n");
				break;
			case 'N': printf("NORTH\n");
				break;
			case 'W': printf("WEST\n");
				break;
		}
		ptr = ptr->next;
	}
}

int loop(list *moves, int x, int y)
{
	int ret = 0;
	int dir[4] = {0};
	elem *ptr = moves->first;
	if(moves->bm[y][x] > 5)
	{
		while(ptr && !ret)
		{
			if(ptr->pos[X] == x && ptr->pos[Y] == y)
			{
				switch(ptr->move)
				{
					case 'S': (dir[0])++;
						break;
					case 'E': (dir[1])++;
						break;
					case 'N': (dir[2])++;
						break;
					case 'W': (dir[3])++;
						break;
				}
				for(int i = 0; i < 4; i++)
					if(dir[i] > 5)
						ret = 1;
			}
			ptr = ptr->next;
		}
	}
	return ret;
}
