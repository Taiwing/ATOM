#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};
#define PI 3.14159265
#define G 3.711

int surf_H(int x, int **surface); /*gets the height Y of the ground at X*/
int **create_map(int **surface, int N); /*maps mars*/
void find_lz(int lz[2], int **surface, int N); /*defines the landing zone coordinates*/
void find_path(int **surface, int *path, int st, int ar); /*calculates the path between two points*/
int *init_path(int **surface, int f_data[7], int ar); /*initializes and finds the shortest path to the landing_zone*/
void dedrek(int f_data[7], int n_data[7], double acc[2]); /*estimates next f_data given current f_data*/

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
	int ar = (surface[lz[0]][X] + surface[lz[1]][X]) / 2; /*coordinate X of arrival*/
	int st; /*starting point*/
	int dir = 0; /*direction of arrival, 0 for right, 1 for left*/
	int f_data[7]; /*flight_data containing all the parameters needed*/
	int n_data[7]; /*estimated f_data at the fallowing second*/
	double acc[2]; /*hor. and ver. acceleration*/
	int rot = 0; /*rotation*/
	int power = 0; /*desired power output*/

	/*game loop*/
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		if(!path)
		{
			path = init_path(surface, f_data, ar);
			st = f_data[X];
			dir = st > ar ? 1 : 0; /*if st is after ar, then go left, else right*/
		}

		dedrek(f_data, n_data, acc);

		printf("%d %d\n", rot, power);

			/*TEST*/
			break;
	}

	/*TEST*/
	printf("start:\nX: %d, Y: %d\n", f_data[X], f_data[Y]);
	printf("arrival:\nX: %d, Y: %d\n", ar, surface[lz[0]][Y]);
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

	/*first get every surface points between st and ar*/ /*get the index of the first surface val after or at st and the last after ar*/
	int pk[2] = {-1, -1}; /*pikes at both ends of the trajectory*/
	for(int i = 0; 1; i++)
	{
		pk[0] = pk[0] == -1 && surface[i][X] > st ? i : pk[0];
		pk[1] = pk[1] == -1 && surface[i][X] >= ar ? i : pk[1];
		if(surface[i][X] == 6999) break;
	}
	for(int j = 0; j < 2 && st >= ar; j++) pk[j] = pk[j] != -1 ? pk[j]-1 : pk[j];

	/*then be sure to be at least 10 meters on top of every one of them*/
	int dir = st < ar ? 0 : 1;
	int pike = pk[0];
	for(int i = st; i != ar; i += (dir ? -1 : 1))
	{
		for(int j = pike; j != (dir ? pk[1]-1 : pk[1]+1); j += (dir ? -1 : 1))
			pike = i == surface[j][X] ? j : pike;
		if(i == surface[pike][X] && th < (double)(surface[pike][Y]+10)) /*redefine the trajectory from the nearest obstacle to st*/
		{
			path[i] = surface[pike][Y]+10; /*first redefine trajectory by setting current path point high enough*/
			/*then verify that the last points are not below the new trajectory point*/
			for(int j = (dir ? i+1 : i-1); j != st && path[j] < path[i]; j += (dir ? 1 : -1))
				path[j] = path[j] < path[i] ? -1 : path[j]; /*if there is, set it to -1*/
			/*set the new th/step values between the new point and ar*/
			th = (double)path[i];
			step = (double)(path[ar]-path[i])/(double)(abs(i-ar));
		}
		else
			th+=step;
	}
}

int *init_path(int **surface, int f_data[7], int ar)
{
	int *path = (int *)malloc(7000 * sizeof(int));
	for(int i = 0; i < 7000; i++)
		path[i] = -1;
	path[f_data[X]] = f_data[Y]; /*starting point*/
	path[ar] = surf_H(ar, surface); /*arrival*/
	find_path(surface, path, f_data[X], ar);
	return path;
}

void dedrek(int f_data[7], int n_data[7], double acc[2])
{
	acc[0] = f_data[angle] ? (double)f_data[power_d] * cos((double)f_data[angle] * (PI/180.0)) : 0;
	acc[0] *= f_data[angle] > 0 ? -1 : 1;
	acc[1] = f_data[angle] ? (double)f_data[power_d] * cos((90 - (double)abs(f_data[angle])) * (PI/180.0)) : (double)f_data[power_d];
	acc[1] = G - acc[1];
	n_data[power_d] = f_data[power_d];
	n_data[angle] = f_data[angle];
	n_data[fuel] -= 10 * f_data[power_d];
	n_data[vSpeed] = f_data[vSpeed] + round(acc[1]);
	n_data[hSpeed] = f_data[hSpeed] + round(acc[0]);
	n_data[Y] -= f_data[vSpeed];
	n_data[X] += f_data[hSpeed];
}
