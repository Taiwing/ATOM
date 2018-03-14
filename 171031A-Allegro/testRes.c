#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>

int main()
{
  al_init();

  ALLEGRO_DISPLAY_MODE *mode = malloc(sizeof(ALLEGRO_DISPLAY_MODE));

  int nbModes = al_get_num_display_modes();

  int resMaxW = 0, resMaxH = 0, resMinW = 0, resMinH = 0;

  for(int i = 0; i < nbModes; i++)
  {
    al_get_display_mode(i, mode);
    printf("Resolution %d: %dx%d\n", i+1, mode->width, mode->height);
    if((mode->width < resMinW && mode->height < resMinH) || i == 0)
    {
      resMinW = mode->width;
      resMinH = mode->height;
    }
    if((mode->width > resMaxW && mode->height > resMaxH) || i == 0)
    {
      resMaxW = mode->width;
      resMaxH = mode->height;
    }
  }
  printf("\nResolution Min: %dx%d\nResolution Max: %dx%d\n", resMinW, resMinH, resMaxW, resMaxH);

  return EXIT_SUCCESS;
}
