#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};

int surf_H(int x, int **surface); /*gets the height Y of the ground at X*/
int **create_map(int **surface, int N); /*maps mars*/
void find_lz(int lz[2], int **surface, int N); /*defines the landing zone coordinates*/
int *find_path(int **surface, int N, int posX, int posY, int lpoint); /*finds the shortest path to the landing_zone*/

int main()
{
	int N; /*the number of points used to draw the surface of Mars.*/
	scanf("%d", &N);
	int **surface = (int **)malloc(N * sizeof(int *));
	for(int i = 0; i < N; i++)
	{
		surface[i] = (int *)malloc(2 * sizeof(int));
		scanf("%d%d", &(surface[i][X]), &(surface[i][Y]));
	}

	int **map = create_map(surface, N);
	int *path = NULL; /*stores the shortest path to the landing zone*/
	int f_data[7]; /*flight_data containing all the parameters needed*/
	int lz[2]; /*index of the points corresponding to the flat zone of at least 1000m in the surface array*/
	int rot = 0; /*rotation*/
	int power = 0; /*desired power output*/
	find_lz(lz, surface, N);
	int lpoint = (lz[0] + lz[1]) / 2;

	/*game loop*/
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		path = !path ? find_path(surface, N, f_data[X], f_data[Y], lpoint) : path;

		printf("%d %d\n", rot, power);
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

int **create_map(int **surface, int N)
{
	int grY;
	int **map = (int **)malloc(7000 * sizeof(int *));
	for(int i = 0; i < 7000; i++)
	{
		map[i] = (int *)malloc(3000 * sizeof(int));
		grY = surf_H(i, surface);
		for(int j = 0; j < 3000; j++)
			map[i][j] = j < grY ? 0 : 1;
	}
	return map;
}

void find_lz(int lz[2], int **surface, int N)
{
	for(int i = 1; i < N; i++)
	{
		if(surface[i-1][Y] == surface[i][Y] && (surface[i][X] - surface[i-1][X]) >= 1000)
		{
			lz[0] = i-1;
			lz[1] = i;
			break;
		}
	}
}

int *find_path(int **surface, int N, int posX, int posY, int lpoint)
{
	int *path = (int *)malloc(7000 * sizeof(int));
	for(int i = 0; i < 7000; i++)
		path[i] = -1;
	path[lpoint] = surf_H(lpoint, surface); /*arrival*/
	path[posX] = posY; /*starting point*/
	for(int i = posX; i != lpoint; i+= posX > lpoint ? -1 : 1)
	{
		int H = surf_H(i, surface);
		//path[i] = H >= path[i] NOT FINISHED
	}
	return path;
}
