#include "images.h"
#include "score.h"
#include "time.h"
#include "lines.h"

packMenu *genererPackMenu(elementsFondMenu *elem)
{
  //on crée un pointeur vers la structure d'images
  packMenu *images = malloc(sizeof(*images));

  //puis on initie chacune des images
  images->fondMenu = genererFondMenu(elem);
  images->highScore = genererHigh(MARATHON, elem);
  images->highTemps = genererHigh(SPRINT, elem);
  images->highLines = genererHigh(ULTRA, elem);
  images->boutonJouerOff = genererBoutonMenu(JOUER, OFF, 0, elem);
  images->boutonJouerOn = genererBoutonMenu(JOUER, ON, 0, elem);
  images->boutonMarathonOff = genererBoutonMenu(MARATHON, OFF, 0, elem);
  images->boutonMarathonOn = genererBoutonMenu(MARATHON, ON, 0, elem);
  images->boutonSprintOff = genererBoutonMenu(SPRINT, OFF, 0, elem);
  images->boutonSprintOn = genererBoutonMenu(SPRINT, ON, 0, elem);
  images->boutonUltraOff = genererBoutonMenu(ULTRA, OFF, 0, elem);
  images->boutonUltraOn = genererBoutonMenu(ULTRA, ON, 0, elem);
  images->boutonAideOff = genererBoutonMenu(AIDE, OFF, 0, elem);
  images->boutonAideOn = genererBoutonMenu(AIDE, ON, 0, elem);
  images->boutonOptionsOff = genererBoutonMenu(OPTIONS, OFF, 0, elem);
  images->boutonOptionsOn = genererBoutonMenu(OPTIONS, ON, 0, elem);
  images->boutonNiveau1Off = genererBoutonMenu(NIVEAU, OFF, 1, elem);
  images->boutonNiveau2Off = genererBoutonMenu(NIVEAU, OFF, 2, elem);
  images->boutonNiveau3Off = genererBoutonMenu(NIVEAU, OFF, 3, elem);
  images->boutonNiveau4Off = genererBoutonMenu(NIVEAU, OFF, 4, elem);
  images->boutonNiveau5Off = genererBoutonMenu(NIVEAU, OFF, 5, elem);
  images->boutonNiveau6Off = genererBoutonMenu(NIVEAU, OFF, 6, elem);
  images->boutonNiveau7Off = genererBoutonMenu(NIVEAU, OFF, 7, elem);
  images->boutonNiveau8Off = genererBoutonMenu(NIVEAU, OFF, 8, elem);
  images->boutonNiveau9Off = genererBoutonMenu(NIVEAU, OFF, 9, elem);
  images->boutonNiveau10Off = genererBoutonMenu(NIVEAU, OFF, 10, elem);
  images->boutonNiveau11Off = genererBoutonMenu(NIVEAU, OFF, 11, elem);
  images->boutonNiveau12Off = genererBoutonMenu(NIVEAU, OFF, 12, elem);
  images->boutonNiveau13Off = genererBoutonMenu(NIVEAU, OFF, 13, elem);
  images->boutonNiveau14Off = genererBoutonMenu(NIVEAU, OFF, 14, elem);
  images->boutonNiveau15Off = genererBoutonMenu(NIVEAU, OFF, 15, elem);
  images->boutonNiveau16Off = genererBoutonMenu(NIVEAU, OFF, 16, elem);
  images->boutonNiveau17Off = genererBoutonMenu(NIVEAU, OFF, 17, elem);
  images->boutonNiveau18Off = genererBoutonMenu(NIVEAU, OFF, 18, elem);
  images->boutonNiveau19Off = genererBoutonMenu(NIVEAU, OFF, 19, elem);
  images->boutonNiveau20Off = genererBoutonMenu(NIVEAU, OFF, 20, elem);
  images->boutonNiveau21Off = genererBoutonMenu(NIVEAU, OFF, 21, elem);
  images->boutonNiveau22Off = genererBoutonMenu(NIVEAU, OFF, 22, elem);
  images->boutonNiveau23Off = genererBoutonMenu(NIVEAU, OFF, 23, elem);
  images->boutonNiveau24Off = genererBoutonMenu(NIVEAU, OFF, 24, elem);
  images->boutonNiveau25Off = genererBoutonMenu(NIVEAU, OFF, 25, elem);
  images->boutonNiveau26Off = genererBoutonMenu(NIVEAU, OFF, 26, elem);
  images->boutonNiveau27Off = genererBoutonMenu(NIVEAU, OFF, 27, elem);
  images->boutonNiveau28Off = genererBoutonMenu(NIVEAU, OFF, 28, elem);
  images->boutonNiveau29Off = genererBoutonMenu(NIVEAU, OFF, 29, elem);
  images->boutonNiveau30Off = genererBoutonMenu(NIVEAU, OFF, 30, elem);
  images->boutonNiveau1On = genererBoutonMenu(NIVEAU, ON, 1, elem);
  images->boutonNiveau2On = genererBoutonMenu(NIVEAU, ON, 2, elem);
  images->boutonNiveau3On = genererBoutonMenu(NIVEAU, ON, 3, elem);
  images->boutonNiveau4On = genererBoutonMenu(NIVEAU, ON, 4, elem);
  images->boutonNiveau5On = genererBoutonMenu(NIVEAU, ON, 5, elem);
  images->boutonNiveau6On = genererBoutonMenu(NIVEAU, ON, 6, elem);
  images->boutonNiveau7On = genererBoutonMenu(NIVEAU, ON, 7, elem);
  images->boutonNiveau8On = genererBoutonMenu(NIVEAU, ON, 8, elem);
  images->boutonNiveau9On = genererBoutonMenu(NIVEAU, ON, 9, elem);
  images->boutonNiveau10On = genererBoutonMenu(NIVEAU, ON, 10, elem);
  images->boutonNiveau11On = genererBoutonMenu(NIVEAU, ON, 11, elem);
  images->boutonNiveau12On = genererBoutonMenu(NIVEAU, ON, 12, elem);
  images->boutonNiveau13On = genererBoutonMenu(NIVEAU, ON, 13, elem);
  images->boutonNiveau14On = genererBoutonMenu(NIVEAU, ON, 14, elem);
  images->boutonNiveau15On = genererBoutonMenu(NIVEAU, ON, 15, elem);
  images->boutonNiveau16On = genererBoutonMenu(NIVEAU, ON, 16, elem);
  images->boutonNiveau17On = genererBoutonMenu(NIVEAU, ON, 17, elem);
  images->boutonNiveau18On = genererBoutonMenu(NIVEAU, ON, 18, elem);
  images->boutonNiveau19On = genererBoutonMenu(NIVEAU, ON, 19, elem);
  images->boutonNiveau20On = genererBoutonMenu(NIVEAU, ON, 20, elem);
  images->boutonNiveau21On = genererBoutonMenu(NIVEAU, ON, 21, elem);
  images->boutonNiveau22On = genererBoutonMenu(NIVEAU, ON, 22, elem);
  images->boutonNiveau23On = genererBoutonMenu(NIVEAU, ON, 23, elem);
  images->boutonNiveau24On = genererBoutonMenu(NIVEAU, ON, 24, elem);
  images->boutonNiveau25On = genererBoutonMenu(NIVEAU, ON, 25, elem);
  images->boutonNiveau26On = genererBoutonMenu(NIVEAU, ON, 26, elem);
  images->boutonNiveau27On = genererBoutonMenu(NIVEAU, ON, 27, elem);
  images->boutonNiveau28On = genererBoutonMenu(NIVEAU, ON, 28, elem);
  images->boutonNiveau29On = genererBoutonMenu(NIVEAU, ON, 29, elem);
  images->boutonNiveau30On = genererBoutonMenu(NIVEAU, ON, 30, elem);

  images->fondMenuAide = genererFondMenuAide(elem, NULL);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectOk);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectOk);

  return images; //on renvoit le pack d'images
}

ALLEGRO_BITMAP *genererFondMenu(elementsFondMenu *elem)
{
  //on crée une image aux dimensions de l'écran dans laquelle on va dessiner le menu Principal
  ALLEGRO_BITMAP *fondMenu = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondMenu); //on cible l'image crée pour le dessin
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  al_clear_to_color(bleuFond); //on met un fond bleu très très clair

  //on dessine des lignes en diagonale de px de large sur le fond (CA FAIT JOLI gnééééééé)
  ALLEGRO_COLOR bleuLignes = al_map_rgb(190, 208, 232); //on crée une nuance de bleu
  int x = 0, x2 = 4, y = 8, y2 = 0;
  for(y; y <= SCREEN_H; y+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x2+=4;
  }
  for(x2; x2 <= SCREEN_W; x2+=4)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }
  for(y2; y2 <= SCREEN_H; y2+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuInactif = al_map_rgb(137, 154, 192); //couleur de la partie inactive de la fenêtre

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPrincipal;
  //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectJouer;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectNiveau;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectMode;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectScores;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectAide;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectPieceSuiv;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuInactif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuInactif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuInactif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuInactif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectNSL;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuInactif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuInactif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuInactif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuInactif); //barre horizontale basse
  //barre horizontales milieu
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + 48, rect->x2 - rect->t, rect->y + (rect->t * 2) + 48, bleuInactif); //première
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - 48, rect->x2 - rect->t,  rect->y2 - rect->t - 48, bleuInactif); //deuxième
  //fonds
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + 48, bleuFond); //niveau
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + 48, rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - 48, bleuFond); //score
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - 48, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

  //maintenant on va écrire dans les cases du rectNSL
  al_init_font_addon(); //on initie l'addon de police de caractères
  al_init_ttf_addon(); //on initie l'addon "ttf"

  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y + rect->t + 9, 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
  al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y + (rect->t * 2) + 48 + 9, 0, "SCORE"); //affiche le mot "score" dans la case correspondante
  al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y2 - rect->t - 48 + 9, 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

  //on libère la mémoire
  al_destroy_font(font);

  return fondMenu; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererHigh(int modeDeJeu, elementsFondMenu *elem)
{
  //on crée une image aux dimensions du panneau de score
  ALLEGRO_BITMAP *panneau = al_create_bitmap(elem->rectScores->w - (elem->rectScores->t * 2), elem->rectScores->h - (elem->rectScores->t * 2));
  al_set_target_bitmap(panneau); //on cible l'image créée pour le dessin
  al_clear_to_color(al_map_rgb(219, 237, 255)); //on remplit le fond de blanc

  //puis dans le rectangle du high score
  ALLEGRO_COLOR ligneFoncee = al_map_rgb(186, 201, 228);
  ALLEGRO_COLOR ligneClaire = al_map_rgb(198, 214, 237);
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 20, 0);
  //string dans lesquels on va recueillir les scores
  char J[5][4]; //va stocker le nom des joueurs
  char S[5][7]; //va stocker les scores, les temps ou les lignes

  switch(modeDeJeu)
  {
    case MARATHON:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, 9, ALLEGRO_ALIGN_CENTRE, "HIGH SCORES");
      lireFichierScore(J, S); //on récupère les valeurs du high score
      //on va remplacer le premier caractère '*' par un '\0' pour qu'ils ne s'affichent pas
      for(int i = 0; i < 5; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          if(J[i][j] == '*')
          {
            J[i][j] = '\0';
            j = 3;
          }
        }
      }
      //on dessine les lignes dans lesquelles on va écrire les scores
      font = al_load_ttf_font("Gameplay.ttf", 17, 0);
      al_draw_filled_rectangle(3, 44, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + 30, ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + 4, ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 4, ALLEGRO_ALIGN_RIGHT, S[0]);
      al_draw_filled_rectangle(3, 44 + 30 + 2, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (2 * 30) + 2, ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_RIGHT, S[1]);
      al_draw_filled_rectangle(3, 44 + (2 * 30) + (2 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (3 * 30) + (2 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[2]);
      al_draw_filled_rectangle(3, 44 + (3 * 30) + (3 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (4 * 30) + (3 * 2), ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[3]);
      al_draw_filled_rectangle(3, 44 + (4 * 30) + (4 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (5 * 30) + (4 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[4]);
      break;
    case SPRINT:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, 9, ALLEGRO_ALIGN_CENTRE, "BEST TIMES");
      char strTime[5][9];
      lireFichierTemps(J, S); //on récupère les valeurs du high score
      //on va remplacer le premier caractère '*' par un '\0' pour qu'ils ne s'affichent pas
      for(int i = 0; i < 5; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          if(J[i][j] == '*')
          {
            J[i][j] = '\0';
            j = 3;
          }
        }
      }
      for(int i = 0; i < 5; i++)
      {
        int minutes = (atoi(S[i])/3600), secondes = ((atoi(S[i]) % 3600)/60), dixiemes = ((atoi(S[i]) % 60)/6);

        if(secondes < 1 && minutes == 0) //si le temps fait moins d'une seconde (LOL, bonne chance)
        {
          sprintf(strTime[i], "00:00:%d0", dixiemes); //on affiche les dixième de seconde
        }
        else if(secondes > 0 && secondes < 10 && minutes == 0) //on est entre 0 et 10 secondes
        {
          sprintf(strTime[i], "00:0%d:%d0", secondes, dixiemes);
        }
        else if(secondes > 9 && secondes < 60 && minutes == 0) //si on est deça de la minute
        {
          sprintf(strTime[i], "%d:%d0", secondes, dixiemes);
        }
        else if(minutes > 0 && minutes < 10) //si on est au-dessus de la minute
        {
          if(secondes < 10) //si le nombre de secondes est inférieur à 10
          {
            sprintf(strTime[i], "0%d:0%d:%d0", minutes, secondes, dixiemes);
          }
          else
          {
            sprintf(strTime[i], "0%d:%d:%d0", minutes, secondes, dixiemes);
          }
        }
        else if(minutes > 10) //si on est au-dessus de la minute
        {
          if(secondes < 10) //si le nombre de secondes est inférieur à 10
          {
            sprintf(strTime[i], "%d:0%d:%d0", minutes, secondes, dixiemes);
          }
          else
          {
            sprintf(strTime[i], "%d:%d:%d0", minutes, secondes, dixiemes);
          }
        }
      }
      //on dessine les lignes dans lesquelles on va écrire les scores
      font = al_load_ttf_font("Gameplay.ttf", 17, 0);
      al_draw_filled_rectangle(3, 44, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + 30, ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + 4, ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 4, ALLEGRO_ALIGN_RIGHT, strTime[0]);
      al_draw_filled_rectangle(3, 44 + 30 + 2, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (2 * 30) + 2, ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_RIGHT, strTime[1]);
      al_draw_filled_rectangle(3, 44 + (2 * 30) + (2 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (3 * 30) + (2 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_RIGHT, strTime[2]);
      al_draw_filled_rectangle(3, 44 + (3 * 30) + (3 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (4 * 30) + (3 * 2), ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_RIGHT, strTime[3]);
      al_draw_filled_rectangle(3, 44 + (4 * 30) + (4 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (5 * 30) + (4 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_RIGHT, strTime[4]);
      break;
    case ULTRA:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, 9, ALLEGRO_ALIGN_CENTRE, "BEST LINES");
      lireFichierLignes(J, S); //on récupère les valeurs du high score
      //on va remplacer le premier caractère '*' par un '\0' pour qu'ils ne s'affichent pas
      for(int i = 0; i < 5; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          if(J[i][j] == '*')
          {
            J[i][j] = '\0';
            j = 3;
          }
        }
      }
      //on dessine les lignes dans lesquelles on va écrire les scores
      font = al_load_ttf_font("Gameplay.ttf", 17, 0);
      al_draw_filled_rectangle(3, 44, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + 30, ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + 4, ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 4, ALLEGRO_ALIGN_RIGHT, S[0]);
      al_draw_filled_rectangle(3, 44 + 30 + 2, (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (2 * 30) + 2, ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + 30 + 2 + 4, ALLEGRO_ALIGN_RIGHT, S[1]);
      al_draw_filled_rectangle(3, 44 + (2 * 30) + (2 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (3 * 30) + (2 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (2 * 30) + (2 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[2]);
      al_draw_filled_rectangle(3, 44 + (3 * 30) + (3 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (4 * 30) + (3 * 2), ligneClaire);
      al_draw_text(font, bleuActif, 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (3 * 30) + (3 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[3]);
      al_draw_filled_rectangle(3, 44 + (4 * 30) + (4 * 2), (elem->rectScores->w - (elem->rectScores->t * 2)) - 3, 44 + (5 * 30) + (4 * 2), ligneFoncee);
      al_draw_text(font, bleuActif, 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - 8, 44 + (4 * 30) + (4 * 2) + 4, ALLEGRO_ALIGN_RIGHT, S[4]);
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  return panneau;
}

elementsFondMenu *genererElementsFondMenu()
{
  elementsFondMenu *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectJouer = malloc(sizeof(coord));
  elem->rectNiveau = malloc(sizeof(coord));
  elem->rectMode = malloc(sizeof(coord));
  elem->rectScores = malloc(sizeof(coord));
  elem->rectAide = malloc(sizeof(coord));
  elem->rectOptions = malloc(sizeof(coord));
  elem->rectPieceSuiv = malloc(sizeof(coord));
  elem->rectNSL = malloc(sizeof(coord));
  elem->rectMenuAide = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  int epaisseur = 6; //étant donné que l'épaisseur est la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 78; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 13; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 373; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 588; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectJouer
  elem->rectJouer->x = 111; //coordonnée x du point d'origine
  elem->rectJouer->y = 37; //coordonnée y du point d'origine
  elem->rectJouer->x2 = 341; //coordonnée x du point de fin
  elem->rectJouer->y2 = 127; //coordonnée y du point de fin
  elem->rectJouer->w = elem->rectJouer->x2 - elem->rectJouer->x; //largeur
  elem->rectJouer->h = elem->rectJouer->y2 - elem->rectJouer->y; //hauteur
  elem->rectJouer->t = epaisseur; //épaisseur des traits

  //rectMode
  elem->rectMode->x = 126; //coordonnée x du point d'origine
  elem->rectMode->y = 137; //coordonnée y du point d'origine
  elem->rectMode->x2 = 326; //coordonnée x du point de fin
  elem->rectMode->y2 = 197; //coordonnée y du point de fin
  elem->rectMode->w = elem->rectMode->x2 - elem->rectMode->x; //largeur
  elem->rectMode->h = elem->rectMode->y2 - elem->rectMode->y; //hauteur
  elem->rectMode->t = epaisseur; //épaisseur des traits

  //rectNiveau
  elem->rectNiveau->x = 126; //coordonnée x du point d'origine
  elem->rectNiveau->y = 207; //coordonnée y du point d'origine
  elem->rectNiveau->x2 = 326; //coordonnée x du point de fin
  elem->rectNiveau->y2 = 267; //coordonnée y du point de fin
  elem->rectNiveau->w = elem->rectNiveau->x2 - elem->rectNiveau->x; //largeur
  elem->rectNiveau->h = elem->rectNiveau->y2 - elem->rectNiveau->y; //hauteur
  elem->rectNiveau->t = epaisseur; //épaisseur des traits

  //rectScores
  elem->rectScores->x = 126; //coordonnée x du point d'origine
  elem->rectScores->y = 277; //coordonnée y du point d'origine
  elem->rectScores->x2 = 326; //coordonnée x du point de fin
  elem->rectScores->y2 = 493; //coordonnée y du point de fin
  elem->rectScores->w = elem->rectScores->x2 - elem->rectScores->x; //largeur
  elem->rectScores->h = elem->rectScores->y2 - elem->rectScores->y; //hauteur
  elem->rectScores->t = epaisseur; //épaisseur des traits

  //rectAide
  elem->rectAide->x = 126; //coordonnée x du point d'origine
  elem->rectAide->y = 503; //coordonnée y du point d'origine
  elem->rectAide->x2 = 221; //coordonnée x du point de fin
  elem->rectAide->y2 = 563; //coordonnée y du point de fin
  elem->rectAide->w = elem->rectAide->x2 - elem->rectAide->x; //largeur
  elem->rectAide->h = elem->rectAide->y2 - elem->rectAide->y; //hauteur
  elem->rectAide->t = epaisseur; //épaisseur des traits

  //rectOptions
  elem->rectOptions->x = 231; //coordonnée x du point d'origine
  elem->rectOptions->y = 503; //coordonnée y du point d'origine
  elem->rectOptions->x2 = 326; //coordonnée x du point de fin
  elem->rectOptions->y2 = 563; //coordonnée y du point de fin
  elem->rectOptions->w = elem->rectOptions->x2 - elem->rectOptions->x; //largeur
  elem->rectOptions->h = elem->rectOptions->y2 - elem->rectOptions->y; //hauteur
  elem->rectOptions->t = epaisseur; //épaisseur des traits

  //rectPieceSuiv
  elem->rectPieceSuiv->x = 382; //coordonnée x du point d'origine
  elem->rectPieceSuiv->y = 13; //coordonnée y du point d'origine
  elem->rectPieceSuiv->x2 = 649; //coordonnée x du point de fin
  elem->rectPieceSuiv->y2 = 131; //coordonnée y du point de fin
  elem->rectPieceSuiv->w = elem->rectPieceSuiv->x2 - elem->rectPieceSuiv->x; //largeur
  elem->rectPieceSuiv->h = elem->rectPieceSuiv->y2 - elem->rectPieceSuiv->y; //hauteur
  elem->rectPieceSuiv->t = epaisseur; //épaisseur des traits

  //rectNSL
  elem->rectNSL->x = 382; //coordonnée x du point d'origine
  elem->rectNSL->y = 139; //coordonnée y du point d'origine
  elem->rectNSL->x2 = 649; //coordonnée x du point de fin
  elem->rectNSL->y2 = 307; //coordonnée y du point de fin
  elem->rectNSL->w = elem->rectNSL->x2 - elem->rectNSL->x; //largeur
  elem->rectNSL->h = elem->rectNSL->y2 - elem->rectNSL->y; //hauteur
  elem->rectNSL->t = epaisseur; //épaisseur des traits

  //rectMenuAide
  elem->rectMenuAide->x = 104; //coordonnée x du point d'origine
  elem->rectMenuAide->y = 53; //coordonnée y du point d'origine
  elem->rectMenuAide->x2 = 347; //coordonnée x du point de fin
  elem->rectMenuAide->y2 = 548; //coordonnée y du point de fin
  elem->rectMenuAide->w = elem->rectMenuAide->x2 - elem->rectMenuAide->x; //largeur
  elem->rectMenuAide->h = elem->rectMenuAide->y2 - elem->rectMenuAide->y; //hauteur
  elem->rectMenuAide->t = epaisseur; //épaisseur des traits

  //rectOk
  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 475; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 525; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = epaisseur; //épaisseur des traits

  return elem; //on renvoit le pack de "coord"
}

ALLEGRO_BITMAP *genererBoutonMenu(int typeDeBouton, int onOff, int niveau, elementsFondMenu *elem)
{
  //on crée un pointeur vers l'image qu'on va renvoyer
  ALLEGRO_BITMAP *bouton = NULL;

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  //on établie la couleur de fond du bouton en fonction de onOff
  ALLEGRO_COLOR couleurDeFond = al_map_rgb(219, 237, 255); //bleu très très clair
  if(onOff == ON)
  {
    couleurDeFond = al_map_rgb(162, 195, 232); //bleu clair
  }

  //on détermine quel type de bouton on génère
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);
  switch(typeDeBouton)
  {
    case JOUER:
      rect = elem->rectJouer;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 45, 0); //on charge la police "Gameplay"
      //on écrit le mot "jouer" en noir au milieu de l'image
      al_draw_text(font, al_map_rgb(0, 0, 0), ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-28, ALLEGRO_ALIGN_CENTRE, "JOUER");
      break;
    case MARATHON:
      rect = elem->rectMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "MARATHON" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "MARATHON");
      break;
    case SPRINT:
      rect = elem->rectMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "SPRINT" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "SPRINT");
      break;
    case ULTRA:
      rect = elem->rectMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "ULTRA" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "ULTRA");
      break;
    case AIDE:
      rect = elem->rectAide;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "?");
      break;
    case OPTIONS:
      rect = elem->rectOptions;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      //on établie l'image à charger dans le bouton en fonction de onOff
      ALLEGRO_BITMAP *options = NULL;
      if(onOff == ON)
      {
        options = al_load_bitmap("optionsOn.png");
      }
      else if(onOff == OFF)
      {
        options = al_load_bitmap("optionsOff.png");
      }
      al_draw_bitmap(options, (((rect->w - (rect->t * 2))/2) - (al_get_bitmap_width(options)/2)), (((rect->h - (rect->t * 2))/2) - (al_get_bitmap_height(options)/2)), 0);
      al_destroy_bitmap(options);
      break;
    case NIVEAU:
      rect = elem->rectNiveau;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      char stringNiveau[9] = "niveau 0";
      switch(niveau)
      {
      case 1:
        stringNiveau[7] = '1';
        break;
      case 2:
        stringNiveau[7] = '2';
        break;
      case 3:
        stringNiveau[7] = '3';
        break;
      case 4:
        stringNiveau[7] = '4';
        break;
      case 5:
        stringNiveau[7] = '5';
        break;
      case 6:
        stringNiveau[7] = '6';
        break;
      case 7:
        stringNiveau[7] = '7';
        break;
      case 8:
        stringNiveau[7] = '8';
        break;
      case 9:
        stringNiveau[7] = '9';
        break;
      case 10:
        stringNiveau[7] = '1';
        stringNiveau[8] = '0';
        break;
      case 11:
        stringNiveau[7] = '1';
        stringNiveau[8] = '1';
        break;
      case 12:
        stringNiveau[7] = '1';
        stringNiveau[8] = '2';
        break;
      case 13:
        stringNiveau[7] = '1';
        stringNiveau[8] = '3';
        break;
      case 14:
        stringNiveau[7] = '1';
        stringNiveau[8] = '4';
        break;
      case 15:
        stringNiveau[7] = '1';
        stringNiveau[8] = '5';
        break;
      case 16:
        stringNiveau[7] = '1';
        stringNiveau[8] = '6';
        break;
      case 17:
        stringNiveau[7] = '1';
        stringNiveau[8] = '7';
        break;
      case 18:
        stringNiveau[7] = '1';
        stringNiveau[8] = '8';
        break;
      case 19:
        stringNiveau[7] = '1';
        stringNiveau[8] = '9';
        break;
      case 20:
        stringNiveau[7] = '2';
        stringNiveau[8] = '0';
        break;
      case 21:
        stringNiveau[7] = '2';
        stringNiveau[8] = '1';
        break;
      case 22:
        stringNiveau[7] = '2';
        stringNiveau[8] = '2';
        break;
      case 23:
        stringNiveau[7] = '2';
        stringNiveau[8] = '3';
        break;
      case 24:
        stringNiveau[7] = '2';
        stringNiveau[8] = '4';
        break;
      case 25:
        stringNiveau[7] = '2';
        stringNiveau[8] = '5';
        break;
      case 26:
        stringNiveau[7] = '2';
        stringNiveau[8] = '6';
        break;
      case 27:
        stringNiveau[7] = '2';
        stringNiveau[8] = '7';
        break;
      case 28:
        stringNiveau[7] = '2';
        stringNiveau[8] = '8';
        break;
      case 29:
        stringNiveau[7] = '2';
        stringNiveau[8] = '9';
        break;
      case 30:
        stringNiveau[7] = '3';
        stringNiveau[8] = '0';
        break;
      }
      //on écrit "niveau x" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, stringNiveau);
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

void destroyPackMenu(packMenu *images)
{
  //on efface de la mémoire toutes les images contenues dans le pack
  al_destroy_bitmap(images->fondMenu);
  al_destroy_bitmap(images->highScore);
  al_destroy_bitmap(images->highTemps);
  al_destroy_bitmap(images->highLines);
  al_destroy_bitmap(images->boutonJouerOff);
  al_destroy_bitmap(images->boutonMarathonOn);
  al_destroy_bitmap(images->boutonMarathonOff);
  al_destroy_bitmap(images->boutonSprintOn);
  al_destroy_bitmap(images->boutonSprintOff);
  al_destroy_bitmap(images->boutonUltraOn);
  al_destroy_bitmap(images->boutonUltraOff);
  al_destroy_bitmap(images->boutonJouerOn);
  al_destroy_bitmap(images->boutonAideOff);
  al_destroy_bitmap(images->boutonAideOn);
  al_destroy_bitmap(images->boutonOptionsOff);
  al_destroy_bitmap(images->boutonOptionsOn);
  al_destroy_bitmap(images->boutonNiveau1Off);
  al_destroy_bitmap(images->boutonNiveau2Off);
  al_destroy_bitmap(images->boutonNiveau3Off);
  al_destroy_bitmap(images->boutonNiveau4Off);
  al_destroy_bitmap(images->boutonNiveau5Off);
  al_destroy_bitmap(images->boutonNiveau6Off);
  al_destroy_bitmap(images->boutonNiveau7Off);
  al_destroy_bitmap(images->boutonNiveau8Off);
  al_destroy_bitmap(images->boutonNiveau9Off);
  al_destroy_bitmap(images->boutonNiveau10Off);
  al_destroy_bitmap(images->boutonNiveau11Off);
  al_destroy_bitmap(images->boutonNiveau12Off);
  al_destroy_bitmap(images->boutonNiveau13Off);
  al_destroy_bitmap(images->boutonNiveau14Off);
  al_destroy_bitmap(images->boutonNiveau15Off);
  al_destroy_bitmap(images->boutonNiveau16Off);
  al_destroy_bitmap(images->boutonNiveau17Off);
  al_destroy_bitmap(images->boutonNiveau18Off);
  al_destroy_bitmap(images->boutonNiveau19Off);
  al_destroy_bitmap(images->boutonNiveau20Off);
  al_destroy_bitmap(images->boutonNiveau21Off);
  al_destroy_bitmap(images->boutonNiveau22Off);
  al_destroy_bitmap(images->boutonNiveau23Off);
  al_destroy_bitmap(images->boutonNiveau24Off);
  al_destroy_bitmap(images->boutonNiveau25Off);
  al_destroy_bitmap(images->boutonNiveau26Off);
  al_destroy_bitmap(images->boutonNiveau27Off);
  al_destroy_bitmap(images->boutonNiveau28Off);
  al_destroy_bitmap(images->boutonNiveau29Off);
  al_destroy_bitmap(images->boutonNiveau30Off);
  al_destroy_bitmap(images->boutonNiveau1On);
  al_destroy_bitmap(images->boutonNiveau2On);
  al_destroy_bitmap(images->boutonNiveau3On);
  al_destroy_bitmap(images->boutonNiveau4On);
  al_destroy_bitmap(images->boutonNiveau5On);
  al_destroy_bitmap(images->boutonNiveau6On);
  al_destroy_bitmap(images->boutonNiveau7On);
  al_destroy_bitmap(images->boutonNiveau8On);
  al_destroy_bitmap(images->boutonNiveau9On);
  al_destroy_bitmap(images->boutonNiveau10On);
  al_destroy_bitmap(images->boutonNiveau11On);
  al_destroy_bitmap(images->boutonNiveau12On);
  al_destroy_bitmap(images->boutonNiveau13On);
  al_destroy_bitmap(images->boutonNiveau14On);
  al_destroy_bitmap(images->boutonNiveau15On);
  al_destroy_bitmap(images->boutonNiveau16On);
  al_destroy_bitmap(images->boutonNiveau17On);
  al_destroy_bitmap(images->boutonNiveau18On);
  al_destroy_bitmap(images->boutonNiveau19On);
  al_destroy_bitmap(images->boutonNiveau20On);
  al_destroy_bitmap(images->boutonNiveau21On);
  al_destroy_bitmap(images->boutonNiveau22On);
  al_destroy_bitmap(images->boutonNiveau23On);
  al_destroy_bitmap(images->boutonNiveau24On);
  al_destroy_bitmap(images->boutonNiveau25On);
  al_destroy_bitmap(images->boutonNiveau26On);
  al_destroy_bitmap(images->boutonNiveau27On);
  al_destroy_bitmap(images->boutonNiveau28On);
  al_destroy_bitmap(images->boutonNiveau29On);
  al_destroy_bitmap(images->boutonNiveau30On);
  al_destroy_bitmap(images->fondMenuAide);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);

  //on détruit le pack
  free(images);
}

void destroyElementsFondMenu(elementsFondMenu *elem)
{
  //on efface de la mémoire tous les éléments de la structure
  free(elem->rectPrincipal);
  free(elem->rectJouer);
  free(elem->rectNiveau);
  free(elem->rectMode);
  free(elem->rectScores);
  free(elem->rectAide);
  free(elem->rectOptions);
  free(elem->rectPieceSuiv);
  free(elem->rectNSL);
  free(elem->rectMenuAide);
  free(elem->rectOk);

  //on détruit la structure elle-même
  free(elem);
}

elementsFondPartie *genererElementsFondPartie()
{
  elementsFondPartie *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectPieceSuiv = malloc(sizeof(coord));
  elem->rectNSL = malloc(sizeof(coord));
  elem->rectTemps = malloc(sizeof(coord));
  elem->rectPause = malloc(sizeof(coord));
  elem->rectReprendre = malloc(sizeof(coord));
  elem->rectAide = malloc(sizeof(coord));
  elem->rectOptions = malloc(sizeof(coord));
  elem->rectQuitter = malloc(sizeof(coord));
  elem->rectMenuAide = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  int epaisseur = 6; //étant donné que l'épaisseur est la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 78; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 13; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 373; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 588; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectPieceSuiv
  elem->rectPieceSuiv->x = 382; //coordonnée x du point d'origine
  elem->rectPieceSuiv->y = 13; //coordonnée y du point d'origine
  elem->rectPieceSuiv->x2 = 649; //coordonnée x du point de fin
  elem->rectPieceSuiv->y2 = 131; //coordonnée y du point de fin
  elem->rectPieceSuiv->w = elem->rectPieceSuiv->x2 - elem->rectPieceSuiv->x; //largeur
  elem->rectPieceSuiv->h = elem->rectPieceSuiv->y2 - elem->rectPieceSuiv->y; //hauteur
  elem->rectPieceSuiv->t = epaisseur; //épaisseur des traits

  //rectNSL
  elem->rectNSL->x = 382; //coordonnée x du point d'origine
  elem->rectNSL->y = 139; //coordonnée y du point d'origine
  elem->rectNSL->x2 = 649; //coordonnée x du point de fin
  elem->rectNSL->y2 = 307; //coordonnée y du point de fin
  elem->rectNSL->w = elem->rectNSL->x2 - elem->rectNSL->x; //largeur
  elem->rectNSL->h = elem->rectNSL->y2 - elem->rectNSL->y; //hauteur
  elem->rectNSL->t = epaisseur; //épaisseur des traits

  //rectTemps
  elem->rectTemps->x = 382; //coordonnée x du point d'origine
  elem->rectTemps->y = 301; //coordonnée y du point d'origine
  elem->rectTemps->x2 = 649; //coordonnée x du point de fin
  elem->rectTemps->y2 = 361; //coordonnée y du point de fin
  elem->rectTemps->w = elem->rectTemps->x2 - elem->rectTemps->x; //largeur
  elem->rectTemps->h = elem->rectTemps->y2 - elem->rectTemps->y; //hauteur
  elem->rectTemps->t = epaisseur; //épaisseur des traits

  //rectPause
  elem->rectPause->x = 96; //coordonnée x du point d'origine
  elem->rectPause->y = 75; //coordonnée y du point d'origine
  elem->rectPause->x2 = 355; //coordonnée x du point de fin
  elem->rectPause->y2 = 526; //coordonnée y du point de fin
  elem->rectPause->w = elem->rectPause->x2 - elem->rectPause->x; //largeur
  elem->rectPause->h = elem->rectPause->y2 - elem->rectPause->y; //hauteur
  elem->rectPause->t = epaisseur; //épaisseur des traits

  //rectReprendre
  elem->rectReprendre->x = 106; //coordonnée x du point d'origine
  elem->rectReprendre->y = 181; //coordonnée y du point d'origine
  elem->rectReprendre->x2 = 345; //coordonnée x du point de fin
  elem->rectReprendre->y2 = 271; //coordonnée y du point de fin
  elem->rectReprendre->w = elem->rectReprendre->x2 - elem->rectReprendre->x; //largeur
  elem->rectReprendre->h = elem->rectReprendre->y2 - elem->rectReprendre->y; //hauteur
  elem->rectReprendre->t = epaisseur; //épaisseur des traits

  //rectAide
  elem->rectAide->x = 136; //coordonnée x du point d'origine
  elem->rectAide->y = 281; //coordonnée y du point d'origine
  elem->rectAide->x2 = 315; //coordonnée x du point de fin
  elem->rectAide->y2 = 351; //coordonnée y du point de fin
  elem->rectAide->w = elem->rectAide->x2 - elem->rectAide->x; //largeur
  elem->rectAide->h = elem->rectAide->y2 - elem->rectAide->y; //hauteur
  elem->rectAide->t = epaisseur; //épaisseur des traits

  //rectOptions
  elem->rectOptions->x = 136; //coordonnée x du point d'origine
  elem->rectOptions->y = 361; //coordonnée y du point d'origine
  elem->rectOptions->x2 = 315; //coordonnée x du point de fin
  elem->rectOptions->y2 = 431; //coordonnée y du point de fin
  elem->rectOptions->w = elem->rectOptions->x2 - elem->rectOptions->x; //largeur
  elem->rectOptions->h = elem->rectOptions->y2 - elem->rectOptions->y; //hauteur
  elem->rectOptions->t = epaisseur; //épaisseur des traits

  //rectQuitter
  elem->rectQuitter->x = 136; //coordonnée x du point d'origine
  elem->rectQuitter->y = 441; //coordonnée y du point d'origine
  elem->rectQuitter->x2 = 315; //coordonnée x du point de fin
  elem->rectQuitter->y2 = 511; //coordonnée y du point de fin
  elem->rectQuitter->w = elem->rectQuitter->x2 - elem->rectQuitter->x; //largeur
  elem->rectQuitter->h = elem->rectQuitter->y2 - elem->rectQuitter->y; //hauteur
  elem->rectQuitter->t = epaisseur; //épaisseur des traits

  //rectMenuAide
  elem->rectMenuAide->x = 104; //coordonnée x du point d'origine
  elem->rectMenuAide->y = 53; //coordonnée y du point d'origine
  elem->rectMenuAide->x2 = 347; //coordonnée x du point de fin
  elem->rectMenuAide->y2 = 548; //coordonnée y du point de fin
  elem->rectMenuAide->w = elem->rectMenuAide->x2 - elem->rectMenuAide->x; //largeur
  elem->rectMenuAide->h = elem->rectMenuAide->y2 - elem->rectMenuAide->y; //hauteur
  elem->rectMenuAide->t = epaisseur; //épaisseur des traits

  //rectOk
  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 475; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 525; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = epaisseur; //épaisseur des traits

  return elem; //on renvoit le pack de "coord"
}

void destroyElementsFondPartie(elementsFondPartie *elem)
{
  //on efface de la mémoire tous les éléments de la structure
  free(elem->rectPrincipal);
  free(elem->rectPieceSuiv);
  free(elem->rectNSL);
  free(elem->rectTemps);

  free(elem->rectPause);
  free(elem->rectReprendre);
  free(elem->rectAide);
  free(elem->rectOptions);
  free(elem->rectQuitter);

  free(elem->rectMenuAide);
  free(elem->rectOk);

  //on détruit la structure elle-même
  free(elem);
}

packPartie *genererPackPartie(elementsFondPartie *elem, int modeDeJeu)
{
  //on crée un pointeur vers la structure d'images
  packPartie *images = malloc(sizeof(packPartie));

  //puis on initie chacune des images
  images->fondPartie = genererFondPartie(elem, modeDeJeu);
  images->blocJaune = genererBloc(JAUNE);
  images->blocCyan = genererBloc(CYAN);
  images->blocMauve = genererBloc(MAUVE);
  images->blocViolet = genererBloc(VIOLET);
  images->blocOrange = genererBloc(ORANGE);
  images->blocVert = genererBloc(VERT);
  images->blocRouge = genererBloc(ROUGE);
  images->blocBlanc = genererBloc(BLANC);

  images->barreGrilleVerticale = al_create_bitmap(3, 28);
  al_set_target_bitmap(images->barreGrilleVerticale);
  al_clear_to_color(al_map_rgb(0, 0, 0));

  images->barreGrilleHorizontale = al_create_bitmap(28, 3);
  al_set_target_bitmap(images->barreGrilleHorizontale);
  al_clear_to_color(al_map_rgb(0, 0, 0));

  //on crée un pointeur vers la structure packPause
  packPause *imagesPause = malloc(sizeof(packPause));
  images->imagesPause = imagesPause;

  //puis on génère les images du menu pause
  images->imagesPause->fondPause = genererFondPause(elem, images->fondPartie);
  images->imagesPause->boutonReprendreOff = genererBoutonPause(REPRENDRE, OFF, elem);
  images->imagesPause->boutonReprendreOn = genererBoutonPause(REPRENDRE, ON, elem);
  images->imagesPause->boutonAideOff = genererBoutonPause(AIDE, OFF, elem);
  images->imagesPause->boutonAideOn = genererBoutonPause(AIDE, ON, elem);
  images->imagesPause->boutonOptionsOff = genererBoutonPause(OPTIONS, OFF, elem);
  images->imagesPause->boutonOptionsOn = genererBoutonPause(OPTIONS, ON, elem);
  images->imagesPause->boutonQuitterOff = genererBoutonPause(QUITTER, OFF, elem);
  images->imagesPause->boutonQuitterOn = genererBoutonPause(QUITTER, ON, elem);

  images->imagesPause->fondMenuAide = genererFondMenuAide(NULL, elem);
  images->imagesPause->boutonOkOff = genererBoutonOk(OFF, elem->rectOk);
  images->imagesPause->boutonOkOn = genererBoutonOk(ON, elem->rectOk);

  //on crée un pointeur vers la structure ghostPiece
  packGhost *ghostPiece = malloc(sizeof(packGhost));
  images->ghostPiece = ghostPiece;

  //puis on initie chacune des images
  images->ghostPiece->jauneo = genererGhostPiece(JAUNE_O, POS1, images);
  images->ghostPiece->cyaniPOS1 = genererGhostPiece(CYAN_I, POS1, images);
  images->ghostPiece->cyaniPOS2 = genererGhostPiece(CYAN_I, POS2, images);
  images->ghostPiece->cyaniPOS3 = genererGhostPiece(CYAN_I, POS3, images);
  images->ghostPiece->cyaniPOS4 = genererGhostPiece(CYAN_I, POS4, images);
  images->ghostPiece->rougezPOS1 = genererGhostPiece(ROUGE_Z, POS1, images);
  images->ghostPiece->rougezPOS2 = genererGhostPiece(ROUGE_Z, POS2, images);
  images->ghostPiece->rougezPOS3 = genererGhostPiece(ROUGE_Z, POS3, images);
  images->ghostPiece->rougezPOS4 = genererGhostPiece(ROUGE_Z, POS4, images);
  images->ghostPiece->vertsPOS1 = genererGhostPiece(VERT_S, POS1, images);
  images->ghostPiece->vertsPOS2 = genererGhostPiece(VERT_S, POS2, images);
  images->ghostPiece->vertsPOS3 = genererGhostPiece(VERT_S, POS3, images);
  images->ghostPiece->vertsPOS4 = genererGhostPiece(VERT_S, POS4, images);
  images->ghostPiece->mauvetPOS1 = genererGhostPiece(MAUVE_T, POS1, images);
  images->ghostPiece->mauvetPOS2 = genererGhostPiece(MAUVE_T, POS2, images);
  images->ghostPiece->mauvetPOS3 = genererGhostPiece(MAUVE_T, POS3, images);
  images->ghostPiece->mauvetPOS4 = genererGhostPiece(MAUVE_T, POS4, images);
  images->ghostPiece->orangelPOS1 = genererGhostPiece(ORANGE_L, POS1, images);
  images->ghostPiece->orangelPOS2 = genererGhostPiece(ORANGE_L, POS2, images);
  images->ghostPiece->orangelPOS3 = genererGhostPiece(ORANGE_L, POS3, images);
  images->ghostPiece->orangelPOS4 = genererGhostPiece(ORANGE_L, POS4, images);
  images->ghostPiece->violetjPOS1 = genererGhostPiece(VIOLET_J, POS1, images);
  images->ghostPiece->violetjPOS2 = genererGhostPiece(VIOLET_J, POS2, images);
  images->ghostPiece->violetjPOS3 = genererGhostPiece(VIOLET_J, POS3, images);
  images->ghostPiece->violetjPOS4 = genererGhostPiece(VIOLET_J, POS4, images);

  return images; //on renvoit le pack d'images
}

void destroyPackPartie(packPartie *images)
{
  //on détruit chacune des images
  al_destroy_bitmap(images->fondPartie);
  al_destroy_bitmap(images->blocJaune);
  al_destroy_bitmap(images->blocCyan);
  al_destroy_bitmap(images->blocMauve);
  al_destroy_bitmap(images->blocViolet);
  al_destroy_bitmap(images->blocOrange);
  al_destroy_bitmap(images->blocVert);
  al_destroy_bitmap(images->blocRouge);
  al_destroy_bitmap(images->blocBlanc);
  al_destroy_bitmap(images->barreGrilleVerticale);
  al_destroy_bitmap(images->barreGrilleHorizontale);

  al_destroy_bitmap(images->ghostPiece->jauneo);
  al_destroy_bitmap(images->ghostPiece->cyaniPOS1);
  al_destroy_bitmap(images->ghostPiece->cyaniPOS2);
  al_destroy_bitmap(images->ghostPiece->cyaniPOS3);
  al_destroy_bitmap(images->ghostPiece->cyaniPOS4);
  al_destroy_bitmap(images->ghostPiece->rougezPOS1);
  al_destroy_bitmap(images->ghostPiece->rougezPOS2);
  al_destroy_bitmap(images->ghostPiece->rougezPOS3);
  al_destroy_bitmap(images->ghostPiece->rougezPOS4);
  al_destroy_bitmap(images->ghostPiece->vertsPOS1);
  al_destroy_bitmap(images->ghostPiece->vertsPOS2);
  al_destroy_bitmap(images->ghostPiece->vertsPOS3);
  al_destroy_bitmap(images->ghostPiece->vertsPOS4);
  al_destroy_bitmap(images->ghostPiece->mauvetPOS1);
  al_destroy_bitmap(images->ghostPiece->mauvetPOS2);
  al_destroy_bitmap(images->ghostPiece->mauvetPOS3);
  al_destroy_bitmap(images->ghostPiece->mauvetPOS4);
  al_destroy_bitmap(images->ghostPiece->orangelPOS1);
  al_destroy_bitmap(images->ghostPiece->orangelPOS2);
  al_destroy_bitmap(images->ghostPiece->orangelPOS3);
  al_destroy_bitmap(images->ghostPiece->orangelPOS4);
  al_destroy_bitmap(images->ghostPiece->violetjPOS1);
  al_destroy_bitmap(images->ghostPiece->violetjPOS2);
  al_destroy_bitmap(images->ghostPiece->violetjPOS3);
  al_destroy_bitmap(images->ghostPiece->violetjPOS4);

  al_destroy_bitmap(images->imagesPause->fondPause);
  al_destroy_bitmap(images->imagesPause->boutonReprendreOff);
  al_destroy_bitmap(images->imagesPause->boutonReprendreOn);
  al_destroy_bitmap(images->imagesPause->boutonAideOff);
  al_destroy_bitmap(images->imagesPause->boutonAideOn);
  al_destroy_bitmap(images->imagesPause->boutonOptionsOff);
  al_destroy_bitmap(images->imagesPause->boutonOptionsOn);
  al_destroy_bitmap(images->imagesPause->boutonQuitterOff);
  al_destroy_bitmap(images->imagesPause->boutonQuitterOn);

  //on détruit les structures
  free(images->imagesPause);
  free(images->ghostPiece);
  free(images);
}

ALLEGRO_BITMAP *genererFondPartie(elementsFondPartie *elem, int modeDeJeu)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner la partie
  ALLEGRO_BITMAP *fondPartie = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondPartie); //on cible l'image crée pour le dessin
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  al_clear_to_color(bleuFond); //on met un fond bleu très très clair

  //on dessine des lignes en diagonale de px de large sur le fond (CA FAIT JOLI gnééééééé)
  ALLEGRO_COLOR bleuLignes = al_map_rgb(190, 208, 232); //on crée une nuance de bleu
  int x = 0, x2 = 4, y = 8, y2 = 0;
  for(y; y <= SCREEN_H; y+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x2+=4;
  }
  for(x2; x2 <= SCREEN_W; x2+=4)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }
  for(y2; y2 <= SCREEN_H; y2+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuInactif = al_map_rgb(137, 154, 192); //couleur de la partie inactive de la fenêtre

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  //on dessine un rectangle en x=98, y=41 et x2=393, y2=560, donc de w=295, h=519 qui sera la grille de jeu  (6px d'épaisseur)
  rect = elem->rectPrincipal;
  //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //on dessine un second rectangle en x=402, y=41, et x2=629, y2=159, donc de w=227, h=118 pour afficher la prochaine pièce (6px d'épaisseur)
  rect = elem->rectPieceSuiv;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  //on dessine un troisième rectangle en x=402, y=167, et x2=629, y2=335, donc de w=227, h=168 (6px d'épaisseur)
  //il va servir à afficher le niveau, le score et les lignes
  rect = elem->rectNSL;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //barre horizontales milieu
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + 48, rect->x2 - rect->t, rect->y + (rect->t * 2) + 48, bleuActif); //première
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - 48, rect->x2 - rect->t,  rect->y2 - rect->t - 48, bleuActif); //deuxième
  //fonds
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + 48, bleuFond); //niveau
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + 48, rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - 48, bleuFond); //score
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - 48, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

  //maintenant on va écrire dans les cases du septième rectangle qu'on a créé
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y + rect->t + 9, 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
  al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y + (rect->t * 2) + 48 + 9, 0, "SCORE"); //affiche le mot "score" dans la case correspondante
  al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y2 - rect->t - 48 + 9, 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

  if(modeDeJeu == SPRINT || modeDeJeu == ULTRA)
  {
    //on dessine le carde du Timer
    rect = elem->rectTemps;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);
    al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y + rect->t + 9, 0, "TIMER"); //affiche le mot "TIMER" dans la case correspondante
  }

  //on libère la mémoire
  al_destroy_font(font);

  return fondPartie; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererFondPause(elementsFondPartie *elem, ALLEGRO_BITMAP *fondPartie)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner la pause
  ALLEGRO_BITMAP *fondPause = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondPause); //on cible l'image crée pour le dessin
  al_draw_bitmap(fondPartie, 0, 0, 0); //on dessine le fond de la partie

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPause;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectReprendre;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectAide;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectQuitter;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maintenant on va écrire "Pause" dans le rectPause
  rect = elem->rectPause;
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 45, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 28, ALLEGRO_ALIGN_CENTRE, "PAUSE");

  //on libère la mémoire
  al_destroy_font(font);

  return fondPause; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererBoutonPause(int typeDeBouton, int onOff, elementsFondPartie *elem)
{
  //on crée un pointeur vers l'image qu'on va renvoyer
  ALLEGRO_BITMAP *bouton = NULL;

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  //on établie la couleur de fond du bouton en fonction de onOff
  ALLEGRO_COLOR couleurDeFond = al_map_rgb(219, 237, 255); //bleu très très clair
  if(onOff == ON)
  {
    couleurDeFond = al_map_rgb(162, 195, 232); //bleu clair
  }

  //on détermine quel type de bouton on génère
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);
  switch(typeDeBouton)
  {
    case REPRENDRE:
      rect = elem->rectReprendre;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "jouer" en noir au milieu de l'image
      al_draw_text(font, al_map_rgb(0, 0, 0), ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "REPRENDRE");
      break;
    case AIDE:
      rect = elem->rectAide;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "AIDE");
      break;
    case OPTIONS:
      rect = elem->rectOptions;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "OPTIONS");
      break;
    case QUITTER:
      rect = elem->rectQuitter;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-20, ALLEGRO_ALIGN_CENTRE, "QUITTER");
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

ALLEGRO_BITMAP *genererBloc(int typeDeBloc)
{
  ALLEGRO_BITMAP *bloc = al_create_bitmap(BLOC_SIZE, BLOC_SIZE); //on crée un pointeur vers l'image

  ALLEGRO_COLOR couleurPrincipale;
  ALLEGRO_COLOR couleurFoncee;
  ALLEGRO_COLOR couleurClaire;

  //on détermine la couleur du bloc qu'on veut créer
  switch(typeDeBloc)
  {
    case JAUNE:
      couleurPrincipale = al_map_rgb(234, 251, 0);
      couleurFoncee = al_map_rgb(176, 190, 0);
      couleurClaire = al_map_rgb(246, 255, 50);
      break;
    case CYAN:
      couleurPrincipale = al_map_rgb(0, 193, 249);
      couleurFoncee = al_map_rgb(0, 144, 188);
      couleurClaire = al_map_rgb(66, 234, 255);
      break;
    case MAUVE:
      couleurPrincipale = al_map_rgb(232, 0, 247);
      couleurFoncee = al_map_rgb(176, 0, 188);
      couleurClaire = al_map_rgb(255, 0, 255);
      break;
    case VIOLET:
      couleurPrincipale = al_map_rgb(78, 0, 251);
      couleurFoncee = al_map_rgb(59, 0, 190);
      couleurClaire = al_map_rgb(118, 40, 255);
      break;
    case ORANGE:
      couleurPrincipale = al_map_rgb(255, 98, 0);
      couleurFoncee = al_map_rgb(207, 74, 0);
      couleurClaire = al_map_rgb(255, 144, 60);
      break;
    case VERT:
      couleurPrincipale = al_map_rgb(0, 255, 37);
      couleurFoncee = al_map_rgb(0, 199, 28);
      couleurClaire = al_map_rgb(0, 255, 84);
      break;
    case ROUGE:
      couleurPrincipale = al_map_rgb(255, 0, 0);
      couleurFoncee = al_map_rgb(211, 0, 0);
      couleurClaire = al_map_rgb(255, 42, 61);
      break;
    case BLANC:
      couleurPrincipale = al_map_rgb(255, 255, 255);
      couleurFoncee = al_map_rgb(255, 255, 255);
      couleurClaire = al_map_rgb(255, 255, 255);
      break;
  }

  //on dessine le bloc
  al_set_target_bitmap(bloc); //on cible le bloc
  al_draw_filled_rectangle(3, 3, 23, 22, couleurPrincipale); //on dessine le rectangle central
  al_draw_filled_rectangle(3, 0, 25, 3, couleurClaire); //barre claire horizontale
  al_draw_filled_rectangle(22, 3, 25, 22, couleurClaire); //barre claire verticale

  al_draw_filled_rectangle(0, 0, 3, 22, couleurFoncee); //barre foncée horizontale
  al_draw_filled_rectangle(0, 22, 25, 25, couleurFoncee); //barre foncée verticale

  al_draw_filled_triangle(0, 0, 3, 0, 3, 3, couleurClaire); //triangle clair gauche
  al_draw_filled_triangle(22, 22, 25, 22, 25, 25, couleurClaire); //triangle clair droit

  return bloc; //et on oublie pas de renvoyer le pointeur (gnééééééééééééé)
}

ALLEGRO_BITMAP *genererGhostPiece(int typeDeBloc, int position, packPartie *images)
{
  //on crée l'image
  ALLEGRO_BITMAP *ghost = al_create_bitmap(115, 115);
  al_set_target_bitmap(ghost); //on la cible
  al_clear_to_color(al_map_rgb(0, 0, 0)); //on met un fond noir

  //on génère un packTetro pour dessiner les ghost
  packTetro *tetros = chargerTetrominos();

  //on détermine le type de bloc à utiliesr pour le dessin
  ALLEGRO_BITMAP *bloc = NULL;
  int pos[2] = {0, 0};
  switch(typeDeBloc)
  {
    case JAUNE_O:
      bloc = images->blocJaune;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_jaune_O[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case CYAN_I:
      bloc = images->blocCyan;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_cyan_I[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case MAUVE_T:
      bloc = images->blocMauve;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_mauve_T[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case VIOLET_J:
      bloc = images->blocViolet;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_violet_J[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case ORANGE_L:
      bloc = images->blocOrange;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_orange_L[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case VERT_S:
      bloc = images->blocVert;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_vert_S[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
    case ROUGE_Z:
      bloc = images->blocRouge;
      //on dessine les blocs un à un dans l'image
      pos[Y] = 3;
      for(int y = 0; y < 4; y++)
      {
        pos[X] = 3;
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_rouge_Z[position][x][y] != VIDE)
            al_draw_bitmap(bloc, pos[X], pos[Y], 0);
          pos[X] += 28;
        }
        pos[Y] += 28;
      }
      break;
  }

  //on libère la mémoire
  destroyTetrominos(tetros);

  return ghost; //CETTE FOIS, ON A PAS OUBLIE, C'EST BIIIIIIIIIIIIEN
}

ALLEGRO_BITMAP *genererBoutonOk(int onOff, coord *rectOk)
{
  //on crée un pointeur vers l'image qu'on va renvoyer
  ALLEGRO_BITMAP *bouton = NULL;

  //on établie la couleur de fond du bouton en fonction de onOff
  ALLEGRO_COLOR couleurDeFond = al_map_rgb(219, 237, 255); //bleu très très clair
  if(onOff == ON)
  {
    couleurDeFond = al_map_rgb(162, 195, 232); //bleu clair
  }

  //on génère le bouton
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);

  //on crée la surface intérieure du bouton
  bouton = al_create_bitmap((rectOk->x2 - rectOk->x - (rectOk->t * 2)), (rectOk->y2 - rectOk->y - (rectOk->t * 2)));
  al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
  al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
  font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  //on écrit "OK" en bleu au milieu de l'image
  al_draw_text(font, bleuActif, ((rectOk->x2 - rectOk->x - (rectOk->t * 2))/2), ((rectOk->y2 - rectOk->y - (rectOk->t * 2))/2)-15, ALLEGRO_ALIGN_CENTRE, "OK");

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

ALLEGRO_BITMAP *genererFondMenuAide(elementsFondMenu *elemMenu, elementsFondPartie *elemPartie)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner le menu d'Aide
  ALLEGRO_BITMAP *fondAide = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondAide); //on cible l'image crée pour le dessin
  ALLEGRO_FONT *font = NULL; //pointeur dans lequel on va charger notre police d'écriture
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuInactif = al_map_rgb(137, 154, 192); //couleur de la partie inactive de la fenêtre


  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  al_clear_to_color(bleuFond); //on met un fond bleu très très clair

  //on dessine des lignes en diagonale de px de large sur le fond (CA FAIT JOLI gnééééééé)
  ALLEGRO_COLOR bleuLignes = al_map_rgb(190, 208, 232); //on crée une nuance de bleu
  int x = 0, x2 = 4, y = 8, y2 = 0;
  for(y; y <= SCREEN_H; y+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x2+=4;
  }
  for(x2; x2 <= SCREEN_W; x2+=4)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }
  for(y2; y2 <= SCREEN_H; y2+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  if(elemMenu != NULL)
  {
    rect = elemMenu->rectPrincipal;
    //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    rect = elemMenu->rectPieceSuiv;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuInactif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuInactif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuInactif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuInactif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

    rect = elemMenu->rectNSL;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuInactif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuInactif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuInactif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuInactif); //barre horizontale basse
    //barre horizontales milieu
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + 48, rect->x2 - rect->t, rect->y + (rect->t * 2) + 48, bleuInactif); //première
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - 48, rect->x2 - rect->t,  rect->y2 - rect->t - 48, bleuInactif); //deuxième
    //fonds
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + 48, bleuFond); //niveau
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + 48, rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - 48, bleuFond); //score
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - 48, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

    //maintenant on va écrire dans les cases du rectangle NSL
    font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y + rect->t + 9, 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
    al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y + (rect->t * 2) + 48 + 9, 0, "SCORE"); //affiche le mot "score" dans la case correspondante
    al_draw_text(font, bleuInactif, rect->x + rect->t + 10, rect->y2 - rect->t - 48 + 9, 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

    rect = elemMenu->rectMenuAide;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgb(219, 237, 255));

    rect = elemMenu->rectOk;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    //maitenant qu'on a fini de dessiner le fond, on écrit les commandes une à une
    //d'abord le titre du cadre
    rect = elemMenu->rectMenuAide;
    font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 15, ALLEGRO_ALIGN_CENTRE, "CONTROLES");

    //puis les commandes du jeu
    font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65, ALLEGRO_ALIGN_CENTRE, "FLECHE A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (1 * 20), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (2 * 20) + (1 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (3 * 20) + (1 * 10), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (4 * 20) + (2 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE HAUTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (5 * 20) + (2 * 10), ALLEGRO_ALIGN_CENTRE, "ROTATION DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (6 * 20) + (3 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE BASSE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (7 * 20) + (3 * 10), ALLEGRO_ALIGN_CENTRE, "SOFT DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (8 * 20) + (4 * 10), ALLEGRO_ALIGN_CENTRE, "CTRL - ROTATION GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (9 * 20) + (5 * 10), ALLEGRO_ALIGN_CENTRE, "ESPACE - HARD DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (10 * 20) + (6 * 10), ALLEGRO_ALIGN_CENTRE, "G - FONCTION GHOST");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (11 * 20) + (7 * 10), ALLEGRO_ALIGN_CENTRE, "MAJ - PIECE SUIVANTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (12 * 20) + (8 * 10), ALLEGRO_ALIGN_CENTRE, "P - PAUSE");
  }
  else //si on est dans la partie
  {
    rect = elemPartie->rectPrincipal;
    //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    rect = elemPartie->rectPieceSuiv;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

    rect = elemPartie->rectNSL;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //barre horizontales milieu
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + 48, rect->x2 - rect->t, rect->y + (rect->t * 2) + 48, bleuActif); //première
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - 48, rect->x2 - rect->t,  rect->y2 - rect->t - 48, bleuActif); //deuxième
    //fonds
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + 48, bleuFond); //niveau
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + 48, rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - 48, bleuFond); //score
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - 48, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

    //maintenant on va écrire dans les cases du rectangle NSL
    font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y + rect->t + 9, 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
    al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y + (rect->t * 2) + 48 + 9, 0, "SCORE"); //affiche le mot "score" dans la case correspondante
    al_draw_text(font, bleuActif, rect->x + rect->t + 10, rect->y2 - rect->t - 48 + 9, 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

    rect = elemPartie->rectMenuAide;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgb(219, 237, 255));

    rect = elemPartie->rectOk;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    //maitenant qu'on a fini de dessiner le fond, on écrit les commandes une à une
    //d'abord le titre du cadre
    rect = elemPartie->rectMenuAide;
    font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 15, ALLEGRO_ALIGN_CENTRE, "CONTROLES");

    //puis les commandes du jeu
    font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65, ALLEGRO_ALIGN_CENTRE, "FLECHE A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (1 * 20), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (2 * 20) + (1 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (3 * 20) + (1 * 10), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (4 * 20) + (2 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE HAUTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (5 * 20) + (2 * 10), ALLEGRO_ALIGN_CENTRE, "ROTATION DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (6 * 20) + (3 * 10), ALLEGRO_ALIGN_CENTRE, "FLECHE BASSE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (7 * 20) + (3 * 10), ALLEGRO_ALIGN_CENTRE, "SOFT DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (8 * 20) + (4 * 10), ALLEGRO_ALIGN_CENTRE, "CTRL - ROTATION GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (9 * 20) + (5 * 10), ALLEGRO_ALIGN_CENTRE, "ESPACE - HARD DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (10 * 20) + (6 * 10), ALLEGRO_ALIGN_CENTRE, "G - FONCTION GHOST");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (11 * 20) + (7 * 10), ALLEGRO_ALIGN_CENTRE, "MAJ - PIECE SUIVANTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 65 + (12 * 20) + (8 * 10), ALLEGRO_ALIGN_CENTRE, "P - PAUSE");
  }

  //on libère la mémoire
  al_destroy_font(font);

  return fondAide; //on renvoit l'image créée
}

elementsFondScoreInput *genererElementsFondScoreInput()
{
  elementsFondScoreInput *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectInput = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  int epaisseur = 6; //étant donné que l'épaisseur est la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 96; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 135; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 355; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 466; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectInput
  elem->rectInput->x = 141; //coordonnée x du point d'origine
  elem->rectInput->y = 315; //coordonnée y du point d'origine
  elem->rectInput->x2 = 310; //coordonnée x du point de fin
  elem->rectInput->y2 = 365; //coordonnée y du point de fin
  elem->rectInput->w = elem->rectInput->x2 - elem->rectInput->x; //largeur
  elem->rectInput->h = elem->rectInput->y2 - elem->rectInput->y; //hauteur
  elem->rectInput->t = epaisseur; //épaisseur des traits

  //rectOk
  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 385; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 435; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = epaisseur; //épaisseur des traits

  return elem; //on revoit la structure créée
}

void destroyElementsFondScoreInput(elementsFondScoreInput *elem)
{
  free(elem->rectPrincipal);
  free(elem->rectInput);
  free(elem->rectOk);
  free(elem);
}

packScoreInput *genererPackScoreInput(ALLEGRO_DISPLAY *fenetre, elementsFondScoreInput *elem, int score)
{
  packScoreInput *images = malloc(sizeof(packScoreInput));

  images->fond = genererFondScoreInput(fenetre, elem, score);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectOk);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectOk);

  return images; //on revoit la structure d'images
}

void destroyPackScoreInput(packScoreInput *images)
{
  al_destroy_bitmap(images->fond);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);
  free(images);
}

ALLEGRO_BITMAP *genererFondScoreInput(ALLEGRO_DISPLAY *fenetre, elementsFondScoreInput *elem, int score)
{
  ALLEGRO_BITMAP *fond = al_create_bitmap(SCREEN_W, SCREEN_H); //on crée l'image de fond
  al_set_target_bitmap(fond); //on cible l'image créée
  al_draw_bitmap(al_get_backbuffer(fenetre), 0, 0, 0); //on copie l'écran de fin de partie

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_COLOR fondInput = al_map_rgb(162, 195, 232); //fond de la zone d'input

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPrincipal;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectInput;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, fondInput);

  rect = elem->rectOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maitenant qu'on a fini de dessiner le fond, on va écrire dans le cadre
  //d'abord le titre du cadre
  rect = elem->rectPrincipal;
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 30, ALLEGRO_ALIGN_CENTRE, "NOUVEAU SCORE!");
  //le score juste en dessous
  char strScore[7];
  sprintf(strScore, "%d", score); //on transforme le int de score en string
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + 75, ALLEGRO_ALIGN_CENTRE, strScore);
  //puis on demande au joueur d'entrer ses initiales
  font = al_load_ttf_font("Gameplay.ttf", 18, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 140, ALLEGRO_ALIGN_CENTRE, "ENTREZ VOS INITIALES:");

  //on libère la mémoire
  al_destroy_font(font);

  return fond;
}

packOptions *genererPackOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3])
{
  //on crée un pointeur vers la structure d'images
  packOptions *images = malloc(sizeof(packOptions));

  //puis on initie chacune des images
  images->fondOptions = genererFondOptions(elem, fondPrecedent, 0);
  images->boutonOkOff = genererBoutonOptions(OK, OFF, elem, keyMap);
  images->boutonOkOn = genererBoutonOptions(OK, ON, elem, keyMap);
  images->inputrotaterOff = genererBoutonOptions(IROTATER, OFF, elem, keyMap);
  images->inputrotaterOn = genererBoutonOptions(IROTATER, ON, elem, keyMap);
  images->inputsoftdOff = genererBoutonOptions(ISOFTD, OFF, elem, keyMap);
  images->inputsoftdOn = genererBoutonOptions(ISOFTD, ON, elem, keyMap);
  images->inputleftOff = genererBoutonOptions(ILEFT, OFF, elem, keyMap);
  images->inputleftOn = genererBoutonOptions(ILEFT, ON, elem, keyMap);
  images->inputrightOff = genererBoutonOptions(IRIGHT, OFF, elem, keyMap);
  images->inputrightOn = genererBoutonOptions(IRIGHT, ON, elem, keyMap);
  images->inputharddOff = genererBoutonOptions(IHARDD, OFF, elem, keyMap);
  images->inputharddOn = genererBoutonOptions(IHARDD, ON, elem, keyMap);
  images->inputrotatelOff = genererBoutonOptions(IROTATEL, OFF, elem, keyMap);
  images->inputrotatelOn = genererBoutonOptions(IROTATEL, ON, elem, keyMap);
  images->inputpauseOff = genererBoutonOptions(IPAUSE, OFF, elem, keyMap);
  images->inputpauseOn = genererBoutonOptions(IPAUSE, ON, elem, keyMap);
  images->inputghostOff = genererBoutonOptions(IGHOST, OFF, elem, keyMap);
  images->inputghostOn = genererBoutonOptions(IGHOST, ON, elem, keyMap);
  images->inputchangeOff = genererBoutonOptions(ICHANGE, OFF, elem, keyMap);
  images->inputchangeOn = genererBoutonOptions(ICHANGE, ON, elem, keyMap);
  images->boutonVolThemeMOff = genererBoutonOptions(VOLTHEMEM, OFF, elem, keyMap);
  images->boutonVolThemeMOn = genererBoutonOptions(VOLTHEMEM, ON, elem, keyMap);
  images->boutonVolThemePOff = genererBoutonOptions(VOLTHEMEP, OFF, elem, keyMap);
  images->boutonVolThemePOn = genererBoutonOptions(VOLTHEMEP, ON, elem, keyMap);
  images->boutonVolFXMOff = genererBoutonOptions(VOLFXM, OFF, elem, keyMap);
  images->boutonVolFXMOn = genererBoutonOptions(VOLFXM, ON, elem, keyMap);
  images->boutonVolFXPOff = genererBoutonOptions(VOLFXP, OFF, elem, keyMap);
  images->boutonVolFXPOn = genererBoutonOptions(VOLFXP, ON, elem, keyMap);
  images->boutonResetOff = genererBoutonOptions(RESET, OFF, elem, keyMap);
  images->boutonResetOn = genererBoutonOptions(RESET, ON, elem, keyMap);

  images->fondInputOptions = genererFondInputOptions(elem, images->fondOptions);
  images->boutonOkInpOptOff = genererBoutonInputOptions(OKINPOPT, OFF, elem);
  images->boutonOkInpOptOn = genererBoutonInputOptions(OKINPOPT, ON, elem);
  images->touche1Off = genererBoutonInputOptions(TOUCHE1, OFF, elem);
  images->touche1On = genererBoutonInputOptions(TOUCHE1, ON, elem);
  images->touche2Off = genererBoutonInputOptions(TOUCHE2, OFF, elem);
  images->touche2On = genererBoutonInputOptions(TOUCHE2, ON, elem);
  images->touche3Off = genererBoutonInputOptions(TOUCHE3, OFF, elem);
  images->touche3On = genererBoutonInputOptions(TOUCHE3, ON, elem);

  return images; //on renvoit le pack d'images
}

void destroyPackOptions(packOptions *images)
{
  al_destroy_bitmap(images->fondOptions);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);
  al_destroy_bitmap(images->inputrotaterOff);
  al_destroy_bitmap(images->inputrotaterOn);
  al_destroy_bitmap(images->inputsoftdOff);
  al_destroy_bitmap(images->inputsoftdOn);
  al_destroy_bitmap(images->inputleftOff);
  al_destroy_bitmap(images->inputleftOn);
  al_destroy_bitmap(images->inputrightOff);
  al_destroy_bitmap(images->inputrightOn);
  al_destroy_bitmap(images->inputharddOff);
  al_destroy_bitmap(images->inputharddOn);
  al_destroy_bitmap(images->inputrotatelOff);
  al_destroy_bitmap(images->inputrotatelOn);
  al_destroy_bitmap(images->inputpauseOff);
  al_destroy_bitmap(images->inputpauseOn);
  al_destroy_bitmap(images->inputghostOff);
  al_destroy_bitmap(images->inputghostOn);
  al_destroy_bitmap(images->inputchangeOff);
  al_destroy_bitmap(images->inputchangeOn);
  al_destroy_bitmap(images->boutonVolThemeMOff);
  al_destroy_bitmap(images->boutonVolThemeMOn);
  al_destroy_bitmap(images->boutonVolThemePOff);
  al_destroy_bitmap(images->boutonVolThemePOn);
  al_destroy_bitmap(images->boutonVolFXMOff);
  al_destroy_bitmap(images->boutonVolFXMOn);
  al_destroy_bitmap(images->boutonVolFXPOff);
  al_destroy_bitmap(images->boutonVolFXPOn);
  al_destroy_bitmap(images->boutonResetOff);
  al_destroy_bitmap(images->boutonResetOn);

  al_destroy_bitmap(images->fondInputOptions);
  al_destroy_bitmap(images->boutonOkInpOptOff);
  al_destroy_bitmap(images->boutonOkInpOptOn);
  al_destroy_bitmap(images->touche1Off);
  al_destroy_bitmap(images->touche1On);
  al_destroy_bitmap(images->touche2Off);
  al_destroy_bitmap(images->touche2On);
  al_destroy_bitmap(images->touche3Off);
  al_destroy_bitmap(images->touche3On);

  free(images);
}

ALLEGRO_BITMAP *genererFondOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent, int recharge)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner le menu d'options
  ALLEGRO_BITMAP *fondOptions = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondOptions); //on cible l'image crée pour le dessin
  al_draw_bitmap(fondPrecedent, 0, 0, 0); //on dessine le fond précédent le menu d'options (donc le menu principal ou la pause)

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_FONT *font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Gameplay"

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPrincipal;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectIrotater;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "ROTATION DROITE");

  rect = elem->rectIsoftd;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "SOFT DROP");

  rect = elem->rectIleft;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "MOUVEMENT GAUCHE");

  rect = elem->rectIright;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "MOUVEMENT DROITE");

  rect = elem->rectIhardd;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "HARD DROP");

  rect = elem->rectIrotatel;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "ROTATION GAUCHE");

  rect = elem->rectIpause;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "PAUSE");

  rect = elem->rectIghost;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "PIECE FANTOME");

  rect = elem->rectIchange;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "PIECE SUIVANTE");

  rect = elem->rectVolThemeM;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "VOLUME DU THEME");

  rect = elem->rectVolThemeP;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectVolFXM;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectPrincipal->x + 11, rect->y, 0, "VOLUME DES FX");

  rect = elem->rectVolFXP;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectReset;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maintenant on va écrire "OPTIONS" dans le rectPrincipal
  rect = elem->rectPrincipal;
  font = al_load_ttf_font("Gameplay.ttf", 45, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + 28, ALLEGRO_ALIGN_CENTRE, "OPTIONS");

  //on libère la mémoire
  al_destroy_font(font);

  return fondOptions; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererFondInputOptions(elementsFondOptions *elem, ALLEGRO_BITMAP *fondPrecedent)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner l'inputOptions
  ALLEGRO_BITMAP *fondInputOptions = al_create_bitmap(SCREEN_W, SCREEN_H);
  al_set_target_bitmap(fondInputOptions); //on cible l'image crée pour le dessin
  al_draw_bitmap(fondPrecedent, 0, 0, 0); //on dessine le fond précédent

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_FONT *font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway"

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectInputOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectOkInpOpt;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectTouche1;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + 11, rect->y, 0, "TOUCHE 1");

  rect = elem->rectTouche2;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + 11, rect->y, 0, "TOUCHE 2");

  rect = elem->rectTouche3;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + 11, rect->y, 0, "TOUCHE 3");

  //on libère la mémoire
  al_destroy_font(font);

  return fondInputOptions; //on renvoit l'image créée
}

elementsFondOptions *genererElementsFondOptions()
{
  elementsFondOptions *elem = malloc(sizeof(elementsFondOptions)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  elem->rectIrotater = malloc(sizeof(coord));
  elem->rectIsoftd = malloc(sizeof(coord));
  elem->rectIleft = malloc(sizeof(coord));
  elem->rectIright = malloc(sizeof(coord));
  elem->rectIhardd = malloc(sizeof(coord));
  elem->rectIrotatel = malloc(sizeof(coord));
  elem->rectIpause = malloc(sizeof(coord));
  elem->rectIghost = malloc(sizeof(coord));
  elem->rectIchange = malloc(sizeof(coord));
  elem->rectVolThemeM = malloc(sizeof(coord));
  elem->rectVolThemeP = malloc(sizeof(coord));
  elem->rectVolFXM = malloc(sizeof(coord));
  elem->rectVolFXP = malloc(sizeof(coord));
  elem->rectReset = malloc(sizeof(coord));

  elem->rectInputOptions = malloc(sizeof(coord));
  elem->rectTouche1 = malloc(sizeof(coord));
  elem->rectTouche2 = malloc(sizeof(coord));
  elem->rectTouche3 = malloc(sizeof(coord));
  elem->rectOkInpOpt = malloc(sizeof(coord));

  int epaisseur = 2; //étant donné que l'épaisseur est quasiment la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 48; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 3; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 403; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 598; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = 6; //épaisseur des traits

  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 508; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 558; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = 6; //épaisseur des traits

  elem->rectIleft->x = 241; //coordonnée x du point d'origine
  elem->rectIleft->y = 103; //coordonnée y du point d'origine
  elem->rectIleft->x2 = 392; //coordonnée x du point de fin
  elem->rectIleft->y2 = 123; //coordonnée y du point de fin
  elem->rectIleft->w = elem->rectIleft->x2 - elem->rectIleft->x; //largeur
  elem->rectIleft->h = elem->rectIleft->y2 - elem->rectIleft->y; //hauteur
  elem->rectIleft->t = epaisseur; //épaisseur des traits

  elem->rectIright->x = 241; //coordonnée x du point d'origine
  elem->rectIright->y = 128; //coordonnée y du point d'origine
  elem->rectIright->x2 = 392; //coordonnée x du point de fin
  elem->rectIright->y2 = 148; //coordonnée y du point de fin
  elem->rectIright->w = elem->rectIright->x2 - elem->rectIright->x; //largeur
  elem->rectIright->h = elem->rectIright->y2 - elem->rectIright->y; //hauteur
  elem->rectIright->t = epaisseur; //épaisseur des traits

  elem->rectIrotatel->x = 241; //coordonnée x du point d'origine
  elem->rectIrotatel->y = 153; //coordonnée y du point d'origine
  elem->rectIrotatel->x2 = 392; //coordonnée x du point de fin
  elem->rectIrotatel->y2 = 173; //coordonnée y du point de fin
  elem->rectIrotatel->w = elem->rectIrotatel->x2 - elem->rectIrotatel->x; //largeur
  elem->rectIrotatel->h = elem->rectIrotatel->y2 - elem->rectIrotatel->y; //hauteur
  elem->rectIrotatel->t = epaisseur; //épaisseur des traits

  elem->rectIrotater->x = 241; //coordonnée x du point d'origine
  elem->rectIrotater->y = 178; //coordonnée y du point d'origine
  elem->rectIrotater->x2 = 392; //coordonnée x du point de fin
  elem->rectIrotater->y2 = 198; //coordonnée y du point de fin
  elem->rectIrotater->w = elem->rectIrotater->x2 - elem->rectIrotater->x; //largeur
  elem->rectIrotater->h = elem->rectIrotater->y2 - elem->rectIrotater->y; //hauteur
  elem->rectIrotater->t = epaisseur; //épaisseur des traits

  elem->rectIhardd->x = 241; //coordonnée x du point d'origine
  elem->rectIhardd->y = 203; //coordonnée y du point d'origine
  elem->rectIhardd->x2 = 392; //coordonnée x du point de fin
  elem->rectIhardd->y2 = 223; //coordonnée y du point de fin
  elem->rectIhardd->w = elem->rectIhardd->x2 - elem->rectIhardd->x; //largeur
  elem->rectIhardd->h = elem->rectIhardd->y2 - elem->rectIhardd->y; //hauteur
  elem->rectIhardd->t = epaisseur; //épaisseur des traits

  elem->rectIsoftd->x = 241; //coordonnée x du point d'origine
  elem->rectIsoftd->y = 228; //coordonnée y du point d'origine
  elem->rectIsoftd->x2 = 392; //coordonnée x du point de fin
  elem->rectIsoftd->y2 = 248; //coordonnée y du point de fin
  elem->rectIsoftd->w = elem->rectIsoftd->x2 - elem->rectIsoftd->x; //largeur
  elem->rectIsoftd->h = elem->rectIsoftd->y2 - elem->rectIsoftd->y; //hauteur
  elem->rectIsoftd->t = epaisseur; //épaisseur des traits

  elem->rectIpause->x = 241; //coordonnée x du point d'origine
  elem->rectIpause->y = 253; //coordonnée y du point d'origine
  elem->rectIpause->x2 = 392; //coordonnée x du point de fin
  elem->rectIpause->y2 = 273; //coordonnée y du point de fin
  elem->rectIpause->w = elem->rectIpause->x2 - elem->rectIpause->x; //largeur
  elem->rectIpause->h = elem->rectIpause->y2 - elem->rectIpause->y; //hauteur
  elem->rectIpause->t = epaisseur; //épaisseur des traits

  elem->rectIghost->x = 241; //coordonnée x du point d'origine
  elem->rectIghost->y = 278; //coordonnée y du point d'origine
  elem->rectIghost->x2 = 392; //coordonnée x du point de fin
  elem->rectIghost->y2 = 298; //coordonnée y du point de fin
  elem->rectIghost->w = elem->rectIghost->x2 - elem->rectIghost->x; //largeur
  elem->rectIghost->h = elem->rectIghost->y2 - elem->rectIghost->y; //hauteur
  elem->rectIghost->t = epaisseur; //épaisseur des traits

  elem->rectIchange->x = 241; //coordonnée x du point d'origine
  elem->rectIchange->y = 303; //coordonnée y du point d'origine
  elem->rectIchange->x2 = 392; //coordonnée x du point de fin
  elem->rectIchange->y2 = 323; //coordonnée y du point de fin
  elem->rectIchange->w = elem->rectIchange->x2 - elem->rectIchange->x; //largeur
  elem->rectIchange->h = elem->rectIchange->y2 - elem->rectIchange->y; //hauteur
  elem->rectIchange->t = epaisseur; //épaisseur des traits

  elem->rectVolThemeM->x = 241; //coordonnée x du point d'origine
  elem->rectVolThemeM->y = 343; //coordonnée y du point d'origine
  elem->rectVolThemeM->x2 = 281; //coordonnée x du point de fin
  elem->rectVolThemeM->y2 = 363; //coordonnée y du point de fin
  elem->rectVolThemeM->w = elem->rectVolThemeM->x2 - elem->rectVolThemeM->x; //largeur
  elem->rectVolThemeM->h = elem->rectVolThemeM->y2 - elem->rectVolThemeM->y; //hauteur
  elem->rectVolThemeM->t = epaisseur; //épaisseur des traits

  elem->rectVolThemeP->x = 352; //coordonnée x du point d'origine
  elem->rectVolThemeP->y = 343; //coordonnée y du point d'origine
  elem->rectVolThemeP->x2 = 392; //coordonnée x du point de fin
  elem->rectVolThemeP->y2 = 363; //coordonnée y du point de fin
  elem->rectVolThemeP->w = elem->rectVolThemeP->x2 - elem->rectVolThemeP->x; //largeur
  elem->rectVolThemeP->h = elem->rectVolThemeP->y2 - elem->rectVolThemeP->y; //hauteur
  elem->rectVolThemeP->t = epaisseur; //épaisseur des traits

  elem->rectVolFXM->x = 241; //coordonnée x du point d'origine
  elem->rectVolFXM->y = 383; //coordonnée y du point d'origine
  elem->rectVolFXM->x2 = 281; //coordonnée x du point de fin
  elem->rectVolFXM->y2 = 403; //coordonnée y du point de fin
  elem->rectVolFXM->w = elem->rectVolFXM->x2 - elem->rectVolFXM->x; //largeur
  elem->rectVolFXM->h = elem->rectVolFXM->y2 - elem->rectVolFXM->y; //hauteur
  elem->rectVolFXM->t = epaisseur; //épaisseur des traits

  elem->rectVolFXP->x = 352; //coordonnée x du point d'origine
  elem->rectVolFXP->y = 383; //coordonnée y du point d'origine
  elem->rectVolFXP->x2 = 392; //coordonnée x du point de fin
  elem->rectVolFXP->y2 = 403; //coordonnée y du point de fin
  elem->rectVolFXP->w = elem->rectVolFXP->x2 - elem->rectVolFXP->x; //largeur
  elem->rectVolFXP->h = elem->rectVolFXP->y2 - elem->rectVolFXP->y; //hauteur
  elem->rectVolFXP->t = epaisseur; //épaisseur des traits

  elem->rectReset->x = 134; //coordonnée x du point d'origine
  elem->rectReset->y = 433; //coordonnée y du point d'origine
  elem->rectReset->x2 = 317; //coordonnée x du point de fin
  elem->rectReset->y2 = 483; //coordonnée y du point de fin
  elem->rectReset->w = elem->rectReset->x2 - elem->rectReset->x; //largeur
  elem->rectReset->h = elem->rectReset->y2 - elem->rectReset->y; //hauteur
  elem->rectReset->t = 6; //épaisseur des traits

  //rectInputOptions
  elem->rectInputOptions->x = 78; //coordonnée x du point d'origine
  elem->rectInputOptions->y = 200; //coordonnée y du point d'origine
  elem->rectInputOptions->x2 = 373; //coordonnée x du point de fin
  elem->rectInputOptions->y2 = 400; //coordonnée y du point de fin
  elem->rectInputOptions->w = elem->rectInputOptions->x2 - elem->rectInputOptions->x; //largeur
  elem->rectInputOptions->h = elem->rectInputOptions->y2 - elem->rectInputOptions->y; //hauteur
  elem->rectInputOptions->t = 6; //épaisseur des traits

  elem->rectOkInpOpt->x = 194; //coordonnée x du point d'origine
  elem->rectOkInpOpt->y = 320; //coordonnée y du point d'origine
  elem->rectOkInpOpt->x2 = 257; //coordonnée x du point de fin
  elem->rectOkInpOpt->y2 = 370; //coordonnée y du point de fin
  elem->rectOkInpOpt->w = elem->rectOkInpOpt->x2 - elem->rectOkInpOpt->x; //largeur
  elem->rectOkInpOpt->h = elem->rectOkInpOpt->y2 - elem->rectOkInpOpt->y; //hauteur
  elem->rectOkInpOpt->t = 6; //épaisseur des traits

  elem->rectTouche1->x = 241; //coordonnée x du point d'origine
  elem->rectTouche1->y = 230; //coordonnée y du point d'origine
  elem->rectTouche1->x2 = 362; //coordonnée x du point de fin
  elem->rectTouche1->y2 = 250; //coordonnée y du point de fin
  elem->rectTouche1->w = elem->rectTouche1->x2 - elem->rectTouche1->x; //largeur
  elem->rectTouche1->h = elem->rectTouche1->y2 - elem->rectTouche1->y; //hauteur
  elem->rectTouche1->t = epaisseur; //épaisseur des traits

  elem->rectTouche2->x = 241; //coordonnée x du point d'origine
  elem->rectTouche2->y = 255; //coordonnée y du point d'origine
  elem->rectTouche2->x2 = 362; //coordonnée x du point de fin
  elem->rectTouche2->y2 = 275; //coordonnée y du point de fin
  elem->rectTouche2->w = elem->rectTouche2->x2 - elem->rectTouche2->x; //largeur
  elem->rectTouche2->h = elem->rectTouche2->y2 - elem->rectTouche2->y; //hauteur
  elem->rectTouche2->t = epaisseur; //épaisseur des traits

  elem->rectTouche3->x = 241; //coordonnée x du point d'origine
  elem->rectTouche3->y = 280; //coordonnée y du point d'origine
  elem->rectTouche3->x2 = 362; //coordonnée x du point de fin
  elem->rectTouche3->y2 = 300; //coordonnée y du point de fin
  elem->rectTouche3->w = elem->rectTouche3->x2 - elem->rectTouche3->x; //largeur
  elem->rectTouche3->h = elem->rectTouche3->y2 - elem->rectTouche3->y; //hauteur
  elem->rectTouche3->t = epaisseur; //épaisseur des traits

  return elem;
}

void destroyElementsFondOptions(elementsFondOptions *elem)
{
  free(elem->rectPrincipal);
  free(elem->rectOk);
  free(elem->rectIrotater);
  free(elem->rectIsoftd);
  free(elem->rectIleft);
  free(elem->rectIright);
  free(elem->rectIhardd);
  free(elem->rectIrotatel);
  free(elem->rectIpause);
  free(elem->rectIghost);
  free(elem->rectIchange);
  free(elem->rectVolThemeM);
  free(elem->rectVolThemeP);
  free(elem->rectVolFXM);
  free(elem->rectVolFXP);
  free(elem->rectReset);

  free(elem->rectInputOptions);
  free(elem->rectTouche1);
  free(elem->rectTouche2);
  free(elem->rectTouche3);
  free(elem->rectOkInpOpt);

  free(elem);
}

ALLEGRO_BITMAP *genererBoutonOptions(int typeDeBouton, int onOff, elementsFondOptions *elem, int keyMap[16][3])
{
  //on crée un pointeur vers l'image qu'on va renvoyer
  ALLEGRO_BITMAP *bouton = NULL;

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  //on établie la couleur de fond du bouton en fonction de onOff
  ALLEGRO_COLOR couleurDeFond = al_map_rgb(219, 237, 255); //bleu très très clair
  if(onOff == ON)
  {
    couleurDeFond = al_map_rgb(162, 195, 232); //bleu clair
  }

  //on détermine quel type de bouton on génère
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);

  char str[40]; //chaîne de caractère pour la touche d'input

  switch(typeDeBouton)
  {
    case OK:
      rect = elem->rectOk;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit OK en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-18, ALLEGRO_ALIGN_CENTRE, "OK");
      break;
    case IROTATER:
      rect = elem->rectIrotater;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ISOFTD:
      rect = elem->rectIsoftd;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ILEFT:
      rect = elem->rectIleft;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IRIGHT:
      rect = elem->rectIright;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IHARDD:
      rect = elem->rectIhardd;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IROTATEL:
      rect = elem->rectIrotatel;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IPAUSE:
      rect = elem->rectIpause;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IGHOST:
      rect = elem->rectIghost;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ICHANGE:
      rect = elem->rectIchange;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Raleway-Bold.ttf", 15, 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case VOLTHEMEM:
      rect = elem->rectVolThemeM;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 15, 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "-");
      break;
    case VOLTHEMEP:
      rect = elem->rectVolThemeP;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 15, 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "+");
      break;
    case VOLFXM:
      rect = elem->rectVolFXM;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 15, 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "-");
      break;
    case VOLFXP:
      rect = elem->rectVolFXP;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 15, 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "+");
      break;
    case RESET:
      rect = elem->rectReset;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-18, ALLEGRO_ALIGN_CENTRE, "RESET");
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

void strTouche(int typeDeBouton, int keyMap[16][3], char str[40])
{
  int touche[3];
  int curseur = 0; //va servir à nous déplacer dans la chaîne

  //on recueille les valeurs des touches
  for(int i = 0; i < 3; i++)
  {
    touche[i] = keyMap[typeDeBouton - 9][i];
  }

  //on écrit la chaîne de caractère
  for(int i = 0; i < 3; i++)
  {
    if(touche[i] != 0)
    {
      switch(touche[i])
      {

      }
      switch(touche[i]) //on détermine laquelle
      {
        case ALLEGRO_KEY_A:
          str[curseur] = 'A';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_Z:
          str[curseur] = 'Z';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_E:
          str[curseur] = 'E';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_R:
          str[curseur] = 'R';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_T:
          str[curseur] = 'T';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_Y:
          str[curseur] = 'Y';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_U:
          str[curseur] = 'U';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_I:
          str[curseur] = 'I';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_O:
          str[curseur] = 'O';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_P:
          str[curseur] = 'P';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_Q:
          str[curseur] = 'Q';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_S:
          str[curseur] = 'S';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_D:
          str[curseur] = 'D';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_F:
          str[curseur] = 'F';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_G:
          str[curseur] = 'G';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_H:
          str[curseur] = 'H';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_J:
          str[curseur] = 'J';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_K:
          str[curseur] = 'K';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_L:
          str[curseur] = 'L';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_M:
          str[curseur] = 'M';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_W:
          str[curseur] = 'W';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_X:
          str[curseur] = 'X';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_C:
          str[curseur] = 'C';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_V:
          str[curseur] = 'V';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_B:
          str[curseur] = 'B';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_N:
          str[curseur] = 'N';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_0:
          str[curseur] = '0';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_1:
          str[curseur] = '1';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_2:
          str[curseur] = '2';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_3:
          str[curseur] = '3';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_4:
          str[curseur] = '4';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_5:
          str[curseur] = '5';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_6:
          str[curseur] = '6';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_7:
          str[curseur] = '7';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_8:
          str[curseur] = '8';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_9:
          str[curseur] = '9';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_TILDE:
          sprintf((str+curseur), ")");
          curseur+= strlen(")");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_EQUALS:
          sprintf((str+curseur), "EQUALS");
          curseur+=strlen("EQUALS");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_MINUS:
          str[curseur] = '^';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_OPENBRACE:
          str[curseur] = '$';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_CLOSEBRACE:
          str[curseur] = 'u';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_BACKSLASH:
          str[curseur] = '*';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_COMMA:
          str[curseur] = ',';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_SEMICOLON:
          str[curseur] = ';';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_FULLSTOP:
          str[curseur] = ':';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_SLASH:
          str[curseur] = '!';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_QUOTE:
          str[curseur] = 'e';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_BACKSLASH2:
          str[curseur] = '<';
          curseur++;
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          else
          {
            str[curseur] = '\0';
          }
          break;
        case ALLEGRO_KEY_LSHIFT:
          sprintf((str+curseur), "LSHIFT");
          curseur+= strlen("LSHIFT");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_RSHIFT:
          sprintf((str+curseur), "RSHIFT");
          curseur+=strlen("RSHIFT");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_LCTRL:
          sprintf((str+curseur), "LCTRL");
          curseur+=strlen("LCTRL");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_RCTRL:
          sprintf((str+curseur), "RCTRL");
          curseur+=strlen("RCTRL");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_ALT:
          sprintf((str+curseur), "ALT");
          curseur+=strlen("ALT");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_ALTGR:
          sprintf((str+curseur), "ALTGR");
          curseur+=strlen("ALTGR");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_TAB:
          sprintf((str+curseur), "TAB");
          curseur+=strlen("TAB");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_BACKSPACE:
          sprintf((str+curseur), "BACKSPACE");
          curseur+=strlen("BACKSPACE");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_SPACE:
          sprintf((str+curseur), "SPACE");
          curseur+=strlen("SPACE");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_UP:
          sprintf((str+curseur), "HAUT");
          curseur+=strlen("HAUT");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_DOWN:
          sprintf((str+curseur), "BAS");
          curseur+=strlen("BAS");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_LEFT:
          sprintf((str+curseur), "GAUCHE");
          curseur+=strlen("GAUCHE");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_RIGHT:
          sprintf((str+curseur), "DROITE");
          curseur+=strlen("DROITE");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F1:
          sprintf((str+curseur), "F1");
          curseur+=strlen("F1");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F2:
          sprintf((str+curseur), "F2");
          curseur+=strlen("F2");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F3:
          sprintf((str+curseur), "F3");
          curseur+=strlen("F3");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F4:
          sprintf((str+curseur), "F4");
          curseur+=strlen("F4");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F5:
          sprintf((str+curseur), "F5");
          curseur+=strlen("F5");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F6:
          sprintf((str+curseur), "F6");
          curseur+=strlen("F6");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F7:
          sprintf((str+curseur), "F7");
          curseur+=strlen("F7");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F8:
          sprintf((str+curseur), "F8");
          curseur+=strlen("F8");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F9:
          sprintf((str+curseur), "F9");
          curseur+=strlen("F9");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F10:
          sprintf((str+curseur), "F10");
          curseur+=strlen("F10");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F11:
          sprintf((str+curseur), "F11");
          curseur+=strlen("F11");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_F12:
          sprintf((str+curseur), "F12");
          curseur+=strlen("F12");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_ESCAPE:
          sprintf((str+curseur), "ESCAPE");
          curseur+=strlen("ESCAPE");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        case ALLEGRO_KEY_ENTER:
          sprintf((str+curseur), "ENTER");
          curseur+=strlen("ENTER");
          if(i < 2 && touche[i + 1] != 0)
          {
            str[curseur] = ',';
            str[curseur+1] = ' ';
            curseur += 2;
          }
          break;
        default:
          str[curseur] = '\0';
          break;
      }
    }
  }
}

ALLEGRO_BITMAP *genererBoutonInputOptions(int typeDeBouton, int onOff, elementsFondOptions *elem)
{
  //on crée un pointeur vers l'image qu'on va renvoyer
  ALLEGRO_BITMAP *bouton = NULL;

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  //on établie la couleur de fond du bouton en fonction de onOff
  ALLEGRO_COLOR couleurDeFond = al_map_rgb(219, 237, 255); //bleu très très clair
  if(onOff == ON)
  {
    couleurDeFond = al_map_rgb(162, 195, 232); //bleu clair
  }

  //on détermine quel type de bouton on génère
  ALLEGRO_FONT *font = NULL;
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166);

  char str[40]; //chaîne de caractère pour la touche d'input

  switch(typeDeBouton)
  {
    case OKINPOPT:
      rect = elem->rectOkInpOpt;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("Gameplay.ttf", 30, 0); //on charge la police "Gameplay"
      //on écrit OK en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2)-18, ALLEGRO_ALIGN_CENTRE, "OK");
      break;
    case TOUCHE1:
      rect = elem->rectTouche1;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      break;
    case TOUCHE2:
      rect = elem->rectTouche2;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      break;
    case TOUCHE3:
      rect = elem->rectTouche3;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

elementsFondTempsInput *genererElementsFondTempsInput()
{
  elementsFondTempsInput *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectInput = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  int epaisseur = 6; //étant donné que l'épaisseur est la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 96; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 135; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 355; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 466; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectInput
  elem->rectInput->x = 141; //coordonnée x du point d'origine
  elem->rectInput->y = 315; //coordonnée y du point d'origine
  elem->rectInput->x2 = 310; //coordonnée x du point de fin
  elem->rectInput->y2 = 365; //coordonnée y du point de fin
  elem->rectInput->w = elem->rectInput->x2 - elem->rectInput->x; //largeur
  elem->rectInput->h = elem->rectInput->y2 - elem->rectInput->y; //hauteur
  elem->rectInput->t = epaisseur; //épaisseur des traits

  //rectOk
  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 385; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 435; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = epaisseur; //épaisseur des traits

  return elem; //on revoit la structure créée
}

void destroyElementsFondTempsInput(elementsFondTempsInput *elem)
{
  free(elem->rectPrincipal);
  free(elem->rectInput);
  free(elem->rectOk);
  free(elem);
}

packTempsInput *genererPackTempsInput(ALLEGRO_DISPLAY *fenetre, elementsFondTempsInput *elem, int temps)
{
  packTempsInput *images = malloc(sizeof(packTempsInput));

  images->fond = genererFondTempsInput(fenetre, elem, temps);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectOk);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectOk);

  return images; //on revoit la structure d'images
}

void destroyPackTempsInput(packTempsInput *images)
{
  al_destroy_bitmap(images->fond);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);
  free(images);
}

ALLEGRO_BITMAP *genererFondTempsInput(ALLEGRO_DISPLAY *fenetre, elementsFondTempsInput *elem, int temps)
{
  ALLEGRO_BITMAP *fond = al_create_bitmap(SCREEN_W, SCREEN_H); //on crée l'image de fond
  al_set_target_bitmap(fond); //on cible l'image créée
  al_draw_bitmap(al_get_backbuffer(fenetre), 0, 0, 0); //on copie l'écran de fin de partie

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_COLOR fondInput = al_map_rgb(162, 195, 232); //fond de la zone d'input

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPrincipal;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectInput;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, fondInput);

  rect = elem->rectOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maitenant qu'on a fini de dessiner le fond, on va écrire dans le cadre
  //d'abord le titre du cadre
  rect = elem->rectPrincipal;
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 30, ALLEGRO_ALIGN_CENTRE, "NOUVEAU TEMPS!");
  //le temps juste en dessous
  char strTemps[9];

  int minutes = (temps/3600), secondes = ((temps % 3600)/60), dixiemes = ((temps % 60)/6);

  if(secondes < 1 && minutes == 0) //si le temps fait moins d'une seconde (LOL, bonne chance)
  {
    sprintf(strTemps, "00:00:%d0", dixiemes); //on affiche les dixième de seconde
  }
  else if(secondes > 0 && secondes < 10 && minutes == 0) //on est entre 0 et 10 secondes
  {
    sprintf(strTemps, "00:0%d:%d0", secondes, dixiemes);
  }
  else if(secondes > 9 && secondes < 60 && minutes == 0) //si on est deça de la minute
  {
    sprintf(strTemps, "%d:%d0", secondes, dixiemes);
  }
  else if(minutes > 0 && minutes < 10) //si on est au-dessus de la minute
  {
    if(secondes < 10) //si le nombre de secondes est inférieur à 10
    {
      sprintf(strTemps, "0%d:0%d:%d0", minutes, secondes, dixiemes);
    }
    else
    {
      sprintf(strTemps, "0%d:%d:%d0", minutes, secondes, dixiemes);
    }
  }
  else if(minutes > 10) //si on est au-dessus de la minute
  {
    if(secondes < 10) //si le nombre de secondes est inférieur à 10
    {
      sprintf(strTemps, "%d:0%d:%d0", minutes, secondes, dixiemes);
    }
    else
    {
      sprintf(strTemps, "%d:%d:%d0", minutes, secondes, dixiemes);
    }
  }

  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + 75, ALLEGRO_ALIGN_CENTRE, strTemps);
  //puis on demande au joueur d'entrer ses initiales
  font = al_load_ttf_font("Gameplay.ttf", 18, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 140, ALLEGRO_ALIGN_CENTRE, "ENTREZ VOS INITIALES:");

  //on libère la mémoire
  al_destroy_font(font);

  return fond;
}

elementsFondLignesInput *genererElementsFondLignesInput()
{
  elementsFondLignesInput *elem = malloc(sizeof(*elem)); //on crée le pointeur qu'on va renvoyer

  //on initialise les pointeurs de la structure "elem"
  elem->rectPrincipal = malloc(sizeof(coord));
  elem->rectInput = malloc(sizeof(coord));
  elem->rectOk = malloc(sizeof(coord));
  int epaisseur = 6; //étant donné que l'épaisseur est la même partout, on l'initie maintenant

  //rectPrincipal
  elem->rectPrincipal->x = 96; //coordonnée x du point d'origine
  elem->rectPrincipal->y = 135; //coordonnée y du point d'origine
  elem->rectPrincipal->x2 = 355; //coordonnée x du point de fin
  elem->rectPrincipal->y2 = 466; //coordonnée y du point de fin
  elem->rectPrincipal->w = elem->rectPrincipal->x2 - elem->rectPrincipal->x; //largeur
  elem->rectPrincipal->h = elem->rectPrincipal->y2 - elem->rectPrincipal->y; //hauteur
  elem->rectPrincipal->t = epaisseur; //épaisseur des traits

  //rectInput
  elem->rectInput->x = 141; //coordonnée x du point d'origine
  elem->rectInput->y = 315; //coordonnée y du point d'origine
  elem->rectInput->x2 = 310; //coordonnée x du point de fin
  elem->rectInput->y2 = 365; //coordonnée y du point de fin
  elem->rectInput->w = elem->rectInput->x2 - elem->rectInput->x; //largeur
  elem->rectInput->h = elem->rectInput->y2 - elem->rectInput->y; //hauteur
  elem->rectInput->t = epaisseur; //épaisseur des traits

  //rectOk
  elem->rectOk->x = 194; //coordonnée x du point d'origine
  elem->rectOk->y = 385; //coordonnée y du point d'origine
  elem->rectOk->x2 = 257; //coordonnée x du point de fin
  elem->rectOk->y2 = 435; //coordonnée y du point de fin
  elem->rectOk->w = elem->rectOk->x2 - elem->rectOk->x; //largeur
  elem->rectOk->h = elem->rectOk->y2 - elem->rectOk->y; //hauteur
  elem->rectOk->t = epaisseur; //épaisseur des traits

  return elem; //on revoit la structure créée
}

void destroyElementsFondLignesInput(elementsFondLignesInput *elem)
{
  free(elem->rectPrincipal);
  free(elem->rectInput);
  free(elem->rectOk);
  free(elem);
}

packLignesInput *genererPackLignesInput(ALLEGRO_DISPLAY *fenetre, elementsFondLignesInput *elem, int lignes)
{
  packLignesInput *images = malloc(sizeof(packLignesInput));

  images->fond = genererFondLignesInput(fenetre, elem, lignes);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectOk);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectOk);

  return images; //on revoit la structure d'images
}

void destroyPackLignesInput(packLignesInput *images)
{
  al_destroy_bitmap(images->fond);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);
  free(images);
}

ALLEGRO_BITMAP *genererFondLignesInput(ALLEGRO_DISPLAY *fenetre, elementsFondLignesInput *elem, int lignes)
{
  ALLEGRO_BITMAP *fond = al_create_bitmap(SCREEN_W, SCREEN_H); //on crée l'image de fond
  al_set_target_bitmap(fond); //on cible l'image créée
  al_draw_bitmap(al_get_backbuffer(fenetre), 0, 0, 0); //on copie l'écran de fin de partie

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_COLOR fondInput = al_map_rgb(162, 195, 232); //fond de la zone d'input

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectPrincipal;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectInput;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, fondInput);

  rect = elem->rectOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maitenant qu'on a fini de dessiner le fond, on va écrire dans le cadre
  //d'abord le titre du cadre
  rect = elem->rectPrincipal;
  ALLEGRO_FONT *font = al_load_ttf_font("Gameplay.ttf", 25, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 30, ALLEGRO_ALIGN_CENTRE, "NOUVEAU SCORE!");
  //le total de lignes juste en dessous
  char strLignes[9];
  sprintf(strLignes, "%d", lignes);
  al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + 75, ALLEGRO_ALIGN_CENTRE, strLignes);
  //puis on demande au joueur d'entrer ses initiales
  font = al_load_ttf_font("Gameplay.ttf", 18, 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + 140, ALLEGRO_ALIGN_CENTRE, "ENTREZ VOS INITIALES:");

  //on libère la mémoire
  al_destroy_font(font);

  return fond;
}
