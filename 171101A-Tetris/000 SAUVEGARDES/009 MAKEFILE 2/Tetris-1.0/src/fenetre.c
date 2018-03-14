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

  //on initialise ces pointeurs à NULL vu que pour l'instant la taille de la fenêtre correspond au buffer du jeu
  screen->bandeLargeur = NULL;
  screen->bandeHauteur = NULL;

  //on initie des données d'échelle par défaut (l'écran apparaît à la résolution par défaut)
  screen->sx = 1;
  screen->sy = 1;
  screen->scale = 1;
  screen->scaleW = SCREEN_W;
  screen->scaleH = SCREEN_H;
  screen->scaleX = 0;
  screen->scaleY = 0;

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

  //on récupère le plus petit des facteurs d'échelle
  if(screen->sx == screen->sy || screen->sx < screen->sy)
    screen->scale = screen->sx;
  else if(screen->sy < screen->sx)
    screen->scale = screen->sy;

  screen->scaleW = SCREEN_W * screen->scale;
  screen->scaleH = SCREEN_H * screen->scale;
  screen->scaleX = (windowWidth - screen->scaleW) / 2;
  screen->scaleY = (windowHeight - screen->scaleH) / 2;

  if(windowWidth > screen->scaleW) //s'il y a des bandes noires en largeur
  {
    if(screen->bandeLargeur != NULL)
      al_destroy_bitmap(screen->bandeLargeur);

    screen->bandeLargeur = al_create_bitmap(screen->scaleX / screen->scale, SCREEN_H);
    genererBande(screen->bandeLargeur);
  }
  else if(windowHeight > screen->scaleH) //s'il y a des bandes noires en hauteur
  {
    if(screen->bandeHauteur != NULL)
      al_destroy_bitmap(screen->bandeHauteur);

    screen->bandeHauteur = al_create_bitmap(SCREEN_W, screen->scaleY / screen->scale);
    genererBande(screen->bandeHauteur);
  }
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

void drawBuffer(gameScreen *screen)
{
  al_set_target_backbuffer(screen->display);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_scaled_bitmap(screen->buffer, 0, 0, SCREEN_W, SCREEN_H, screen->scaleX, screen->scaleY, screen->scaleW, screen->scaleH, 0);
  if(al_get_display_width(screen->display) > screen->scaleW)
  {
    int largeurB = al_get_bitmap_width(screen->bandeLargeur);
    al_draw_scaled_bitmap(screen->bandeLargeur, 0, 0, largeurB, SCREEN_H, screen->scaleX - (largeurB * screen->scale), 0, largeurB * screen->scale, screen->scaleH, 0);
    al_draw_scaled_bitmap(screen->bandeLargeur, 0, 0, largeurB, SCREEN_H, screen->scaleW + screen->scaleX, 0, largeurB * screen->scale, screen->scaleH, 0);
  }
  else if(al_get_display_height(screen->display) > screen->scaleH)
  {
    int hauteurB = al_get_bitmap_height(screen->bandeHauteur);
    al_draw_scaled_bitmap(screen->bandeHauteur, 0, 0, SCREEN_W, hauteurB, 0, screen->scaleY - (hauteurB * screen->scale), screen->scaleW, hauteurB * screen->scale, 0);
    al_draw_scaled_bitmap(screen->bandeHauteur, 0, 0, SCREEN_W, hauteurB, 0, screen->scaleH + screen->scaleY, screen->scaleW, hauteurB * screen->scale, 0);
  }
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
