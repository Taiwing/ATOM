#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};

int surf_H(int x, int **surface); //gets the height of the surface at the point x
int **create_map(int **surface, int N);
int obstacle(int shuttle_x, int shuttle_y, int **surface, int target[2], int dir); /*REDUCE EXEC TIME*/
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

	int **map = create_map(surface, N);

	int f_data[7]; //flight_data containing all the parameters needed
	int lz[2]; //index of the points corresponding to the flat zone of at least 1000m in the surface array
	int ob; //stores the nearest obstacle X
	int target[2]; //stores the highest point between the shuttle and the next obstacle or landing_zone (by storing their index in the surface array)
	int rot; //rotation
	int power; //desired power output
	int dir; //side on which the obstacle is

	for(int i = 1; i < N; i++) //defines the landing_zone
	{
		if(surface[i-1][Y] == surface[i][Y] && (surface[i][X] - surface[i-1][X]) >= 1000)
		{
			lz[0] = i-1;
			lz[1] = i;
			break;
		}
	}

	//game loop
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		if(f_data[X] >= surface[lz[0]][X]+10 && f_data[X] <= surface[lz[1]][X]-10) //if the shuttle is above the landing_zone
		{
			//landing procedure
			rot = 0;
			power = f_data[vSpeed] > -39 ? 0 : 4;
		}
		else
		{
			dir = f_data[X]-((surface[lz[0]][X]+surface[lz[1]][X])/2);
			ob = obstacle(f_data[X], f_data[Y], surface, lz, dir);
			if(ob == -1) //if the shuttle is above every point between the landing_zone and itself including the landing_zone
			{
				if(dir > 0)
				{
					rot = 45;
					power = f_data[hSpeed] < -80 ? 0 : 4;
				}
				else
				{
					rot = -45;
					power = f_data[hSpeed] > 80 ? 0 : 4;
				}
			}
			else
			{
				power = 4;
				while(ob != -1)
				{
					target[0] = ob;
					target[1] = ob;
					rot = rotate(f_data[X], f_data[Y], surface[ob][X], surface[ob][Y]+10);
					//simulate trajectory at rot angle (eg: hypothenuse)
					/*TEST*/
					ob = -1;
				}
			}
		}

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

int obstacle(int shuttle_x, int shuttle_y, int **surface, int target[2], int dir) //returns the highest point between the shuttle and l_zone
{
	int i;
	int max = -1;

	if(dir < 0)
	{
		for(i = 0; surface[i][X] < shuttle_x; i++);
		for(; i <= target[0]; i++)
		max = surface[i][Y] > shuttle_y && (max == -1 || surface[i][Y] > surface[max][Y]) ? i : max;
	}
	else
	{
		for(i = 0; surface[i][X] < shuttle_x; i++);
		for(i--; i >= target[1]; i--)
		max = surface[i][Y] > shuttle_y && (max == -1 || surface[i][Y] > surface[max][Y]) ? i : max;
	}

	return max;
}

int rotate(int shuttle_x, int shuttle_y, int ob_x, int ob_y)
{
	double O = ob_y - shuttle_y;
	double A = shuttle_x - ob_x;
	return atan(O/A);
}
