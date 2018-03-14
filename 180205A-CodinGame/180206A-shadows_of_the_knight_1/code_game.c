#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum cord {X, Y};
enum lim  {BL, UR}; /*BL: Bottom-Left; UR: Upper-Right*/

int main()
{
  int W; //width of the building.
  int H; //height of the building.
  scanf("%d%d", &W, &H);
  int N; //maximum number of turns before game over.
  scanf("%d", &N);
  int bat[2];
  scanf("%d%d", &bat[X], &bat[Y]);

  //array that stocks the two limit values of possibilities (bottom-left and upper-right squares)
  int lim[2][2];
  lim[BL][X] = 0;    //bottom-left X
  lim[BL][Y] = H-1;  //bottom-left Y
  lim[UR][X] = W-1;  //upper-right X
  lim[UR][Y] = 0;    //upper-right Y
  //covers the entire area at the begining

  //test values
  int i, UP, DOWN, LEFT, RIGHT;

  //game loop
  while(1)
  {
    char bombDir[4]; //the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
    scanf("%s", bombDir);
    UP = 0;
    DOWN = 0;
    LEFT = 0;
    RIGHT = 0;
    for(i = 0; bombDir[i]; i++)
    {
      switch(bombDir[i])
      {
        case 'U': UP = 1;
          break;
        case 'D': DOWN = 1;
          break;
        case 'L': LEFT = 1;
          break;
        case 'R': RIGHT = 1;
          break;
      }
    }

    /*IS THE SKY THE LIMIT ?*/
    if(UP)
      lim[BL][Y] = bat[Y] - 1;
    if(DOWN)
      lim[UR][Y] = bat[Y] + 1;
    if(LEFT)
      lim[UR][X] = bat[X] - 1;
    if(RIGHT)
      lim[BL][X] = bat[X] + 1;
    if(i == 1 && (UP || DOWN))
    {
      lim[BL][X] = bat[X];
      lim[UR][X] = bat[X];
    }
    if(i == 1 && (LEFT || RIGHT))
    {
      lim[BL][Y] = bat[Y];
      lim[UR][Y] = bat[Y];
    }

    /*BATMAN IS ON THE MOVE*/
    bat[Y] = lim[UR][Y] + ((lim[BL][Y] - lim[UR][Y]) / 2);
    bat[X] = lim[BL][X] + ((lim[UR][X] - lim[BL][X]) / 2);

    //the location of the next window Batman should jump to.
    printf("%d %d\n", bat[X], bat[Y]);
  }

  return 0;
}
