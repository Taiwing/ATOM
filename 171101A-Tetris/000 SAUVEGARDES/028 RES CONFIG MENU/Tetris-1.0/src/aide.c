#include "include/aide.h"

void menuAide(gameScreen *screen,
              ALLEGRO_BITMAP *fond, ALLEGRO_BITMAP *boutonOkON, ALLEGRO_BITMAP *boutonOkOFF,
              coord *Aide, coord *OK, coord *NSL,
              int niveau, int score, int lignes)
{

  //on charge la liste d'éléments pour la fonction "estSurUnBouton"
  Liste *lElem = initialisationListe();
  chargerListeElemFondAide(screen, OK, lElem);

  al_install_mouse(); //on initialise la souris

  //variables de la boucle
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  bool legalInput = true; //va contrôler l'input clavier
  int boutonOk = OFF; //va déterminer si la souris se trouve sur le bouton OK

  //on initialise le timer
  ALLEGRO_TIMER *timer_aide = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_aide = al_create_event_queue();
  al_register_event_source(event_queue_aide, al_get_display_event_source(screen->display)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_aide, al_get_timer_event_source(timer_aide)); //on lie la file au timer
  al_register_event_source(event_queue_aide, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_aide, al_get_keyboard_event_source());

  //on démarre le timer
  al_start_timer(timer_aide);

  while(continuer) //on lance la boucle du menu
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_aide, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) //si la souris bouge
    {
      //on vérifie si elle est ou non sur le bouton OK
      boutonOk = estSurUnBoutonAide(lElem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie si elle est ou non sur le bouton OK
      boutonOk = estSurUnBoutonAide(lElem, ev.mouse.x, ev.mouse.y);

      if(boutonOk == ON && (ev.mouse.button & 1)) //si c'est le cas
      {
        continuer = false; //on sort du menu d'aide
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      windowInputKeyDown(screen, ev.keyboard.keycode, &legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      windowInputKeyUp(screen, ev.keyboard.keycode, &legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE || screen->fullScreenSwitch)
    {
      if(screen->fullScreenSwitch)
      {
        fullScreen(screen);
        screen->fullScreenSwitch = false;
      }
      resizeGameScreen(screen);
      dechargerListe(lElem);
      chargerListeElemFondAide(screen, OK, lElem);
    }

    if(redraw && al_is_event_queue_empty(event_queue_aide)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherAide(screen, fond, boutonOkON, boutonOkOFF, OK, NSL, boutonOk, niveau, score, lignes); //on affiche l'aide à nouveau
    }
  }

  //on libère la mémoire
  detruireListe(lElem);
  al_destroy_timer(timer_aide);
  al_destroy_event_queue(event_queue_aide);
}

int estSurUnBoutonAide(Liste *lElem, int x, int y)
{
  switch(posMouse(lElem, x, y))
  {
    case 1:
      return ON;
    default:
      return OFF;
  }
}

void afficherAide(gameScreen *screen,
                  ALLEGRO_BITMAP *fond,
                  ALLEGRO_BITMAP *boutonOkON,
                  ALLEGRO_BITMAP *boutonOkOFF,
                  coord *OK,
                  coord *NSL,
                  int boutonOk,
                  int niveau, int score, int lignes)
{
  targetBuffer(screen);
  float scale = screen->scaleBuff;

  //on charge l'image de fond
  al_draw_bitmap(fond, 0, 0, 0);

  //puis le bouton OK
  switch(boutonOk)
  {
    case OFF:
      al_draw_bitmap(boutonOkOFF, OK->x + OK->t, OK->y + OK->t, 0);
      break;
    case ON:
      al_draw_bitmap(boutonOkON, OK->x + OK->t, OK->y + OK->t, 0);
      break;
  }

  if(niveau != 0 || score != 0 || lignes != 0) //si on est dans le menu pause
  {
    //on affiche ces données
    //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
    char strNiveau[3]; //trois caractère max (de 1 à 99)
    char strScore[7]; //six caractères max (de 1 99999)
    char strLignes[6]; //cinq caractères max (de 1 99999)
    sprintf(strNiveau, "%d", niveau);
    sprintf(strScore, "%d", score);
    sprintf(strLignes, "%d", lignes);

    //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
    ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", 25 * scale, 0); //on charge la police "Gameplay"
    //affiche la valeur de "niveau" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), NSL->x + NSL->t + (247 * scale), NSL->y + NSL->t + (9 * scale), ALLEGRO_ALIGN_RIGHT, strNiveau);
    //affiche la valeur de "score" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), NSL->x + NSL->t + (247 * scale), NSL->y + (NSL->t * 2) + (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strScore);
    //affiche la valeur de "lignes" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), NSL->x + NSL->t + (247 * scale), NSL->y2 - NSL->t - (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strLignes);

    //on libère la mémoire
    al_destroy_font(font);
  }

  drawBuffer(screen);
}

void chargerListeElemFondAide(gameScreen *screen, coord *OK, Liste *lElem)
{
  elemToList(screen, lElem, OK);
}
