#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 enum directions{NONE, LEFT, RIGHT};

int main()
{
  int nbFloors; //number of floors
  int width; //width of the area
  int nbRounds; //maximum number of rounds
  int exitFloor; //floor on which the exit is found
  int exitPos; //position of the exit on its floor
  int nbTotalClones; //number of generated clones
  int nbAdditionalElevators; //ignore (always zero)
  int nbElevators; //number of elevators
  scanf("%d%d%d%d%d%d%d%d", &nbFloors, &width, &nbRounds, &exitFloor, &exitPos, &nbTotalClones, &nbAdditionalElevators, &nbElevators);

  int *lifts = (int *)malloc(nbFloors * sizeof(int));

  for(int i = 0; i < nbFloors; i++)
    lifts[i] = -1;

  for(int i = 0; i < nbElevators; i++)
  {
    int elevatorFloor; //floor on which this elevator is found
    int elevatorPos; //position of the elevator on its floor
    scanf("%d%d", &elevatorFloor, &elevatorPos);
    lifts[elevatorFloor] = elevatorPos;
  }

  int dir = NONE;

  //game loop
  while(1)
  {
    int cloneFloor; //floor of the leading clone
    int clonePos; //position of the leading clone on its floor
    char direction[11]; //direction of the leading clone: LEFT or RIGHT
    scanf("%d%d%s", &cloneFloor, &clonePos, direction);

    /*where the fuck is he going ?*/
    if(!strcmp("LEFT", direction))
      dir = LEFT;
    else if(!strcmp("RIGHT", direction))
      dir = RIGHT;
    else
      dir = NONE;

    /*action time*/
    if(lifts[cloneFloor] == -1 && exitFloor == cloneFloor)
    {
      if(clonePos > exitPos && dir == RIGHT)
        printf("BLOCK\n");
      else if(clonePos < exitPos && dir == LEFT)
        printf("BLOCK\n");
      else
        printf("WAIT\n");
    }
    else if((clonePos > lifts[cloneFloor] || (exitFloor == cloneFloor && clonePos > exitPos)) && dir == RIGHT)
      printf("BLOCK\n");
    else if((clonePos < lifts[cloneFloor] || (exitFloor == cloneFloor && clonePos < exitPos)) && dir == LEFT)
      printf("BLOCK\n");
    else
      printf("WAIT\n");
  }

  return 0;
}
