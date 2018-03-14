#include "fPartie.h"

void phdMario(SDL_Rect* hitboxMario, int niveau[144])
{
  //on initie les valeurs x et y de "hitboxMario" à 0
  hitboxMario->x = 0;
  hitboxMario->y = 0;
  //et sa taille
  hitboxMario->w = 16;
  hitboxMario->h = 28;

  //on parcourt le tableau de niveau
  for(int i = 0; i < 144; i ++)
  {
    //quand on trouve le 4 déterminant la position de départ
    if(niveau[i] == 4)
    {
      i = 144; //on sort de la boucle
    }

    //on incrémente "hitboxMario.x" de 34 pour la prochaine exécution de la boucle sauf si on a trouvé la bonne valeur
    if(i != 144)
      hitboxMario->x += 34;

    //si on arrive au bout d'une ligne
    if(hitboxMario->x == 408)
    {
      hitboxMario->x = 0; //on remet x à 0
      hitboxMario->y += 34; //et on saute une ligne
    }
  }

  //une fois qu'on a trouvé la position du sprite, on détermine celle de la hitbox de mario
  hitboxMario->x += 9; //la hitbox de mario se trouve à 9 à droite pixels du début du sprite
  hitboxMario->y += 3; //et à 3 pixels en bas
}

void genererNiveauHitbox(int niveau[144], SDL_Rect niveauHitbox[144])
{
  //on crée un SDL_Rect dans laquelle on va récupérer les coordonnées en fonction de "niveau[i]"
  SDL_Rect position;
  position.x = 0;
  position.y = 0;

  //on lit le tableau de niveau
  for(int i = 0; i < 144; i++)
  {
    //on switch la valeur indiquée
    switch(niveau[i])
    {
      case 0: //si c'est un mur
        niveauHitbox[i].x = position.x;
        niveauHitbox[i].y = position.y;
        niveauHitbox[i].w = 34;
        niveauHitbox[i].h = 34;
        break;
      case 1: //si c'est du vide
        niveauHitbox[i].x = 0;
        niveauHitbox[i].y = 0;
        niveauHitbox[i].w = 0;
        niveauHitbox[i].h = 0;
        break;
      case 2: //si c'est une caisse
        niveauHitbox[i].x = position.x;
        niveauHitbox[i].y = position.y;
        niveauHitbox[i].w = 34;
        niveauHitbox[i].h = 34;
        break;
      case 3: //si c'est un objectif
        niveauHitbox[i].x = position.x;
        niveauHitbox[i].y = position.y;
        niveauHitbox[i].w = 34;
        niveauHitbox[i].h = 34;
        break;
      case 4: //si c'est le départ du joueur
        niveauHitbox[i].x = 0;
        niveauHitbox[i].y = 0;
        niveauHitbox[i].w = 0;
        niveauHitbox[i].h = 0;
        break;
    }

    //on modifie ensuite les valeurs de "position" pour la prochaine exécution de la boucle
    position.x += 34;

    //si on arrive au bout d'une ligne
    if(position.x == 408)
    {
      position.x = 0; //on remet x à 0
      position.y += 34; //et on saute une ligne
    }
  }
}

void deplacerHitbox(SDL_Rect* hitbox, char direction, int vitesse)
{
  switch(direction)
  {
    case 'h':
      hitbox->y -= vitesse;
      break;
    case 'b':
      hitbox->y += vitesse;
      break;
    case 'd':
      hitbox->x += vitesse;
      break;
    case 'g':
      hitbox->x -= vitesse;
      break;
  }
}

int testMouvement(SDL_Rect hitboxMario, int niveau[144], SDL_Rect niveauHitbox[144], char direction, int vitesse, SDL_Window* sokoban, int* decalage)
{
  //on initie la valeur int qu'on retournera pour dire si le déplacement est autorisé ou non et celle indiquant s'il y a croisement
  int autorise = 0;
  int croisement = 0;
  int coordCroisement = 0;
  int coordCroisementTMC = 0; //valeurs qui seront données à "valideCaisse"
  int positionCaisse = 0; //pareil
  int nbCaisse = 0;
  int caisseDecalee = 0;
  int legal = 0;
  SDL_Rect intersect;

  //on teste si la hitbox de mario en croise une autre
  for(int i = 0; i < 144; i ++)
  {
    //si la valeur de niveau[i] ne correspond pas à une case vide ou à un objectif
    if(niveau[i] != 1 && niveau[i] != 3)
    {
      switch(SDL_IntersectRect(&hitboxMario, &niveauHitbox[i], &intersect))
      {
        case SDL_TRUE:
          croisement = 1; //on indique que la hitbox de mario en croise une autre
          coordCroisement = i; //on enregistre la position de la hitbox croisée dans le tableau
          if(niveau[coordCroisement] == 2) //on compte le nombre de caisse croisées
            nbCaisse++;
          if(!(niveau[coordCroisement] == 2)) //si la hitbox croisée est une caisse on continue à tester si mario ne croise pas d'autre hitbox
            i = 144; //et on sort de la boucle
          break;
      }
    }

    //si on quitte la boucle sans avoir trouvé d'intersection (si mario avance dans le vide)
    if(i == 143 && croisement == 0)
      return autorise = 1; //on sort de la fonction pour dire que le déplacement est autorisé
  }

  if(nbCaisse > 1) //si la hitbox de mario est en contact avec plus d'une caisse lors de son déplacement
    return autorise = 0; //alors il n'est pas autorisé

  //on vérifie le type de la hitbox croisée
  switch(niveau[coordCroisement])
  {
    case 0: //si c'est un mur
      autorise = 0; //le déplacement n'est pas autorisé
      break;
    case 2: //si c'est une caisse
      deplacerHitbox(&niveauHitbox[coordCroisement], direction, vitesse);
      legal = testMouvementCaisse(niveauHitbox[coordCroisement], niveau, niveauHitbox, coordCroisement, direction, sokoban, &coordCroisementTMC, decalage, vitesse);
      if(!legal) //si le mouvement est illégal
      {
        deplacerHitbox(&niveauHitbox[coordCroisement], direction, -vitesse); //on remet la hibox de la caisse où elle se trouvait
        autorise = 0; //et on retourne que le déplacement est illégal
        if(*decalage != 0)
        {
          decalerCaisse(decalage, &niveauHitbox[coordCroisement], direction, sokoban, niveau); //fonction de décalage si décalage il y a
          caisseDecalee = 1;
        }
      }
      else
      {
        autorise = 1; //alors on retourne que le déplacement est autorisé
        afficherMouvementCaisse(niveauHitbox[coordCroisement], direction, vitesse, sokoban, niveau);
        if(legal == 2) //si testMouvementCaisse renvoit 2, alors
          valideCaisse(coordCroisementTMC, niveau, niveauHitbox, coordCroisement, sokoban);
      }
      break;
    case 3: //si c'est un objectif
      autorise = 1; //le déplacement est autorisé
      break;
    case 4: //si c'est le départ
      autorise = 1; //le déplacement est légal vu que la zone est vide
      break;
    case 5: //si c'est une caisse validée
      autorise = 0; //le déplacement n'est pas autorisé
      break;
  }

  //si le mouvement n'est toujours pas autorisé et qu'il n'y a pas décalage de la part de "testMouvementCaisse"
  if((!autorise) && (caisseDecalee == 0) && (intersect.h > 0) && (intersect.w > 0))
  {
    switch(direction)
    {
      case 'h':
        if(intersect.h < hitboxMario.h) //si la hauteur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.h; //la valeur de décalage va être égale à la hauteur de l'intersection
        }
        break;
      case 'b':
        if(intersect.h < hitboxMario.h) //si la hauteur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.h; //la valeur de décalage va être égale à la hauteur de l'intersection
        }
        break;
      case 'd':
        if(intersect.w < hitboxMario.w) //si la largeur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.w; //la valeur de décalage va être égale à la largeur de l'intersection
        }
        break;
      case 'g':
        if(intersect.w < hitboxMario.w) //si la largeur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.w;
        }
        break;
    }
  }

  //on retourne la valeur de "autorise" pour dire si le déplacement est légal ou pas
  return autorise;
}

int testMouvementCaisse(SDL_Rect hitboxCaisse, int niveau[144], SDL_Rect niveauHitbox[144], int positionCaisse, char direction, SDL_Window* sokoban, int* coordCroisementTMC, int* decalage, int vitesse)
{
  //on initie la valeur int qu'on retournera pour dire si le déplacement est autorisé ou non et celle indiquant s'il y a croisement
  int autorise = 0;
  int croisement = 0;
  *coordCroisementTMC = 0;
  SDL_Rect intersect;

  //on teste si la hitbox de la caisse en croise une autre
  for(int i = 0; i < 144; i ++)
  {
    //si la valeur de niveau[i] ne correspond pas à une case vide
    if(niveau[i] != 1)
    {
      switch(SDL_IntersectRect(&hitboxCaisse, &niveauHitbox[i], &intersect) && i != positionCaisse)
      {
        case SDL_TRUE:
          croisement = 1; //on indique que la hitbox de la caisse en croise une autre
          *coordCroisementTMC = i; //on enregistre la position de la hitbox croisée dans le tableau

          //si la hitbox croisée est un objectif, on continue la boucle
          if(niveau[i] != 3)
            i = 143; //on sort de la boucle
          break;
      }
    }

    //si on quitte la boucle sans avoir trouvé d'intersection (si la caisse avance dans le vide)
    if(i == 143 && croisement == 0)
      return autorise = 1; //on sort de la fonction pour dire que le déplacement est autorisé
  }

  //on vérifie le type de la hitbox croisée
  switch(niveau[*coordCroisementTMC])
  {
    case 0: //si c'est un mur
      autorise = 0; //le déplacement n'est pas autorisé
      break;
    case 2: //si c'est une caisse
      autorise = 0; //le déplacement n'est pas autorisé
      break;
    case 3: //si c'est un objectif
      autorise = 1; //le déplacement est autorisé
      //on calcule l'intersection de la caisse et de l'objectif
      SDL_IntersectRect(&hitboxCaisse, &niveauHitbox[*coordCroisementTMC], &intersect);
      if((intersect.x > 16) || (intersect.y > 16)) //si la hitbox de la caise est à plus de la moitié de la case, alors
        autorise = 2;
      break;
    case 4: //si c'est le départ
      autorise = 1; //le déplacement est autorisé vu que la zone est vide
      break;
    case 5: //si c'est une caisse validée
      autorise = 0; //le déplacement n'est pas autorisé
      break;
  }

  //si le mouvement n'est pas autorisé, on calcule le décalage
  if(!autorise)
  {
    switch(direction)
    {
      case 'h':
        if(intersect.h < hitboxCaisse.h) //si la hauteur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.h; //la valeur de décalage va être égale à la hauteur de l'intersection
        }
        break;
      case 'b':
        if(intersect.h < hitboxCaisse.h) //si la hauteur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.h; //la valeur de décalage va être égale à la hauteur de l'intersection
        }
        break;
      case 'd':
        if(intersect.w < hitboxCaisse.w) //si la largeur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.w; //la valeur de décalage va être égale à la largeur de l'intersection
        }
        break;
      case 'g':
        if(intersect.w < hitboxCaisse.w) //si la largeur de l'intersection est strictement inférieure à la vitesse
        {
          *decalage = vitesse - intersect.w;
        }
        break;
    }
  }

  //on retourne la valeur de "autorise" pour dire le mouvement était légal ou non
  return autorise;
}

void afficherMouvement(SDL_Rect hitbox, char direction, int vitesse, SDL_Window* sokoban, int niveau[144])
{
  //on initie les variables dont on aura besoin
  SDL_Surface *surface = SDL_GetWindowSurface(sokoban); //on obtient la surface de la fenêtre pour la modifier
  SDL_Rect positionPrecedente; //on initialise une variable pour la position précédente
  positionPrecedente.w = 16; //largeur du sprite de mario
  positionPrecedente.h = 28; //hauteur du sprite de mario
  SDL_Rect nouvellePosition; //puis pour la nouvelle
  nouvellePosition.w = 34;
  nouvellePosition.h = 34;

  //on détermine la nouvelle position de l'image à partir de celle de la hitbox de mario
  nouvellePosition.x =  (hitbox.x - 9);
  nouvellePosition.y =  (hitbox.y - 3);

  switch(direction)
  {
    case 'h': //si le déplacement se fait vers le haut
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x;
      positionPrecedente.y = hitbox.y + vitesse;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      //si mario a marché sur un objectif
      reafficherObjectif(positionPrecedente, surface, niveau);
      //puis on charge le sprite aux nouvelles positions
      SDL_Surface *marioh = SDL_LoadBMP("images/mario_haut.bmp");
      SDL_BlitSurface(marioh, NULL, surface, &nouvellePosition);
      break;
    case 'b': //si le déplacement se fait vers le bas
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x;
      positionPrecedente.y = hitbox.y - vitesse;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      //si mario a marché sur un objectif
      reafficherObjectif(positionPrecedente, surface, niveau);
      //puis on charge le sprite aux nouvelles positions
      SDL_Surface *mariob = SDL_LoadBMP("images/mario_bas.bmp");
      SDL_BlitSurface(mariob, NULL, surface, &nouvellePosition);
      break;
    case 'd': //si le déplacement se fait vers la droite
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x - vitesse;
      positionPrecedente.y = hitbox.y;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      //si mario a marché sur un objectif
      reafficherObjectif(positionPrecedente, surface, niveau);
      //puis on charge le sprite aux nouvelles positions
      SDL_Surface *mariod = SDL_LoadBMP("images/mario_droite.bmp");
      SDL_BlitSurface(mariod, NULL, surface, &nouvellePosition);
      break;
    case 'g': //si le déplacement se fait vers la gauche
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x + vitesse;
      positionPrecedente.y = hitbox.y;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      //si mario a marché sur un objectif
      reafficherObjectif(positionPrecedente, surface, niveau);
      //puis on charge le sprite aux nouvelles positions
      SDL_Surface *mariog = SDL_LoadBMP("images/mario_gauche.bmp");
      SDL_BlitSurface(mariog, NULL, surface, &nouvellePosition);
      break;
  }

  //on affiche les changements à l'écran
  SDL_UpdateWindowSurface(sokoban);

  //on libère la mémoire
  SDL_FreeSurface(surface);
}

void reafficherObjectif(SDL_Rect positionPrecedente, SDL_Surface* surface, int niveau[144])
{
  //variables de la "boucle objectif"
  int caseX = 0;
  int caseY = 0;
  int cCase = 0;

  //on détermine d'abord les coordonnées de la case
  for(int i = 0; i < 144; i++)
  {
    cCase = i;

    //on compare les coordonnées précédentes du sprite avec celles de la case qu'on examine
    if(caseX <= positionPrecedente.x && positionPrecedente.x < (caseX + 34) && caseY <= positionPrecedente.y && positionPrecedente.y < (caseY + 34) )
    {
      i = 144; //on sort de la boucle
      caseX -= 34; //on décrémente caseX de 34 pour compenser l'incrémentation d'après
    }

    caseX += 34; //on incrémente de 34 pour passer à la case d'après
    if(caseX == 408) //quand on finit une ligne
    {
      caseX = 0; //on revient au début de la ligne
      caseY += 34; //on passe à la ligne d'en dessous
    }
  }

  //puis on crée un SDL_Rect aux coordonnées trouvées
  SDL_Rect dest;
  dest.x = caseX;
  dest.y = caseY;

  //on charge la surface qu'on blittera
  SDL_Surface *spriteObjectif = SDL_LoadBMP("images/objectif.bmp");

  //ensuite on teste si la case en question correspond bien à un objectif
  if(niveau[cCase] == 3)
  {
    //puis on blitte l'image "objectif" aux positions de la case
    SDL_BlitSurface(spriteObjectif, NULL, surface, &dest);
  }

  //on teste les cases autour pour voir s'il y a des objectifs autour de la case
  if(niveau[cCase - 1] == 3 && dest.x != 0)
  {
    dest.x -= 34;
    SDL_BlitSurface(spriteObjectif, NULL, surface, &dest);
    dest.x += 34;
  }
  if(niveau[cCase + 1] == 3 && dest.x != 374)
  {
    dest.x += 34;
    SDL_BlitSurface(spriteObjectif, NULL, surface, &dest);
    dest.x -= 34;
  }
  if(niveau[cCase - 12] == 3 && dest.y != 0)
  {
    dest.y -= 34;
    SDL_BlitSurface(spriteObjectif, NULL, surface, &dest);
    dest.y += 34;
  }
  if(niveau[cCase + 12] == 3 && dest.y != 374)
  {
    dest.y += 34;
    SDL_BlitSurface(spriteObjectif, NULL, surface, &dest);
    dest.y -= 34;
  }

}

void afficherMouvementCaisse(SDL_Rect hitbox, char direction, int vitesse, SDL_Window* sokoban, int niveau[144])
{
  //on initie les variables dont on aura besoin
  SDL_Surface *surface = SDL_GetWindowSurface(sokoban); //on obtient la surface de la fenêtre pour la modifier
  SDL_Rect positionPrecedente; //on initialise une variable pour la position précédente
  positionPrecedente.w = 34; //largeur du sprite de la caisse
  positionPrecedente.h = 34; //hauteur du sprite de la caisse

  switch(direction)
  {
    case 'h': //si le déplacement se fait vers le haut
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x;
      positionPrecedente.y = hitbox.y + vitesse;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      break;
    case 'b': //si le déplacement se fait vers le bas
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x;
      positionPrecedente.y = hitbox.y - vitesse;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      break;
    case 'd': //si le déplacement se fait vers la droite
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x - vitesse;
      positionPrecedente.y = hitbox.y;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      break;
    case 'g': //si le déplacement se fait vers la gauche
      //on détermine la position précédente du sprite
      positionPrecedente.x = hitbox.x + vitesse;
      positionPrecedente.y = hitbox.y;
      //on remplie aux coordonnées précédentes du sprite par du blanc
      SDL_FillRect(surface, &positionPrecedente, SDL_MapRGB(surface->format, 255, 255, 255));
      break;
  }

  //on affiche la caisse à la nouvelle position
  SDL_Surface *caisse = SDL_LoadBMP("images/caisse.bmp");
  SDL_BlitSurface(caisse, NULL, surface, &hitbox);

  //on affiche les changements à l'écran
  SDL_UpdateWindowSurface(sokoban);

  //on libère la mémoire
  SDL_FreeSurface(surface);
}

void valideCaisse(int coordCroisement, int niveau[144], SDL_Rect niveauHitbox[144], int positionCaisse, SDL_Window* sokoban)
{
  //on efface la caisse de la surface
  SDL_Surface *surface = SDL_GetWindowSurface(sokoban);
  SDL_FillRect(surface, &niveauHitbox[positionCaisse], SDL_MapRGB(surface->format, 255, 255, 255));

  //puis on fait disparaître la hitbox de la caisse
  niveauHitbox[positionCaisse].x = 0;
  niveauHitbox[positionCaisse].y = 0;
  niveauHitbox[positionCaisse].w = 0;
  niveauHitbox[positionCaisse].h = 0;

  //maintenant on blitte l'image de la caisse validée aux coordonnées de l'objectif
  SDL_Surface *caisseOk = SDL_LoadBMP("images/caisse_ok.bmp");
  SDL_BlitSurface(caisseOk, NULL, surface, &niveauHitbox[coordCroisement]);
  SDL_UpdateWindowSurface(sokoban);

  //on met dans dans le tableau de niveau que la case de l'objectif est désormais une caisse validée
  niveau[coordCroisement] = 5;

  //on libère la mémoire
  SDL_FreeSurface(caisseOk);
  SDL_FreeSurface(surface);
}

void decaler(int* decalage, SDL_Rect* hitbox, char direction, SDL_Window* sokoban, int niveau[144])
{
  if(*decalage) //si "decalage" est différent de 0
  {
    deplacerHitbox(hitbox, direction, *decalage); //on déplace la hitbox de la valeur "decalage" calculée par "testMouvement"
    afficherMouvement(*hitbox, direction, *decalage, sokoban, niveau); //on affiche le mouvement
    *decalage = 0; //on remet décalage à 0
  }
}

void decalerCaisse(int* decalage, SDL_Rect* hitboxCaisse, char direction, SDL_Window* sokoban, int niveau[144])
{
  if(*decalage) //si "decalage" est différent de 0
  {
    deplacerHitbox(hitboxCaisse, direction, *decalage); //on déplace la hitbox de la valeur "decalage" calculée par "testMouvement"
    afficherMouvementCaisse(*hitboxCaisse, direction, *decalage, sokoban, niveau); //on affiche le mouvement
  }
}

void testVictoire(int* continuer, int niveau[144], SDL_Window* sokoban)
{
  //variable bool indiquant s'il y a un objectif ou pas
  int objectif = 0;

  //on lit le tableau pour voir s'il reste des objectifs
  for(int i = 0; i < 144; i++)
  {
    if(niveau[i] == 3) //si on trouve un objectif
    {
      objectif = 1; //alors on indique qu'il y a un objectif
      i = 143; //on sort de la boucle
    }
  }

  //si aucun objectif n'a été trouvé
  if(!objectif)
  {
    //on indique à la boucle d'évènements dans partie.c de se terminer
    *continuer = 0;

    //on met un petit delay, pour que le joueur puisse voir son dernier coup
    SDL_Delay(1500);

    //on charge le message de victoire dans la surface de la fenêtre
    SDL_Surface* surface = SDL_GetWindowSurface(sokoban);
    SDL_Surface* victoire = SDL_LoadBMP("images/victoire.bmp");
    SDL_Rect pVictoire;
    pVictoire.x = 0;
    pVictoire.y = 0;
    SDL_BlitSurface(victoire, NULL, surface, &pVictoire);
    SDL_UpdateWindowSurface(sokoban);

    //on refait une pause pour que l'utilisateur puisse voir le message
    SDL_Delay(2000);

    //on libère la mémoire
    SDL_FreeSurface(surface);
    SDL_FreeSurface(victoire);
  }
}
