#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};

int surf_H(int x, int **surface); /*gets the height Y of the ground at X*/
int **create_map(int **surface, int N); /*maps mars*/
void find_lz(int lz[2], int **surface, int N); /*defines the landing zone coordinates*/
void find_path(int **surface, int *path, int st, int ar); /*calculates the path between two points*/
int *init_path(int **surface, int f_data[7], int lpoint); /*initializes and finds the shortest path to the landing_zone*/

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
	int lz[2]; /*index of the points corresponding to the flat zone of at least 1000m in the surface array*/
	find_lz(lz, surface, N);
	int lpoint = (surface[lz[0]][X] + surface[lz[1]][X]) / 2;
	int f_data[7]; /*flight_data containing all the parameters needed*/
	int rot = 0; /*rotation*/
	int power = 0; /*desired power output*/

	/*game loop*/
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		path = !path ? init_path(surface, f_data, lpoint) : path;

		printf("%d %d\n", rot, power);

			/*TEST*/
			break;
	}

	/*TEST*/
	printf("start:\nX: %d, Y: %d\n", f_data[X], f_data[Y]);
	printf("arrival:\nX: %d, Y: %d\n", lpoint, surface[lz[0]][Y]);
	printf("path:\n");
	for(int i = 0; i < 7000; i++)
		if(path[i] != -1)
			printf("X: %d, Y: %d\n", i, path[i]);

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

void find_path(int **surface, int *path, int st, int ar)
{
	double th = (double)path[st]; /*theoretical height*/
	double step = (double)(path[ar]-path[st])/(double)(abs(st-ar)); /*vertical movement at every X point*/

	/*first get every surface points between st and ar*/ /*get the index of the first surface val after st and the last after ar*/
	int pk[2] = {-1}; /*pikes at both ends of the trajectory*/
	for(int i = 0; surface[i][X] < 6999; i++)
	{
		pk[0] = pk[0] == -1 && surface[i][X] > st ? i : pk[0];
		pk[1] = pk[1] == -1 && surface[i][X] > ar ? i : pk[1];
		for(int j = 0; j < 2 && st >= ar; j++) pk[j] = pk[j] != -1 ? pk[j]-1 : pk[j];
	}

	/*then be sure to be at least 10 meters on top of every one of them*/
	int dir = st < ar ? 0 : 1;
	int pike = pk[dir];
	for(int i = st; i != ar; i += dir ? -1 : 1)
	{
		for(int j = pike; j != dir ? pk[!dir]+1 : pk[!dir]-1; j += dir ? -1 : 1)
			pike = i == surface[j][X] ? j : pike;
		if(i == surface[pike][X] && th < (double)(surface[pike][Y]+10)) /*redefine the trajectory from the nearest obstacle to st*/
		{
			path[i] = surface[pike][Y]+10; /*first redefine trajectory by setting current path point high enough*/
			for(int j = i; j != st || path[j] < path[i]; j += dir ? 1 : -1) /*then verify that the last points are not below the new trajectory point*/
				path[j] = path[j] < path[i] ? -1 : path[j]; /*if there is, set it to -1*/
			/*set the new th/step values between the new point and ar*/
			th = (double)path[i];
			step = (double)(path[ar]-path[i])/(double)(abs(i-ar));
		}
		else
			th+=step;
	}
}

int *init_path(int **surface, int f_data[7], int lpoint)
{
	int *path = (int *)malloc(7000 * sizeof(int));
	for(int i = 0; i < 7000; i++)
		path[i] = -1;
	path[f_data[X]] = f_data[Y]; /*starting point*/
	path[lpoint] = surf_H(lpoint, surface); /*arrival*/
	find_path(surface, path, f_data[X], lpoint);
	return path;
}
