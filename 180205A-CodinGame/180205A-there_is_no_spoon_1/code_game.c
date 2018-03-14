#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
  int out[3][2] = {-1};
  int grid[30][30] = {0};
  int width; // the number of cells on the X axis
  scanf("%d", &width);
  int height; // the number of cells on the Y axis
  scanf("%d", &height); fgetc(stdin);
  for(int i = 0; i < height; i++)
  {
    char line[32]; // width characters, each either 0 or .
    fgets(line, 32, stdin); // width characters, each either 0 or .
    for(int j = 0; j < width; j++)
    {
      switch(line[j])
      {
        case '0': grid[i][j] = 1; break;
        case '.': grid[i][j] = 0; break;
      }
    }
  }

  // Write an action using printf(). DON'T FORGET THE TRAILING \n
  // To debug: fprintf(stderr, "Debug messages...\n");
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      if(grid[i][j])
      {
        out[0][0] = j;  //x1
        out[0][1] = i;  //y1
        j++;
        if(j < width)
        {
          for(; j < width; j++)
          {
            if(grid[i][j])
            {
              out[1][0] = j;  //x2
              out[1][1] = i;  //y2
              break;
            }
            else if(j == (width-1))
            {
              out[1][0] = -1; //x2
              out[1][1] = -1; //y2
            }
          }
        }
        else
        {
          out[1][0] = -1; //x2
          out[1][1] = -1; //y2
        }

        if(i != (height-1))
        {
          for(int k = i+1; k < height; k++)
          {
            if(grid[k][out[0][0]])
            {
              out[2][0] = out[0][0]; //x3
              out[2][1] = k; //y3
              break;
            }
            else if(k == (height-1))
            {
              out[2][0] = -1; //x3
              out[2][1] = -1; //y3
            }
          }
        }
        else
        {
          out[2][0] = -1; //x3
          out[2][1] = -1; //y3
        }
        if(out[1][0] != -1)
          j = out[1][0]-1;
        printf("%d %d %d %d %d %d\n", out[0][0], out[0][1], out[1][0], out[1][1], out[2][0], out[2][1]);
      }
    }
  }

    return 0;
}
