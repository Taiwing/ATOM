#include "include/marathon.h"

void partieMarathon(gameScreen *screen, packImages *images, int niveauChoisi, gameConfig *config, packSons *sons, elements *elem)
{
  //on régénère le fond de la partie
  regenererPackImages(images, elem, PIPARTIE, MARATHON, NULL, config->keyMap, 0);

  //on redémarre la musique du jeu
  if(config->sound->soundOnOff[0])
  {
    config->sound->soundOnOff[0] = false;
    jouerSon(config->sound, sons, 0, false); //va arrêter le son du jeu
    config->sound->soundOnOff[0] = true;
  }

  //on initialise le timer
  ALLEGRO_TIMER *timer_partieMarathon = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde
  al_install_mouse();

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_partieMarathon = al_create_event_queue();
  al_register_event_source(event_queue_partieMarathon, al_get_display_event_source(screen->display)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_partieMarathon, al_get_timer_event_source(timer_partieMarathon)); //on lie la file au timer
  al_register_event_source(event_queue_partieMarathon, al_get_mouse_event_source()); //puis à la souris

  //VARIABLES DU JEU:
  gameData *data = initialiserGameData(niveauChoisi); //on initialise la structure de données du jeu

  //on lance le compte à rebours avant de commencer la partie
  troisDeuxUn(screen, images->imagesPartie, elem, 0, 0, 0, 0);

  al_register_event_source(event_queue_partieMarathon, al_get_keyboard_event_source()); //puis on prend en compte le clavier

  //on démarre le timer
  al_start_timer(timer_partieMarathon);

  //boucle principale de la partie
  while(data->continuer)
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_partieMarathon, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      //on vérifie le score et on augmente le niveau s'il faut
      leveling(data);

      //on regarde si une pièce va se bloquer
      if(lockTest(data))
      {
        if(data->timerLock == 0)
          enfiler(data->gameEv, TOUCHDOWN); //la pièce touche le sol
        //on déclenche un timer d'une demi-seconde pour laisser au joueur la possibilité de bouger pendant cet interval
        data->timerLock++;
        if(data->timerLock == 30) //s'il s'est écoulé une demi-seconde
        {
          data->nextTetro = true; //on change de pièce
          data->timerLock = 0; //on reset le timer
          enfiler(data->gameEv, LOCKED); //la pièce est bloquée
        }
      }
      else
      {
        data->timerLock = 0; //on reset le timer
      }

      //on ne fait le test que quand lComplete est faux (pour répéter les instructions après le prochain test), et que le tétro précédent est locké
      if(!data->lComplete && data->nextTetro)
      {
        data->lComplete = ligneComplete(data); //on vérifie si le joueur a complété des lignes, et on envoit l'évènement dans sounEv
        if(data->TSpin)//s'il y a TSpin
        {
          enfiler(data->gameEv, defiler(data->gameEv) + 5); //s'il y a TSpin on remplace la valeur qu'on a mis dans data->gameEv
        }
      }

      if(data->lComplete) //si c'est le cas
      {
        //Animation de 1/2 secondes où les lignes disparaissant clignotent
        if(data->timerAnimDisp < 30) //l'animation va durer 30 frames
        {
          data->timerAnimDisp++; //on incrémente le timer pour compter les frames
          if((data->timerAnimDisp % 3) == 0) //si timerAnimDisp est pair (donc toutes les trois frames)
          {
            if(!data->animDisp) //on alterne toutes les trois frames
              data->animDisp = true; //on affiche les blocs des lignes pleines en blanc
            else
              data->animDisp = false; //on ne le fait pas (ça devrait donc clignoter)
          }
        }
        else
        {
          data->nbLignes = enleverLignes(data); //on enlève les lignes du tableau et on fait descendre celles du dessus s'il y en a
          data->lignes += data->nbLignes; //on ajoute le nombre de lignes enlevées au total
          if(data->TSpin)
          {
            data->nbLignes += 7; //on ajoute 7 pour compter le T-Spin au score
            data->TSpin = false; //puis on reset la valeur de TSpin
          }
          scoring(data->nbLignes, data); //puis on calcule le score
          data->lComplete = false; //puis on remet lComplete à false
          data->lc = true; //va dire à la prochaine boucle qu'il y a eu ligne complète
          data->timerAnimDisp = 0; //on remet le timer à 0 pour la prochaine fois
          data->animDisp = false; //pour que les lignes pleines arrête de clignoter
        }
      }
      else //sinon, on exécute la boucle normalement
      {
        //on vérifie si le joueur a perdu
        if(data->perdu)
        {
          enfiler(data->gameEv, GAMEOVER); //on envoit GAMEOVER à la fonction de son
          data->continuer = false; //si c'est le cas, alors on revient au menu principal
        }
        else if(data->niveau == 32) //ou s'il a gagné
        {
          data->continuer = false;
          data->victoire = true; //alors on indique à la boucle que le jouur a gagné
        }

        //on vérifie s'il faut placer la nouvelle pièce
        if(data->nextTetro)
        {
          if(data->TSpin) //si la pièce se bloque sans faire diparaître de lignes avec T-Spin
          {
            scoring(7, data); //on augmente le score par la valeur correspondante
            data->TSpin = false; //puis on reset la valeur de TSpin
            enfiler(data->gameEv, STSPIN);
          }
          else if(!data->lc) //s'il n'y a pas eu de lignes complétées au dernier coup ni de T-Spin
          {
            data->dernierCoup = 0; //alors le dernier coup était "inutile"
          }
          data->lc = false;

          lockTetro(data); //on bloque le tétro actuel avant d'en changer

          if(data->holdPieceOn) //si le joueur a utilisé la fonction holdPiece avant le changement de tétro
            data->holdPieceOn = false; //il a a nouveau le droit de l'utiliser

          //on met le tetroSuivant dans tetroActuel, et on le place dans la grille
          if(!placerTetro(data)) //si ça ne marche pas (s'il y a déjà un tétro à cet endroit)
          {
            data->perdu = true; //alors le joueur a perdu
            data->nextTetro = false;
          }
          else
          {
            selectionAleatoireTetromino(data); //on sélectionne la pièce suivante
            data->nbTetro++; //on passe au tétro suivant dans la liste
            if(data->nbTetro == 7) //si on est arrivé au bout
              data->nbTetro = 0; //on revient au début
            data->timerVitesse = 0; //on remet le timer à 0 pour qu'elle ne se redéplace pas tout de suite
            data->nextTetro = false;
          }
        }

        gameInput(data, screen, elem, images, event_queue_partieMarathon, timer_partieMarathon, sons, config); //gestion des input

        //gestion de la vitesse (peut-être fonction à faire, avec le niveau en input pour la modifier en fonction)
        data->timerVitesse++; //on incrémente le timer pour les déplacements
        if((data->key[LEFT] || data->key[RIGHT]) && data->timerLateral < data->vitesse) //si le joueur est en train d'appuyer sur gauche ou droite
          data->timerLateral++;
        else
          data->timerLateral = 0; //sinon on le remet à 0 pour le prchain input
        if(data->timerVitesse == data->vitesse) //si le timer atteint le temps fixé
        {
          deplacerTetro(7, data); //on fait se déplacer le tétromino tout seul
          enfiler(data->gameEv, FALL);
          if(data->key[SOFTD])
          {
            scoring(5, data); //on calcule le score
            defiler(data->gameEv);
          }
          data->timerVitesse = 0; //on le remet à 0
        }
      }

      data->redraw = true; //on met redraw à vrai pour redessiner la partie
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      inputKeyDown(config->keyMap, data, ev.keyboard.keycode, config);
      windowInputKeyDown(screen, ev.keyboard.keycode, &data->legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      inputKeyUp(config->keyMap, data, ev.keyboard.keycode);
      windowInputKeyUp(screen, ev.keyboard.keycode, &data->legalInput);
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE || screen->fullScreenSwitch)
    {
      if(screen->fullScreenSwitch)
      {
        fullScreen(screen);
        screen->fullScreenSwitch = false;
      }
      resizeGameScreen(screen);
    }

    if(data->redraw && al_is_event_queue_empty(event_queue_partieMarathon)) //si redraw est vrai et que la file d'évènements est vide
    {
      data->gameEvent = defiler(data->gameEv); //on récupère l'évènement stocké dans la pile pour l'envoyer aux fonctions d'affichage et de son
      data->redraw = false;
      afficherPartieMarathon(screen, images->imagesPartie, elem, data); //on affiche la partie à nouveau
      jouerSon(config->sound, sons, data->gameEvent, false); //va jouer ou arrêter le son du jeu
    }
  }

  highScore(screen, data->score, images, elem);

  //on libère la mémoire
  destroyGameData(data);
  al_destroy_timer(timer_partieMarathon);
  al_unregister_event_source(event_queue_partieMarathon, al_get_display_event_source(screen->display)); //devrait éviter l'erreur de SEGMENTATION
  al_destroy_event_queue(event_queue_partieMarathon);
}

void afficherPartieMarathon(gameScreen *screen, packPartie *images, elements *elem, gameData *data)
{
  targetBuffer(screen);

  //on charge l'image de fond
  al_draw_bitmap(images->fondPartie, 0, 0, 0);

  //on charge le pointeur "coord" pour raccourcir les lignes suivantes
  coord *rect = elem->rectNSL;

  //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
  char strNiveau[3]; //trois caractère max (de 1 à 99)
  char strScore[7]; //cinq caractères max (de 1 99999)
  char strLignes[6]; //cinq caractères max (de 1 99999)
  sprintf(strNiveau, "%d", data->niveau);
  sprintf(strScore, "%d", data->score);
  sprintf(strLignes, "%d", data->lignes);

  //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  //affiche la valeur de "niveau" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + rect->t + 9, ALLEGRO_ALIGN_RIGHT, strNiveau);
  //affiche la valeur de "score" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + (rect->t * 2) + 48 + 9, ALLEGRO_ALIGN_RIGHT, strScore);
  //affiche la valeur de "lignes" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y2 - rect->t - 48 + 9, ALLEGRO_ALIGN_RIGHT, strLignes);

  //on affiche le "tetroSuivant" dans le cadre correspondant
  bool dessinerBarreHaute = false, dessinerBarreGauche = false;
  int pos[2] = {0, 0}; //position où va coller l'image
  switch(data->tetroSuivant[0][4]) //0;4 est la case correcspondant au type du tétromino stocké dans le tableau
  {
    case JAUNE_O:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 461;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_jaune_O[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_jaune_O[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_jaune_O[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case CYAN_I:
      pos[Y] = 5;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 461;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_cyan_I[POS3][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_cyan_I[POS3][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_cyan_I[POS3][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case MAUVE_T:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_mauve_T[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_mauve_T[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_mauve_T[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case VIOLET_J:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_violet_J[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_violet_J[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_violet_J[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
     break;
    case ORANGE_L:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_orange_L[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_orange_L[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_orange_L[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case VERT_S:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_vert_S[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_vert_S[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_vert_S[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case ROUGE_Z:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_rouge_Z[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(data->tetros->p_rouge_Z[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
                  dessinerBarreHaute = false;
                else //sinon
                  dessinerBarreHaute = true;
                break;
            }
            switch(x)
            {
              case 0: //si on est sur une case à gauche de la grille
                dessinerBarreGauche = true;
                break;
              default:
                if(data->tetros->p_rouge_Z[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                  dessinerBarreGauche = false;
                else //sinon
                  dessinerBarreGauche= true;
                break;
            }
            if(dessinerBarreHaute)
              al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
            if(dessinerBarreGauche)
              al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          }
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
  }

  //si on doit animer la disparition de lignes
  bool lignesDisp[GRID_H] = {false}; //on va y recueillir la valeur y des lignes à faire clignoter
  if(data->animDisp)
  {
    int nbBlocsVides = 0;

    //on regarde quelles lignes doivent disparaître
    for(int y = 2; y < GRID_H; y++)
    {
      for(int x = 0; x < GRID_W; x++)
      {
        if(data->grille[x][y] == VIDE)
          nbBlocsVides++;

        if(x == 9 && nbBlocsVides == 0) //si la ligne parcourue est pleine
        {
          lignesDisp[y] = true; //on récupère la valeur y de la ligne
        }
      }
      nbBlocsVides = 0;
    }
  }

  //on affiche la grille dans le cadre correspondant
  dessinerBarreHaute = false;
  dessinerBarreGauche = false;
  pos[Y] = 22; //départ en y en haut de la grille
  for(int y = 2; y < GRID_H; y++) //on va parcourir la grille à partir de la troisième ligne
  {
    pos[X] = 87;
    for(int x = 0; x < GRID_W; x++) //on va parcourir la grille à partir de la deuxième colonne
    {
      switch(data->grille[x][y]) //on regarde la valeur stockée dans la case
      {
        case JAUNE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide et qu'on est pas sur la première ligne
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case CYAN:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case MAUVE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case VIOLET:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case ORANGE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case VERT:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case ROUGE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case JAUNE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case CYAN_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case MAUVE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case VIOLET_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case ORANGE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case VERT_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
        case ROUGE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(data->grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
                dessinerBarreHaute = false;
              else //sinon
                dessinerBarreHaute = true;
              break;
          }
          switch(x)
          {
            case 0: //si on est sur une case à gauche de la grille
              dessinerBarreGauche = true;
              break;
            default:
              if(data->grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
                dessinerBarreGauche = false;
              else //sinon
                dessinerBarreGauche= true;
              break;
          }
          if(dessinerBarreHaute)
            al_draw_bitmap(images->barreGrilleHorizontale, pos[X]-3, pos[Y]-3, 0);
          if(dessinerBarreGauche)
            al_draw_bitmap(images->barreGrilleVerticale, pos[X]-3, pos[Y], 0);
          al_draw_bitmap(images->barreGrilleHorizontale, pos[X], pos[Y]+25, 0);
          al_draw_bitmap(images->barreGrilleVerticale, pos[X]+25, pos[Y]-3, 0);
          break;
      }
      pos[X] += 28; //une fois qu'on a fini d'inspécter la case, on passe à la suivante sur la ligne
    }
    pos[Y] += 28; //une fois qu'on a fini d'inspécter la ligne, on passe à la suivante
  }

  afficherEvenement(data, elem); //on affiche l'évènement s'il y en a un
  ghostPiece(images, data); //on affiche la pièce fantôme

  //on libère la mémoire
  al_destroy_font(font);

  drawBuffer(screen);
}
