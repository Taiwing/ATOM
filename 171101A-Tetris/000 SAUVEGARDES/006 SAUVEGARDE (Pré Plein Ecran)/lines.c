#include "lines.h"

void highLignes(gameScreen *screen, int lignes)
{
  int place = testLignes(lignes);
  if(place) //si le nouveau lignes est supérieur à l'un de ceux du top (si place != 0)
  {
    char joueur[4]; //va stocker le nom du joueur
    lignesInput(screen, joueur, lignes); //le joueur rentre son nom (et le panneau de lignes est affiché)
    nouveauLignes(joueur, lignes, place); //on rentre les nouvelles données
  }
}

void lireFichierLignes(char J[5][4], char S[5][7])
{
  FILE *lignes = fopen("lignes.lin", "r");

  char ligne[10] = ""; //variable qui va nous servir à lire le fichier

  for(int i = 0; i < 5; i++) //on répète la boucle cinq fois
  {
    fgets(ligne, 10, lignes); //on récupère la ligne
    for(int p = 0; p < 10; p++)
    {
      if(ligne[p] == '\n')
        ligne[p] = '\0';
    }

    for(int j = 0; j < 4; j++) //on récupère le nom du joueur
    {
      if(j < 3)
        J[i][j] = ligne[j];
      else
        J[i][j] = '\0';
    }

    for(int k = 3; k < strlen(ligne) + 1; k++) //on récupère le lignes
    {
      if(k < strlen(ligne))
        S[i][k-3] = ligne[k];
      else
        S[i][k-3] = '\0';
    }
  }

  fclose(lignes);
}

int testLignes(int lignes)
{
  char J[5][4]; //va stocker le nom des joueurs
  char S[5][7]; //va stocker les lignes
  lireFichierLignes(J, S); //on récupère les valeurs du top

  for(int i = 1; i < 6; i++)
  {
    if(lignes > atoi(S[i-1]))
      return i;
  }

  return 0; //si aucun des tests n'est concluant
}

void nouveauLignes(char joueur[4], int lignes, int place)
{
  char strLignes[7];
  sprintf(strLignes, "%d", lignes); //on récupère le nouveau lignes dans un string (heu heu heu LOL)

  //on récupère les données du fichier en double
  char J[5][4], J2[5][4]; //va stocker le nom des joueurs
  char S[5][7], S2[5][7]; //va stocker les lignes
  lireFichierLignes(J, S); //on récupère les valeurs
  lireFichierLignes(J2, S2); //on récupère les valeurs

  //on place le nouveau nom du joueur et le nouveau lignes dans les tableaux récupérés dans le fichier
  for(int i = 0; i < 5; i++)
  {
    if(i == (place - 1)) //quand on arrive à l'endroit où stocker le nouveau lignes
    {
      for(int j = 0; j < 4; j++)
      {
        J2[i][j] = joueur[j]; //on y met le nom du joueur
      }
      for(int k = 0; k < 7; k++)
      {
        S2[i][k] = strLignes[k]; //puis le lignes
      }
    }
    else if(i > (place - 1)) //quand on est après, on copie les anciens lignes à leur nouvelle place
    {
      for(int j = 0; j < 4; j++)
      {
        J2[i][j] = J[i - 1][j];
      }
      for(int k = 0; k < 7; k++)
      {
        S2[i][k] = S[i - 1][k];
      }
    }
  }

  //on ouvre le fichier en écriture
  FILE *fLignes = fopen("lignes.lin", "w+"); //on lit et écrit dans le fichier en effaçant son contenu au préalable

  //on y met le nouveau tableau de lignes
  for(int i = 0; i < 5; i++)
  {
    fputs(J2[i], fLignes); //on met le nom du joueur
    fputs(S2[i], fLignes); //puis le lignes
    fputc('\n', fLignes); //puis on saute une ligne
  }

  //on ferme le fichier
  fclose(fLignes);
}

void lignesInput(gameScreen *screen, char joueur[4], int lignes)
{
  elementsFondLignesInput *elem = genererElementsFondLignesInput(); //on génére les éléments du fond de lignesInput
  packLignesInput *images = genererPackLignesInput(screen->buffer, elem, lignes); //on génère les images nécessaires
  al_set_target_bitmap(al_get_backbuffer(screen->display)); //on recible la fenêtre pour y afficher les images

  //on charge la liste d'éléments pour la fonction "estSurUnBouton"
  Liste *lElem = initialisationListe();
  chargerListeElemFondLignesInput(screen, elem, lElem);

  //variables de la boucle
  bool continuer = true; //valeur booléenne de la boucle principale
  bool redraw = false; //va déterminer quand on va redessiner l'image du menu
  int boutonOk = OFF; //va déterminer si la souris se trouve sur le bouton OK
  joueur[0] = '*'; //valeurs par défaut du nom du joueur
  joueur[1] = '*';
  joueur[2] = '*';
  joueur[3] = '\0';
  int lettre = 1; //va suivre la position du curseur dans la chaîne de caractère "joueur"
  bool key[ALLEGRO_KEY_MAX] = {false}; //va déterminer quelle touche a été pressée
  bool legalInput = true; //va servir à limiter l'input des touches

  //on initialise le timer
  ALLEGRO_TIMER *timer_lignes = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_lignes = al_create_event_queue();
  al_register_event_source(event_queue_lignes, al_get_display_event_source(screen->display)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_lignes, al_get_timer_event_source(timer_lignes)); //on lie la file au timer
  al_register_event_source(event_queue_lignes, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_lignes, al_get_keyboard_event_source()); //puis au clavier

  //on démarre le timer
  al_start_timer(timer_lignes);

  while(continuer) //on lance la boucle du menu
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_lignes, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      //gestion des input
      for(int i = 0; i < ALLEGRO_KEY_MAX; i++) //on parcourt le tableau des touches
      {
        if(key[i]) //si une touche a été appuyée
        {
          switch(i) //on détermine laquelle
          {
            case ALLEGRO_KEY_A:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'A';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_Z:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'Z';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_E:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'E';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_R:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'R';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_T:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'T';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_Y:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'Y';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_U:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'U';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_I:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'I';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_O:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'O';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_P:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'P';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_Q:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'Q';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_S:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'S';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_D:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'D';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_F:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'F';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_G:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'G';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_H:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'H';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_J:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'J';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_K:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'K';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_L:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'L';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_M:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'M';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_W:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'W';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_X:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'X';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_C:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'C';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_V:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'V';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_B:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'B';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_N:
              if(lettre < 4)
              {
                joueur[lettre - 1] = 'N';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_0:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '0';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_1:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '1';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_2:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '2';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_3:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '3';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_4:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '4';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_5:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '5';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_6:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '6';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_7:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '7';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_8:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '8';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_9:
              if(lettre < 4)
              {
                joueur[lettre - 1] = '9';
                if(lettre < 4)
                  lettre++;
              }
              key[i] = false;
              break;
            case ALLEGRO_KEY_ENTER:
              continuer = false; //on enregistre le lignes
              break;
            case ALLEGRO_KEY_BACKSPACE:
              if(lettre > 0)
              {
                if(lettre > 1)
                  lettre--;
                joueur[lettre - 1] = '*';
              }
              key[i] = false;
              break;
          }
        }
      }
      redraw = true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) //si la souris bouge
    {
      //on vérifie si elle est ou non sur le bouton OK
      boutonOk = estSurUnBoutonLignes(lElem, ev.mouse.x, ev.mouse.y);
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) //si un bouton de la souris est relâché
    {
      //on vérifie si elle est ou non sur le bouton OK
      boutonOk = estSurUnBoutonLignes(lElem, ev.mouse.x, ev.mouse.y);

      if(boutonOk == ON && (ev.mouse.button & 1)) //si c'est le cas
      {
        continuer = false; //on sort du menu d'aide
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_A:
          if(legalInput)
          {
            key[ALLEGRO_KEY_A] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_Z:
          if(legalInput)
          {
            key[ALLEGRO_KEY_Z] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_E:
          if(legalInput)
          {
            key[ALLEGRO_KEY_E] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_R:
          if(legalInput)
          {
            key[ALLEGRO_KEY_R] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_T:
          if(legalInput)
          {
            key[ALLEGRO_KEY_T] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_Y:
          if(legalInput)
          {
            key[ALLEGRO_KEY_Y] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_U:
          if(legalInput)
          {
            key[ALLEGRO_KEY_U] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_I:
          if(legalInput)
          {
            key[ALLEGRO_KEY_I] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_O:
          if(legalInput)
          {
            key[ALLEGRO_KEY_O] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_P:
          if(legalInput)
          {
            key[ALLEGRO_KEY_P] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_Q:
          if(legalInput)
          {
            key[ALLEGRO_KEY_Q] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_S:
          if(legalInput)
          {
            key[ALLEGRO_KEY_S] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_D:
          if(legalInput)
          {
            key[ALLEGRO_KEY_D] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_F:
          if(legalInput)
          {
            key[ALLEGRO_KEY_F] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_G:
          if(legalInput)
          {
            key[ALLEGRO_KEY_G] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_H:
          if(legalInput)
          {
            key[ALLEGRO_KEY_H] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_J:
          if(legalInput)
          {
            key[ALLEGRO_KEY_J] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_K:
          if(legalInput)
          {
            key[ALLEGRO_KEY_K] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_L:
          if(legalInput)
          {
            key[ALLEGRO_KEY_L] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_M:
          if(legalInput)
          {
            key[ALLEGRO_KEY_M] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_W:
          if(legalInput)
          {
            key[ALLEGRO_KEY_W] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_X:
          if(legalInput)
          {
            key[ALLEGRO_KEY_X] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_C:
          if(legalInput)
          {
            key[ALLEGRO_KEY_C] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_V:
          if(legalInput)
          {
            key[ALLEGRO_KEY_V] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_B:
          if(legalInput)
          {
            key[ALLEGRO_KEY_B] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_N:
          if(legalInput)
          {
            key[ALLEGRO_KEY_N] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_0:
          if(legalInput)
          {
            key[ALLEGRO_KEY_0] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_1:
          if(legalInput)
          {
            key[ALLEGRO_KEY_1] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_2:
          if(legalInput)
          {
            key[ALLEGRO_KEY_2] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_3:
          if(legalInput)
          {
            key[ALLEGRO_KEY_3] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_4:
          if(legalInput)
          {
            key[ALLEGRO_KEY_4] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_5:
          if(legalInput)
          {
            key[ALLEGRO_KEY_5] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_6:
          if(legalInput)
          {
            key[ALLEGRO_KEY_6] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_7:
          if(legalInput)
          {
            key[ALLEGRO_KEY_7] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_8:
          if(legalInput)
          {
            key[ALLEGRO_KEY_8] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_9:
          if(legalInput)
          {
            key[ALLEGRO_KEY_9] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_ENTER:
          if(legalInput)
          {
            key[ALLEGRO_KEY_ENTER] = true;
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_BACKSPACE:
          if(legalInput)
          {
            key[ALLEGRO_KEY_BACKSPACE] = true;
            legalInput = false;
          }
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_A:
          key[ALLEGRO_KEY_A] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_Z:
          key[ALLEGRO_KEY_Z] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_E:
          key[ALLEGRO_KEY_E] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_R:
          key[ALLEGRO_KEY_R] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_T:
          key[ALLEGRO_KEY_T] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_Y:
          key[ALLEGRO_KEY_Y] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_U:
          key[ALLEGRO_KEY_U] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_I:
          key[ALLEGRO_KEY_I] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_O:
          key[ALLEGRO_KEY_O] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_P:
          key[ALLEGRO_KEY_P] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_Q:
          key[ALLEGRO_KEY_Q] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_S:
          key[ALLEGRO_KEY_S] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_D:
          key[ALLEGRO_KEY_D] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_F:
          key[ALLEGRO_KEY_F] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_G:
          key[ALLEGRO_KEY_G] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_H:
          key[ALLEGRO_KEY_H] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_J:
          key[ALLEGRO_KEY_J] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_K:
          key[ALLEGRO_KEY_K] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_L:
          key[ALLEGRO_KEY_L] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_M:
          key[ALLEGRO_KEY_M] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_W:
          key[ALLEGRO_KEY_W] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_X:
          key[ALLEGRO_KEY_X] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_C:
          key[ALLEGRO_KEY_C] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_V:
          key[ALLEGRO_KEY_V] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_B:
          key[ALLEGRO_KEY_B] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_N:
          key[ALLEGRO_KEY_N] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_0:
          key[ALLEGRO_KEY_0] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_1:
          key[ALLEGRO_KEY_1] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_2:
          key[ALLEGRO_KEY_2] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_3:
          key[ALLEGRO_KEY_3] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_4:
          key[ALLEGRO_KEY_4] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_5:
          key[ALLEGRO_KEY_5] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_6:
          key[ALLEGRO_KEY_6] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_7:
          key[ALLEGRO_KEY_7] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_8:
          key[ALLEGRO_KEY_8] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_9:
          key[ALLEGRO_KEY_9] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_ENTER:
          key[ALLEGRO_KEY_ENTER] = false;
          legalInput = true;
          break;
        case ALLEGRO_KEY_BACKSPACE:
          key[ALLEGRO_KEY_BACKSPACE] = false;
          legalInput = true;
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
    {
      resizeGameScreen(screen);
      dechargerListe(lElem);
      chargerListeElemFondLignesInput(screen, elem, lElem);
    }

    if(redraw && al_is_event_queue_empty(event_queue_lignes)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherLignesInput(screen, images, elem, boutonOk, joueur); //on affiche l'image de lignesInput à nouveau
    }
  }

  //on libère la mémoire
  detruireListe(lElem);
  al_destroy_timer(timer_lignes);
  al_destroy_event_queue(event_queue_lignes);
  destroyElementsFondLignesInput(elem);
  destroyPackLignesInput(images);
}

int estSurUnBoutonLignes(Liste *lElem, int x, int y)
{
  if(posMouse(lElem, x, y))
    return ON;
  else
    return OFF;
}

void afficherLignesInput(gameScreen *screen, packLignesInput *images, elementsFondLignesInput *elem, int boutonOk, char joueur[4])
{
  //on cible le buffer du jeu sur lequel on va dessiner
  al_set_target_bitmap(screen->buffer);
  al_clear_to_color(al_map_rgb(0, 0, 0));

  al_draw_bitmap(images->fond, 0, 0, 0); //on affiche le fond de lignesInput

  switch(boutonOk) //puis le bouton OK
  {
    case OFF:
      al_draw_bitmap(images->boutonOkOff, elem->rectOk->x + elem->rectOk->t, elem->rectOk->y + elem->rectOk->t, 0);
      break;
    case ON:
      al_draw_bitmap(images->boutonOkOn, elem->rectOk->x + elem->rectOk->t, elem->rectOk->y + elem->rectOk->t, 0);
      break;
  }

  //et le nom du joueur dans le rectangle d'input
  char joueurAffiche[4];
  for(int i = 0; i < 4; i++) //on copie la chaîne pour l'afficher sans les '*'
  {
    if(joueur[i] != '*')
    {
      joueurAffiche[i] = joueur[i];
    }
    else
    {
      joueurAffiche[i] = '\0';
    }
  }
  coord *rect = elem->rectInput;
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 20, 0); //on charge la police "Gameplay"
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + 10, ALLEGRO_ALIGN_CENTRE, joueurAffiche);

  //on libère la mémoire
  al_destroy_font(font);

  //on recible le backbuffer
  al_set_target_backbuffer(screen->display);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_scaled_bitmap(screen->buffer, 0, 0, SCREEN_W, SCREEN_H, screen->scaleX, screen->scaleY, screen->scaleW, screen->scaleH, 0);
  al_flip_display();
}

void chargerListeElemFondLignesInput(gameScreen *screen, elementsFondLignesInput *elem, Liste *lElem)
{
  elemToList(screen, lElem, elem->rectOk);
}
