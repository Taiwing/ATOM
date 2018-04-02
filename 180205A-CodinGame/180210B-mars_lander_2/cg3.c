#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

enum flight_param {X, Y, hSpeed, vSpeed, fuel, angle, power_d};
enum acc {Ah, Av};
#define PI 3.14159265
#define G 3.711
#define MAXERR 0.2

typedef struct traj	/*trajectory*/
{
	double Dh;	/*horizontal distance*/
	double Dv;	/*vertical distance*/
	double A;		/*angle*/
} traj;

int surf_H(int x, int **surface); /*gets the height Y of the ground at X*/
void find_lz(int lz[2], int **surface, int N); /*defines the landing zone coordinates*/
void find_path(int **surface, int *path, int st, int ar); /*calculates the path between two points*/
int *init_path(int **surface, int f_data[7], int ar); /*initializes and finds the shortest path to the landing_zone*/
void dedrek(int f_data[7], int n_data[7], double acc[2]); /*estimates next f_data given current f_data*/
int get_npp(int npp, int *path, int dir, int nX); /*finds the next path point and returns it*/
traj *get_traj(double Dh, double Dv); /*computes the angle of trajectory and returns a traj struct*/
void nav(traj *Ta, traj *Tnt, double PA[91][5][2], int *rot, int *power); /*navigation system*/

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

	int *path = NULL; /*stores the shortest path to the landing zone*/
	int lz[2]; /*index of the points corresponding to the flat zone of at least 1000m in the surface array*/
	find_lz(lz, surface, N);
	int ar = (surface[lz[0]][X] + surface[lz[1]][X]) / 2; /*coordinate X of arrival*/
	int st; /*starting point*/
	int dir = 0; /*direction of arrival, 0 for right, 1 for left*/
	int f_data[7]; /*flight_data containing all the parameters needed*/
	int n_data[7]; /*estimated f_data at the fallowing second*/
	double acc[2]; /*hor. and ver. acceleration*/
	int npp = -1; /*next path point*/
	int rot = 0; /*rotation*/
	int power = 0; /*desired power output*/

	double PA[91][5][2];	/*contains every possible acceleration vector in function of angle and power_d*/
												/*if the angle is negative, simply multiply Ah by -1*/
	for(int i = 0; i < 91; i++)
		for(int j = 0; j < 5; j++)
		{
			PA[i][j][Ah] = (double)j * cos((double)i * (PI/180.0));
			PA[i][j][Ah] *= -1;
			PA[i][j][Av] = (double)j * cos((90 - (double)i) * (PI/180.0));
			PA[i][j][Av] -= G;
		}

	/*game loop*/
	while(1)
	{
		scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[angle], &f_data[power_d]);

		if(!path)
		{
			path = init_path(surface, f_data, ar);
			st = f_data[X];
			dir = st > ar ? 1 : 0; /*if st is after ar, then go left, else right*/
			rot = f_data[angle];
			power = f_data[power_d];
		}

		dedrek(f_data, n_data, acc);
		int npp2 = get_npp(npp, path, dir, n_data[X]);
		if(npp2 == st) npp2 = get_npp(-1, path, dir, st);
		traj *Ta = get_traj((double)f_data[hSpeed], (double)f_data[vSpeed]); /*actual trajectory*/
		traj *Tt = get_traj((double)(npp2-f_data[X]), (double)(path[npp2]-f_data[Y])); /*target trajectory*/
		if(fabs(Ta->A - Tt->A) >  MAXERR || npp2 != npp) /*tweak MAXERR value to modify precision*/
		{
			npp = npp2;
			traj *Tnt = get_traj((double)(npp-n_data[X]), (double)(path[npp]-n_data[Y])); /*next target trajectory*/
			nav(Ta, Tnt, PA, &rot, &power);
			free(Tnt);
		}

		free(Ta);
		free(Tt);

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
	acc[Ah] = (double)f_data[power_d] * cos((double)f_data[angle] * (PI/180.0));
	acc[Ah] *= f_data[angle] > 0 ? -1 : 1;
	acc[Av] = (double)f_data[power_d] * cos((90 - (double)abs(f_data[angle])) * (PI/180.0));
	acc[Av] -= G;
	n_data[X] += f_data[hSpeed];
	n_data[Y] -= f_data[vSpeed];
	n_data[hSpeed] = f_data[hSpeed] + round(acc[Ah]);
	n_data[vSpeed] = f_data[vSpeed] + round(acc[Av]);
	n_data[fuel] -= 10 * f_data[power_d];
	n_data[angle] = f_data[angle];
	n_data[power_d] = f_data[power_d];
}

int get_npp(int npp, int *path, int dir, int nX)
{
	if(npp == -1 || (dir && nX < npp) || (!dir && nX > npp))
		for(int i = (dir ? nX-1 : nX+1); i > -1 && i < 7000; i += (dir ? -1 : 1))
			if(path[i] != -1)
			{
				npp = i;
				break;
			}

	return npp;
}

traj *get_traj(double Dh, double Dv)
{
	traj *T = (traj *)malloc(sizeof(traj));
	T->Dh = Dh;
	T->Dv = Dv;

	if(!Dh || !Dv)
	{
		if(!Dh && !Dv) T->A = 181; /*impossible value, meaning no trajectory*/
		else if(!Dh) T->A = Dv > 0 ? 0 : 180; /*0 means north, 180 south (is equivalent to -180)*/
		else if(!Dv) T->A = Dh > 0 ? -90 : 90; /*-90 means east, 90 west*/
	}
	else
	{
		T->A = atan(fabs(Dh)/fabs(Dv)) * (180/PI); /*raw angle, correct if North-West*/
		if(Dh > 0 && Dv > 0) T->A *= -1;	/*if North-East*/
		else if(Dh < 0 && Dv < 0) T->A = 180 - T->A; /*if South-West*/
		else if(Dh > 0 && Dv < 0) T->A -= 180;	/*if South-East*/
	}

	return T;
}

void nav(traj *Ta, traj *Tnt, double PA[91][5][2], int *rot, int *power)
{
	/*minimize the difference between Tna->A and Tnt->A*/
	/*to spare time we're gonna minimize the difference between Tna->(Dh/Dv) and Tnt->(Dh/Dv)*/
	/*if Tnt->Dv == 0 then Tna->Dv must be 0 and the diff between Tna->Dh and Tnt->Dh is to be minimized*/

	int rotMax = ((*rot)+15 > 90 ? 90 : (*rot)+15), rotMin = ((*rot)-15 < -90 ? -90 : (*rot)-15);
	int powMax = ((*power)+1 > 4 ? 4 : (*power)+1) , powMin = ((*power)-1 < 0 ? 0 : (*power)-1);
	int best[2];
	double err, errMin = 999;
	traj *Tna;

	for(int r = rotMin; r <= rotMax; r++)
		for(int p = powMin; p <= powMax; p++)
		{
			double Dh = Ta->Dh + (r < 0 ? PA[r*(-1)][p][Ah]*(-1) : PA[r][p][Ah]);
			double Dv = Ta->Dv + PA[r][p][Av];
			Tna = get_traj(Dh, Dv);
			err = Tnt->A - Tna->A;
			if(err < errMin)
			{
				errMin = err;
				best[0] = r;
				best[1] = p;
			}
			free(Tna);
		}

	*rot = best[0];
	*power = best[1];
}
