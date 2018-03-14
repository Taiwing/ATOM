#include "include/main.h"
#include "include/fenetre.h"

gameScreen *genererGameScreen()
{
  //on crée un pointeur vers la structure
  gameScreen *screen = malloc(sizeof(gameScreen));

  //on crée la fenêtre
  al_set_new_display_flags(ALLEGRO_WINDOWED);
  al_set_new_display_flags(ALLEGRO_RESIZABLE);
  screen->display = al_create_display(SCREEN_W, SCREEN_H);

  screen->buffer = al_create_bitmap(SCREEN_W, SCREEN_H); //on initie le buffer à la même taille que la fenêtre par défaut
  screen->fondDuJeu = al_create_bitmap(SCREEN_W, SCREEN_H); //pareil pour le fond
  genererFondDujeu(screen->fondDuJeu); //puis on le génère

  //on initie des données d'échelle par défaut (l'écran apparaît à la résolution par défaut)
  screen->sx = 1;
  screen->sy = 1;
  screen->scale = 1; //va déterminer le facteur d'agrandissement ou de réduction de la fenêtre par rapport à la résolution
  screen->scaleW = SCREEN_W; //va déterminer la largeur du buffer
  screen->scaleH = SCREEN_H; //va déterminer la hauteur du buffer
  screen->scaleX = 0; //va déterminer la position x du buffer
  screen->scaleY = 0; //va déterminer la position y du buffer
  screen->fondW = SCREEN_W;
  screen->fondH = SCREEN_H;

  //gestion des contrôles du plein écran
  screen->fullScreenSwitch = false; //va servir à activer/descativer le fullScreen
  for(int i = 0; i < 2; i++)
  {
    switch(i)
    {
      case FULLSCREENSWITCH:
        screen->windowKeys[i] = ALLEGRO_KEY_F11;
        break;
      case FULLSCREENOFF:
        screen->windowKeys[i] = ALLEGRO_KEY_ESCAPE;
        break;
    }
  }

  return screen; //puis on renvoit la structure, ça peut aider
}

void destroyGameScreen(gameScreen *screen)
{
  al_destroy_display(screen->display); //on détruit la fenêtre
  al_destroy_bitmap(screen->buffer); //on détruit le buffer
  al_destroy_bitmap(screen->fondDuJeu); //on détruit le fond du jeu
  free(screen); //on libère la mémoire
}

void resizeGameScreen(gameScreen *screen)
{
  al_acknowledge_resize(screen->display);

  float windowWidth = al_get_display_width(screen->display);
  float windowHeight = al_get_display_height(screen->display);

  printf("windowWidth: %f\n", windowWidth);
  printf("windowHeight: %f\n", windowHeight);

  screen->sx = windowWidth / SCREEN_W;
  screen->sy = windowHeight / SCREEN_H;

  //on récupère le plus petit des facteurs d'échelle dans scale et l'autre dans scaleFond
  if(screen->sx == screen->sy || screen->sx < screen->sy)
  {
    screen->scale = screen->sx;
  }
  else if(screen->sy < screen->sx)
  {
    screen->scale = screen->sy;
  }

  screen->scaleW = SCREEN_W * screen->scale;
  screen->scaleH = SCREEN_H * screen->scale;
  screen->scaleX = (windowWidth - screen->scaleW) / 2;
  screen->scaleY = (windowHeight - screen->scaleH) / 2;

  //on va déterminer la taille du fond
  screen->fondW = windowWidth / screen->scale;
  screen->fondH = windowHeight / screen->scale;

  //on recrée le fond du jeu
  al_destroy_bitmap(screen->fondDuJeu);
  screen->fondDuJeu = al_create_bitmap(screen->fondW, screen->fondH);
  genererFondDujeu(screen->fondDuJeu);
}

void fullScreen(gameScreen *screen)
{
  al_set_display_flag(screen->display, ALLEGRO_FULLSCREEN_WINDOW, !(al_get_display_flags(screen->display) & ALLEGRO_FULLSCREEN_WINDOW));
}

void elemToList(gameScreen *screen, Liste *lElem, coord *rect)
{
  coordFloat *posB = malloc(sizeof(coordFloat));
  posB->x = screen->scaleX + (rect->x * screen->scale);
  posB->y = screen->scaleY + (rect->y * screen->scale);
  posB->x2 = screen->scaleX + (rect->x2 * screen->scale);
  posB->y2 = screen->scaleY + (rect->y2 * screen->scale);
  posB->w = posB->x2 - posB->x;
  posB->h = posB->y2 - posB->y;
  posB->t = rect->t * screen->scale;
  insertionL(lElem, tailleChaine(lElem) - 1, posB); //on place le nouvel élément à l'avant dernière position de la liste
}

int posMouse(Liste *lElem, int x, int y)
{
  int posRect = 1; //va indiquer la position du rect dans la liste
  ElementL *elem = lElem->premier; //on se place sur le premier élement de la chaîne
  float xf = (float)x, yf = (float)y;

  for(int i = 0; i < tailleChaine(lElem); i++)
  {
    if(elem->rect != NULL)
    {
      //on teste la position de la souris
      if(xf >= elem->rect->x && xf <= elem->rect->x2 && yf >= elem->rect->y && yf <= elem->rect->y2)
      {
        return posRect; //on renvoit la position du rect dans la liste pour qu'elle soit lue par la fonction "estSurUnBouton" locale
      }
      else
      {
        posRect++;
        elem = elem->suivant; //on passe au prochain élément
      }
    }
    else //si on est arrivé à la fin de la chaîne
    {
      return 0; //on renvoit que la souris ne se trouve dans aucun des rect
    }
  }
}

void targetBuffer(gameScreen *screen)
{
  al_set_target_bitmap(screen->buffer); //on cible le buffer
  al_draw_bitmap_region(screen->fondDuJeu, screen->scaleX, screen->scaleY, SCREEN_H, SCREEN_W, 0, 0, 0); //on y dessine le fondDuJeu
}

void drawBuffer(gameScreen *screen)
{
  al_set_target_backbuffer(screen->display);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_scaled_bitmap(screen->fondDuJeu, 0, 0, screen->fondW, screen->fondH, 0, 0, al_get_display_width(screen->display), al_get_display_height(screen->display), 0);
  al_draw_scaled_bitmap(screen->buffer, 0, 0, SCREEN_W, SCREEN_H, screen->scaleX, screen->scaleY, screen->scaleW, screen->scaleH, 0);
  al_flip_display();
}

void windowInputKeyDown(gameScreen *screen, int key, bool *legalInput)
{
  bool toucheValide = false;
  int input = 0;

  for(int i = 0; i < 2; i++)
  {
    if(screen->windowKeys[i] == key)
    {
      toucheValide = true;
      input = i;
    }
  }

  if(toucheValide)
  {
    switch(input)
    {
      case FULLSCREENSWITCH:
        if(*legalInput)
        {
          screen->fullScreenSwitch = true;
          *legalInput = false;
        }
        break;
      case FULLSCREENOFF:
        if(*legalInput && (al_get_display_flags(screen->display) & ALLEGRO_FULLSCREEN_WINDOW)) //si le mode plein écran est activé
        {
          screen->fullScreenSwitch = true;
          *legalInput = false;
        }
        break;
    }
  }
}

void windowInputKeyUp(gameScreen *screen, int key, bool *legalInput)
{
  for(int i = 0; i < 2; i++)
  {
    if(screen->windowKeys[i] == key)
    {
      screen->fullScreenSwitch = false;
      *legalInput = true;
    }
  }
}

void testRes(int res[4][2])
{
  ALLEGRO_DISPLAY_MODE *mode = malloc(sizeof(ALLEGRO_DISPLAY_MODE));

  int nbModes = al_get_num_display_modes();

  int resMaxW = 0, resMaxH = 0, resMinW = 0, resMinH = 0;

  //on récupère les résolutions maximum et minimum
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
  res[RESMIN][WIDTH] = resMinW;
  res[RESMIN][HEIGHT] = resMinH;
  res[RESMAX][WIDTH] = resMaxW;
  res[RESMAX][HEIGHT] = resMaxH;

  //si la résolution par défaut peut être affichée
  if((SCREEN_W < res[RESMAX][WIDTH] && SCREEN_H < res[RESMAX][HEIGHT]) && (SCREEN_W > res[RESMIN][WIDTH] && SCREEN_H > res[RESMIN][HEIGHT]))
  {
    res[RESDEF][WIDTH] = SCREEN_W;
    res[RESDEF][HEIGHT] = SCREEN_H;
  }
  else if(res[RESMIN][WIDTH] > 0 && res[RESMIN][WIDTH] > 0) //sinon, on la résolution par défaut devient la résolution minimale
  {
    res[RESDEF][WIDTH] = res[RESMIN][WIDTH];
    res[RESDEF][WIDTH] = res[RESMIN][WIDTH];
  }
  else //si la résolution minimale ne paut pas être affichée
  {
    exit(EXIT_FAILURE);
  }

  //si la résolution courante ne peut pas être affichée
  if(!((res[RESCUR][WIDTH] < res[RESMAX][WIDTH] && res[RESCUR][HEIGHT] < res[RESMAX][HEIGHT]) && (res[RESCUR][WIDTH] > res[RESMIN][WIDTH] && res[RESCUR][HEIGHT] > res[RESMIN][HEIGHT])))
  {
    //alors elle devient la résolution par défaut
    res[RESCUR][WIDTH] = res[RESDEF][WIDTH];
    res[RESCUR][HEIGHT] = res[RESDEF][HEIGHT];
  }

  printf("\nResolution Min: %dx%d\nResolution Max: %dx%d\n", res[RESMIN][WIDTH], res[RESMIN][HEIGHT], res[RESMAX][WIDTH], res[RESMAX][HEIGHT]);

  free(mode);
}
