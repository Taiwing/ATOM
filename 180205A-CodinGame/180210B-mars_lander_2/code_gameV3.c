#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};

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

	int f_data[7]; /*flight_data containing all the parameters needed*/
	int lz[2]; /*index of the points corresponding to the flat zone of at least 1000m in the surface array*/
	int rot = 0; /*rotation*/
	int power = 0; /*desired power output*/

	for(int i = 1; i < N; i++) /*defines the landing_zone*/
	{
		if(surface[i-1][Y] == surface[i][Y] && (surface[i][X] - surface[i-1][X]) >= 1000)
		{
			lz[0] = i-1;
			lz[1] = i;
			break;
		}
	}

	/*game loop*/
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		printf("%d %d\n", rot, power);
	}

	return 0;
}
