#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
  int W; // number of columns.
  int H; // number of rows.
  scanf("%d%d", &W, &H); fgetc(stdin);
  int **map = (int **)malloc(W * sizeof(int *));
  for(int i = 0; i < W; i++)
    map[i] = (int *)malloc(H * sizeof(int));

  for(int i = 0; i < H; i++)
  {
    char LINE[201]; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
    fgets(LINE, 201, stdin); // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
    int l = 0;
    for(int j = 0; LINE[j]; j++)
    {
      char room[3];
      int k = 0;
      for(; LINE[j] > 47 && LINE[j] < 58; k++)
      {
        room[k] = LINE[j];
        j++;
      }
      room[k] = '\0';
      map[l][i] = atoi(room);
      l++;
    }
  }

  int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
  scanf("%d", &EX);

  // game loop
  while(1)
  {
    int XI;
    int YI;
    char POS[6];
    scanf("%d%d%s", &XI, &YI, POS);

    switch(map[XI][YI])
    {
      case 2: XI = POS[0] == 'L' ? XI+1 : XI-1;
        break;
      case 4: if(POS[0] == 'R') YI++; else XI--;
        break;
      case 5: if(POS[0] == 'L') YI++; else XI++;
        break;
      case 6: XI = POS[0] == 'L' ? XI+1 : XI-1;
        break;
      case 10: XI--;
        break;
      case 11: XI++;
        break;
      default: YI++;
        break;
    }

    // One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    printf("%d %d\n", XI, YI);
  }

  return 0;
}
