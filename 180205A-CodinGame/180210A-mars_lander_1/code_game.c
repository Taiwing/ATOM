#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum flight_param {X, Y, hSpeed, vSpeed, fuel, rotate, power};

int main()
{
  int surfaceN; // the number of points used to draw the surface of Mars.
  scanf("%d", &surfaceN);
  for(int i = 0; i < surfaceN; i++)
  {
    int landX; // X coordinate of a surface point. (0 to 6999)
    int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    scanf("%d%d", &landX, &landY);
  }

  int f_data[7]; //flight_data containing all the parameters needed

  // game loop
  while(1)
  {
    scanf("%d%d%d%d%d%d%d", &f_data[X], &f_data[Y], &f_data[hSpeed], &f_data[vSpeed], &f_data[fuel], &f_data[rotate], &f_data[power]);

    if(f_data[vSpeed] < -39)
      printf("0 4\n");
    else
      printf("0 0\n");
  }

  return 0;
}
