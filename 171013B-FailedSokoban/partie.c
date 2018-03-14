#include "partie.h"

void partie(SDL_Window* sokoban)
{
  //"niveau" est un tableau représentant la grille du niveau
  int niveau[144];

  //on lance le menu de choix du niveau
  choixNiveau(sokoban, niveau);

  //on charge le niveau dans la fenêtre
  chargerNiveau(sokoban, niveau);

  //on détermine la position de la hitbox de mario au départ
  SDL_Rect hitboxMario;
  phdMario(&hitboxMario, niveau);

  //on crée un tableau de SDL_Rect pour déterminer les hitbox des autres éléments du niveau
  SDL_Rect niveauHitbox[144];

  //on génère ensuite des hitbox là où il y a des éléments de niveau autre que du vide
  genererNiveauHitbox(niveau, niveauHitbox);

  //maintenant on attend l'input du joueur
  SDL_Event event;
  int continuer = 1;
  int decalage = 0; //valeur qui va nous servir dans les tests de mouvement
  int legal = 0; //variable de test de la fonction testMouvement
  while(continuer)
  {
    //on attend un évènement (input du joueur)
    SDL_WaitEvent(&event);

    //on teste l'évènement
    switch(event.type)
    {
      case SDL_QUIT: //s'il veut quitter
        exit(EXIT_SUCCESS);
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_UP:
            deplacerHitbox(&hitboxMario, 'h', VITESSE_MARIO);
            legal = testMouvement(hitboxMario, niveau, niveauHitbox, 'h', VITESSE_MARIO, sokoban, &decalage);
            if(!legal) //si le mouvement est illégal
            {
              deplacerHitbox(&hitboxMario, 'b', VITESSE_MARIO); //on redéplace la hitbox de mario dans le sens inverse
              afficherMouvement(hitboxMario, 'h', 0, sokoban, niveau);
              decaler(&decalage, &hitboxMario, 'h', sokoban, niveau);
            }
            else
            {
              afficherMouvement(hitboxMario, 'h', VITESSE_MARIO, sokoban, niveau);
            }
            testVictoire(&continuer, niveau, sokoban);
            break;
          case SDLK_DOWN:
            deplacerHitbox(&hitboxMario, 'b', VITESSE_MARIO);
            legal = testMouvement(hitboxMario, niveau, niveauHitbox, 'b', VITESSE_MARIO, sokoban, &decalage);
            if(!legal) //si le mouvement est illégal
            {
              deplacerHitbox(&hitboxMario, 'h', VITESSE_MARIO); //on redéplace la hitbox de mario dans le sens inverse
              afficherMouvement(hitboxMario, 'b', 0, sokoban, niveau);
              decaler(&decalage, &hitboxMario, 'b', sokoban, niveau);
            }
            else
            {
              afficherMouvement(hitboxMario, 'b', VITESSE_MARIO, sokoban, niveau);
            }
            testVictoire(&continuer, niveau, sokoban);
            break;
          case SDLK_RIGHT:
            deplacerHitbox(&hitboxMario, 'd', VITESSE_MARIO);
            legal = testMouvement(hitboxMario, niveau, niveauHitbox, 'd', VITESSE_MARIO, sokoban, &decalage);
            if(!legal) //si le mouvement est illégal
            {
              deplacerHitbox(&hitboxMario, 'g', VITESSE_MARIO); //on redéplace la hitbox de mario dans le sens inverse
              afficherMouvement(hitboxMario, 'd', 0, sokoban, niveau);
              decaler(&decalage, &hitboxMario, 'd', sokoban, niveau);
            }
            else
            {
              afficherMouvement(hitboxMario, 'd', VITESSE_MARIO, sokoban, niveau);
            }
            testVictoire(&continuer, niveau, sokoban);
            break;
          case SDLK_LEFT:
            deplacerHitbox(&hitboxMario, 'g', VITESSE_MARIO);
            legal = testMouvement(hitboxMario, niveau, niveauHitbox, 'g', VITESSE_MARIO, sokoban, &decalage);
            if(!legal) //si le mouvement est illégal
            {
              deplacerHitbox(&hitboxMario, 'd', VITESSE_MARIO); //on redéplace la hitbox de mario dans le sens inverse
              afficherMouvement(hitboxMario, 'g', 0, sokoban, niveau);
              decaler(&decalage, &hitboxMario, 'g', sokoban, niveau);
            }
            else
            {
              afficherMouvement(hitboxMario, 'g', VITESSE_MARIO, sokoban, niveau);
            }
            testVictoire(&continuer, niveau, sokoban);
            break;
        }
    }
  }

}
