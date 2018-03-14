#include "fmain.h"
/*fmain.c: fonctions de base du programme qu'on va utiliser dans le main*/

ALLEGRO_DISPLAY *genererFenetre()
{
  ALLEGRO_DISPLAY *display = al_create_display(SCREEN_W, SCREEN_H); //on crée la fenêtre
  return display; //on retourne le pointeur vers la fenêtre
}

void menuPrincipal()
{
  //on va afficher la fenêtre et récupérer un pointeur vers celle-ci
  ALLEGRO_DISPLAY *fenetre = genererFenetre();

  //on génère les images du menu et on l'affiche
  elementsFondMenu *elem = genererElementsFondMenu(); //on crée les structures coord représentant les rectangles du menu
  packMenu *images = genererPackMenu(elem); //on crée la structure d'où on va tirer les images du menu
  al_set_target_bitmap(al_get_backbuffer(fenetre)); //on recible la fenêtre pour y afficher les images

  //on initialise la souris
  al_install_mouse();

  //puis le clavier également, pour la partie
  al_install_keyboard();

  //on initialise les sons du jeu
  packSons *sons = chargerSon(); //on charge les sons du jeu
  gameConfig *config = initialiserConfigJeu(); //on initialise la configuration du jeu

  //on charge les images du menu d'options
  elementsFondOptions *elem2 = genererElementsFondOptions();
  packOptions *images2 = genererPackOptions(elem2, images->fondMenu, config->keyMap);
  al_set_target_bitmap(al_get_backbuffer(fenetre)); //on recible la fenêtre pour y afficher les images

  //puis le timer
  ALLEGRO_TIMER *timer_menu = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_menu = al_create_event_queue();
  al_register_event_source(event_queue_menu, al_get_display_event_source(fenetre)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_menu, al_get_timer_event_source(timer_menu)); //on lie la file au timer
  al_register_event_source(event_queue_menu, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_menu, al_get_keyboard_event_source()); //puis au clavier pour le son

  //variables nécessaires à la boucle
  bool redraw = false;
  bool continuerMenu = true;
  int bouton = OFF;
  int niveau = 1;
  bool legalInput = true; //pour limiter le nombre d'input à la suite
  bool keys[3] = {false, false, false}; //va indiquer si le joueur appuie sur les touches de son (S D F)
  bool pressedKeys[ALLEGRO_KEY_MAX] = {false}; //va indiquer quelle touche a été apuuyée pour la fonction de triche
  File *cheatStr = initialiser(); //va recueillir les input de triche
  int cptCheat = 0; //va compter le nombre d'input pour la fonction de triche

  //on démarre le timer
  al_start_timer(timer_menu);

  //boucle principale du menu
  while(continuerMenu)
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer l'évènments
    al_wait_for_event(event_queue_menu, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      //gestion du bouton de son
      for(int i = 0; i < 3; i++)
      {
        if(keys[i])
        {
          switch(i)
          {
            case SOUND:
              if(!config->sound->soundOnOff[SOUND])
                config->sound->soundOnOff[SOUND] = true;
              else
                config->sound->soundOnOff[SOUND] = false;
              break;
            case THEME:
              if(!config->sound->soundOnOff[THEME])
                config->sound->soundOnOff[THEME] = true;
              else
                config->sound->soundOnOff[THEME] = false;
              break;
            case FX:
              if(!config->sound->soundOnOff[FX])
                config->sound->soundOnOff[FX] = true;
              else
                config->sound->soundOnOff[FX] = false;
              break;
          }
          keys[i] = false; //pour que la touche ne se répète pas
        }
      }

      redraw = true; //on met redraw à vrai pour redessiner le menu
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      continuerMenu = false; //on sort de la boucle et donc du menu, et finalement du programme
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) //si la souris bouge
    {
      //on vérifie si elle est ou non sur un bouton
      bouton = estSurUnBouton(elem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie si elle est ou non sur un bouton
      bouton = estSurUnBouton(elem, ev.mouse.x, ev.mouse.y);

      if(bouton != OFF) //si c'est le cas
      {
        switch(bouton)
        {
          case JOUER:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              al_uninstall_mouse();
              partie(fenetre, niveau, config, sons); //on lance la partie
              al_install_mouse();
              al_register_event_source(event_queue_menu, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
              //puis on recharge l'image du highScore
              al_destroy_bitmap(images->fondMenu); //on libère la mémoire
              images->fondMenu = genererFondMenu(elem, 1);
              //on régénère également le pack options pour afficher les changements s'il y en a eu
              images2 = genererPackOptions(elem2, al_get_backbuffer(fenetre), config->keyMap);
              al_set_target_bitmap(al_get_backbuffer(fenetre)); //on recible la fenêtre pour y afficher les images
            }
            break;
          case NIVEAU:
            if((ev.mouse.button & 1) && niveau < 30) //s'il y a un clic gauche sur ce bouton et que niveau < 30
              niveau++;
            else if((ev.mouse.button & 2) && niveau > 1) //s'il y a un clic droit sur ce bouton et que niveau > 0
              niveau--;
            break;
          case AIDE:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              al_uninstall_mouse();
              menuAide(fenetre, images->fondMenuAide, images->boutonOkOn, images->boutonOkOff, elem->rectMenuAide, elem->rectOk, elem->rectNSL, 0, 0, 0);
              al_install_mouse();
              al_register_event_source(event_queue_menu, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
            }
            break;
          case OPTIONS:
            if(ev.mouse.button & 1) //s'il y a un clic gauche sur ce bouton
            {
              al_uninstall_mouse();
              menuOptions(fenetre, config, elem2, images2, sons);
              al_install_mouse();
              al_register_event_source(event_queue_menu, al_get_mouse_event_source()); //puis on reprend les évènements de la souris en compte
              //on régénère le pack options pour afficher les changements s'il y en a eu
              images2 = genererPackOptions(elem2, al_get_backbuffer(fenetre), config->keyMap);
              al_set_target_bitmap(al_get_backbuffer(fenetre));
            }
            break;
        }
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_S:
          if(legalInput)
          {
            keys[SOUND] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_D:
          if(legalInput)
          {
            keys[THEME] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_F:
          if(legalInput)
          {
            keys[FX] = true;
            legalInput = false;
          }
          break;
        default:
          if(legalInput)
          {
            pressedKeys[ev.keyboard.keycode] = true;
            //on reagarde quelle touche a été appuyée
            for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
            {
              if(pressedKeys[i])
              {
                enfiler(cheatStr, i); //on l'ajoute à la file
                cptCheat++; //on augmente le compteur d'input
                printf("cptCheat: %d\n", cptCheat);
              }
            }
            if(cptCheat >= 5)
            {
              cheatInputVerif(config, cheatStr);
              cptCheat = 0;
            }
            legalInput = false;
          }
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_S:
          keys[SOUND] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_D:
          keys[THEME] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_F:
          keys[FX] = false;
          legalInput = true;
          break;
        default:
          pressedKeys[ev.keyboard.keycode] = false;
          legalInput = true;
          break;
      }
    }

    if(redraw && al_is_event_queue_empty(event_queue_menu)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherMenuPrincipal(images, elem, bouton, niveau); //on affiche le menu à nouveau
      jouerSon(config->sound, sons, NULL, false); //va jouer ou arrêter le son du jeu
    }
  }

  //puis à la fin du menu, on libère la mémoire
  libererMemoireSon(sons);
  destroyGameConfig(config);
  destroyElementsFondMenu(elem);
  destroyPackMenu(images);
  destroyElementsFondOptions(elem2);
  destroyPackOptions(images2);
  al_destroy_timer(timer_menu);
  al_destroy_event_queue(event_queue_menu);
  libererMemoire(fenetre);
}

int estSurUnBouton(elementsFondMenu *elem, int x, int y)
{
  if(x >= elem->rectJouer->x && x <= elem->rectJouer->x2 && y >= elem->rectJouer->y && y <= elem->rectJouer->y2)//si la souris est sur le bouton Jouer
    return JOUER;
  if(x >= elem->rectNiveau->x && x <= elem->rectNiveau->x2 && y >= elem->rectNiveau->y && y <= elem->rectNiveau->y2)//si elle est sur le bouton de niveau
    return NIVEAU;
  if(x >= elem->rectAide->x && x <= elem->rectAide->x2 && y >= elem->rectAide->y && y <= elem->rectAide->y2)//si elle est sur le bouton d'aide
    return AIDE;
  if(x >= elem->rectOptions->x && x <= elem->rectOptions->x2 && y >= elem->rectOptions->y && y <= elem->rectOptions->y2)//si elle est sur le bouton d'options
    return OPTIONS;
  else //si elle n'est sur aucun des trois
    return OFF;
}

void afficherMenuPrincipal(packMenu *images, elementsFondMenu *elem, int boutonOn, int niveau)
{
  //on charge l'image de fond
  al_draw_bitmap(images->fondMenu, 0, 0, 0);

  //puis les boutons
  switch(boutonOn)
  {
    case OFF:
      al_draw_bitmap(images->boutonJouerOff, elem->rectJouer->x + elem->rectJouer->t, elem->rectJouer->y + elem->rectJouer->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectAide->x + elem->rectAide->t, elem->rectAide->y + elem->rectAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectOptions->x + elem->rectOptions->t, elem->rectOptions->y + elem->rectOptions->t, 0);
      switch(niveau)
      {
        case 1:
          al_draw_bitmap(images->boutonNiveau1Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 2:
          al_draw_bitmap(images->boutonNiveau2Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 3:
          al_draw_bitmap(images->boutonNiveau3Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 4:
          al_draw_bitmap(images->boutonNiveau4Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 5:
          al_draw_bitmap(images->boutonNiveau5Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 6:
          al_draw_bitmap(images->boutonNiveau6Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 7:
          al_draw_bitmap(images->boutonNiveau7Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 8:
          al_draw_bitmap(images->boutonNiveau8Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 9:
          al_draw_bitmap(images->boutonNiveau9Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 10:
          al_draw_bitmap(images->boutonNiveau10Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 11:
          al_draw_bitmap(images->boutonNiveau11Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 12:
          al_draw_bitmap(images->boutonNiveau12Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 13:
          al_draw_bitmap(images->boutonNiveau13Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 14:
          al_draw_bitmap(images->boutonNiveau14Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 15:
          al_draw_bitmap(images->boutonNiveau15Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 16:
          al_draw_bitmap(images->boutonNiveau16Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 17:
          al_draw_bitmap(images->boutonNiveau17Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 18:
          al_draw_bitmap(images->boutonNiveau18Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 19:
          al_draw_bitmap(images->boutonNiveau19Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 20:
          al_draw_bitmap(images->boutonNiveau20Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 21:
          al_draw_bitmap(images->boutonNiveau21Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 22:
          al_draw_bitmap(images->boutonNiveau22Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 23:
          al_draw_bitmap(images->boutonNiveau23Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 24:
          al_draw_bitmap(images->boutonNiveau24Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 25:
          al_draw_bitmap(images->boutonNiveau25Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 26:
          al_draw_bitmap(images->boutonNiveau26Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 27:
          al_draw_bitmap(images->boutonNiveau27Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 28:
          al_draw_bitmap(images->boutonNiveau28Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 29:
          al_draw_bitmap(images->boutonNiveau29Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 30:
          al_draw_bitmap(images->boutonNiveau30Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
      }
      break;
    case JOUER:
      al_draw_bitmap(images->boutonJouerOn, elem->rectJouer->x + elem->rectJouer->t, elem->rectJouer->y + elem->rectJouer->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectAide->x + elem->rectAide->t, elem->rectAide->y + elem->rectAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectOptions->x + elem->rectOptions->t, elem->rectOptions->y + elem->rectOptions->t, 0);
      switch(niveau)
      {
        case 1:
          al_draw_bitmap(images->boutonNiveau1Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 2:
          al_draw_bitmap(images->boutonNiveau2Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 3:
          al_draw_bitmap(images->boutonNiveau3Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 4:
          al_draw_bitmap(images->boutonNiveau4Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 5:
          al_draw_bitmap(images->boutonNiveau5Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 6:
          al_draw_bitmap(images->boutonNiveau6Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 7:
          al_draw_bitmap(images->boutonNiveau7Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 8:
          al_draw_bitmap(images->boutonNiveau8Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 9:
          al_draw_bitmap(images->boutonNiveau9Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 10:
          al_draw_bitmap(images->boutonNiveau10Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 11:
          al_draw_bitmap(images->boutonNiveau11Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 12:
          al_draw_bitmap(images->boutonNiveau12Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 13:
          al_draw_bitmap(images->boutonNiveau13Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 14:
          al_draw_bitmap(images->boutonNiveau14Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 15:
          al_draw_bitmap(images->boutonNiveau15Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 16:
          al_draw_bitmap(images->boutonNiveau16Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 17:
          al_draw_bitmap(images->boutonNiveau17Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 18:
          al_draw_bitmap(images->boutonNiveau18Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 19:
          al_draw_bitmap(images->boutonNiveau19Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 20:
          al_draw_bitmap(images->boutonNiveau20Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 21:
          al_draw_bitmap(images->boutonNiveau21Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 22:
          al_draw_bitmap(images->boutonNiveau22Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 23:
          al_draw_bitmap(images->boutonNiveau23Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 24:
          al_draw_bitmap(images->boutonNiveau24Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 25:
          al_draw_bitmap(images->boutonNiveau25Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 26:
          al_draw_bitmap(images->boutonNiveau26Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 27:
          al_draw_bitmap(images->boutonNiveau27Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 28:
          al_draw_bitmap(images->boutonNiveau28Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 29:
          al_draw_bitmap(images->boutonNiveau29Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 30:
          al_draw_bitmap(images->boutonNiveau30Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
      }
      break;
    case AIDE:
      al_draw_bitmap(images->boutonJouerOff, elem->rectJouer->x + elem->rectJouer->t, elem->rectJouer->y + elem->rectJouer->t, 0);
      al_draw_bitmap(images->boutonAideOn, elem->rectAide->x + elem->rectAide->t, elem->rectAide->y + elem->rectAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectOptions->x + elem->rectOptions->t, elem->rectOptions->y + elem->rectOptions->t, 0);
      switch(niveau)
      {
        case 1:
          al_draw_bitmap(images->boutonNiveau1Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 2:
          al_draw_bitmap(images->boutonNiveau2Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 3:
          al_draw_bitmap(images->boutonNiveau3Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 4:
          al_draw_bitmap(images->boutonNiveau4Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 5:
          al_draw_bitmap(images->boutonNiveau5Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 6:
          al_draw_bitmap(images->boutonNiveau6Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 7:
          al_draw_bitmap(images->boutonNiveau7Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 8:
          al_draw_bitmap(images->boutonNiveau8Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 9:
          al_draw_bitmap(images->boutonNiveau9Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 10:
          al_draw_bitmap(images->boutonNiveau10Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 11:
          al_draw_bitmap(images->boutonNiveau11Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 12:
          al_draw_bitmap(images->boutonNiveau12Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 13:
          al_draw_bitmap(images->boutonNiveau13Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 14:
          al_draw_bitmap(images->boutonNiveau14Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 15:
          al_draw_bitmap(images->boutonNiveau15Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 16:
          al_draw_bitmap(images->boutonNiveau16Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 17:
          al_draw_bitmap(images->boutonNiveau17Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 18:
          al_draw_bitmap(images->boutonNiveau18Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 19:
          al_draw_bitmap(images->boutonNiveau19Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 20:
          al_draw_bitmap(images->boutonNiveau20Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 21:
          al_draw_bitmap(images->boutonNiveau21Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 22:
          al_draw_bitmap(images->boutonNiveau22Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 23:
          al_draw_bitmap(images->boutonNiveau23Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 24:
          al_draw_bitmap(images->boutonNiveau24Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 25:
          al_draw_bitmap(images->boutonNiveau25Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 26:
          al_draw_bitmap(images->boutonNiveau26Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 27:
          al_draw_bitmap(images->boutonNiveau27Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 28:
          al_draw_bitmap(images->boutonNiveau28Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 29:
          al_draw_bitmap(images->boutonNiveau29Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 30:
          al_draw_bitmap(images->boutonNiveau30Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
      }
      break;
    case OPTIONS:
      al_draw_bitmap(images->boutonJouerOff, elem->rectJouer->x + elem->rectJouer->t, elem->rectJouer->y + elem->rectJouer->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectAide->x + elem->rectAide->t, elem->rectAide->y + elem->rectAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOn, elem->rectOptions->x + elem->rectOptions->t, elem->rectOptions->y + elem->rectOptions->t, 0);
      switch(niveau)
      {
        case 1:
          al_draw_bitmap(images->boutonNiveau1Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 2:
          al_draw_bitmap(images->boutonNiveau2Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 3:
          al_draw_bitmap(images->boutonNiveau3Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 4:
          al_draw_bitmap(images->boutonNiveau4Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 5:
          al_draw_bitmap(images->boutonNiveau5Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 6:
          al_draw_bitmap(images->boutonNiveau6Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 7:
          al_draw_bitmap(images->boutonNiveau7Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 8:
          al_draw_bitmap(images->boutonNiveau8Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 9:
          al_draw_bitmap(images->boutonNiveau9Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 10:
          al_draw_bitmap(images->boutonNiveau10Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 11:
          al_draw_bitmap(images->boutonNiveau11Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 12:
          al_draw_bitmap(images->boutonNiveau12Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 13:
          al_draw_bitmap(images->boutonNiveau13Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 14:
          al_draw_bitmap(images->boutonNiveau14Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 15:
          al_draw_bitmap(images->boutonNiveau15Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 16:
          al_draw_bitmap(images->boutonNiveau16Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 17:
          al_draw_bitmap(images->boutonNiveau17Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 18:
          al_draw_bitmap(images->boutonNiveau18Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 19:
          al_draw_bitmap(images->boutonNiveau19Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 20:
          al_draw_bitmap(images->boutonNiveau20Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 21:
          al_draw_bitmap(images->boutonNiveau21Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 22:
          al_draw_bitmap(images->boutonNiveau22Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 23:
          al_draw_bitmap(images->boutonNiveau23Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 24:
          al_draw_bitmap(images->boutonNiveau24Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 25:
          al_draw_bitmap(images->boutonNiveau25Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 26:
          al_draw_bitmap(images->boutonNiveau26Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 27:
          al_draw_bitmap(images->boutonNiveau27Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 28:
          al_draw_bitmap(images->boutonNiveau28Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 29:
          al_draw_bitmap(images->boutonNiveau29Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 30:
          al_draw_bitmap(images->boutonNiveau30Off, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
      }
      break;
    case NIVEAU:
      al_draw_bitmap(images->boutonJouerOff, elem->rectJouer->x + elem->rectJouer->t, elem->rectJouer->y + elem->rectJouer->t, 0);
      al_draw_bitmap(images->boutonAideOff, elem->rectAide->x + elem->rectAide->t, elem->rectAide->y + elem->rectAide->t, 0);
      al_draw_bitmap(images->boutonOptionsOff, elem->rectOptions->x + elem->rectOptions->t, elem->rectOptions->y + elem->rectOptions->t, 0);
      switch(niveau)
      {
        case 1:
          al_draw_bitmap(images->boutonNiveau1On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 2:
          al_draw_bitmap(images->boutonNiveau2On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 3:
          al_draw_bitmap(images->boutonNiveau3On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 4:
          al_draw_bitmap(images->boutonNiveau4On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 5:
          al_draw_bitmap(images->boutonNiveau5On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 6:
          al_draw_bitmap(images->boutonNiveau6On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 7:
          al_draw_bitmap(images->boutonNiveau7On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 8:
          al_draw_bitmap(images->boutonNiveau8On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 9:
          al_draw_bitmap(images->boutonNiveau9On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 10:
          al_draw_bitmap(images->boutonNiveau10On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 11:
          al_draw_bitmap(images->boutonNiveau11On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 12:
          al_draw_bitmap(images->boutonNiveau12On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 13:
          al_draw_bitmap(images->boutonNiveau13On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 14:
          al_draw_bitmap(images->boutonNiveau14On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 15:
          al_draw_bitmap(images->boutonNiveau15On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 16:
          al_draw_bitmap(images->boutonNiveau16On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 17:
          al_draw_bitmap(images->boutonNiveau17On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 18:
          al_draw_bitmap(images->boutonNiveau18On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 19:
          al_draw_bitmap(images->boutonNiveau19On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 20:
          al_draw_bitmap(images->boutonNiveau20On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 21:
          al_draw_bitmap(images->boutonNiveau21On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 22:
          al_draw_bitmap(images->boutonNiveau22On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 23:
          al_draw_bitmap(images->boutonNiveau23On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 24:
          al_draw_bitmap(images->boutonNiveau24On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 25:
          al_draw_bitmap(images->boutonNiveau25On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 26:
          al_draw_bitmap(images->boutonNiveau26On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 27:
          al_draw_bitmap(images->boutonNiveau27On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 28:
          al_draw_bitmap(images->boutonNiveau28On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 29:
          al_draw_bitmap(images->boutonNiveau29On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
        case 30:
          al_draw_bitmap(images->boutonNiveau30On, elem->rectNiveau->x + elem->rectNiveau->t, elem->rectNiveau->y + elem->rectNiveau->t, 0);
          break;
      }
      break;
  }

  //on met à jour la fenêtre
  al_flip_display();
}

void libererMemoire(ALLEGRO_DISPLAY *fenetre)
{
  al_destroy_display(fenetre); //on détruit la fenêtre
}

void cheatInputVerif(gameConfig *config, File *cheatStr)
{
  //quand on a ajouté 5 input à la file
  bool verif[5] = {false, false, false, false, false};
  for(int i = 0; i < 5; i++)
  {
    switch(defiler(cheatStr))
    {
      case ALLEGRO_KEY_C:
        if(i == 0)
          verif[i] = true;
        else
          verif[i] = false;
        break;
      case ALLEGRO_KEY_H:
        if(i == 1)
          verif[i] = true;
        else
          verif[i] = false;
        break;
      case ALLEGRO_KEY_E:
        if(i == 2)
          verif[i] = true;
        else
          verif[i] = false;
        break;
      case ALLEGRO_KEY_A:
        if(i == 3)
          verif[i] = true;
        else
          verif[i] = false;
        break;
      case ALLEGRO_KEY_T:
        if(i == 4)
          verif[i] = true;
        else
          verif[i] = false;
        break;
      default:
        verif[i] = false;
        break;
    }
  }
  bool valide = true;
  for(int i = 0; i < 5; i++)
  {
    if(!verif[i])
      valide = false;
  }
  if(valide)
  {
    if(config->cheatFunctions)
      config->cheatFunctions = false;
    else
      config->cheatFunctions = true;
  }
}
