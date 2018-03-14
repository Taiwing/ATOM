#include "main.h"
#include "fenetre.h"

gameScreen *genererGameScreen()
{
  //on crée un pointeur vers la structure
  gameScreen *screen = malloc(sizeof(gameScreen));

  //on crée la fenêtre
  al_set_new_display_flags(ALLEGRO_WINDOWED);
  al_set_new_display_flags(ALLEGRO_RESIZABLE);
  screen->display = al_create_display(SCREEN_W, SCREEN_H);

  screen->buffer = al_create_bitmap(SCREEN_W, SCREEN_H); //on initie le buffer à la même taille que la fenêtre par défaut

  //on initie des données d'échelle par défaut (l'écran apparaît à la résolution par défaut)
  screen->sx = 1;
  screen->sy = 1;
  screen->scale = 1;
  screen->scaleW = SCREEN_W;
  screen->scaleH = SCREEN_H;
  screen->scaleX = 0;
  screen->scaleY = 0;

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
  screen->scaleY = (windowHeight - screen->scaleH) / 2;}

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
