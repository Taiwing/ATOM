#include "include/jeu.h"

gameData *initialiserGameData(int niveauChoisi)
{
  //on génère la structure de données
  gameData *data = malloc(sizeof(gameData));

  //on initialise la valeur des variables de jeu à leur valeur par défaut
  //données du joueur
  data->niveau = niveauChoisi;
  data->score = 0;
  data->lignes = 0;
  data->nbLignes = 0; //va compter le nombre de lignes disparues s'il y en a
  data->vitesse = 45;

  //données tétrominos
  data->tetros = chargerTetrominos(); //on crée la structure de tétrominos
  for(int i = 0; i < GRID_W; i++)
  {
    for(int j = 0; j < GRID_H; j++)
    {
      data->grille[i][j] = VIDE;
    }
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      data->tetroActuel[i][j] = VIDE;
    }
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      data->tetroSuivant[i][j] = VIDE;
    }
  }
  for(int i = 0; i < 7; i++)
  {
    data->sac[i] = 7;
  }
  data->nbTetro = 0; //indique où on en est dans le sac
  randomGenerator(data->sac); //on sélectionne les 7 premières pièces
  selectionAleatoireTetromino(data); //on sélectionne le premier tétro
  data->nbTetro = 1; //on passe au suivant pour la boucle du jeu

  //données de combo
  data->dernierCoup = 0;
  data->comboCount = 0;

  //file d'évènements du jeu
  data->gameEv = initialiser(); //file d'évènements pour la fonction de son
  enfiler(data->gameEv, GAMESTART); //premier évènement du jeu
  data->gameEvent = NOEVENT; //valeur par défaut
  //va dire à la fonction afficherEvenement s'il faut l'afficher ou non
  for(int i = 0; i < 9; i++)
  {
    data->afficherGameEvent[i] = false;
  }
  data->timerAfficheEvent = 0; //va compter le nombre de ticks que va durer l'affichage de l'évènement

  //gestion des déplacements
  data->deplacement = 0; //va recueillir la valeur renvoyée par deplacerTetro
  data->timerVitesse= 0;
  data->timerLateral = 0;
  data->timerAnimDisp = 0;
  data->timerLock = 0;

  //booléens de la partie
  data->redraw = false; //pour redessiner la partie quand 1/60s s'est écoulé
  data->continuer = true; //pour la boucle principale
  for(int i = 0; i < 16; i++)
  {
    data->key[i] = false;
  }
  data->perdu = false;
  data->victoire = false;
  data->nextTetro = true;
  data->legalInput = true;
  data->lComplete = false;
  data->animDisp = false;
  data->ghostPieceOnOff = true;
  data->holdPieceOn = false;
  data->TSpin = false;
  data->lc = false;

  //puis on retourne la structure ainsi créée
  return data;
}

void destroyGameData(gameData *data)
{
  destroyTetrominos(data->tetros);
  free(data);
}

void selectionAleatoireTetromino(gameData *data)
{
  switch(data->sac[data->nbTetro])
  {
    case JAUNE_O:
      data->tetroSuivant[0][4] = JAUNE_O; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_jaune_O[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case CYAN_I:
      data->tetroSuivant[0][4] = CYAN_I; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_cyan_I[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case MAUVE_T:
      data->tetroSuivant[0][4] = MAUVE_T; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_mauve_T[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VIOLET_J:
      data->tetroSuivant[0][4] = VIOLET_J; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_violet_J[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ORANGE_L:
      data->tetroSuivant[0][4] = ORANGE_L; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_orange_L[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VERT_S:
      data->tetroSuivant[0][4] = VERT_S; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_vert_S[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ROUGE_Z:
      data->tetroSuivant[0][4] = ROUGE_Z; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_rouge_Z[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
  }

  if(data->nbTetro == 6) //quand on est arrivé au bout des 7 tétrominos choisi précédemment
  {
    randomGenerator(data->sac); //on sélectionne les prochains
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

bool placerTetro(gameData *data)
{
  //on met le tetroSuivant dans le tetroActuel
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      data->tetroActuel[x][y] = data->tetroSuivant[x][y];
    }
  }

  //on met les coordonnées de départ du nouveau tétro dans la grille
  data->tetroActuel[2][4] = DEPART_X; //position en X sur la grille (au milieu)
  data->tetroActuel[3][4] = DEPART_Y; //position en Y sur la grille (en haut)

  //puis on le place dans la grille, tout en vérifiant qu'il n'y a pas déjà de tétro à cet endroit
  int nbBlocs = 0;
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      if((data->grille[DEPART_X + x][DEPART_Y + y] == VIDE) && (data->tetroActuel[x][y] != VIDE)) //si la case de la grille est vide et que celle du tétro ne l'est pas
      {
        data->grille[DEPART_X + x][DEPART_Y + y] = data->tetroActuel[x][y]; //on place le bloc
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

int deplacerTetro(int mouvement, gameData *data)
{
  int test = testDeplacement(mouvement, data->grille, data->tetroActuel, data->tetros); //on test le déplacement

  if(test >= LEGAL) //si le mouvement est légal (ou que c'est un kick)
  {
    switch(mouvement) //on regarde de quel type de mouvement il s'agit
    {
      case ROTATER: //on fait une rotation à droite
        //on vide le tétro Actuel et on remplace chaque case par la celle correspondant à la prochaine position
        data->tetroActuel[1][4]++; //on incrémente la position de tetroActuel pour le faire tourner à droite
        if(data->tetroActuel[1][4] > POS4) //si on dépasse la position maximale
        {
          data->tetroActuel[1][4] = POS1; //on revient à la première
        }
        for(int y = 0; y < 4; y++)
        {
          for(int x = 0; x < 4; x++)
          {
            switch(data->tetroActuel[0][4])
            {
              case JAUNE_O:
                data->tetroActuel[x][y] = data->tetros->p_jaune_O[(data->tetroActuel[1][4])][x][y];
                break;
              case CYAN_I:
                data->tetroActuel[x][y] = data->tetros->p_cyan_I[(data->tetroActuel[1][4])][x][y];
                break;
              case MAUVE_T:
                data->tetroActuel[x][y] = data->tetros->p_mauve_T[(data->tetroActuel[1][4])][x][y];
                break;
              case VIOLET_J:
                data->tetroActuel[x][y] = data->tetros->p_violet_J[(data->tetroActuel[1][4])][x][y];
                break;
              case ORANGE_L:
                data->tetroActuel[x][y] = data->tetros->p_orange_L[(data->tetroActuel[1][4])][x][y];
                break;
              case VERT_S:
                data->tetroActuel[x][y] = data->tetros->p_vert_S[(data->tetroActuel[1][4])][x][y];
                break;
              case ROUGE_Z:
                data->tetroActuel[x][y] = data->tetros->p_rouge_Z[(data->tetroActuel[1][4])][x][y];
                break;
            }
          }
        }

        //si c'est un kick, on change les coordonnées du tétro actuel
        if(data->tetroActuel[0][4] == CYAN_I) //si c'est un I
        {
          switch(test) //on regarde si on doit faire le kick
          {
            case KICK1:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] -= 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 2;
                  break;
                case POS1:
                  data->tetroActuel[2][4] += 1;
                  break;
              }
              break;
            case KICK2:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS1:
                  data->tetroActuel[2][4] -= 2;
                  break;
              }
              break;
            case KICK3:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] -= 2;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 2;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS1:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 2;
                  break;
              }
              break;
            case KICK4:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 2;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  data->tetroActuel[2][4] -= 2;
                  data->tetroActuel[3][4] -= 1;
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
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS1:
                  data->tetroActuel[2][4] -= 1;
                  break;
              }
              break;
            case KICK2:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS1:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 1;
                  break;
              }
              break;
            case KICK3:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  data->tetroActuel[3][4] -= 2;
                  break;
              }
              break;
            case KICK4:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS1:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
              }
              break;
          }
        }

        //puis on met le nouveau tetroActuel dans la grille
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //si la case est vide
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])];
            }
          }
        }
        break;
      case SOFTD: //on fait descendre le tétro
        //on change les coordonnées du tétro
        data->tetroActuel[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //si la case est vide
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case LEFT: //on le déplace sur la gauche
        //on change les coordonnées du tétro
        data->tetroActuel[2][4]--; //on diminue x de 1 (on va d'une case sur la gauche)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //si la case est vide
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case RIGHT: //on le déplace sur la droite
        //on change les coordonnées du tétro
        data->tetroActuel[2][4]++; //on augmente x de 1 (on va d'une case sur la droite)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //si la case est vide
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])]; //alors on y met le bloc voulu
            }
          }
        }
        break;
      case HARDD: //on le fait descendre tout en bas
        //on le fait descendre jusqu'à ce que le test renvoit 2 (pour changer de tétro)
        while (testDeplacement(SOFTD, data->grille, data->tetroActuel, data->tetros) != ILLEGAL)
        {
          data->tetroActuel[3][4]++;

          //puis on le met dans la grille aux nouvelles coordonnées
          for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
          {
            for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
            {
              if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
              {
                if(data->grille[x][y] == VIDE) //si la case est vide
                  data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])]; //alors on y met le bloc voulu
              }
            }
          }
          scoring(6, data); //puis on calcule le score du hardDrop
        }
        break;
      case ROTATEL: //on fait une rotation à gauche
        //on vide le tétro Actuel et on remplace chaque case par la celle correspondant à la prochaine position
        data->tetroActuel[1][4]--; //on décrémente la position de tetroActuel pour le faire tourner à gauche
        if(data->tetroActuel[1][4] < POS1) //si on dépasse la position minimale
        {
          data->tetroActuel[1][4] = POS4; //on revient à la position maximale
        }
        for(int y = 0; y < 4; y++)
        {
          for(int x = 0; x < 4; x++)
          {
            switch(data->tetroActuel[0][4])
            {
              case JAUNE_O:
                data->tetroActuel[x][y] = data->tetros->p_jaune_O[(data->tetroActuel[1][4])][x][y];
                break;
              case CYAN_I:
                data->tetroActuel[x][y] = data->tetros->p_cyan_I[(data->tetroActuel[1][4])][x][y];
                break;
              case MAUVE_T:
                data->tetroActuel[x][y] = data->tetros->p_mauve_T[(data->tetroActuel[1][4])][x][y];
                break;
              case VIOLET_J:
                data->tetroActuel[x][y] = data->tetros->p_violet_J[(data->tetroActuel[1][4])][x][y];
                break;
              case ORANGE_L:
                data->tetroActuel[x][y] = data->tetros->p_orange_L[(data->tetroActuel[1][4])][x][y];
                break;
              case VERT_S:
                data->tetroActuel[x][y] = data->tetros->p_vert_S[(data->tetroActuel[1][4])][x][y];
                break;
              case ROUGE_Z:
                data->tetroActuel[x][y] = data->tetros->p_rouge_Z[(data->tetroActuel[1][4])][x][y];
                break;
            }
          }
        }

        //si c'est un kick, on change les coordonnées du tétro actuel
        if(data->tetroActuel[0][4] == CYAN_I) //si c'est un I
        {
          switch(test) //on regarde si on doit faire le kick
          {
            case KICK1:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] += 2;
                  break;
                case POS2:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] -= 1;
                  break;
              }
              break;
            case KICK2:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS2:
                  data->tetroActuel[2][4] -= 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 2;
                  break;
              }
              break;
            case KICK3:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] += 2;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS2:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 2;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
              }
              break;
            case KICK4:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS2:
                  data->tetroActuel[2][4] -= 2;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 2;
                  data->tetroActuel[3][4] += 1;
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
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] += 1;
                  break;
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  break;
              }
              break;
            case KICK2:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 1;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 1;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 1;
                  break;
              }
              break;
            case KICK3:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS2:
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[3][4] += 2;
                  break;
              }
              break;
            case KICK4:
              switch(data->tetroActuel[1][4]) //on regarde sur sur quelle permutation on fait le kick
              {
                case POS1:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS2:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] += 2;
                  break;
                case POS3:
                  data->tetroActuel[2][4] -= 1;
                  data->tetroActuel[3][4] -= 2;
                  break;
                case POS4:
                  data->tetroActuel[2][4] += 1;
                  data->tetroActuel[3][4] += 2;
                  break;
              }
              break;
          }
        }

        //puis on met le nouveau tetroActuel dans la grille
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //pour ne pas effacer les blocs qui se trouvent déjà aux coordonnées du tétro
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])];
            }
          }
        }
        break;
      case 7: //on fait descendre le tétro
        //on change les coordonnées du tétro
        data->tetroActuel[3][4]++; //on augmente y de 1 (donc on descend d'une ligne)

        //puis on le met dans la grille aux nouvelles coordonnées
        for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
        {
          for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x++)
          {
            if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
            {
              if(data->grille[x][y] == VIDE) //si la case est vide
                data->grille[x][y] = data->tetroActuel[x - (data->tetroActuel[2][4])][y - (data->tetroActuel[3][4])]; //alors on y met le bloc voulu
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

bool lockTest(gameData *data)
{
  //on va tester chaque ligne des coordonnées du tétro plus une vers le bas
  for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 5); y++)
  {
    for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(data->grille[x][y] != VIDE && data->grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          //on regarde s'il y a le sol ou un bloc de la grille juste en dessous
          if(y == 21) //21 correspond à la toute première ligne de la grille
          {
            return true; //alors la pièce va se bloquer
          }
          else if(data->grille[x][y+1] >= JAUNE_G) //si la case du dessous contient un bloc
          {
            return true; //alors la pièce va se bloquer
          }
        }
      }
    }
  }

  return false; //si la boucle se termine, alors la pièce ne va pas se bloquer
}

void lockTetro(gameData *data)
{
  //On fixe le tétro (on remplace chacun de ses blocs dans la grille par un bloc_G)
  for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
  {
    for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4] + 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(data->grille[x][y] != VIDE && data->grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          switch(data->tetroActuel[0][4]) //on switch le type du tétro
          {
            case JAUNE_O:
              data->grille[x][y] = JAUNE_G; //alors on y met le bloc voulu
              break;
            case CYAN_I:
              data->grille[x][y] = CYAN_G; //alors on y met le bloc voulu
              break;
            case MAUVE_T:
              data->grille[x][y] = MAUVE_G; //alors on y met le bloc voulu
              break;
            case VIOLET_J:
              data->grille[x][y] = VIOLET_G; //alors on y met le bloc voulu
              break;
            case ORANGE_L:
              data->grille[x][y] = ORANGE_G; //alors on y met le bloc voulu
              break;
            case VERT_S:
              data->grille[x][y] = VERT_G; //alors on y met le bloc voulu
              break;
            case ROUGE_Z:
              data->grille[x][y] = ROUGE_G; //alors on y met le bloc voulu
              break;
          }
        }
      }
    }
  }
}

bool ligneComplete(gameData *data)
{
  //variables dont on aura besoin
  int nbLignesCompletes = 0;
  int nbBlocsVides = 0;

  //tout d'abord on parcourt la grille pour vérifier s'il y a une ou plusieurs ligne complète
  for(int y = 2; y < GRID_H; y++)
  {
    for(int x = 0; x < GRID_W; x++)
    {
      if(data->grille[x][y] == VIDE) //si la case de la grille est VIDE
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
    enfiler(data->gameEv, (LCSINGLE + (nbLignesCompletes - 1))); //on revoit l'évènement pour la fonction de son
    return true;
  }
  else
   return false;
}

int enleverLignes(gameData *data)
{
  //variables dont on aura besoin
  int nbBlocsVides = 0, nbLignesCompletes = 0;
  int lignesCompletes[4] = {0}; //va compter stocker la valeur y des lignes complétées

  //on parcourt la grille pour identifier quelles sont les lignes complètes, et les faire disparaître
  for(int y = 2; y < GRID_H; y++)
  {
    for(int x = 0; x < GRID_W; x++)
    {
      if(data->grille[x][y] == VIDE) //si la case de la grille est VIDE
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
              data->grille[j][i] = data->grille[j][i-1]; //on affecte la valeur de la case du dessus à celle de la ligne complète
            }
          }
        }
        nbBlocsVides = 0; //puis on remet le compteur de blocs vides à 0
      }
    }
  }

  return nbLignesCompletes; //puis on retourne combien de lignes ont été enlevées pour calculer le score
}

void scoring(int action, gameData *data)
{
  switch(action) //on regarde quel type d'action va être comptabiliser dans le score
  {
    case 1: //si le joueur complète une ligne
      data->score += 100 * data->niveau;
      break;
    case 2: //si le joueur complète deux lignes
      data->score += 300 * data->niveau;
      break;
    case 3: //si le joueur complète trois lignes
      data->score += 500 * data->niveau;
      break;
    case 4: //si le joueur complète quatre lignes (TETRIS)
      data->score += 800 * data->niveau;
      break;
    case 5: //softDrop
      data->score += 1;
      break;
    case 6: //hardDrop
      data->score += 2;
      break;
    case 7: //T-Spin
      data->score += 400 * data->niveau;
      //printf("T-Spin!\n");
      break;
    case 8: //T-Spin Single (T-Spin + une ligne)
      data->score += 800 * data->niveau;
      //printf("T-Spin Single!\n");
      break;
    case 9: //T-Spin Double (T-Spin + deux lignes)
      data->score += 1200 * data->niveau;
      //printf("T-Spin Double!\n");
      break;
    case 10: //T-Spin Triple (T-Spin + trois lignes)
      data->score += 500 * data->niveau;
      //printf("T-Spin Triple!\n");
      break;
  }

  if(action != 5 && action != 6) //si l'action n'est pas un drop
  {
    switch(data->dernierCoup)
    {
      case 0: //si le dernier coup n'a pas donné de score
        data->comboCount = 0; //va compter le nombre de coups donnant du score d'affilé
        printf("Action 0: pas de point et comboCount = %d\n", data->comboCount);
        break;
      case 1: //si le joueur complète une ligne
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 20 * data->niveau;
        printf("COMBO %dx20!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        break;
      case 2: //si le joueur complète deux lignes
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        break;
      case 3: //si le joueur complète trois lignes
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        break;
      case 4: //si le joueur complète quatre lignes (TETRIS)
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        if(action == 4) //si on a deux TETRIS d'affilés
        {
          data->score += 1200 * data->niveau;
          printf("B2B TETRIS!\n");
        }
        break;
      case 7: //T-Spin
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        break;
      case 8: //T-Spin Single (T-Spin + une ligne)
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        if(action == 8) //si on a deux T-Spin Single d'affilés
        {
          data->score += 1200 * data->niveau;
          printf("B2B T-Spin Single!\n");
        }
        break;
      case 9: //T-Spin Double (T-Spin + deux lignes)
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        if(action == 9) //si on a deux T-Spin Double d'affilés
        {
          data->score += 1800 * data->niveau;
          printf("B2B T-Spin Double!\n");
        }
        break;
      case 10: //T-Spin Triple (T-Spin + trois lignes)
        data->comboCount++; //on incrémente le nombre de coups d'affilés
        data->score += data->comboCount * 50 * data->niveau;
        printf("COMBO %dx50!\n", data->comboCount);
        printf("dernierCoup = %d et comboCount = %d\n", data->dernierCoup, data->comboCount);
        break;
    }
    data->dernierCoup = action; //puis on règle le dernier coup pour la prochaine boucle
  }
}

void leveling(gameData *data)
{
  //on met les valeurs manipulées dans des variables temporaires
  int niveauTemp = data->niveau;
  int scoreTemp = data->score;
  float vitesseTemp = data->vitesse;

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
    enfiler(data->gameEv, LEVELUP); //on envoit LEVELUP à la fonction de son
    printf("LEVEL UP ! %d -> %d\n", niveauTemp - 1, niveauTemp);
  }

  vitesseTemp = round((0.8-((niveauTemp)*0.025)) * 60); //on modifie la vitesse s'il y a levelup
  if(vitesseTemp == 0)
    vitesseTemp++;
  data->vitesse = vitesseTemp; //et on l'affecte à la valeur du pointeur
  data->niveau = niveauTemp; //on fait de même pour le niveau
}

void ghostPiece(packPartie *images, gameData *data, float scale)
{
  if(data->ghostPieceOnOff)
  {
    //on crée un ghostTetro
    int ghostTetro[4][5] = {VIDE};
    for(int y = 0; y < 5; y++)
    {
      for(int x = 0; x < 4; x++)
      {
        ghostTetro[x][y] = data->tetroActuel[x][y];
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
              if((data->grille[x][y] < JAUNE || data->grille[x][y] > ROUGE ) && (ghostTetro[x - (ghostTetro[2][4])][y - (ghostTetro[3][4])] != VIDE))
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
            if((data->grille[x][y] < JAUNE_G) && (ghostTetro[x - (ghostTetro[2][4])][y - (ghostTetro[3][4])] != VIDE))
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
          al_draw_tinted_bitmap_region(images->ghostPiece->jauneo, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
          break;
        case CYAN_I:
          switch(ghostTetro[1][4])
          {
            case POS1:
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (4 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS2:
              posTetro[X] += (2 * 28);
              posGrille[X] += posTetro[X];
              al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (4 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS3:
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (4 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS4:
              posTetro[X] += 28;
              posGrille[X] += posTetro[X];
              al_draw_tinted_bitmap_region(images->ghostPiece->cyaniPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (4 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
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
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 28;
              posGrille[X] -= 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS2:
              posTetro[X] += 28;
              posGrille[X] += posTetro[X];
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 31;
              posTetro[Y] += 28;
              posGrille[X] += 31;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS3:
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 28;
              posTetro[Y] += 31;
              posGrille[X] += 28;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS4:
              posTetro[X] += 28;
              posGrille[X] += posTetro[X];
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 28;
              posGrille[X] -= 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->mauvetPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
          }
          break;
        case VIOLET_J:
          switch(ghostTetro[1][4])
          {
            case POS1:
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[Y] += 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS2:
              posTetro[X] += 28;
              posGrille[X] += posTetro[X];
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 31;
              posGrille[X] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS3:
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += (2 * 28);
              posGrille[X] += (2 * 28);
              posTetro[Y] += 31;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS4:
              posTetro[X] += 28;
              posGrille[X] += posTetro[X];
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posGrille[X] -= 28;
              posTetro[Y] += (2 * 28);
              posGrille[Y] += (2 * 28);
              al_draw_tinted_bitmap_region(images->ghostPiece->violetjPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
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
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= (2 * 28);
              posGrille[X] -= (2 * 28);
              posTetro[Y] += 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS2:
              posTetro[X] += 28;
              posGrille[X] +=28;
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 31;
              posGrille[X] += 31;
              posTetro[Y] += (2 * 28);
              posGrille[Y] += (2 * 28);
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS3:
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (3 * 28)), 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[Y] += 31;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              break;
            case POS4:
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, 31 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 28;
              posGrille[X] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->orangelPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 31, (3 + (3 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
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
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 31;
              posGrille[X] -= 28;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X] * scale, (posGrille[Y] - 3) * scale, 0);
              break;
            case POS2:
              posTetro[X] += 28;
              posTetro[Y] += 28;
              posGrille[X] += posTetro[X];
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 31;
              posTetro[Y] += 28;
              posGrille[X] += 31;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, (posGrille[X] - 3) * scale, (posGrille[Y] + 31) * scale, 0);
              break;
            case POS3:
              posTetro[X] += 28;
              posGrille[X] += 28;
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 31;
              posGrille[X] -= 28;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, posGrille[X] * scale, (posGrille[Y] - 3) * scale, 0);
              break;
            case POS4:
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 31;
              posTetro[Y] += 28;
              posGrille[X] += 31;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->vertsPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, (posGrille[X] - 3) * scale, (posGrille[Y] + 31) * scale, 0);
              break;
          }
          break;
        case ROUGE_Z:
          switch(ghostTetro[1][4])
          {
            case POS1:
              posTetro[Y] += 28;
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 28;
              posTetro[Y] += 31;
              posGrille[X] += 28;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS1, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, (posGrille[X] + 31) * scale, (posGrille[Y] - 3) * scale, 0);
              break;
            case POS2:
              posTetro[X] += (2 * 28);
              posTetro[Y] += 28;
              posGrille[X] += posTetro[X];
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 28;
              posGrille[X] -= 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS2, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, (posGrille[X] + 28) * scale, (posGrille[Y] + 31) * scale, 0);
              break;
            case POS3:
              posTetro[Y] += (2 * 28);
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), (3 + (1 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] += 28;
              posTetro[Y] += 31;
              posGrille[X] += 28;
              posGrille[Y] += 31;
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS3, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (2 * 28)), 28 * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleHorizontale, transparent, (posGrille[X] + 31) * scale, (posGrille[Y] - 3) * scale, 0);
              break;
            case POS4:
              posTetro[X] += 28;
              posTetro[Y] += 28;
              posGrille[X] += posTetro[X];
              posGrille[Y] += posTetro[Y];
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * (3 + (1 * 28)), (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              posTetro[X] -= 28;
              posTetro[Y] += 28;
              posGrille[X] -= 28;
              posGrille[Y] += 28;
              al_draw_tinted_bitmap_region(images->ghostPiece->rougezPOS4, transparent, posTetro[X] * scale, posTetro[Y] * scale, scale * 28, (3 + (2 * 28)) * scale, posGrille[X] * scale, posGrille[Y] * scale,  0);
              al_draw_tinted_bitmap(images->barreGrilleVerticale, transparent, (posGrille[X] + 28) * scale, (posGrille[Y] + 31) * scale, 0);
              break;
          }
          break;
      }
    }
  }
}

bool holdPiece(gameData *data)
{
  int newPiece[4][5] = {VIDE}; //va servir à copier le tétro suivant

  //d'abord on sauvegarde le tétro suivant
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      newPiece[x][y] = data->tetroSuivant[x][y];
    }
  }

  //puis on copie le tétro actuel dans le tétro suivant
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      data->tetroSuivant[x][y] = data->tetroActuel[x][y];
    }
  }

  //puis la nouvelle pièce (l'ancien tétro suivant) dans le tétro actuel
  for(int y = 0; y < 5; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      data->tetroActuel[x][y] = newPiece[x][y];
    }
  }

  //puis on efface l'ancien tétro actuel de la grille
  for(int y = data->tetroSuivant[3][4]; y < (data->tetroSuivant[3][4] + 4); y++)
  {
    for(int x = data->tetroSuivant[2][4]; x < (data->tetroSuivant[2][4] + 4); x++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(data->grille[x][y] != VIDE && data->grille[x][y] < JAUNE_G) //si case contient un bloc du tétro actuel
          data->grille[x][y] = VIDE; //alors on la vide
      }
    }
  }

  //maintenant on change les coordonnées des deux tétros
  data->tetroActuel[2][4] = DEPART_X; //position en X sur la grille (au milieu)
  data->tetroActuel[3][4] = DEPART_Y; //position en Y sur la grille (en haut)
  data->tetroSuivant[2][4] = 0;
  data->tetroSuivant[3][4] = 0;

  //puis on le place dans la grille, tout en vérifiant qu'il n'y a pas déjà de tétro à cet endroit
  int nbBlocs = 0;
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      if((data->grille[DEPART_X + x][DEPART_Y + y] == VIDE) && (data->tetroActuel[x][y] != VIDE)) //si la case de la grille est vide et que celle du tétro ne l'est pas
      {
        data->grille[DEPART_X + x][DEPART_Y + y] = data->tetroActuel[x][y]; //on place le bloc
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

void troisDeuxUn(gameScreen *screen, packPartie *images, elements *elem, int pause, int niveau, int score, int lignes)
{
  //on initialise le timer
  ALLEGRO_TIMER *timer_troisDeuxUn = al_create_timer(1.0 / FPS); //on règle le timer à un soixantième de seconde

  //on crée la file d'évènements
  ALLEGRO_EVENT_QUEUE *event_queue_troisDeuxUn = al_create_event_queue();
  al_register_event_source(event_queue_troisDeuxUn, al_get_display_event_source(screen->display)); //on lie la file d'évènements à la fenêtre (pour la fermer)
  al_register_event_source(event_queue_troisDeuxUn, al_get_timer_event_source(timer_troisDeuxUn)); //on lie la file au timer
  al_register_event_source(event_queue_troisDeuxUn, al_get_keyboard_event_source()); //puis on reprend les évènements du clavier en compte
  al_register_event_source(event_queue_troisDeuxUn, al_get_mouse_event_source()); //puis à la souris

  //variables nécessaires à la boucle
  bool redraw = false;
  bool continuer = true;
  bool legalInput = true;
  int temps = 180; //3s

  //on démarre le timer
  al_start_timer(timer_troisDeuxUn);

  //boucle principale du menu
  while(continuer)
  {
    ALLEGRO_EVENT ev; //on crée la variable qui va enregistrer l'évènments
    al_wait_for_event(event_queue_troisDeuxUn, &ev); //on attend qu'un évènement se produise

    if(ev.type == ALLEGRO_EVENT_TIMER) //quand 1/60s s'est écoulé
    {
      temps--;
      if(temps <= 0)
        continuer = false;
      redraw = true; //on met redraw à vrai pour redessiner le menu
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //si le singe ferme la fenêtre
    {
      continuer = false; //on sort de la boucle et donc du menu, et finalement du programme
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
    }

    if(redraw && al_is_event_queue_empty(event_queue_troisDeuxUn)) //si redraw est vrai et que la file d'évènements est vide
    {
      redraw = false;
      afficherTroisDeuxUn(screen, images, elem, pause, niveau, score, lignes, temps); //on affiche le menu à nouveau
    }
  }

  //puis à la fin du menu, on libère la mémoire
  al_destroy_timer(timer_troisDeuxUn);
  al_destroy_event_queue(event_queue_troisDeuxUn);
}

void afficherTroisDeuxUn(gameScreen *screen, packPartie *images, elements *elem, int pause, int niveau, int score, int lignes, int temps)
{
  //on cible le buffer du jeu sur lequel on va dessiner
  targetBuffer(screen);

  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //on charge la couleur du texte
  coord *rect = NULL; //on crée un pointeur pour les coordonnées

  //on dessine d'abord le fond de l'écran
  al_draw_bitmap(images->fondPartie, 0, 0, 0);

  float scale = screen->scaleBuff;

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

    font = al_load_ttf_font("media_files/Gameplay.ttf", 25 * scale, 0); //on charge la police "Gameplay" en taille 25

    //affiche la valeur de "niveau" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y + rect->t + (9 * scale), ALLEGRO_ALIGN_RIGHT, strNiveau);
    //affiche la valeur de "score" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strScore);
    //affiche la valeur de "lignes" dans la case correspondante
    al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strLignes);
  }

  //puis on affiche le nombre du compte à rebours
  font = al_load_ttf_font("media_files/Gameplay.ttf", 50 * scale, 0); //on recharge la police Gameplay en taille 50 cette fois
  rect = elem->rectPause;

  int nombreAffiche = 0;
  if(temps > 120)
    nombreAffiche = 3;
  else if(temps > 60 && temps <= 120)
    nombreAffiche = 2;
  else if(temps <= 60)
    nombreAffiche = 1;

  switch(nombreAffiche)
  {
    case 3:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, screen->buffH/2 - (50 * scale), ALLEGRO_ALIGN_CENTRE, "3");
      break;
    case 2:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, screen->buffH/2 - (50 * scale), ALLEGRO_ALIGN_CENTRE, "2");
      break;
    case 1:
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, screen->buffH/2 - (50 * scale), ALLEGRO_ALIGN_CENTRE, "1");
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  drawBuffer(screen);
}

bool TSpinTest(gameData *data)
{
  //déjà on regarde si le tétromino actuel est un T
  if(data->tetroActuel[0][4] == MAUVE_T)
  {
    //on va tester les quatre cases autour du centre de rotation du T pour savoir si elles sont occuppées
    int x = 0, y = 0; //coordonnées que l'on va tester
    int nbBlocsOc = 0; //va compter le nombre de blocs occupés autour du centre de rotation
    //coordonnées de la première case:
    x = data->tetroActuel[2][4];
    y = data->tetroActuel[3][4] + 1;
    if(x >= 0)
    {
      if(data->grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa gauche
      nbBlocsOc++; //alors c'est une case occuppé
    //coordonnées de la deuxième case:
    x = data->tetroActuel[2][4] + 2;
    y = data->tetroActuel[3][4] + 1;
    if(x <= GRID_W)
    {
      if(data->grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa droite
      nbBlocsOc++; //alors c'est une case occuppée
    //coordonnées de la troisième case:
    x = data->tetroActuel[2][4] + 2;
    y = data->tetroActuel[3][4] + 3;
    if(x <= GRID_W && y <= GRID_H)
    {
      if(data->grille[x][y] != VIDE) //si la case n'est pas vide
        nbBlocsOc++; //alors elle est occuppée (gnééééééééééé)
    }
    else //si le T est contre le mur sur sa gauche ou le sol
      nbBlocsOc++; //alors c'est une case occuppé
    //coordonnées de la quatrième case:
    x = data->tetroActuel[2][4];
    y = data->tetroActuel[3][4] + 3;
    if(x >= 0 && y <= GRID_H)
    {
      if(data->grille[x][y] != VIDE) //si la case n'est pas vide
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

bool testTouchLR(gameData *data)
{
  //on va tester chaque ligne des coordonnées du tétro plus une vers la gauche et la droite
  for(int y = data->tetroActuel[3][4]; y < (data->tetroActuel[3][4] + 4); y++)
  {
    for(int x = data->tetroActuel[2][4]; x < (data->tetroActuel[2][4]+ 4); x ++)
    {
      if(x >= 0 && x < GRID_W && y < GRID_H) //si la case est dans la grille
      {
        if(data->grille[x][y] != VIDE && data->grille[x][y] < JAUNE_G) //si la case contient un bloc du tétro actuel
        {
          //on regarde s'il y a le sol ou un bloc de la grille juste en dessous
          if(x-1 < 0 || x+1 > GRID_W) //0 et GRID_W représentent les côtés de la grille
          {
            return true; //alors la pièce touche le mur
          }
          else if(data->grille[x-1][y] >= JAUNE_G || data->grille[x+1][y] >= JAUNE_G) //si une case à gauche ou à droite contient un bloc
          {
            return true; //alors la pièce touche un bloc de la grille
          }
        }
      }
    }
  }

  return false; //si la boucle se termine, alors la pièce ne touche pas d'obstacles
}

void gameInput(gameData *data,
               gameScreen *screen,
               elements *elem,
               packImages *images,
               ALLEGRO_EVENT_QUEUE *event_queue_partie,
               ALLEGRO_TIMER *timer_partie,
               packSons *sons,
               gameConfig *config)
{
  for(int i = 0; i < 16; i++) //on parcourt le tableau des touches
  {
    if(data->key[i]) //si une touche a été appuyée
    {
      switch(i) //on détermine laquelle
      {
        case ROTATER:
          data->deplacement = deplacerTetro(ROTATER, data);
          if(data->deplacement == LEGAL) //si la rotation est légale et s'effectue sans kick
          {
            data->TSpin = TSpinTest(data); //on fait le test pour savoir s'il y a T-Spin ou non
            enfiler(data->gameEv, ROTATELR);
          }
          else
          {
            data->TSpin = false;
            enfiler(data->gameEv, ROTATEFAIL);
          }
          data->key[ROTATER] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case SOFTD:
          //on déplace la pièce vers le bas
          if(data->timerVitesse % 4 == 0)
          {
            data->deplacement = deplacerTetro(SOFTD, data);
            scoring(5, data); //on calcule le score
            if(data->deplacement)
            {
              data->TSpin = false;
              enfiler(data->gameEv, SOFTDROP);
            }
          }
          break;
        case LEFT:
          //on déplace la pièce vers la gauche
          if(data->timerLateral == 0 || (data->timerLateral % 4 == 0 && data->timerLateral > 4))
          {
            data->deplacement = deplacerTetro(LEFT, data);
            if(data->deplacement)
            {
              data->TSpin = false;
              enfiler(data->gameEv, MOVELR);
              if(testTouchLR(data))
              {
                defiler(data->gameEv);
                enfiler(data->gameEv, TOUCHLR);
              }
            }
          }
          break;
        case RIGHT:
          //on déplace la pièce vers la droite au quadruple de la vitesse auto
          if(data->timerLateral == 0|| (data->timerLateral % 4 == 0 && data->timerLateral > 4))
          {
            data->deplacement = deplacerTetro(RIGHT, data);
            if(data->deplacement)
            {
              data->TSpin = false;
              enfiler(data->gameEv, MOVELR);
              if(testTouchLR(data))
              {
                defiler(data->gameEv);
                enfiler(data->gameEv, TOUCHLR);
              }
            }
          }
          break;
        case HARDD:
          deplacerTetro(HARDD, data);
          enfiler(data->gameEv, HARDDROP);
          data->nextTetro = true; //on dit à la boucle de changer de tétromino
          data->key[HARDD] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case ROTATEL:
          data->deplacement = deplacerTetro(ROTATEL, data);
          if(data->deplacement == LEGAL) //si la rotation est légale et s'effectue sans kick
          {
            data->TSpin = TSpinTest(data); //on fait le test pour savoir s'il y a T-Spin ou non
            enfiler(data->gameEv, ROTATELR);
          }
          else
          {
            data->TSpin = false;
            enfiler(data->gameEv, ROTATEFAIL);
          }
          data->key[ROTATEL] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case PAUSE:
          data->key[PAUSE] = false; //on le met à faux pour que ça ne se répète pas
          al_stop_timer(timer_partie); //on stoppe le timer pour que le temps passé en pause ne soit pas compté
          al_unregister_event_source(event_queue_partie, al_get_keyboard_event_source());
          if(menuPause(screen, elem, images, data->niveau, data->score, data->lignes, sons, config)) //si le joueur a fait quitter
            data->continuer = false; //on revient au menu principal
          else
          {
            troisDeuxUn(screen, images->imagesPartie, elem, 1, data->niveau, data->score, data->lignes); //on lance le compte à rebours avant de reprendre
            al_register_event_source(event_queue_partie, al_get_keyboard_event_source());
            al_start_timer(timer_partie); //on relance le timer
          }
          break;
        case GHOST:
          if(!data->ghostPieceOnOff)
            data->ghostPieceOnOff = true;
          else
            data->ghostPieceOnOff = false;
          data->key[GHOST] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGE:
          //on remplace le tetroActuel par tetroSuivant et vice-versa, et on le replace dans la grille
          if(!holdPiece(data))
          {
            data->perdu = true; //si la fonction ne marche pas, le joueur a perdu
          }
          else
          {
            enfiler(data->gameEv, HOLD);
          }
          data->timerVitesse = 0; //on reset le timer pour que la nouvelle pièce ne rebouge pas tout de suite
          data->holdPieceOn = true;
          data->key[CHANGE] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGEZ:
          changeTetro(ROUGE_Z, data, config);
          data->key[CHANGEZ] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGES:
          changeTetro(VERT_S, data, config);
          data->key[CHANGES] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGET:
          changeTetro(MAUVE_T, data, config);
          data->key[CHANGET] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGEI:
          changeTetro(CYAN_I, data, config);
          data->key[CHANGEI] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGEO:
          changeTetro(JAUNE_O, data, config);
          data->key[CHANGEO] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGEJ:
          changeTetro(VIOLET_J, data, config);
          data->key[CHANGEJ] = false; //on le met à faux pour que ça ne se répète pas
          break;
        case CHANGEL:
          changeTetro(ORANGE_L, data, config);
          data->key[CHANGEL] = false; //on le met à faux pour que ça ne se répète pas
          break;
      }
    }
  }
}

void inputKeyDown(int keyMap[16][3], gameData *data, int key, gameConfig *config)
{
  int input = 0; //va recueillir la fonction de jeu coorespondant à l'input du joueur
  bool toucheValide = false; //va indiquer si la touche appuyée correspond à une touche de jeu
  //on regarde si la touche appuyée correspond à une touche du jeu
  for(int i = 0; i < 16; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(keyMap[i][j] == key)
      {
        input = i;
        toucheValide = true;
      }
    }
  }

  if(toucheValide) //si la touche appuyée correspond à une touche de jeu
  {
    switch(input)
    {
      case ROTATER: //s'il appuie sur la touche de Rotation à Droite
        if(data->legalInput)
        {
          data->key[ROTATER] = true; //on met la case du tableau de touche à vrai
          data->legalInput = false;
        }
        break;
      case SOFTD: //s'il appuie sur la touche de Soft Drop
        data->key[SOFTD] = true; //on met la case du tableau de touche à vrai
        break;
      case LEFT: //s'il appuie sur la touche de Mouvement Gauche
        data->key[LEFT] = true; //on met la case du tableau de touche à vrai
        break;
      case RIGHT: //s'il appuie sur la touche de Mouvement Droite
        data->key[RIGHT] = true; //on met la case du tableau de touche à vrai
        break;
      case HARDD: //s'il appuie sur la touche de Hard Drop
        if(data->legalInput)
        {
          data->key[HARDD] = true; //on met la case du tableau de touche à vrai
          data->legalInput = false;
        }
        break;
      case ROTATEL: //s'il appuie sur la touche de Rotation à Gauche
        if(data->legalInput)
        {
          data->key[ROTATEL] = true; //on met la case du tableau de touche à vrai
          data->legalInput = false;
        }
        break;
      case GHOST: //s'il appuie sur la touche de Ghost
        if(data->legalInput)
        {
          data->key[GHOST] = true; //on met la case du tableau de touche à vrai
          data->legalInput = false;
        }
        break;
      case CHANGE: //s'il appuie sur la touche de Hold
        if(data->legalInput && !data->holdPieceOn) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGE] = true;
          data->legalInput = false;
        }
        break;
      case CHANGEZ:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGEZ] = true;
          data->legalInput = false;
        }
        break;
      case CHANGES:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGES] = true;
          data->legalInput = false;
        }
        break;
      case CHANGET:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGET] = true;
          data->legalInput = false;
        }
        break;
      case CHANGEI:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGEI] = true;
          data->legalInput = false;
        }
        break;
      case CHANGEO:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGEO] = true;
          data->legalInput = false;
        }
        break;
      case CHANGEJ:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGEJ] = true;
          data->legalInput = false;
        }
        break;
      case CHANGEL:
        if(data->legalInput && config->cheatFunctions) //si l'input est légal et que holdpiece n'a pas déjà été utilisé
        {
          data->key[CHANGEL] = true;
          data->legalInput = false;
        }
        break;
    }
  }
}

void inputKeyUp(int keyMap[16][3], gameData *data, int key)
{
  int input = 0; //va recueillir la fonction de jeu coorespondant à l'input du joueur
  bool toucheValide = false; //va indiquer si la touche appuyée correspond à une touche de jeu
  //on regarde si la touche appuyée correspond à une touche du jeu
  for(int i = 0; i < 16; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(keyMap[i][j] == key)
      {
        input = i;
        toucheValide = true;
      }
    }
  }

  if(toucheValide) //si la touche appuyée correspond à une touche de jeu
  {
    switch(input) //on vérifie laquelle
    {
      case ROTATER: //s'il arrête d'appuyer sur la touche de Rotation à Droite
        data->key[ROTATER] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case SOFTD: //s'il arrête d'appuyer sur la touche de Soft Drop
        data->key[SOFTD] = false; //on met la case du tableau de touche à faux
        break;
      case LEFT: //s'il arrête d'appuyer sur la touche de Mouvement à Gauche
        data->key[LEFT] = false; //on met la case du tableau de touche à faux
        break;
      case RIGHT: //s'il arrête d'appuyer sur la touche de Mouvement à Droite
        data->key[RIGHT] = false; //on met la case du tableau de touche à faux
        break;
      case HARDD: //s'il arrête d'appuyer sur la touche de Hard Drop
        data->key[HARDD] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case ROTATEL: //s'il arrête d'appuyer sur la touche de Rotation à Gauche
        data->key[ROTATEL] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case PAUSE: //s'il arrête d'appuyer sur la touche de Pause
        data->key[PAUSE] = true; //quand il arrête d'appuyer, l'input est légal
        break;
      case GHOST: //s'il arrête d'appuyer sur la touche de Ghost
        data->key[GHOST] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGE: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGE] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGEZ: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGEZ] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGES: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGES] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGET: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGET] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGEI: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGEI] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGEO: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGEO] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGEJ: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGEJ] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
      case CHANGEL: //s'il arrête d'appuyer sur la touche de Hold
        data->key[CHANGEL] = false; //on met la case du tableau de touche à faux
        data->legalInput = true; //quand le singe arrête d'appuyer, on lui redonne le droit de le faire
        break;
    }
  }
}

void changeTetro(int tetro, gameData *data, gameConfig *config)
{
  switch(tetro)
  {
    case JAUNE_O:
      data->tetroSuivant[0][4] = JAUNE_O; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_jaune_O[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case CYAN_I:
      data->tetroSuivant[0][4] = CYAN_I; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_cyan_I[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case MAUVE_T:
      data->tetroSuivant[0][4] = MAUVE_T; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_mauve_T[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VIOLET_J:
      data->tetroSuivant[0][4] = VIOLET_J; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_violet_J[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ORANGE_L:
      data->tetroSuivant[0][4] = ORANGE_L; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_orange_L[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case VERT_S:
      data->tetroSuivant[0][4] = VERT_S; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_vert_S[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
    case ROUGE_Z:
      data->tetroSuivant[0][4] = ROUGE_Z; //on indique le type de la pièce dans le tableau
      data->tetroSuivant[1][4] = POS1; //puis quelle position elle est
      for(int x = 0; x < 4; x++)
      {
        for(int y = 0; y < 4; y++)
        {
          data->tetroSuivant[x][y] = data->tetros->p_rouge_Z[POS1][x][y]; //on copie la pièce choisie dans "piece"
        }
      }
      break;
  }

  //on remplace le tetroActuel par tetroSuivant et vice-versa, et on le replace dans la grille
  if(!holdPiece(data))
  {
    data->perdu = true; //si la fonction ne marche pas, le joueur a perdu
  }
  else
  {
    enfiler(data->gameEv, HOLD);
  }
}

void speed(gameData *data)
{
  //on met les valeurs manipulées dans des variables temporaires
  int niveauTemp = data->niveau;
  float vitesseTemp = data->vitesse;

  vitesseTemp = round((0.8-((niveauTemp)*0.025)) * 60); //on établie la vitesse en fonction du niveau
  if(vitesseTemp == 0)
    vitesseTemp++;
  data->vitesse = vitesseTemp; //et on l'affecte à la valeur du pointeur
}

void afficherEvenement(gameData *data, elements *elem)
{
  switch(data->gameEvent) //on va lister quels évènements seront affichés
  {
    case LEVELUP:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ALEVELUP] = true;
      break;
    case LCSINGLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ALCSINGLE] = true;
      break;
    case LCDOUBLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ALCDOUBLE] = true;
      break;
    case LCTRIPLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ALCTRIPLE] = true;
      break;
    case LCTETRIS:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ATETRIS] = true;
      break;
    case STSPIN:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ATSPIN] = true;
      break;
    case STSPINSINGLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ATSPINSINGLE] = true;
      break;
    case STSPINDOUBLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ATSPINDOUBLE] = true;
      break;
    case STSPINTRIPLE:
      //on vérifie qu'il n'y a pas plusieurs évènements a afficher en même temps
      for(int i = 0; i < 9; i++)
      {
        if(data->afficherGameEvent[i]) //si c'est le cas
        {
          data->afficherGameEvent[i] = false; //on remet le premier évènement à faux
          data->timerAfficheEvent = 0; //et on reset le timer
        }
      }
      data->afficherGameEvent[ATSPINTRIPLE] = true;
      break;
  }

  for(int i = 0; i < 9; i++)
  {
    if(data->afficherGameEvent[i])
    {
      data->timerAfficheEvent++;
      ALLEGRO_FONT *font = al_load_ttf_font("media_files/Raleway-Bold.ttf", 30, 0);
      ALLEGRO_COLOR noir = al_map_rgb(0, 0, 0); //couleur du texte
      //on affiche l'évènement
      switch(i)
      {
        case 0:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "LEVEL UP!");
          break;
        case 1:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "SINGLE!");
          break;
        case 2:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "DOUBLE!");
          break;
        case 3:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "TRIPLE!");
          break;
        case 4:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "TETRIS!");
          break;
        case 5:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "T-SPIN!");
          break;
        case 6:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "T-SPIN SINGLE!");
          break;
        case 7:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "T-SPIN DOUBLE!");
          break;
        case 8:
          al_draw_text(font, noir, elem->rectPieceSuiv->x + (elem->rectPieceSuiv->w/2), elem->rectPrincipal->y + ((elem->rectPrincipal->h/4) * 3), ALLEGRO_ALIGN_CENTRE, "T-SPIN TRIPLE!");
          break;
      }

      if(data->timerAfficheEvent == 90) //si on est arrivé à 1,5s
      {
        data->afficherGameEvent[i] = false;
        data->timerAfficheEvent = 0;
      }

      al_destroy_font(font);
    }
  }
}

void afficherPartie(gameScreen *screen, packPartie *images, elements *elem, gameData *data, int modeDeJeu, int timer)
{
  targetBuffer(screen);
  float scale = screen->scaleBuff;

  //on charge l'image de fond
  al_draw_bitmap(images->fondPartie, 0, 0, 0);

  //on charge le pointeur "coord" pour raccourcir les lignes suivantes
  coord *rect = elem->rectNSL;

  //on traduit les valeurs de "niveau", "score" et lignes en chaîne de caractère
  char strNiveau[3]; //trois caractère max (de 1 à 99)
  char strScore[7]; //cinq caractères max (de 1 99999)
  char strLignes[6]; //cinq caractères max (de 1 99999)
  char strTimer[9]; //huit caractères max (de 0 à 99:59:59)
  sprintf(strNiveau, "%d", data->niveau);
  sprintf(strScore, "%d", data->score);
  sprintf(strLignes, "%d", data->lignes);
  int minutes = (timer/3600), secondes = ((timer % 3600)/60), dixiemes = ((timer % 60)/6);

  //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", 25 * scale, 0); //on charge la police "Gameplay"
  //affiche la valeur de "niveau" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y + rect->t + (9 * scale), ALLEGRO_ALIGN_RIGHT, strNiveau);
  //affiche la valeur de "score" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strScore);
  //affiche la valeur de "lignes" dans la case correspondante
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), ALLEGRO_ALIGN_RIGHT, strLignes);

  if(modeDeJeu == SPRINT || modeDeJeu == ULTRA)
  {
    if(timer < 0) //si le timer est négatif
    {
      sprintf(strTimer, "0"); //on affiche 0
    }
    else if(secondes < 1 && minutes == 0 && timer >= 0) //s'il ne s'est pas encore écoulé une seconde
    {
      sprintf(strTimer, "%d", dixiemes); //on affiche les dixième de seconde
    }
    else if(secondes > 0 && secondes < 10 && minutes == 0) //quand on est entre 0 et 10 secondes
    {
      sprintf(strTimer, "0%d:%d", secondes, dixiemes);
    }
    else if(secondes > 9 && secondes < 60 && minutes == 0) //si on est deça de la minute
    {
      sprintf(strTimer, "%d:%d", secondes, dixiemes);
    }
    else if(minutes > 0) //si on est au-dessus de la minute
    {
      if(secondes < 10) //si le nombre de secondes est inférieur à 10
      {
        sprintf(strTimer, "%d:0%d:%d", minutes, secondes, dixiemes);
      }
      else
      {
        sprintf(strTimer, "%d:%d:%d", minutes, secondes, dixiemes);
      }
    }

    //affiche le timer
    al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + rect->t + (247 * scale), rect->y2 + (9 * scale), ALLEGRO_ALIGN_RIGHT, strTimer);
  }

  //on affiche le "tetroSuivant" dans le cadre correspondant
  bool dessinerBarreHaute = false, dessinerBarreGauche = false;
  float pos[2] = {0, 0}; //position où va coller l'image
  switch(data->tetroSuivant[0][4]) //0;4 est la case correcspondant au type du tétromino stocké dans le tableau
  {
    case JAUNE_O:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 461;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_jaune_O[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(JAUNE, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case CYAN_I:
      pos[Y] = scale * 5;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 461;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_cyan_I[POS3][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(CYAN, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case MAUVE_T:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_mauve_T[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(MAUVE, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case VIOLET_J:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_violet_J[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(VIOLET, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
     break;
    case ORANGE_L:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_orange_L[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(ORANGE, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case VERT_S:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_vert_S[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(VERT, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case ROUGE_Z:
      pos[Y] = scale * 19;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = scale * 475;
        for(int x = 0; x < 4; x++)
        {
          if(data->tetros->p_rouge_Z[POS1][x][y] != VIDE) //s'il y a un bloc à dessiner
          {
            drawBlock(ROUGE, pos[X], pos[Y], scale);
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
              drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
            if(dessinerBarreGauche)
              drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
            drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
            drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          }
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
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
  pos[Y] = scale * 22; //départ en y en haut de la grille
  for(int y = 2; y < GRID_H; y++) //on va parcourir la grille à partir de la troisième ligne
  {
    pos[X] = scale * 87;
    for(int x = 0; x < GRID_W; x++) //on va parcourir la grille à partir de la deuxième colonne
    {
      switch(data->grille[x][y]) //on regarde la valeur stockée dans la case
      {
        case JAUNE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(JAUNE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case CYAN:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(CYAN, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case MAUVE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(MAUVE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case VIOLET:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(VIOLET, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case ORANGE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(ORANGE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case VERT:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(VERT, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case ROUGE:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(ROUGE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case JAUNE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(JAUNE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case CYAN_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(CYAN, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case MAUVE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(MAUVE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case VIOLET_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(VIOLET, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case ORANGE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(ORANGE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case VERT_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(VERT, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
        case ROUGE_G:
          if(data->animDisp && lignesDisp[y]) //si cette ligne doit disparaître
            drawBlock(BLANC, pos[X], pos[Y], scale);
          else
            drawBlock(ROUGE, pos[X], pos[Y], scale);
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
            drawHorBarre(pos[X] - (3 * scale), pos[Y] - (3 * scale), scale);
          if(dessinerBarreGauche)
            drawVerBarre(pos[X] - (3 * scale), pos[Y], scale);
          drawHorBarre(pos[X], pos[Y] + (25 * scale), scale);
          drawVerBarre(pos[X] + (25 * scale), pos[Y] - (3 * scale), scale);
          break;
      }
      pos[X] += (28 * scale); //une fois qu'on a fini d'inspécter la case, on passe à la suivante sur la ligne
    }
    pos[Y] += (28 * scale); //une fois qu'on a fini d'inspécter la ligne, on passe à la suivante
  }

  afficherEvenement(data, elem); //on affiche l'évènement s'il y en a un
  ghostPiece(images, data, scale); //on affiche la pièce fantôme

  //on libère la mémoire
  al_destroy_font(font);

  drawBuffer(screen);
}
