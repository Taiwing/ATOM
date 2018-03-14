#include "jeu.h"

void partie(ALLEGRO_DISPLAY *fenetre, int niveauChoisi, bool sound[3], packSons *sons)
{
  //on génère les images de la partie
  elementsFondPartie *elem = genererElementsFondPartie(); //on crée les structures coord représentant les rectangles de la partie
  packPartie *images = genererPackPartie(elem); //on crée la structure d'où on va tirer les images de la partie
  al_set_target_bitmap(al_get_backbuffer(fenetre)); //on recible la fenêtre pour y afficher les images

  //on initialise le timer
  ALLEGRO_TIMER *timer_partie = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde
  al_install_mouse();

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_partie = al_create_event_queue();
  al_register_event_source(event_queue_partie, al_get_display_event_source(fenetre)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_partie, al_get_timer_event_source(timer_partie)); //on lie la file au timer
  al_register_event_source(event_queue_partie, al_get_mouse_event_source()); //puis à la souris
  al_register_event_source(event_queue_partie, al_get_keyboard_event_source()); //et au clavier

  //VARIABLES DU JEU:
  bool redraw = false; //pour redessiner la partie quand 1/60s s'est écoulé
  bool continuer = true; //pour la boucle principale
  bool key[9] = {false, false, false, false, false, false, false, false, false}; //indique si une touche a été appuyée ou pas
  int *score = malloc(sizeof(int)); //compteur de score
  *score = 0; //on initialise la valeur de l'int stocké à 0
  int *lignes = malloc(sizeof(int)); //compteur de lignes
  *lignes = 0; //on initialise la valeur de l'int stocké à 0
  int *niveau = malloc(sizeof(int)); //indique le niveau
  *niveau = niveauChoisi; //on l'initialise à la valeur choisie par le joueur
  int *vitesse = malloc(sizeof(int)); //nombre de ticks du timer avant que la pièce ne se déplace toute seule
  *vitesse = 45; //vitesse de départ
  int *dernierCoup = malloc(sizeof(int)); //va retenir le dernier coup pour les combos dans la fonction score
  *dernierCoup = 0; //par défaut le dernier coup ne donne pas de bonus de score
  int *comboCount = malloc(sizeof(int)); //va compter le nombre de coups d'affilés lors d'une combo
  *comboCount = 0; //est à zéro par défaut
  File *soundEv = initialiser(); //file d'évènements pour la fonction de son
  enfiler(soundEv, GAMESTART); //premier évènement du jeu
  int grille[GRID_W][GRID_H] = {VIDE}; //symbolise la grille du jeu
  packTetro *tetros = chargerTetrominos(); //on crée la structure de tétrominos
  int tetroActuel[4][5] = {VIDE};
  int tetroSuivant[4][5] = {VIDE};
  int sac[7] = {7}; //va contenir les 7 prochains tétros
  int nbTetro = 0; //va parcourir le tableau jusqu'à la fin et dire à la fonction d'activer le randomGenerator(TM)
  randomGenerator(sac); //on l'active pour sélectionner les 7 premières pièces
  selectionAleatoireTetromino(tetroSuivant, tetros, sac, nbTetro); //on sélectionne le premier tétro
  nbTetro = 1; //on passe au suivant pour la boucle du jeu
  int nbLignes = 0; //va récupérer le combre de lignes enlevées pour calculer le score, et le niveau
  int timerVitesse = 0; //va compter le nombre de ticks pour la fonction de déplacement automatique
  int timerLateral = 0; //va compter le nombre de ticks pour les déplacements latéraux
  int timerAnimDisp = 0; //va compter le nombre de ticks pour l'animation de disparition de lignes
  int timerLock = 0; //va compter le nombre de ticks avant de bloquer le tétromino actuel
  int deplacement = 0; //va recueillir la valeur renvoyée par deplacerTetro (qui est celle de testDeplacement)
  bool perdu = false; //si placerTetro ou holdPiece renvoit false, alors le joueur a perdu car le tétromino n'a pas pu se placer
  bool victoire = false; //si le joueur atteint le niveau 32, alors il a gagné
  bool nextTetro = true; //quand le tétro actuel est en bas, on signale à la boucle de mettre le prochain, et de sélectionner celui d'après
  bool legalInput = true; //pour limiter le nombre d'input à la suite
  bool lComplete = false; //va stocker le résultat de la fonction ligneComplete
  bool animDisp = false; //va dire à la fonction d'affichage d'animer la disparition de lignes
  bool ghostPieceOnOff = true; //va activer ou désactiver la fonction "ghostPiece"
  bool holdPieceOn = false; //va indiquer si la fonction holdPiece a été utilisée ou pas
  bool TSpin = false; //va indiquer s'il y a TSpin ou non
  bool lc = false; //va indiquer à boucle "nextTetro" s'il y a eu des lignes complétées ou pas

  //on lance le compte à rebours avant de commencer la partie
  troisDeuxUn(images, elem, 0, 0, 0, 0);

  //on démarre le timer
  al_start_timer(timer_partie);

  //boucle principale de la partie
  while(continuer)
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer les évènements
    al_wait_for_event(event_queue_partie, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      //on vérifie le score et on augmente le niveau s'il faut
      leveling(niveau, score, vitesse, soundEv);

      //on regarde si une pièce va se bloquer
      if(lockTest(grille, tetroActuel))
      {
        if(timerLock == 0)
          enfiler(soundEv, TOUCHDOWN); //la pièce touche le sol
        //on déclenche un timer d'une demi-seconde pour laisser au joueur la possibilité de bouger pendant cet interval
        timerLock++;
        if(timerLock == 30) //s'il s'est écoulé une demi-seconde
        {
          nextTetro = true; //on change de pièce
          timerLock = 0; //on reset le timer
          enfiler(soundEv, LOCKED); //la pièce est bloquée
        }
      }
      else
      {
        timerLock = 0; //on reset le timer
      }

      //on ne fait le test que quand lComplete est faux (pour répéter les instructions après le prochain test), et que le tétro précédent est locké
      if(!lComplete && nextTetro)
      {
        lComplete = ligneComplete(grille, soundEv); //on vérifie si le joueur a complété des lignes, et on envoit l'évènement dans sounEv
        if(TSpin)//s'il y a TSpin
        {
          enfiler(soundEv, defiler(soundEv) + 5); //s'il y a TSpin on remplace la valeur qu'on a mis dans soundEv
        }
      }

      if(lComplete) //si c'est le cas
      {
        //Animation de 1/2 secondes où les lignes disparaissant clignotent
        if(timerAnimDisp < 30) //l'animation va durer 30 frames
        {
          timerAnimDisp++; //on incrémente le timer pour compter les frames
          if((timerAnimDisp % 3) == 0) //si timerAnimDisp est pair (donc toutes les trois frames)
          {
            if(!animDisp) //on alterne toutes les trois frames
              animDisp = true; //on affiche les blocs des lignes pleines en blanc
            else
              animDisp = false; //on ne le fait pas (ça devrait donc clignoter)
          }
        }
        else
        {
          nbLignes = enleverLignes(grille); //on enlève les lignes du tableau et on fait descendre celles du dessus s'il y en a
          *lignes += nbLignes; //on ajoute le nombre de lignes enlevées au total
          if(TSpin)
          {
            nbLignes += 7; //on ajoute 7 pour compter le T-Spin au score
            TSpin = false; //puis on reset la valeur de TSpin
          }
          scoring(score, *niveau, nbLignes, dernierCoup, comboCount); //puis on calcule le score
          lComplete = false; //puis on remet lComplete à false
          lc = true; //va dire à la prochaine boucle qu'il y a eu ligne complète
          timerAnimDisp = 0; //on remet le timer à 0 pour la prochaine fois
          animDisp = false; //pour que les lignes pleines arrête de clignoter
        }
      }
      else //sinon, on exécute la boucle normalement
      {
        //on vérifie si le joueur a perdu
        if(perdu)
        {
          enfiler(soundEv, GAMEOVER); //on envoit GAMEOVER à la fonction de son
          continuer = false; //si c'est le cas, alors on revient au menu principal
        }
        else if(*niveau == 32) //ou s'il a gagné
        {
          continuer = false;
          victoire = true; //alors on indique à la boucle que le jouur a gagné
        }

        //on vérifie s'il faut placer la nouvelle pièce
        if(nextTetro)
        {
          if(TSpin) //si la pièce se bloque sans faire diparaître de lignes avec T-Spin
          {
            scoring(score, *niveau, 7, dernierCoup, comboCount); //on augmente le score par la valeur correspondante
            TSpin = false; //puis on reset la valeur de TSpin
            enfiler(soundEv, STSPIN);
          }
          else if(!lc) //s'il n'y a pas eu de lignes complétées au dernier coup ni de T-Spin
          {
            *dernierCoup = 0; //alors le dernier coup était "inutile"
          }
          lc = false;

          lockTetro(grille, tetroActuel); //on bloque le tétro actuel avant d'en changer

          if(holdPieceOn) //si le joueur a utilisé la fonction holdPiece avant le changement de tétro
            holdPieceOn = false; //il a a nouveau le droit de l'utiliser

          //on met le tetroSuivant dans tetroActuel, et on le place dans la grille
          if(!placerTetro(grille, tetroSuivant, tetroActuel)) //si ça ne marche pas (s'il y a déjà un tétro à cet endroit)
          {
            perdu = true; //alors le joueur a perdu
            nextTetro = false;
          }
          else
          {
            selectionAleatoireTetromino(tetroSuivant, tetros, sac, nbTetro); //on sélectionne la pièce suivante
            nbTetro++; //on passe au tétro suivant dans la liste
            if(nbTetro == 7) //si on est arrivé au bout
              nbTetro = 0; //on revient au début
            timerVitesse = 0; //on remet le timer à 0 pour qu'elle ne se redéplace pas tout de suite
            nextTetro = false;
          }
        }

        //gestion des input
        for(int i = 0; i < 9; i++) //on parcourt le tableau des touches
        {
          if(key[i]) //si une touche a été appuyée
          {
            switch(i) //on détermine laquelle
            {
              case ROTATER:
                deplacement = deplacerTetro(ROTATER, grille, tetroActuel, tetros, niveau, score);
                if(deplacement == LEGAL) //si la rotation est légale et s'effectue sans kick
                {
                  TSpin = TSpinTest(grille, tetroActuel); //on fait le test pour savoir s'il y a T-Spin ou non
                  enfiler(soundEv, ROTATELR);
                }
                else
                {
                  TSpin = false;
                  enfiler(soundEv, ROTATEFAIL);
                }
                key[ROTATER] = false; //on le met à faux pour que ça ne se répète pas
                break;
              case SOFTD:
                //on déplace la pièce vers le bas
                if(timerVitesse % 4 == 0)
                {
                  deplacement = deplacerTetro(SOFTD, grille, tetroActuel, tetros, niveau, score);
                  scoring(score, *niveau, 5, dernierCoup, comboCount); //on calcule le score
                  if(deplacement)
                  {
                    TSpin = false;
                    enfiler(soundEv, SOFTDROP);
                  }
                }
                break;
              case LEFT:
                //on déplace la pièce vers la gauche
                if(timerLateral == 0 || (timerLateral % 4 == 0 && timerLateral > 4))
                {
                  deplacement = deplacerTetro(LEFT, grille, tetroActuel, tetros, niveau, score);
                  if(deplacement)
                  {
                    TSpin = false;
                    enfiler(soundEv, MOVELR);
                    if(testTouchLR(grille, tetroActuel))
                    {
                      defiler(soundEv);
                      enfiler(soundEv, TOUCHLR);
                    }
                  }
                }
                break;
              case RIGHT:
                //on déplace la pièce vers la droite au quadruple de la vitesse auto
                if(timerLateral == 0|| (timerLateral % 4 == 0 && timerLateral > 4))
                {
                  deplacement = deplacerTetro(RIGHT, grille, tetroActuel, tetros, niveau, score);
                  if(deplacement)
                  {
                    TSpin = false;
                    enfiler(soundEv, MOVELR);
                    if(testTouchLR(grille, tetroActuel))
                    {
                      defiler(soundEv);
                      enfiler(soundEv, TOUCHLR);
                    }
                  }
                }
                break;
              case HARDD:
                deplacerTetro(HARDD, grille, tetroActuel, tetros, niveau, score);
                enfiler(soundEv, HARDDROP);
                nextTetro = true; //on dit à la boucle de changer de tétromino
                key[HARDD] = false; //on le met à faux pour que ça ne se répète pas
                break;
              case ROTATEL:
                deplacement = deplacerTetro(ROTATEL, grille, tetroActuel, tetros, niveau, score);
                if(deplacement == LEGAL) //si la rotation est légale et s'effectue sans kick
                {
                  TSpin = TSpinTest(grille, tetroActuel); //on fait le test pour savoir s'il y a T-Spin ou non
                  enfiler(soundEv, ROTATELR);
                }
                else
                {
                  TSpin = false;
                  enfiler(soundEv, ROTATEFAIL);
                }
                key[ROTATEL] = false; //on le met à faux pour que ça ne se répète pas
                break;
              case PAUSE:
                key[PAUSE] = false; //on le met à faux pour que ça ne se répète pas
                al_stop_timer(timer_partie); //on stoppe le timer pour que le temps passé en pause ne soit pas compté
                if(menuPause(fenetre, elem, images->imagesPause, *niveau, *score, *lignes)) //si le joueur a fait quitter
                  continuer = false; //on revient au menu principal
                else
                {
                  troisDeuxUn(images, elem, 1, *niveau, *score, *lignes); //on lance le compte à rebours avant de reprendre
                  al_start_timer(timer_partie); //on relance le timer
                }
                break;
              case GHOST:
                if(!ghostPieceOnOff)
                  ghostPieceOnOff = true;
                else
                  ghostPieceOnOff = false;
                key[GHOST] = false; //on le met à faux pour que ça ne se répète pas
                break;
              case CHANGE:
                //on remplace le tetroActuel par tetroSuivant et vice-versa, et on le replace dans la grille
                if(!holdPiece(tetroActuel, tetroSuivant, grille))
                {
                  perdu = true; //si la fonction ne marche pas, le joueur a perdu
                }
                else
                {
                  enfiler(soundEv, HOLD);
                }
                timerVitesse = 0; //on reset le timer pour que la nouvelle pièce ne rebouge pas tout de suite
                holdPieceOn = true;
                key[CHANGE] = false; //on le met à faux pour que ça ne se répète pas
                break;
            }
          }
        }

        //gestion de la vitesse (peut-être fonction à faire, avec le niveau en input pour la modifier en fonction)
        timerVitesse++; //on incrémente le timer pour les déplacements
        if((key[LEFT] || key[RIGHT]) && timerLateral < *vitesse) //si le joueur est en train d'appuyer sur gauche ou droite
          timerLateral++;
        else
          timerLateral = 0; //sinon on le remet à 0 pour le prchain input
        if(timerVitesse == *vitesse) //si le timer atteint le temps fixé
        {
          deplacerTetro(7, grille, tetroActuel, tetros, niveau, score); //on fait se déplacer le tétromino tout seul
          enfiler(soundEv, FALL);
          if(key[SOFTD])
          {
            scoring(score, *niveau, 5, dernierCoup, comboCount); //on calcule le score
            defiler(soundEv);
          }
          timerVitesse = 0; //on le remet à 0
        }
      }

      redraw = true; //on met redraw à vrai pour redessiner la partie
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      exit(EXIT_SUCCESS); //on quitte le programme
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //s'il appuie sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_UP: //s'il appuie sur une flèche
          if(legalInput)
          {
            key[ROTATER] = true; //on met la case du tableau de touche à vrai
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_DOWN: //s'il appuie sur une flèche
          key[SOFTD] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_LEFT: //s'il appuie sur une flèche
          key[LEFT] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_RIGHT: //s'il appuie sur une flèche
          key[RIGHT] = true; //on met la case du tableau de touche à vrai
          break;
        case ALLEGRO_KEY_SPACE: //s'il appuie sur espace
          if(legalInput)
          {
            key[HARDD] = true; //on met la case du tableau de touche à vrai
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_RCTRL: //s'il appuie sur CTRL
          if(legalInput)
          {
            key[ROTATEL] = true; //on met la case du tableau de touche à vrai
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_G: //s'il appuie sur G
          if(legalInput)
          {
            key[GHOST] = true; //on met la case du tableau de touche à vrai
            legalInput = false;
          }
          break;
        case ALLEGRO_KEY_RSHIFT: //s'il appuie sur MAJ
          if(legalInput && !holdPieceOn) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
          {
            key[CHANGE] = true;
            legalInput = false;
          }
          break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) //s'il arrête d'appuyer sur une touche du clavier
    {
      switch(ev.keyboard.keycode) //on vérifie laquelle
      {
        case ALLEGRO_KEY_UP: //s'il arrête d'appuyer sur une flèche
          key[ROTATER] = false; //on met la case du tableau de touche à faux
          legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
          break;
        case ALLEGRO_KEY_DOWN: //s'il arrête d'appuyer sur une flèche
          key[SOFTD] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_LEFT: //s'il arrête d'appuyer sur une flèche
          key[LEFT] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_RIGHT: //s'il arrête d'appuyer sur une flèche
          key[RIGHT] = false; //on met la case du tableau de touche à faux
          break;
        case ALLEGRO_KEY_SPACE: //s'il arrête d'appuyer sur espace
          key[HARDD] = false; //on met la case du tableau de touche à faux
          legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
          break;
        case ALLEGRO_KEY_RCTRL: //s'il arrête d'appuyer sur CTRL
          key[ROTATEL] = false; //on met la case du tableau de touche à faux
          legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
          break;
        case ALLEGRO_KEY_P: //s'il arrête d'appuyer sur P
          key[PAUSE] = true; //quand il arrête d'appuyer, l'input est légal
          break;
        case ALLEGRO_KEY_G: //s'il arrête d'appuyer sur G
          key[GHOST] = false; //on met la case du tableau de touche à faux
          legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
          break;
        case ALLEGRO_KEY_RSHIFT: //s'il arrête d'appuyer sur SHIFT
          key[CHANGE] = false; //on met la case du tableau de touche à faux
          legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
          break;
      }
    }


    if(redraw && al_is_event_queue_empty(event_queue_partie)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherPartie(images, elem, tetros, grille, tetroSuivant, animDisp, *niveau, *score, *lignes); //on affiche la partie à nouveau
      if(ghostPieceOnOff)
        ghostPiece(images, grille, tetroActuel); //on affiche la pièce fantôme
      al_flip_display(); //on affiche les changements
      jouerSon(sound, sons, soundEv); //va jouer ou arrêter le son du jeu
    }
  }

  highScore(fenetre, *score);

  //on libère la mémoire
  free(soundEv);
  destroyElementsFondPartie(elem);
  destroyPackPartie(images);
  destroyTetrominos(tetros);
  al_destroy_timer(timer_partie);
  al_unregister_event_source(event_queue_partie, al_get_display_event_source(fenetre)); //devrait éviter l'erreur de SEGMENTATION
  al_destroy_event_queue(event_queue_partie);
}

void afficherPartie(packPartie *images,
                    elementsFondPartie *elem,
                    packTetro *tetros,
                    int grille[GRID_W][GRID_H],
                    int tetroSuivant[4][5],
                    bool animDisp,
                    int niveau, int score, int lignes)
{
  //on charge l'image de fond
  al_draw_bitmap(images->fondPartie, 0, 0, 0);

  //on charge le pointeur "coord" pour raccourcir les lignes suivantes
  coord *rect = elem->rectNSL;

  //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
  char strNiveau[3]; //trois caractère max (de 1 à 99)
  char strScore[7]; //cinq caractères max (de 1 99999)
  char strLignes[6]; //cinq caractères max (de 1 99999)
  sprintf(strNiveau, "%d", niveau);
  sprintf(strScore, "%d", score);
  sprintf(strLignes, "%d", lignes);

  //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  //affiche la valeur de "niveau" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + rect->t + 9, ALLEGRO_ALIGN_RIGHT, strNiveau);
  //affiche la valeur de "score" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + (rect->t * 2) + 48 + 9, ALLEGRO_ALIGN_RIGHT, strScore);
  //affiche la valeur de "lignes" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y2 - rect->t - 48 + 9, ALLEGRO_ALIGN_RIGHT, strLignes);

  //on affiche le "tetroSuivant" dans le cadre correspondant
  bool dessinerBarreHaute = false, dessinerBarreGauche = false;
  int pos[2] = {0, 0}; //position où va coller l'image
  switch(tetroSuivant[0][4]) //0;4 est la case correcspondant au type du tétromino stocké dans le tableau
  {
    case JAUNE_O:
      pos[Y] = 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 461;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_jaune_O[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_jaune_O[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_jaune_O[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_cyan_I[POS3][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_cyan_I[POS3][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_cyan_I[POS3][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_mauve_T[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_mauve_T[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_mauve_T[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_violet_J[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_violet_J[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_violet_J[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_orange_L[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_orange_L[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_orange_L[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_vert_S[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_vert_S[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_vert_S[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(tetros->p_rouge_Z[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
            switch(y)
            {
              case 0: //si on est sur une case en haut de la grille
                dessinerBarreHaute = true;
                break;
              default:
                if(tetros->p_rouge_Z[POS1][x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
                if(tetros->p_rouge_Z[POS1][x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
  bool lignesDisp[GRID_H] = {false}; //on va y recueillir la veleur y des lignes à faire clignoter
  if(animDisp)
  {
    int nbBlocsVides = 0;

    //on regarde quelles lignes doivent disparaître
    for(int y = 2; y < GRID_H; y++)
    {
      for(int x = 0; x < GRID_W; x++)
      {
        if(grille[x][y] == VIDE)
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
      switch(grille[x][y]) //on regarde la valeur stockée dans la case
      {
        case JAUNE:
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide et qu'on est pas sur la première ligne
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocJaune, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocCyan, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocMauve, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocViolet, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocOrange, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocVert, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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
          if(animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            al_draw_bitmap(images->blocBlanc, pos[X], pos[Y], 0);
          else
            al_draw_bitmap(images->blocRouge, pos[X], pos[Y], 0);
          switch(y)
          {
            case 2: //si on est sur une case en haut de la grille
              dessinerBarreHaute = true;
              break;
            default:
              if(grille[x][y-1] != VIDE) //si la case du dessus n'est pas vide
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
              if(grille[x-1][y] != VIDE) //si la case du de gauche n'est pas vide
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

  //on libère la mémoire
  al_destroy_font(font);
}

void selectionAleatoireTetromino(int piece[4][5], packTetro *tetros, int sac[7], int nbTetro)
{
  switch(sac[nbTetro])
  {
    case JAUNE_O:
      piece[0][4] = JAUNE_O; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_jaune_O[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case CYAN_I:
      piece[0][4] = CYAN_I; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_cyan_I[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case MAUVE_T:
      piece[0][4] = MAUVE_T; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_mauve_T[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VIOLET_J:
      piece[0][4] = VIOLET_J; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_violet_J[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ORANGE_L:
      piece[0][4] = ORANGE_L; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_orange_L[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VERT_S:
      piece[0][4] = VERT_S; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_vert_S[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ROUGE_Z:
      piece[0][4] = ROUGE_Z; //on indique le type de la pièce dans le tableau
      piece[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          piece[x][y] = tetros->p_rouge_Z[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
  }

  if(nbTetro == 6) //quand on est arrivé au bout des 7 tétrominos choisi précédemment
  {
    randomGenerator(sac); //on sélectionne les prochains
  }
}

void randomGenerator(int sac[7])
{
  int tetros[7] = {0, 1, 2, 3, 4, 5, 6}; //liste des tétros à choisir
  int j = 0; //variable dans laquelle on va stocker le nombre choisi aléatoirement

  for(int i = 0; i < 7; i++) //on répète la boucle 7 fois (en fait on le fera 6 fois)
  {
    srand(time(NULL));
    j = (rand() % (7 - i)); //on sélectionne un chiffre entre 0 et 6-i aléatoirement
    sac[i] = tetros[j]; //on affecte la valeur de la liste tétro au sac
    tetros[j] = tetros[6 - i]; //on place la dernière valeur de la liste à la place de celle qui a été choisie
  }
}

bool placerTetro(int grille[GRID_W][GRID_H], int tetroSuivant[4][5], int tetroActuel[4][5])
{
  //on met le tetroSuivant dans le tetroActuel
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      tetroActuel[x][y] = tetroSuivant[x][y];
    }
  }

  //on met les coordonnées de départ du nouveau tétro dans la grille
  tetroActuel[2][4] = DEPART_X; //position en X sur la grille (au milieu)
  tetroActuel[3][4] = DEPART_Y; //position en Y sur la grille (en haut)

  //puis on le place dans la grille, tout en vérifiant qu'il n'y a pas déjà de tétro à cet endroit
  int nbBlocs = 0;
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      if((grille[DEPART_X + x][DEPART_Y + y] == VIDE) && (tetroActuel[x][y] != VIDE)) //si la case de la grille est vide et que celle du tétro ne l'est pas
      {
        grille[DEPART_X + x][DEPART_Y + y] = tetroActuel[x][y]; //on place le bloc
        nbBlocs++; //et on incrémente nBblocs
      }
    }
  }

  //on vérifie que les quatre blocs ont bien été placé
  if(nbBlocs == 4)
    return true; //si c'est le cas, alors placerTetro renvoit true pour indiquer que tout s'est bien passé
  else
    return false; //sinon elle renvoit false, et le joueur a perdu la partie
}

int deplacerTetro(int mouvement, int grille[GRID_W][GRID_H], int tetroActuel[4][5], packTetro *tetros, int *niveau, int *score)
{
  int test = testDeplacement(mouvement, grille, tetroActuel, tetros); //on test le déplacement

  if(test >= LEGAL) //si le mouvement est légal (ou que c'est un kick)
  {
    switch(mouvement) //on regarde de quel type de mouvement il s'agit
    {
      case ROTATER: //on fait une rotation à droite
        //on vide le tétro Actuel et on remplace chaque case par la celle correspondant à la prochaine position
        tetroActuel[1][4]++; //on incrémente la position de tetroActuel pour le faire tourner à droite
        if(tetroActuel[1][4] > POS4) //si on dépasse la position maximale
        {
          tetroActuel[1][4] = POS1; //on revient à la première
        }
        for(int y = 0; y < 4; y++)
        {
          for(int x = 0; x < 4; x++)
          {
            switch(tetroActuel[0][4])
            {
              case JAUNE_O:
                tetroActuel[x][y] = tetros->p_jaune_O[(tetroActuel[1][4])][x][y];
                break;
              case CYAN_I:
                tetroActuel[x][y] = tetros->p_cyan_I[(tetroActuel[1][4])][x][y];
                break;
              case MAUVE_T:
                tetroActuel[x][y] = tetros->p_mauve_T[(tetroActuel[1][4])][x][y];
                break;
              case VIOLET_J:
                tetroActuel[x][y] = tetros->p_violet_J[(tetroActuel[1][4])][x][y];
                break;
              case ORANGE_L:
                tetroActuel[x][y] = tetros->p_orange_L[(tetroActuel[1][4])][x][y];
                break;
              case VERT_S:
                tetroActuel[x][y] = tetros->p_vert_S[(tetroActuel[1][4])][x][y];
                break;
              case ROUGE_Z:
                tetroActuel[x][y] = tetros->p_rouge_Z[(tetroActuel[1][4])][x][y];
                break;
            }
          }
        }

        //si c'est un kick, on change les coordonnées du tétro actuel
        if(tetroActuel[0][4] == CYAN_I) //si c'est un I
        {
          switch(test) //on regarde si on doit faire le kick
          {
            case KICK1:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] -= 2;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 2;
                  break;
                case POS1:
                  tetroActuel[2][4] += 1;
                  break;
              }
              break;
            case KICK2:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] += 1;
                  break;
                case POS3:
                  tetroActuel[2][4] += 2;
                  break;
                case POS4:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS1:
                  tetroActuel[2][4] -= 2;
                  break;
              }
              break;
            case KICK3:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] -= 2;
                  tetroActuel[3][4] += 1;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[2][4] += 2;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS1:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 2;
                  break;
              }
              break;
            case KICK4:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS3:
                  tetroActuel[2][4] += 2;
                  tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  tetroActuel[2][4] -= 2;
                  tetroActuel[3][4] -= 1;
                  break;
              }
              break;
          }
        }
        else //si c'est une autre pièce kickable (T, J, L, S, Z)
        {
          switch(test)
          {
            case KICK1:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS3:
                  tetroActuel[2][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  break;
                case POS1:
                  tetroActuel[2][4] -= 1;
                  break;
              }
              break;
            case KICK2:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS1:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 1;
                  break;
              }
              break;
            case KICK3:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  tetroActuel[3][4] -= 2;
                  break;
              }
              break;
            case KICK4:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 2;
                  break;
              }
              break;
          }
        }

        //puis on met le nouveau tetroActuel dans la grille
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
        break;
      case SOFTD: //on fait descendre le tétro
        //on change les coordonnées du tétro
        tetroActuel[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case LEFT: //on le déplace sur la gauche
        //on change les coordonnées du tétro
        tetroActuel[2][4]--; //on diminue x de 1 (on va d'une case sur la gauche)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case RIGHT: //on le déplace sur la droite
        //on change les coordonnées du tétro
        tetroActuel[2][4]++; //on augmente x de 1 (on va d'une case sur la droite)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case HARDD: //on le fait descendre tout en bas
        //on le fait descendre jusqu'à ce que le test renvoit 2 (pour changer de tétro)
        while (testDeplacement(SOFTD, grille, tetroActuel, tetros) != ILLEGAL)
        {
          tetroActuel[3][4]++;

          //puis on le met dans la grille aux nouvelles coordonnées
          for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
          {
            for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
            {
              if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
              {
                if(grille[x][y] == VIDE) //si la case est vide
                  grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])]; //alors on y met le bloc voulu
              }
            }
          }
          scoring(score, *niveau, 6, NULL, NULL); //puis on calcule le score du hardDrop
        }
        break;
      case ROTATEL: //on fait une rotation à gauche
        //on vide le tétro Actuel et on remplace chaque case par la celle correspondant à la prochaine position
        tetroActuel[1][4]--; //on décrémente la position de tetroActuel pour le faire tourner à gauche
        if(tetroActuel[1][4] < POS1) //si on dépasse la position minimale
        {
          tetroActuel[1][4] = POS4; //on revient à la position maximale
        }
        for(int y = 0; y < 4; y++)
        {
          for(int x = 0; x < 4; x++)
          {
            switch(tetroActuel[0][4])
            {
              case JAUNE_O:
                tetroActuel[x][y] = tetros->p_jaune_O[(tetroActuel[1][4])][x][y];
                break;
              case CYAN_I:
                tetroActuel[x][y] = tetros->p_cyan_I[(tetroActuel[1][4])][x][y];
                break;
              case MAUVE_T:
                tetroActuel[x][y] = tetros->p_mauve_T[(tetroActuel[1][4])][x][y];
                break;
              case VIOLET_J:
                tetroActuel[x][y] = tetros->p_violet_J[(tetroActuel[1][4])][x][y];
                break;
              case ORANGE_L:
                tetroActuel[x][y] = tetros->p_orange_L[(tetroActuel[1][4])][x][y];
                break;
              case VERT_S:
                tetroActuel[x][y] = tetros->p_vert_S[(tetroActuel[1][4])][x][y];
                break;
              case ROUGE_Z:
                tetroActuel[x][y] = tetros->p_rouge_Z[(tetroActuel[1][4])][x][y];
                break;
            }
          }
        }

        //si c'est un kick, on change les coordonnées du tétro actuel
        if(tetroActuel[0][4] == CYAN_I) //si c'est un I
        {
          switch(test) //on regarde si on doit faire le kick
          {
            case KICK1:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] += 2;
                  break;
                case POS2:
                  tetroActuel[2][4] += 1;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[2][4] -= 1;
                  break;
              }
              break;
            case KICK2:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS2:
                  tetroActuel[2][4] -= 2;
                  break;
                case POS3:
                  tetroActuel[2][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 2;
                  break;
              }
              break;
            case KICK3:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] += 2;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS2:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 2;
                  tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 2;
                  break;
              }
              break;
            case KICK4:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS2:
                  tetroActuel[2][4] -= 2;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[2][4] += 2;
                  tetroActuel[3][4] += 1;
                  break;
              }
              break;
          }
        }
        else //si c'est une autre pièce kickable (T, J, L, S, Z)
        {
          switch(test)
          {
            case KICK1:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] += 1;
                  break;
                case POS2:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  break;
              }
              break;
            case KICK2:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 1;
                  break;
                case POS2:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 1;
                  break;
              }
              break;
            case KICK3:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[3][4] -= 2;
                  break;
                case POS2:
                  tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[3][4] += 2;
                  break;
              }
              break;
            case KICK4:
              switch(tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS2:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  tetroActuel[2][4] -= 1;
                  tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  tetroActuel[2][4] += 1;
                  tetroActuel[3][4] += 2;
                  break;
              }
              break;
          }
        }

        //puis on met le nouveau tetroActuel dans la grille
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //pour ne pas effacer les blocs qui se trouvent déjà aux coordonnées du tétro
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
        break;
      case 7: //on fait descendre le tétro
        //on change les coordonnées du tétro
        tetroActuel[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
    }
  }

  return test; //on va communiquer le résultat du test de déplacement à la fonction partie() pour le TSpin Test
}

int testDeplacement(int mouvement, int grille[GRID_W][GRID_H], int tetroActuel[4][5], packTetro *tetros)
{
  int nbBlocs = 0; //va nous servir à compter le nombre de blocs pourvant être placés dans la grille
  int legal = ILLEGAL; //valeur que la fonction va renvoyer

  //On copie le tétro pour faire nos tests
  int tetroTest[4][5] = {VIDE};
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      tetroTest[x][y] = tetroActuel[x][y];
    }
  }

  switch(mouvement) //on regarde de quel type de mouvement il s'agit
  {
    case ROTATER: //on fait une rotation à droite
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      tetroTest[1][4]++; //on incrémente la position de tetroTest pour le faire tourner à droite
      if(tetroTest[1][4] > POS4) //si on dépasse la position maximale
      {
        tetroTest[1][4] = POS1; //on revient à la première
      }
      for(int y = 0; y < 4; y++)
      {
        for(int x = 0; x < 4; x++)
        {
          switch(tetroTest[0][4])
          {
            case JAUNE_O:
              tetroTest[x][y] = tetros->p_jaune_O[(tetroTest[1][4])][x][y];
              break;
            case CYAN_I:
              tetroTest[x][y] = tetros->p_cyan_I[(tetroTest[1][4])][x][y];
              break;
            case MAUVE_T:
              tetroTest[x][y] = tetros->p_mauve_T[(tetroTest[1][4])][x][y];
              break;
            case VIOLET_J:
              tetroTest[x][y] = tetros->p_violet_J[(tetroTest[1][4])][x][y];
              break;
            case ORANGE_L:
              tetroTest[x][y] = tetros->p_orange_L[(tetroTest[1][4])][x][y];
              break;
            case VERT_S:
              tetroTest[x][y] = tetros->p_vert_S[(tetroTest[1][4])][x][y];
              break;
            case ROUGE_Z:
              tetroTest[x][y] = tetros->p_rouge_Z[(tetroTest[1][4])][x][y];
              break;
          }
        }
      }

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement de base est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        //on regarde si on peut kicker le tétromino
        switch(tetroTest[0][4])
        {
          case JAUNE_O: //on ne peut pas kicker le carré
            break;
          case CYAN_I: //I a son propre set de kick
            for(int i = 0; i < 4; i++) //on va tester les quatre possibilités de kick
            {
              switch(tetroTest[1][4]) //on détermine le set de kicks en fonction de la rotation effectuée
              {
                case POS2:
                  switch(i)
                  {
                    case 0: //(-2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(-2, 1)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 3: //(1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
                case POS3:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(-1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(2, 1)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                  }
                  break;
                case POS4:
                  switch(i)
                  {
                    case 0: //(2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(2, -1)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 3: //(-1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
                case POS1:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(-2, -1)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                  }
                  break;
              }
              nbBlocs = 0; //on reset la valeur de nbBlocs pour le prochain test
              for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
              {
                for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
                {
                  if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
                  {
                    //si la case de la grille est vide et qu'il y a un bloc à mettre
                    if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
                      nbBlocs++;
                  }
                }
              }
              if(nbBlocs == 4) // si l'un des kicks est possibles
              {
                legal = KICK1 + i; //va donner KICK1, KICK2, KICK 3, ou KICK4 en fonction du test qui a été réussi
                i = 4; //on sort de la boucle
                nbBlocs = 0; //et on réinitialise le compteur pout éviter les conflits
              }
            }
            break;
          default: //tous les autres (T, J, L, S, Z) ont le même set de kick
            for(int i = 0; i < 4; i++) //on va tester les quatre possibilités de kick
            {
              switch(tetroTest[1][4]) //on détermine le set de kicks en fonction de la rotation effectuée
              {
                case POS2:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, -1)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 2: //(0, 2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(-1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
                case POS3:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, 1)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 2: //(0, -2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
                case POS4:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, -1)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 2: //(0, 2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
                case POS1:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, 1)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 2: //(0, -2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(-1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
              }
              nbBlocs = 0; //on reset la valeur de nbBlocs pour le prochain test
              for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
              {
                for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
                {
                  if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
                  {
                    //si la case de la grille est vide et qu'il y a un bloc à mettre
                    if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
                      nbBlocs++;
                  }
                }
              }
              if(nbBlocs == 4) // si l'un des kicks est possibles
              {
                legal = KICK1 + i; //va donner KICK1, KICK2, KICK 3, ou KICK4 en fonction du test qui a été réussi
                i = 4; //on sort de la boucle
                nbBlocs = 0; //et on réinitialise le compteur pout éviter les conflits
              }
            }
            break;
        }

        if(legal < KICK1) //si le tétromino ne peut pas être kické
        {
          legal = ILLEGAL; //on met la valeur de retour à 0
          //et on replace le tetroActuel où il était
          for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
          {
            for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
            {
              if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
              {
                if(grille[x][y] == VIDE) //si la case est vide
                  grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
              }
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
    case SOFTD: //on fait descendre le tétro
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      //on change les coordonnées du tétro
      tetroTest[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        legal = ILLEGAL; //on met la valeur de retour à 2 pour dire au jeu de changer de tétro
        //et on replace le tetroActuel où il était
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
    case LEFT: //on le déplace sur la gauche
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      //on change les coordonnées du tétro
      tetroTest[2][4]--; //on diminue x de 1 (on va d'une case sur la gauche)

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        legal = ILLEGAL; //on met la valeur de retour à 0
        //et on replace le tetroActuel où il était
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
    case RIGHT: //on le déplace sur la droite
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //et qu'elle contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      //on change les coordonnées du tétro
      tetroTest[2][4]++; //on augmente x de 1 (on va d'une case sur la droite)

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        legal = ILLEGAL; //on met la valeur de retour à 0
        //et on replace le tetroActuel où il était
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
    case HARDD: //on le fait descendre tout en bas
      legal = LEGAL; //le mouvement est toujours légal
      break;
    case ROTATEL: //on fait une rotation à gauche
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      tetroTest[1][4]--; //on décrémente la position de tetroTest pour le faire tourner à gauche
      if(tetroTest[1][4] < POS1) //si on dépasse la position minimale
      {
        tetroTest[1][4] = POS4; //on revient à la position maximale
      }
      for(int y = 0; y < 4; y++)
      {
        for(int x = 0; x < 4; x++)
        {
          switch(tetroTest[0][4])
          {
            case JAUNE_O:
              tetroTest[x][y] = tetros->p_jaune_O[(tetroTest[1][4])][x][y];
              break;
            case CYAN_I:
              tetroTest[x][y] = tetros->p_cyan_I[(tetroTest[1][4])][x][y];
              break;
            case MAUVE_T:
              tetroTest[x][y] = tetros->p_mauve_T[(tetroTest[1][4])][x][y];
              break;
            case VIOLET_J:
              tetroTest[x][y] = tetros->p_violet_J[(tetroTest[1][4])][x][y];
              break;
            case ORANGE_L:
              tetroTest[x][y] = tetros->p_orange_L[(tetroTest[1][4])][x][y];
              break;
            case VERT_S:
              tetroTest[x][y] = tetros->p_vert_S[(tetroTest[1][4])][x][y];
              break;
            case ROUGE_Z:
              tetroTest[x][y] = tetros->p_rouge_Z[(tetroTest[1][4])][x][y];
              break;
          }
        }
      }

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        //on regarde si on peut kicker le tétromino
        switch(tetroTest[0][4])
        {
          case JAUNE_O: //on ne peut pas kicker le carré
            break;
          case CYAN_I: //I a son propre set de kick
            for(int i = 0; i < 4; i++) //on va tester les quatre possibilités de kick
            {
              switch(tetroTest[1][4]) //on détermine le set de kicks en fonction de la rotation effectuée
              {
                case POS1:
                  switch(i)
                  {
                    case 0: //(2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(2, -1)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 3: //(-1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
                case POS2:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(-2, -1)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                  }
                  break;
                case POS3:
                  switch(i)
                  {
                    case 0: //(-2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(-2, 1)
                      tetroTest[2][4] = tetroActuel[2][4] - 2;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 3: //(1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
                case POS4:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(2, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 2: //(-1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(2, 1)
                      tetroTest[2][4] = tetroActuel[2][4] + 2;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                  }
                  break;
              }
              nbBlocs = 0; //on reset la valeur de nbBlocs pour le prochain test
              for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
              {
                for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
                {
                  if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
                  {
                    //si la case de la grille est vide et qu'il y a un bloc à mettre
                    if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
                      nbBlocs++;
                  }
                }
              }
              if(nbBlocs == 4) // si l'un des kicks est possibles
              {
                legal = KICK1 + i; //va donner KICK1, KICK2, KICK 3, ou KICK4 en fonction du test qui a été réussi
                i = 4; //on sort de la boucle
                nbBlocs = 0; //et on réinitialise le compteur pout éviter les conflits
              }
            }
            break;
          default: //tous les autres (T, J, L, S, Z) ont le même set de kick
            for(int i = 0; i < 4; i++) //on va tester les quatre possibilités de kick
            {
              switch(tetroTest[1][4]) //on détermine le set de kicks en fonction de la rotation effectuée
              {
                case POS1:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, 1)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 2: //(0, -2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
                case POS2:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, -1)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 2: //(0, 2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(-1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
                case POS3:
                  switch(i)
                  {
                    case 0: //(-1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(-1, 1)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 1;
                      break;
                    case 2: //(0, -2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                    case 3: //(-1, -2)
                      tetroTest[2][4] = tetroActuel[2][4] - 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 2;
                      break;
                  }
                  break;
                case POS4:
                  switch(i)
                  {
                    case 0: //(1, 0)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4];
                      break;
                    case 1: //(1, -1)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] - 1;
                      break;
                    case 2: //(0, 2)
                      tetroTest[2][4] = tetroActuel[2][4];
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                    case 3: //(1, 2)
                      tetroTest[2][4] = tetroActuel[2][4] + 1;
                      tetroTest[3][4] = tetroActuel[3][4] + 2;
                      break;
                  }
                  break;
              }
              nbBlocs = 0; //on reset la valeur de nbBlocs pour le prochain test
              for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
              {
                for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
                {
                  if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
                  {
                    //si la case de la grille est vide et qu'il y a un bloc à mettre
                    if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
                      nbBlocs++;
                  }
                }
              }
              if(nbBlocs == 4) // si l'un des kicks est possibles
              {
                legal = KICK1 + i; //va donner KICK1, KICK2, KICK 3, ou KICK4 en fonction du test qui a été réussi
                i = 4; //on sort de la boucle
                nbBlocs = 0; //et on réinitialise le compteur pout éviter les conflits
              }
            }
            break;
        }

        if(legal < KICK1) //si le tétromino ne peut pas être kické
        {
          legal = ILLEGAL; //on met la valeur de retour à 0
          //et on replace le tetroActuel où il était
          for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
          {
            for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
            {
              if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
              {
                if(grille[x][y] == VIDE) //si la case est vide
                  grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
              }
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
    case 7: //on fait descendre le tétro
      //on efface d'abord l'ancienne position du tétro dans la grille
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
              grille[x][y] = VIDE; //alors on la vide
          }
        }
      }

      //on change les coordonnées du tétro
      tetroTest[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

      //puis vérifie que le tétro peut bien être mis à la position voulu
      for(int y = tetroTest[3][4]; y < (tetroTest[3][4] + 4); y++)
      {
        for(int x = tetroTest[2][4]; x < (tetroTest[2][4] + 4); x ++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case de la grille est vide et qu'il y a un bloc à mettre
            if((grille[x][y] == VIDE) && (tetroTest[x - (tetroTest[2][4])][y - (tetroTest[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      //maintenant qu'on sait si le déplacement est légal ou non
      if(nbBlocs < 4) //s'il ne l'est pas
      {
        legal = ILLEGAL; //on met la valeur de retour à 2 pour dire qu'il faut changer de tétro
        //et on replace le tetroActuel où il était
        for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
        {
          for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(grille[x][y] == VIDE) //si la case est vide
                grille[x][y] = tetroActuel[x - (tetroActuel[2][4])][y - (tetroActuel[3][4])];
            }
          }
        }
      }
      else if(nbBlocs == 4) //s'il l'est
      {
        legal = LEGAL; //on met la valeur de retour à 1
      }
      break;
  }

  return legal;
}

bool lockTest(int grille[GRID_W][GRID_H], int tetroActuel[4][5])
{
  //on va tester chaque ligne des coordonnées du tétro plus une vers le bas
  for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 5); y++)
  {
    for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          //on regarde s'il y a le sol ou un bloc de la grille juste en dessous
          if(y == 21) //21 correspond à la toute première ligne de la grille
          {
            return true; //alors la pièce va se bloquer
          }
          else if(grille[x][y+1] >= JAUNE_G) //si la case du dessous contient un bloc
          {
            return true; //alors la pièce va se bloquer
          }
        }
      }
    }
  }

  return false; //si la boucle se termine, alors la pièce ne va pas se bloquer
}

void lockTetro(int grille[GRID_W][GRID_H], int tetroActuel[4][5])
{
  //On fixe le tétro (on remplace chacun de ses blocs dans la grille par un bloc_G)
  for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
  {
    for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4] + 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          switch(tetroActuel[0][4]) //on switch le type du tétro
          {
            case JAUNE_O:
              grille[x][y] = JAUNE_G; //alors on y met le bloc voulu
              break;
            case CYAN_I:
              grille[x][y] = CYAN_G; //alors on y met le bloc voulu
              break;
            case MAUVE_T:
              grille[x][y] = MAUVE_G; //alors on y met le bloc voulu
              break;
            case VIOLET_J:
              grille[x][y] = VIOLET_G; //alors on y met le bloc voulu
              break;
            case ORANGE_L:
              grille[x][y] = ORANGE_G; //alors on y met le bloc voulu
              break;
            case VERT_S:
              grille[x][y] = VERT_G; //alors on y met le bloc voulu
              break;
            case ROUGE_Z:
              grille[x][y] = ROUGE_G; //alors on y met le bloc voulu
              break;
          }
        }
      }
    }
  }
}

bool ligneComplete(int grille[GRID_W][GRID_H], File *soundEv)
{
  //variables dont on aura besoin
  int nbLignesCompletes = 0;
  int nbBlocsVides = 0;

  //tout d'abord on parcourt la grille pour vérifier s'il y a une ou plusieurs ligne complète
  for(int y = 2; y < GRID_H; y++)
  {
    for(int x = 0; x < GRID_W; x++)
    {
      if(grille[x][y] == VIDE) //si la case de la grille est VIDE
        nbBlocsVides++;

      if(x == 9) //quand on a fini la ligne
      {
        if(nbBlocsVides == 0) //si la ligne est complète
          nbLignesCompletes++;

        nbBlocsVides = 0; //puis on remet le compteur de blocs vides à 0
      }
    }
  }

  if(nbLignesCompletes > 0)
  {
    enfiler(soundEv, (LCSINGLE + (nbLignesCompletes - 1))); //on revoit l'évènement pour la fonction de son
    return true;
  }
  else
   return false;
}

int enleverLignes(int grille[GRID_W][GRID_H])
{
  //variables dont on aura besoin
  int nbBlocsVides = 0, nbLignesCompletes = 0;
  int lignesCompletes[4] = {0}; //va compter stocker la valeur y des lignes complétées

  //on parcourt la grille pour identifier quelles sont les lignes complètes, et les faire disparaître
  for(int y = 2; y < GRID_H; y++)
  {
    for(int x = 0; x < GRID_W; x++)
    {
      if(grille[x][y] == VIDE) //si la case de la grille est VIDE
        nbBlocsVides++;

      if(x == 9) //quand on a fini la ligne
      {
        if(nbBlocsVides == 0) //si la ligne est complète
        {
          nbLignesCompletes++;
          lignesCompletes[nbLignesCompletes - 1] = y;
          //on fait descendre toutes celles du dessus sur elle
          for(int i = y; i > 0; i--) //on répète la boucle autant de fois qu'il y a de lignes au dessus de la complète
          {
            for(int j = 0; j < 10; j++) //on répète celle-ci une fois pour chaque bloc de la ligne (donc 10 fois)
            {
              grille[j][i] = grille[j][i-1]; //on affecte la valeur de la case du dessus à celle de la ligne complète
            }
          }
        }
        nbBlocsVides = 0; //puis on remet le compteur de blocs vides à 0
      }
    }
  }

  return nbLignesCompletes; //puis on retourne combien de lignes ont été enlevées pour calculer le score
}

void scoring(int *score, int niveau, int action, int *dernierCoup, int *comboCount)
{
  switch(action) //on regarde quel type d'action va être comptabiliser dans le score
  {
    case 1: //si le joueur complète une ligne
      *score += 100 * niveau;
      break;
    case 2: //si le joueur complète deux lignes
      *score += 300 * niveau;
      break;
    case 3: //si le joueur complète trois lignes
      *score += 500 * niveau;
      break;
    case 4: //si le joueur complète quatre lignes (TETRIS)
      *score += 800 * niveau;
      break;
    case 5: //softDrop
      *score += 1;
      break;
    case 6: //hardDrop
      *score += 2;
      break;
    case 7: //T-Spin
      *score += 400 * niveau;
      //printf("T-Spin!\n");
      break;
    case 8: //T-Spin Single (T-Spin + une ligne)
      *score += 800 * niveau;
      //printf("T-Spin Single!\n");
      break;
    case 9: //T-Spin Double (T-Spin + deux lignes)
      *score += 1200 * niveau;
      //printf("T-Spin Double!\n");
      break;
    case 10: //T-Spin Triple (T-Spin + trois lignes)
      *score += 500 * niveau;
      //printf("T-Spin Triple!\n");
      break;
  }

  if(action != 5 && action != 6) //si l'action n'est pas un drop
  {
    switch(*dernierCoup)
    {
      case 0: //si le dernier coup n'a pas donné de score
        *comboCount = 0; //va compter le nombre de coups donnant du score d'affilé
        printf("Action 0: pas de point et comboCount = %d\n", *comboCount);
        break;
      case 1: //si le joueur complète une ligne
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 20 * niveau;
        printf("COMBO %dx20!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        break;
      case 2: //si le joueur complète deux lignes
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        break;
      case 3: //si le joueur complète trois lignes
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        break;
      case 4: //si le joueur complète quatre lignes (TETRIS)
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        if(action == 4) //si on a deux TETRIS d'affilés
        {
          *score += 1200 * niveau;
          printf("B2B TETRIS!\n");
        }
        break;
      case 7: //T-Spin
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        break;
      case 8: //T-Spin Single (T-Spin + une ligne)
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        if(action == 8) //si on a deux T-Spin Single d'affilés
        {
          *score += 1200 * niveau;
          printf("B2B T-Spin Single!\n");
        }
        break;
      case 9: //T-Spin Double (T-Spin + deux lignes)
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        if(action == 9) //si on a deux T-Spin Double d'affilés
        {
          *score += 1800 * niveau;
          printf("B2B T-Spin Double!\n");
        }
        break;
      case 10: //T-Spin Triple (T-Spin + trois lignes)
        (*comboCount)++; //on incrémente le nombre de coups d'affilés
        *score += (*comboCount) * 50 * niveau;
        printf("COMBO %dx50!\n", *comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", *dernierCoup, *comboCount);
        break;
    }
    *dernierCoup = action; //puis on règle le dernier coup pour la prochaine boucle
  }
}

void leveling(int *niveau, int *score, int *vitesse, File *soundEv)
{
  //on met les valeurs manipulées dans des variables temporaires
  int niveauTemp = *niveau;
  int scoreTemp = *score;
  float vitesseTemp = *vitesse;

  //calcul du score requis pour atteindre le prochain niveau
  int scoreRequis = 0;
  for(int i = (niveauTemp+1); i > 1; i--)
  {
    scoreRequis += i * 1000;
  }

  //si le score actuel dépasse ou égale le score requis
  if((scoreTemp) >= scoreRequis)
  {
    niveauTemp++; //alors on passe au niveau suivant
    enfiler(soundEv, LEVELUP); //on envoit LEVELUP à la fonction de son
    printf("LEVEL UP ! %d -> %d\n", niveauTemp - 1, niveauTemp);
  }

  vitesseTemp = round((0.8-((niveauTemp)*0.025)) * 60); //on modifie la vitesse s'il y a levelup
  if(vitesseTemp == 0)
    vitesseTemp++;
  *vitesse = vitesseTemp; //et on l'affecte à la valeur du pointeur
  *niveau = niveauTemp; //on fait de même pour le niveau
}

void ghostPiece(packPartie *images, int grille[GRID_W][GRID_H], int tetroActuel[4][5])
{
  //on crée un ghostTetro
  int ghostTetro[4][5] = {VIDE};
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      ghostTetro[x][y] = tetroActuel[x][y];
    }
  }

  //on test le mouvement jusqu'en bas de la grille (comme dans le cas d'un space)
  int legal = 2;
  int nbBlocs = 0;
  bool croiseTetroActuel = true; //permet de savoir si le ghostTetro croise encore le tetroActuel
  bool croiseBloc = false; //permet de savoit si le ghostTetro croise un bloc de la grille
  bool tetroActuelPlusUn = false; //permet de savoir si à un moment du test le ghost ne croise plus le tétro actuel ni de bloc de la grille
  while(legal == 2)
  {
    //on change les coordonnées du tétro
    ghostTetro[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

    //puis on vérifie si le ghostTetro croise encore le tetroActuel
    if(croiseTetroActuel)
    {
      for(int y = ghostTetro[3][4]; y < (ghostTetro[3][4] + 4); y++)
      {
        for(int x = ghostTetro[2][4]; x < (ghostTetro[2][4] + 4); x++)
        {
          if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
          {
            //si la case occupée par le ghost tetro ne l'est pas également par un bloc du tetroActuel
            if((grille[x][y] < JAUNE || grille[x][y] > ROUGE ) && (ghostTetro[x - (ghostTetro[2][4])][y - (ghostTetro[3][4])] != VIDE))
              nbBlocs++;
          }
        }
      }

      if(nbBlocs == 4) //s'il ne croise plus le tétro actuel
      {
        croiseTetroActuel = false; //on ne fait plus le test
      }

      nbBlocs = 0; //puis on remet nbBlocs à 0 pour l'autre test
    }

    //puis on vérifie que le tétro ne croise pas un bloc de la grille (ou qu'il est encore dans la grille)
    for(int y = ghostTetro[3][4]; y < (ghostTetro[3][4] + 4); y++)
    {
      for(int x = ghostTetro[2][4]; x < (ghostTetro[2][4] + 4); x++)
      {
        if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
        {
          //si la case de la grille est vide et qu'il y a un bloc à mettre
          if((grille[x][y] < JAUNE_G) && (ghostTetro[x - (ghostTetro[2][4])][y - (ghostTetro[3][4])] != VIDE))
            nbBlocs++;
        }
      }
    }

    if(nbBlocs < 4)
      croiseBloc = true;
    else if(nbBlocs == 4)
      croiseBloc = false;

    nbBlocs = 0; //puis on remet nbBlocs à 0 pour le prochain test

    if(!croiseBloc && !croiseTetroActuel) //si le ghost ne croise plus ni le tétro actuel, ni un bloc de la grille
      tetroActuelPlusUn = true; //alors il pourra être affiché

    if(croiseTetroActuel && croiseBloc) //si le ghost croise à la fois le tétro actuel et un bloc (ou que y > GRID_H)
      legal = 0; //on ne peut pas afficher le ghost
    else if(!croiseTetroActuel && croiseBloc) //si le ghost ne croise plus le tétro actuel, mais un bloc de la grille (ou que y > GRID_H)
    {
      if(tetroActuelPlusUn) //si la dernière position du ghost ne croisait pas le tétro actuel
      {
        ghostTetro[3][4]--; //on a la position d'affichage du ghost
        legal = 1; //on signale qu'on peut afficher le ghost
      }
      else
      {
        legal = 0; //sinon on ne peut pas l'afficher
      }
    }
  }

  //une fois trouvée la position du hardDrop, on affiche le tétromino fantôme
  if(legal) //si on peut afficher le ghost
  {
    //alors on le fait putain
    ALLEGRO_COLOR transparent = al_map_rgba_f(0.5, 0.5, 0.5, 0.5);
    int posTetro[2] = {0, 0}; //position du tétro dans l'image
    int posGrille[2] = {0, 0}; //position du ghost sur la grille
    posGrille[Y] = 19 + ((ghostTetro[3][4] - 2) * 28); //départ en y à la première case du ghost
    posGrille[X] = 84 + ((ghostTetro[2][4]) * 28); //départ en x à la première case du ghost

    //on blitte l'image en fonction de son type
    switch(ghostTetro[0][4])
    {
      case JAUNE_O:
        posTetro[X] += 28;
        posTetro[Y] += 28;
        posGrille[X] += posTetro[X];
        posGrille[Y] += posTetro[Y];
        al_draw_tinted_bitmap_region(images->ghostPiece->jauneo, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
        break;
      case CYAN_I:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS1, transparent, posTetro[X], posTetro[Y], (3 + (4 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            break;
          case POS2:
            posTetro[X] += (2 * 28);
            posGrille[X] += posTetro[X];
            al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS2, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (4 * 28)), posGrille[X], posGrille[Y], 0);
            break;
          case POS3:
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS3, transparent, posTetro[X], posTetro[Y], (3 + (4 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            break;
          case POS4:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS4, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (4 * 28)), posGrille[X], posGrille[Y], 0);
            break;
        }
        break;
      case MAUVE_T:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS1, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 28;
            posGrille[X] -= 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS1, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS2:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS2, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 31;
            posTetro[Y] += 28;
            posGrille[X] += 31;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS2, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS3:
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS3, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            posTetro[X] += 28;
            posTetro[Y] += 31;
            posGrille[X] += 28;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS3, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            break;
          case POS4:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS4, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 28;
            posGrille[X] -= 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS4, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            break;
        }
        break;
      case VIOLET_J:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS1, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            posTetro[Y] += 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS1, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS2:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS2, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 31;
            posGrille[X] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS2, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS3:
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS3, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            posTetro[X] += (2 * 28);
            posGrille[X] += (2 * 28);
            posTetro[Y] += 31;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS3, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            break;
          case POS4:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS4, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posGrille[X] -= 28;
            posTetro[Y] += (2 * 28);
            posGrille[Y] += (2 * 28);
            al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS4, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            break;
        }
        break;
      case ORANGE_L:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[X] += (2 * 28);
            posTetro[Y] += 28;
            posGrille[X] += posTetro[X];
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS1, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            posTetro[X] -= (2 * 28);
            posGrille[X] -= (2 * 28);
            posTetro[Y] += 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS1, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS2:
            posTetro[X] += 28;
            posGrille[X] +=28;
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS2, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 31;
            posGrille[X] += 31;
            posTetro[Y] += (2 * 28);
            posGrille[Y] += (2 * 28);
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS2, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            break;
          case POS3:
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS3, transparent, posTetro[X], posTetro[Y], (3 + (3 * 28)), 31, posGrille[X], posGrille[Y], 0);
            posTetro[Y] += 31;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS3, transparent, posTetro[X], posTetro[Y], 31, 28, posGrille[X], posGrille[Y], 0);
            break;
          case POS4:
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS4, transparent, posTetro[X], posTetro[Y], 28, 31, posGrille[X], posGrille[Y], 0);
            posTetro[X] += 28;
            posGrille[X] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS4, transparent, posTetro[X], posTetro[Y], 31, (3 + (3 * 28)), posGrille[X], posGrille[Y], 0);
            break;
        }
        break;
      case VERT_S:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[X] += 28;
            posGrille[X] += posTetro[X];
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS1, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 31;
            posGrille[X] -= 28;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS1, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), 28, posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X], posGrille[Y] - 3, 0);
            break;
          case POS2:
            posTetro[X] += 28;
            posTetro[Y] += 28;
            posGrille[X] += posTetro[X];
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS2, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 31;
            posTetro[Y] += 28;
            posGrille[X] += 31;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS2, transparent, posTetro[X], posTetro[Y], 28, (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, posGrille[X] - 3, posGrille[Y] + 31, 0);
            break;
          case POS3:
            posTetro[X] += 28;
            posGrille[X] += 28;
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS3, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 31;
            posGrille[X] -= 28;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS3, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), 28, posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X], posGrille[Y] - 3, 0);
            break;
          case POS4:
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS4, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 31;
            posTetro[Y] += 28;
            posGrille[X] += 31;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS4, transparent, posTetro[X], posTetro[Y], 28, (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, posGrille[X] - 3, posGrille[Y] + 31, 0);
            break;
        }
        break;
      case ROUGE_Z:
        switch(ghostTetro[1][4])
        {
          case POS1:
            posTetro[Y] += 28;
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS1, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 28;
            posTetro[Y] += 31;
            posGrille[X] += 28;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS1, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), 28, posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X] + 31, posGrille[Y] - 3, 0);
            break;
          case POS2:
            posTetro[X] += (2 * 28);
            posTetro[Y] += 28;
            posGrille[X] += posTetro[X];
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS2, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 28;
            posGrille[X] -= 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS2, transparent, posTetro[X], posTetro[Y], 28, (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, posGrille[X] + 28, posGrille[Y] + 31, 0);
            break;
          case POS3:
            posTetro[Y] += (2 * 28);
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS3, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), (3 + (1 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] += 28;
            posTetro[Y] += 31;
            posGrille[X] += 28;
            posGrille[Y] += 31;
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS3, transparent, posTetro[X], posTetro[Y], (3 + (2 * 28)), 28, posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X] + 31, posGrille[Y] - 3, 0);
            break;
          case POS4:
            posTetro[X] += 28;
            posTetro[Y] += 28;
            posGrille[X] += posTetro[X];
            posGrille[Y] += posTetro[Y];
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS4, transparent, posTetro[X], posTetro[Y], (3 + (1 * 28)), (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            posTetro[X] -= 28;
            posTetro[Y] += 28;
            posGrille[X] -= 28;
            posGrille[Y] += 28;
            al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS4, transparent, posTetro[X], posTetro[Y], 28, (3 + (2 * 28)), posGrille[X], posGrille[Y], 0);
            al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, posGrille[X] + 28, posGrille[Y] + 31, 0);
            break;
        }
        break;
    }
  }

}

bool holdPiece(int tetroActuel[4][5], int tetroSuivant[4][5], int grille[GRID_W][GRID_H])
{
  int newPiece[4][5] = {VIDE}; //va servir à copier le tétro suivant

  //d'abord on sauvegarde le tétro suivant
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      newPiece[x][y] = tetroSuivant[x][y];
    }
  }

  //puis on copie le tétro actuel dans le tétro suivant
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      tetroSuivant[x][y] = tetroActuel[x][y];
    }
  }

  //puis la nouvelle pièce (l'ancien tétro suivant) dans le tétro actuel
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      tetroActuel[x][y] = newPiece[x][y];
    }
  }

  //puis on efface l'ancien tétro actuel de la grille
  for(int y = tetroSuivant[3][4]; y < (tetroSuivant[3][4] + 4); y++)
  {
    for(int x = tetroSuivant[2][4]; x < (tetroSuivant[2][4] + 4); x++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
          grille[x][y] = VIDE; //alors on la vide
      }
    }
  }

  //maintenant on change les coordonnées des deux tétros
  tetroActuel[2][4] = DEPART_X; //position en X sur la grille (au milieu)
  tetroActuel[3][4] = DEPART_Y; //position en Y sur la grille (en haut)
  tetroSuivant[2][4] = 0;
  tetroSuivant[3][4] = 0;

  //puis on le place dans la grille, tout en vérifiant qu'il n'y a pas déjà de tétro à cet endroit
  int nbBlocs = 0;
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      if((grille[DEPART_X + x][DEPART_Y + y] == VIDE) && (tetroActuel[x][y] != VIDE)) //si la case de la grille est vide et que celle du tétro ne l'est pas
      {
        grille[DEPART_X + x][DEPART_Y + y] = tetroActuel[x][y]; //on place le bloc
        nbBlocs++; //et on incrémente nBblocs
      }
    }
  }

  //on vérifie que les quatre blocs ont bien été placé
  if(nbBlocs == 4)
    return true; //si c'est le cas, alors holdPiece renvoit true pour indiquer que tout s'est bien passé
  else
    return false; //sinon elle renvoit false, et le joueur a perdu la partie
}

void troisDeuxUn(packPartie *images, elementsFondPartie *elem, int pause, int niveau, int score, int lignes)
{
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //on charge la couleur du texte
  coord *rect = NULL; //on crée un pointeur pour les coordonnées

  for(int i = 3; i > 0; i--)
  {
    //on dessine d'abord le fond de l'écran
    al_draw_bitmap(images->fondPartie, 0, 0, 0);

    if(pause == 1) //si on sort de la pause, alors on affiche aussi les données NSL
    {
      //on charge le pointeur "coord" pour raccourcir les lignes suivantes
      rect = elem->rectNSL;

      //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
      char strNiveau[3]; //trois caractère max (de 1 à 99)
      char strScore[7]; //six caractères max (de 1 999999)
      char strLignes[6]; //cinq caractères max (de 1 99999)
      sprintf(strNiveau, "%d", niveau);
      sprintf(strScore, "%d", score);
      sprintf(strLignes, "%d", lignes);

      font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay" en taille 25

      //affiche la valeur de "niveau" dans la case correspondante
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + rect->t + 9, ALLEGRO_ALIGN_RIGHT, strNiveau);
      //affiche la valeur de "score" dans la case correspondante
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y + (rect->t * 2) + 48 + 9, ALLEGRO_ALIGN_RIGHT, strScore);
      //affiche la valeur de "lignes" dans la case correspondante
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + 247, rect->y2 - rect->t - 48 + 9, ALLEGRO_ALIGN_RIGHT, strLignes);
    }

    //puis on affiche le nombre du compte à rebours
    font = al_load_ttf_font("Gameplay.ttf", 50, 0); //on recharge la police Gameplay en taille 50 cette fois
    rect = elem->rectPause;

    switch(i)
    {
      case 3:
        al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, SCREEN_H/2 - 50, ALLEGRO_ALIGN_CENTRE, "3");
        break;
      case 2:
        al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, SCREEN_H/2 - 50, ALLEGRO_ALIGN_CENTRE, "2");
        break;
      case 1:
        al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, SCREEN_H/2 - 50, ALLEGRO_ALIGN_CENTRE, "1");
        break;
    }

    //puis on affiche les changements (gnééééééééééééééééééééééé)
    al_flip_display();

    //puis on fait une pause d'une seconde
    al_rest(1);
  }

  //on libère la mémoire
  al_destroy_font(font);
}

bool TSpinTest(int grille[GRID_W][GRID_H], int tetroActuel[4][5])
{
  //déjà on regarde si le tétromino actuel est un T
  if(tetroActuel[0][4] == MAUVE_T)
  {
    //on va tester les quatre cases autour du centre de rotation du T pour savoir si elles sont occuppées
    int x = 0, y = 0; //coordonnées que l'on va tester
    int nbBlocsOc = 0; //va compter le nombre de blocs occupés autour du centre de rotation
    //coordonnées de la première case:
    x = tetroActuel[2][4];
    y = tetroActuel[3][4] + 1;
    if(x >= 0)
    {
      if(grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa gauche
      nbBlocsOc++; //alors c'est une case occuppé
    //coordonnées de la deuxième case:
    x = tetroActuel[2][4] + 2;
    y = tetroActuel[3][4] + 1;
    if(x <= GRID_W)
    {
      if(grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa droite
      nbBlocsOc++; //alors c'est une case occuppée
    //coordonnées de la troisième case:
    x = tetroActuel[2][4] + 2;
    y = tetroActuel[3][4] + 3;
    if(x <= GRID_W && y <= GRID_H)
    {
      if(grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa gauche ou le sol
      nbBlocsOc++; //alors c'est une case occuppé
    //coordonnées de la quatrième case:
    x = tetroActuel[2][4];
    y = tetroActuel[3][4] + 3;
    if(x >= 0 && y <= GRID_H)
    {
      if(grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa droite ou le sol
      nbBlocsOc++; //alors c'est une case occuppé

    //maintenant on teste la valeur de nbBlocsOc
    if(nbBlocsOc >= 3) //si 3 cases ou plus sont occupées
      return true; //alors on a un T-Spin
    else
      return false;
  }
  else //sinon
   return false; //il ne peut y avoir de T-Spin
}

bool testTouchLR(int grille[GRID_W][GRID_H], int tetroActuel[4][5])
{
  //on va tester chaque ligne des coordonnées du tétro plus une vers la gauche et la droite
  for(int y = tetroActuel[3][4]; y < (tetroActuel[3][4] + 4); y++)
  {
    for(int x = tetroActuel[2][4]; x < (tetroActuel[2][4]+ 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(grille[x][y] != VIDE && grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          //on regarde s'il y a le sol ou un bloc de la grille juste en dessous
          if(x-1 < 0 || x+1 > GRID_W) //0 et GRID_W représentent les côtés de la grille
          {
            return true; //alors la pièce touche le mur
          }
          else if(grille[x-1][y] >= JAUNE_G || grille[x+1][y] >= JAUNE_G) //si une case à gauche ou à droite contient un bloc
          {
            return true; //alors la pièce touche un bloc de la grille
          }
        }
      }
    }
  }

  return false; //si la boucle se termine, alors la pièce ne touche pas d'obstacles
}
