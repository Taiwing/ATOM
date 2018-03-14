#include "include/images.h"
#include "include/score.h"
#include "include/time.h"
#include "include/lines.h"

packMenu *genererPackMenu(elements *elem, float scale)
{
  //on crée un pointeur vers la structure d'images
  packMenu *images = malloc(sizeof(*images));

  //puis on initie chacune des images
  images->fondMenu = genererFondMenu(elem, scale);
  images->highScore = genererHigh(MARATHON, elem, scale);
  images->highTemps = genererHigh(SPRINT, elem, scale);
  images->highLines = genererHigh(ULTRA, elem, scale);
  images->boutonJouerOff = genererBoutonMenu(JOUER, OFF, 0, elem, scale);
  images->boutonJouerOn = genererBoutonMenu(JOUER, ON, 0, elem, scale);
  images->boutonMarathonOff = genererBoutonMenu(MARATHON, OFF, 0, elem, scale);
  images->boutonMarathonOn = genererBoutonMenu(MARATHON, ON, 0, elem, scale);
  images->boutonSprintOff = genererBoutonMenu(SPRINT, OFF, 0, elem, scale);
  images->boutonSprintOn = genererBoutonMenu(SPRINT, ON, 0, elem, scale);
  images->boutonUltraOff = genererBoutonMenu(ULTRA, OFF, 0, elem, scale);
  images->boutonUltraOn = genererBoutonMenu(ULTRA, ON, 0, elem, scale);
  images->boutonAideOff = genererBoutonMenu(AIDE, OFF, 0, elem, scale);
  images->boutonAideOn = genererBoutonMenu(AIDE, ON, 0, elem, scale);
  images->boutonOptionsOff = genererBoutonMenu(OPTIONS, OFF, 0, elem, scale);
  images->boutonOptionsOn = genererBoutonMenu(OPTIONS, ON, 0, elem, scale);
  images->boutonNiveau1Off = genererBoutonMenu(NIVEAU, OFF, 1, elem, scale);
  images->boutonNiveau2Off = genererBoutonMenu(NIVEAU, OFF, 2, elem, scale);
  images->boutonNiveau3Off = genererBoutonMenu(NIVEAU, OFF, 3, elem, scale);
  images->boutonNiveau4Off = genererBoutonMenu(NIVEAU, OFF, 4, elem, scale);
  images->boutonNiveau5Off = genererBoutonMenu(NIVEAU, OFF, 5, elem, scale);
  images->boutonNiveau6Off = genererBoutonMenu(NIVEAU, OFF, 6, elem, scale);
  images->boutonNiveau7Off = genererBoutonMenu(NIVEAU, OFF, 7, elem, scale);
  images->boutonNiveau8Off = genererBoutonMenu(NIVEAU, OFF, 8, elem, scale);
  images->boutonNiveau9Off = genererBoutonMenu(NIVEAU, OFF, 9, elem, scale);
  images->boutonNiveau10Off = genererBoutonMenu(NIVEAU, OFF, 10, elem, scale);
  images->boutonNiveau11Off = genererBoutonMenu(NIVEAU, OFF, 11, elem, scale);
  images->boutonNiveau12Off = genererBoutonMenu(NIVEAU, OFF, 12, elem, scale);
  images->boutonNiveau13Off = genererBoutonMenu(NIVEAU, OFF, 13, elem, scale);
  images->boutonNiveau14Off = genererBoutonMenu(NIVEAU, OFF, 14, elem, scale);
  images->boutonNiveau15Off = genererBoutonMenu(NIVEAU, OFF, 15, elem, scale);
  images->boutonNiveau16Off = genererBoutonMenu(NIVEAU, OFF, 16, elem, scale);
  images->boutonNiveau17Off = genererBoutonMenu(NIVEAU, OFF, 17, elem, scale);
  images->boutonNiveau18Off = genererBoutonMenu(NIVEAU, OFF, 18, elem, scale);
  images->boutonNiveau19Off = genererBoutonMenu(NIVEAU, OFF, 19, elem, scale);
  images->boutonNiveau20Off = genererBoutonMenu(NIVEAU, OFF, 20, elem, scale);
  images->boutonNiveau21Off = genererBoutonMenu(NIVEAU, OFF, 21, elem, scale);
  images->boutonNiveau22Off = genererBoutonMenu(NIVEAU, OFF, 22, elem, scale);
  images->boutonNiveau23Off = genererBoutonMenu(NIVEAU, OFF, 23, elem, scale);
  images->boutonNiveau24Off = genererBoutonMenu(NIVEAU, OFF, 24, elem, scale);
  images->boutonNiveau25Off = genererBoutonMenu(NIVEAU, OFF, 25, elem, scale);
  images->boutonNiveau26Off = genererBoutonMenu(NIVEAU, OFF, 26, elem, scale);
  images->boutonNiveau27Off = genererBoutonMenu(NIVEAU, OFF, 27, elem, scale);
  images->boutonNiveau28Off = genererBoutonMenu(NIVEAU, OFF, 28, elem, scale);
  images->boutonNiveau29Off = genererBoutonMenu(NIVEAU, OFF, 29, elem, scale);
  images->boutonNiveau30Off = genererBoutonMenu(NIVEAU, OFF, 30, elem, scale);
  images->boutonNiveau1On = genererBoutonMenu(NIVEAU, ON, 1, elem, scale);
  images->boutonNiveau2On = genererBoutonMenu(NIVEAU, ON, 2, elem, scale);
  images->boutonNiveau3On = genererBoutonMenu(NIVEAU, ON, 3, elem, scale);
  images->boutonNiveau4On = genererBoutonMenu(NIVEAU, ON, 4, elem, scale);
  images->boutonNiveau5On = genererBoutonMenu(NIVEAU, ON, 5, elem, scale);
  images->boutonNiveau6On = genererBoutonMenu(NIVEAU, ON, 6, elem, scale);
  images->boutonNiveau7On = genererBoutonMenu(NIVEAU, ON, 7, elem, scale);
  images->boutonNiveau8On = genererBoutonMenu(NIVEAU, ON, 8, elem, scale);
  images->boutonNiveau9On = genererBoutonMenu(NIVEAU, ON, 9, elem, scale);
  images->boutonNiveau10On = genererBoutonMenu(NIVEAU, ON, 10, elem, scale);
  images->boutonNiveau11On = genererBoutonMenu(NIVEAU, ON, 11, elem, scale);
  images->boutonNiveau12On = genererBoutonMenu(NIVEAU, ON, 12, elem, scale);
  images->boutonNiveau13On = genererBoutonMenu(NIVEAU, ON, 13, elem, scale);
  images->boutonNiveau14On = genererBoutonMenu(NIVEAU, ON, 14, elem, scale);
  images->boutonNiveau15On = genererBoutonMenu(NIVEAU, ON, 15, elem, scale);
  images->boutonNiveau16On = genererBoutonMenu(NIVEAU, ON, 16, elem, scale);
  images->boutonNiveau17On = genererBoutonMenu(NIVEAU, ON, 17, elem, scale);
  images->boutonNiveau18On = genererBoutonMenu(NIVEAU, ON, 18, elem, scale);
  images->boutonNiveau19On = genererBoutonMenu(NIVEAU, ON, 19, elem, scale);
  images->boutonNiveau20On = genererBoutonMenu(NIVEAU, ON, 20, elem, scale);
  images->boutonNiveau21On = genererBoutonMenu(NIVEAU, ON, 21, elem, scale);
  images->boutonNiveau22On = genererBoutonMenu(NIVEAU, ON, 22, elem, scale);
  images->boutonNiveau23On = genererBoutonMenu(NIVEAU, ON, 23, elem, scale);
  images->boutonNiveau24On = genererBoutonMenu(NIVEAU, ON, 24, elem, scale);
  images->boutonNiveau25On = genererBoutonMenu(NIVEAU, ON, 25, elem, scale);
  images->boutonNiveau26On = genererBoutonMenu(NIVEAU, ON, 26, elem, scale);
  images->boutonNiveau27On = genererBoutonMenu(NIVEAU, ON, 27, elem, scale);
  images->boutonNiveau28On = genererBoutonMenu(NIVEAU, ON, 28, elem, scale);
  images->boutonNiveau29On = genererBoutonMenu(NIVEAU, ON, 29, elem, scale);
  images->boutonNiveau30On = genererBoutonMenu(NIVEAU, ON, 30, elem, scale);

  images->fondMenuAide = genererFondMenuAide(elem, true, scale);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectBAideOk, scale);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectBAideOk, scale);

  return images; //on renvoit le pack d'images
}

ALLEGRO_BITMAP *genererFondMenu(elements *elem, float scale)
{
  //on crée une image aux dimensions de l'écran dans laquelle on va dessiner le menu Principal
  ALLEGRO_BITMAP *fondMenu = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
  al_set_target_bitmap(fondMenu); //on cible l'image crée pour le dessin
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
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

  rect = elem->rectBMenuJouer;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBMenuNiveau;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBMenuMode;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectScores;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBMenuAide;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBMenuOptions;
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
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + (48 * scale), rect->x2 - rect->t, rect->y + (rect->t * 2) + (48 * scale), bleuInactif); //première
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - (48 * scale), rect->x2 - rect->t,  rect->y2 - rect->t - (48 * scale), bleuInactif); //deuxième
  //fonds
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + (48 * scale), bleuFond); //niveau
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + (48 * scale), rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - (48* scale), bleuFond); //score
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - (48 * scale), rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

  //maintenant on va écrire dans les cases du rectNSL
  al_init_font_addon(); //on initie l'addon de police de caractères
  al_init_ttf_addon(); //on initie l'addon "ttf"

  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y + rect->t + (9 * scale), 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
  al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), 0, "SCORE"); //affiche le mot "score" dans la case correspondante
  al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

  //on libère la mémoire
  al_destroy_font(font);

  return fondMenu; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererHigh(int modeDeJeu, elements *elem, float scale)
{
  //on crée une image aux dimensions du panneau de score
  ALLEGRO_BITMAP *panneau = al_create_bitmap(elem->rectScores->w - (elem->rectScores->t * 2), elem->rectScores->h - (elem->rectScores->t * 2));
  al_set_target_bitmap(panneau); //on cible l'image créée pour le dessin
  al_clear_to_color(al_map_rgb(219, 237, 255)); //on remplit le fond de blanc

  //puis dans le rectangle du high score
  ALLEGRO_COLOR ligneFoncee = al_map_rgb(186, 201, 228);
  ALLEGRO_COLOR ligneClaire = al_map_rgb(198, 214, 237);
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (20 * scale), 0);
  //string dans lesquels on va recueillir les scores
  char J[5][4]; //va stocker le nom des joueurs
  char S[5][7]; //va stocker les scores, les temps ou les lignes

  switch(modeDeJeu)
  {
    case MARATHON:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, (9 * scale), ALLEGRO_ALIGN_CENTRE, "HIGH SCORES");
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
      font = al_load_ttf_font("media_files/Gameplay.ttf", (17 * scale), 0);
      al_draw_filled_rectangle((3 * scale), (44 * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + 30) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[0]);
      al_draw_filled_rectangle((3 * scale), ((44 + 30 + 2) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (2 * 30) + 2) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[1]);
      al_draw_filled_rectangle((3 * scale), ((44 + (2 * 30) + (2 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (3 * 30) + (2 * 2)) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[2]);
      al_draw_filled_rectangle((3 * scale), ((44 + (3 * 30) + (3 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (4 * 30) + (3 * 2)) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[3]);
      al_draw_filled_rectangle((3 * scale), ((44 + (4 * 30) + (4 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (5 * 30) + (4 * 2))* scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[4]);
      break;
    case SPRINT:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, (9 * scale), ALLEGRO_ALIGN_CENTRE, "BEST TIMES");
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
      font = al_load_ttf_font("media_files/Gameplay.ttf", (17 * scale), 0);
      al_draw_filled_rectangle((3 * scale), (44 * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + 30) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_RIGHT, strTime[0]);
      al_draw_filled_rectangle((3 * scale), ((44 + 30 + 2) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (2 * 30) + 2) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_RIGHT, strTime[1]);
      al_draw_filled_rectangle((3 * scale), ((44 + (2 * 30) + (2 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (3 * 30) + (2 * 2)) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, strTime[2]);
      al_draw_filled_rectangle((3 * scale), ((44 + (3 * 30) + (3 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (4 * 30) + (3 * 2)) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, strTime[3]);
      al_draw_filled_rectangle((3 * scale), ((44 + (4 * 30) + (4 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (5 * 30) + (4 * 2))* scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, strTime[4]);
      break;
    case ULTRA:
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2))/2, (9 * scale), ALLEGRO_ALIGN_CENTRE, "BEST LINES");
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
      font = al_load_ttf_font("media_files/Gameplay.ttf", (17 * scale), 0);
      al_draw_filled_rectangle((3 * scale), (44 * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + 30) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[0]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[0]);
      al_draw_filled_rectangle((3 * scale), ((44 + 30 + 2) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (2 * 30) + 2) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_LEFT, J[1]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + 30 + 2 + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[1]);
      al_draw_filled_rectangle((3 * scale), ((44 + (2 * 30) + (2 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (3 * 30) + (2 * 2)) * scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[2]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (2 * 30) + (2 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[2]);
      al_draw_filled_rectangle((3 * scale), ((44 + (3 * 30) + (3 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (4 * 30) + (3 * 2)) * scale), ligneClaire);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[3]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (3 * 30) + (3 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[3]);
      al_draw_filled_rectangle((3 * scale), ((44 + (4 * 30) + (4 * 2)) * scale), (elem->rectScores->w - (elem->rectScores->t * 2)) - (3 * scale), ((44 + (5 * 30) + (4 * 2))* scale), ligneFoncee);
      al_draw_text(font, bleuActif, (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_LEFT, J[4]);
      al_draw_text(font, bleuActif, (elem->rectScores->w - (elem->rectScores->t * 2)) - (8 * scale), ((44 + (4 * 30) + (4 * 2) + 4) * scale), ALLEGRO_ALIGN_RIGHT, S[4]);
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  return panneau;
}

ALLEGRO_BITMAP *genererBoutonMenu(int typeDeBouton, int onOff, int niveau, elements *elem, float scale)
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
      rect = elem->rectBMenuJouer;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (45 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "jouer" en noir au milieu de l'image
      al_draw_text(font, al_map_rgb(0, 0, 0), ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (28 * scale), ALLEGRO_ALIGN_CENTRE, "JOUER");
      break;
    case MARATHON:
      rect = elem->rectBMenuMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "MARATHON" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "MARATHON");
      break;
    case SPRINT:
      rect = elem->rectBMenuMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "SPRINT" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "SPRINT");
      break;
    case ULTRA:
      rect = elem->rectBMenuMode;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "ULTRA" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "ULTRA");
      break;
    case AIDE:
      rect = elem->rectBMenuAide;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "?");
      break;
    case OPTIONS:
      rect = elem->rectBMenuOptions;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      //on établie l'image à charger dans le bouton en fonction de onOff
      ALLEGRO_BITMAP *options = NULL;
      if(onOff == ON)
      {
        options = al_load_bitmap("media_files/optionsOn.png");
      }
      else if(onOff == OFF)
      {
        options = al_load_bitmap("media_files/optionsOff.png");
      }
      al_draw_bitmap(options, (((rect->w - (rect->t * 2))/2) - (al_get_bitmap_width(options)/2)), (((rect->h - (rect->t * 2))/2) - (al_get_bitmap_height(options)/2)), 0);
      al_destroy_bitmap(options);
      break;
    case NIVEAU:
      rect = elem->rectBMenuNiveau;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
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
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, stringNiveau);
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

packPartie *genererPackPartie(elements *elem, int modeDeJeu, float scale)
{
  //on crée un pointeur vers la structure d'images
  packPartie *images = malloc(sizeof(packPartie));

  //puis on initie chacune des images
  images->fondPartie = genererFondPartie(elem, modeDeJeu, scale);
  images->gridBuffer = genererGridBuffer(elem);

  for(int i = 0; i < GRID_W; i++)
  {
    for(int j = 0; j < GRID_H; j++)
    {
      images->buffingGrid[i][j] = false;
    }
  }

  //on crée l'image de "ligneDisp"
  images->ligneBlanche = genererLigneBlanche(scale);

  //on crée un pointeur vers la structure packPause
  packPause *imagesPause = malloc(sizeof(packPause));
  images->imagesPause = imagesPause;

  //puis on génère les images du menu pause
  images->imagesPause->fondPause = genererFondPause(elem, images->fondPartie, scale);
  images->imagesPause->boutonReprendreOff = genererBoutonPause(REPRENDRE, OFF, elem, scale);
  images->imagesPause->boutonReprendreOn = genererBoutonPause(REPRENDRE, ON, elem, scale);
  images->imagesPause->boutonAideOff = genererBoutonPause(AIDE, OFF, elem, scale);
  images->imagesPause->boutonAideOn = genererBoutonPause(AIDE, ON, elem, scale);
  images->imagesPause->boutonOptionsOff = genererBoutonPause(OPTIONS, OFF, elem, scale);
  images->imagesPause->boutonOptionsOn = genererBoutonPause(OPTIONS, ON, elem, scale);
  images->imagesPause->boutonQuitterOff = genererBoutonPause(QUITTER, OFF, elem, scale);
  images->imagesPause->boutonQuitterOn = genererBoutonPause(QUITTER, ON, elem, scale);

  images->imagesPause->fondMenuAide = genererFondMenuAide(elem, false, scale);
  images->imagesPause->boutonOkOff = genererBoutonOk(OFF, elem->rectBAideOk, scale);
  images->imagesPause->boutonOkOn = genererBoutonOk(ON, elem->rectBAideOk, scale);

  //on crée un pointeur vers la structure ghostPiece
  packGhost *ghostPiece = malloc(sizeof(packGhost));
  images->ghostPiece = ghostPiece;

  //puis on initie chacune des images
  images->ghostPiece->jauneo = genererGhostPiece(JAUNE_O, POS1, images, scale);
  images->ghostPiece->cyaniPOS1 = genererGhostPiece(CYAN_I, POS1, images, scale);
  images->ghostPiece->cyaniPOS2 = genererGhostPiece(CYAN_I, POS2, images, scale);
  images->ghostPiece->cyaniPOS3 = genererGhostPiece(CYAN_I, POS3, images, scale);
  images->ghostPiece->cyaniPOS4 = genererGhostPiece(CYAN_I, POS4, images, scale);
  images->ghostPiece->rougezPOS1 = genererGhostPiece(ROUGE_Z, POS1, images, scale);
  images->ghostPiece->rougezPOS2 = genererGhostPiece(ROUGE_Z, POS2, images, scale);
  images->ghostPiece->rougezPOS3 = genererGhostPiece(ROUGE_Z, POS3, images, scale);
  images->ghostPiece->rougezPOS4 = genererGhostPiece(ROUGE_Z, POS4, images, scale);
  images->ghostPiece->vertsPOS1 = genererGhostPiece(VERT_S, POS1, images, scale);
  images->ghostPiece->vertsPOS2 = genererGhostPiece(VERT_S, POS2, images, scale);
  images->ghostPiece->vertsPOS3 = genererGhostPiece(VERT_S, POS3, images, scale);
  images->ghostPiece->vertsPOS4 = genererGhostPiece(VERT_S, POS4, images, scale);
  images->ghostPiece->mauvetPOS1 = genererGhostPiece(MAUVE_T, POS1, images, scale);
  images->ghostPiece->mauvetPOS2 = genererGhostPiece(MAUVE_T, POS2, images, scale);
  images->ghostPiece->mauvetPOS3 = genererGhostPiece(MAUVE_T, POS3, images, scale);
  images->ghostPiece->mauvetPOS4 = genererGhostPiece(MAUVE_T, POS4, images, scale);
  images->ghostPiece->orangelPOS1 = genererGhostPiece(ORANGE_L, POS1, images, scale);
  images->ghostPiece->orangelPOS2 = genererGhostPiece(ORANGE_L, POS2, images, scale);
  images->ghostPiece->orangelPOS3 = genererGhostPiece(ORANGE_L, POS3, images, scale);
  images->ghostPiece->orangelPOS4 = genererGhostPiece(ORANGE_L, POS4, images, scale);
  images->ghostPiece->violetjPOS1 = genererGhostPiece(VIOLET_J, POS1, images, scale);
  images->ghostPiece->violetjPOS2 = genererGhostPiece(VIOLET_J, POS2, images, scale);
  images->ghostPiece->violetjPOS3 = genererGhostPiece(VIOLET_J, POS3, images, scale);
  images->ghostPiece->violetjPOS4 = genererGhostPiece(VIOLET_J, POS4, images, scale);

  return images; //on renvoit le pack d'images
}

void destroyPackPartie(packPartie *images)
{
  //on détruit chacune des images
  al_destroy_bitmap(images->fondPartie);
  al_destroy_bitmap(images->gridBuffer);
  al_destroy_bitmap(images->ligneBlanche);

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

ALLEGRO_BITMAP *genererFondPartie(elements *elem, int modeDeJeu, float scale)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner la partie
  ALLEGRO_BITMAP *fondPartie = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
  al_set_target_bitmap(fondPartie); //on cible l'image crée pour le dessin
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
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
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + (48 * scale), rect->x2 - rect->t, rect->y + (rect->t * 2) + (48 * scale), bleuActif); //première
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - (48 * scale), rect->x2 - rect->t,  rect->y2 - rect->t - (48 * scale), bleuActif); //deuxième
  //fonds
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + (48 * scale), bleuFond); //niveau
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + (48 * scale), rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - (48* scale), bleuFond); //score
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - (48 * scale), rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y + rect->t + (9 * scale), 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
  al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), 0, "SCORE"); //affiche le mot "score" dans la case correspondante
  al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante


  if(modeDeJeu == SPRINT || modeDeJeu == ULTRA)
  {
    //on dessine le carde du Timer
    rect = elem->rectTemps;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);
    al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y + rect->t + (9 * scale), 0, "TIMER"); //affiche le mot "TIMER" dans la case correspondante
  }

  //on libère la mémoire
  al_destroy_font(font);

  return fondPartie; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererGridBuffer(elements *elem)
{
  //l'image va faire systématiquement un peu plus que la taille précise de l'intérieur du cadre principal
  ALLEGRO_BITMAP *grid = al_create_bitmap(ceil(elem->rectPrincipal->w - (elem->rectPrincipal->t * 2)), ceil(elem->rectPrincipal->h - (elem->rectPrincipal->t * 2)));
  al_set_target_bitmap(grid);
  al_clear_to_color(al_map_rgb(0, 0, 0)); //on remplit de noir pour les barres de la grille
  return grid; //on renvoit l'image
}

ALLEGRO_BITMAP *genererLigneBlanche(float scale)
{
  ALLEGRO_BITMAP *ligne = al_create_bitmap(ceil(283 * scale), ceil(31 * scale));
  al_set_target_bitmap(ligne);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  float x = 3 * scale, y = 3 * scale;
  for(int i = 0; i < 10; i++)
  {
    drawBlock(BLANC, x, y, scale);
    x += 28 * scale;
  }
  return ligne;
}

ALLEGRO_BITMAP *genererFondPause(elements *elem, ALLEGRO_BITMAP *fondPartie, float scale)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner la pause
  ALLEGRO_BITMAP *fondPause = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
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

  rect = elem->rectBPauseReprendre;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBPauseAide;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBPauseOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBPauseQuitter;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maintenant on va écrire "Pause" dans le rectPause
  rect = elem->rectPause;
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (45 * scale), 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + (28 * scale), ALLEGRO_ALIGN_CENTRE, "PAUSE");

  //on libère la mémoire
  al_destroy_font(font);

  return fondPause; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererBoutonPause(int typeDeBouton, int onOff, elements *elem, float scale)
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
      rect = elem->rectBPauseReprendre;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "jouer" en noir au milieu de l'image
      al_draw_text(font, al_map_rgb(0, 0, 0), ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "REPRENDRE");
      break;
    case AIDE:
      rect = elem->rectBPauseAide;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "AIDE");
      break;
    case OPTIONS:
      rect = elem->rectBPauseOptions;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "OPTIONS");
      break;
    case QUITTER:
      rect = elem->rectBPauseQuitter;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (20 * scale), ALLEGRO_ALIGN_CENTRE, "QUITTER");
      break;
  }

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

ALLEGRO_BITMAP *genererGhostPiece(int typeDeBloc, int position, packPartie *images, float scale)
{
  //on crée l'image
  ALLEGRO_BITMAP *ghost = al_create_bitmap(115 * scale, 115 * scale);
  al_set_target_bitmap(ghost); //on la cible
  al_clear_to_color(al_map_rgb(0, 0, 0)); //on met un fond noir

  //on génère un packTetro pour dessiner les ghost
  packTetro *tetros = chargerTetrominos();

  //on détermine le type de bloc à utiliser pour le dessin
  float pos[2] = {0, 0};
  switch(typeDeBloc)
  {
    case JAUNE_O:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_jaune_O[position][x][y] != VIDE)
            drawBlock(JAUNE, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case CYAN_I:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_cyan_I[position][x][y] != VIDE)
            drawBlock(CYAN, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case MAUVE_T:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_mauve_T[position][x][y] != VIDE)
            drawBlock(MAUVE, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case VIOLET_J:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_violet_J[position][x][y] != VIDE)
            drawBlock(VIOLET, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case ORANGE_L:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_orange_L[position][x][y] != VIDE)
            drawBlock(ORANGE, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case VERT_S:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_vert_S[position][x][y] != VIDE)
            drawBlock(VERT, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
    case ROUGE_Z:
      pos[Y] = (3 * scale);
      for(int y = 0; y < 4; y++)
      {
        pos[X] = (3 * scale);
        for(int x = 0; x < 4; x++)
        {
          if(tetros->p_rouge_Z[position][x][y] != VIDE)
            drawBlock(ROUGE, pos[X], pos[Y], scale);
          pos[X] += (28 * scale);
        }
        pos[Y] += (28 * scale);
      }
      break;
  }

  //on libère la mémoire
  destroyTetrominos(tetros);

  return ghost; //CETTE FOIS, ON A PAS OUBLIE, C'EST BIIIIIIIIIIIIEN
}

ALLEGRO_BITMAP *genererBoutonOk(int onOff, coord *rectOk, float scale)
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
  font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
  //on écrit "OK" en bleu au milieu de l'image
  al_draw_text(font, bleuActif, ((rectOk->x2 - rectOk->x - (rectOk->t * 2))/2), ((rectOk->y2 - rectOk->y - (rectOk->t * 2))/2) - (15 * scale), ALLEGRO_ALIGN_CENTRE, "OK");

  //on libère la mémoire
  al_destroy_font(font);

  //on revoit le bouton généré
  return bouton;
}

ALLEGRO_BITMAP *genererFondMenuAide(elements *elem, bool menu, float scale)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner le menu d'Aide
  ALLEGRO_BITMAP *fondAide = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
  al_set_target_bitmap(fondAide); //on cible l'image crée pour le dessin
  ALLEGRO_FONT *font = NULL; //pointeur dans lequel on va charger notre police d'écriture
  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuInactif = al_map_rgb(137, 154, 192); //couleur de la partie inactive de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  if(menu)
  {
    rect = elem->rectPrincipal;
    //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
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
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + (48 * scale), rect->x2 - rect->t, rect->y + (rect->t * 2) + (48 * scale), bleuInactif); //première
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - (48 * scale), rect->x2 - rect->t,  rect->y2 - rect->t - (48 * scale), bleuInactif); //deuxième
    //fonds
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + (48 * scale), bleuFond); //niveau
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + (48 * scale), rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - (48* scale), bleuFond); //score
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - (48 * scale), rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

    ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y + rect->t + (9 * scale), 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
    al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), 0, "SCORE"); //affiche le mot "score" dans la case correspondante
    al_draw_text(font, bleuInactif, rect->x + rect->t + (10 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

    rect = elem->rectAide;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgb(219, 237, 255));

    rect = elem->rectBAideOk;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    //maitenant qu'on a fini de dessiner le fond, on écrit les commandes une à une
    //d'abord le titre du cadre
    rect = elem->rectAide;
    font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (15 * scale), ALLEGRO_ALIGN_CENTRE, "CONTROLES");

    //puis les commandes du jeu
    font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (1 * 20 * scale), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (2 * 20 * scale) + (1 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (3 * 20 * scale) + (1 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (4 * 20 * scale) + (2 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE HAUTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (5 * 20 * scale) + (2 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "ROTATION DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (6 * 20 * scale) + (3 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE BASSE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (7 * 20 * scale) + (3 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "SOFT DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (8 * 20 * scale) + (4 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "CTRL - ROTATION GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (9 * 20 * scale) + (5 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "ESPACE - HARD DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (10 * 20 * scale) + (6 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "G - FONCTION GHOST");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (11 * 20 * scale) + (7 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "MAJ - PIECE SUIVANTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (12 * 20 * scale) + (8 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "P - PAUSE");
  }
  else //si on est dans la partie
  {
    rect = elem->rectPrincipal;
    //on met un filtre bleu dans la grille (CA FAIT JOLI AUSSI)
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgba(80, 80, 255, 122));
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    rect = elem->rectPieceSuiv;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

    rect = elem->rectNSL;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //barre horizontales milieu
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t + (48 * scale), rect->x2 - rect->t, rect->y + (rect->t * 2) + (48 * scale), bleuActif); //première
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - (rect->t * 2) - (48 * scale), rect->x2 - rect->t,  rect->y2 - rect->t - (48 * scale), bleuActif); //deuxième
    //fonds
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t,  rect->y + rect->t + (48 * scale), bleuFond); //niveau
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + (rect->t * 2) + (48 * scale), rect->x2 - rect->t,  rect->y2 - (rect->t * 2) - (48* scale), bleuFond); //score
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t - (48 * scale), rect->x2 - rect->t, rect->y2 - rect->t, bleuFond); //lignes

    ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y + rect->t + (9 * scale), 0, "NIVEAU"); //affiche le mot "niveau" dans la case correspondante
    al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y + (rect->t * 2) + (48 * scale) + (9 * scale), 0, "SCORE"); //affiche le mot "score" dans la case correspondante
    al_draw_text(font, bleuActif, rect->x + rect->t + (10 * scale), rect->y2 - rect->t - (48 * scale) + (9 * scale), 0, "LIGNES"); //affiche le mot "lignes" dans la case correspondante

    rect = elem->rectAide;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
    //fond du rectangle
    al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, al_map_rgb(219, 237, 255));

    rect = elem->rectBAideOk;
    al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
    al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
    al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
    al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

    //maitenant qu'on a fini de dessiner le fond, on écrit les commandes une à une
    //d'abord le titre du cadre
    rect = elem->rectAide;
    font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (15 * scale), ALLEGRO_ALIGN_CENTRE, "CONTROLES");

    //puis les commandes du jeu
    font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Gameplay"
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (1 * 20 * scale), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (2 * 20 * scale) + (1 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (3 * 20 * scale) + (1 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "MOUVEMENT A DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (4 * 20 * scale) + (2 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE HAUTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (5 * 20 * scale) + (2 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "ROTATION DROITE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (6 * 20 * scale) + (3 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "FLECHE BASSE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (7 * 20 * scale) + (3 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "SOFT DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (8 * 20 * scale) + (4 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "CTRL - ROTATION GAUCHE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (9 * 20 * scale) + (5 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "ESPACE - HARD DROP");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (10 * 20 * scale) + (6 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "G - FONCTION GHOST");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (11 * 20 * scale) + (7 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "MAJ - PIECE SUIVANTE");
    al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (65 * scale) + (12 * 20 * scale) + (8 * 10 * scale), ALLEGRO_ALIGN_CENTRE, "P - PAUSE");
  }

  //on libère la mémoire
  al_destroy_font(font);

  return fondAide; //on renvoit l'image créée
}

packOptions *genererPackOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3], float scale)
{
  //on crée un pointeur vers la structure d'images
  packOptions *images = malloc(sizeof(packOptions));

  //puis on initie chacune des images
  images->fondOptions = genererFondOptions(elem, fondPrecedent, 0, scale);
  images->boutonOkOff = genererBoutonOptions(OK, OFF, elem, keyMap, scale);
  images->boutonOkOn = genererBoutonOptions(OK, ON, elem, keyMap, scale);
  images->inputrotaterOff = genererBoutonOptions(IROTATER, OFF, elem, keyMap, scale);
  images->inputrotaterOn = genererBoutonOptions(IROTATER, ON, elem, keyMap, scale);
  images->inputsoftdOff = genererBoutonOptions(ISOFTD, OFF, elem, keyMap, scale);
  images->inputsoftdOn = genererBoutonOptions(ISOFTD, ON, elem, keyMap, scale);
  images->inputleftOff = genererBoutonOptions(ILEFT, OFF, elem, keyMap, scale);
  images->inputleftOn = genererBoutonOptions(ILEFT, ON, elem, keyMap, scale);
  images->inputrightOff = genererBoutonOptions(IRIGHT, OFF, elem, keyMap, scale);
  images->inputrightOn = genererBoutonOptions(IRIGHT, ON, elem, keyMap, scale);
  images->inputharddOff = genererBoutonOptions(IHARDD, OFF, elem, keyMap, scale);
  images->inputharddOn = genererBoutonOptions(IHARDD, ON, elem, keyMap, scale);
  images->inputrotatelOff = genererBoutonOptions(IROTATEL, OFF, elem, keyMap, scale);
  images->inputrotatelOn = genererBoutonOptions(IROTATEL, ON, elem, keyMap, scale);
  images->inputpauseOff = genererBoutonOptions(IPAUSE, OFF, elem, keyMap, scale);
  images->inputpauseOn = genererBoutonOptions(IPAUSE, ON, elem, keyMap, scale);
  images->inputghostOff = genererBoutonOptions(IGHOST, OFF, elem, keyMap, scale);
  images->inputghostOn = genererBoutonOptions(IGHOST, ON, elem, keyMap, scale);
  images->inputchangeOff = genererBoutonOptions(ICHANGE, OFF, elem, keyMap, scale);
  images->inputchangeOn = genererBoutonOptions(ICHANGE, ON, elem, keyMap, scale);
  images->boutonVolThemeMOff = genererBoutonOptions(VOLTHEMEM, OFF, elem, keyMap, scale);
  images->boutonVolThemeMOn = genererBoutonOptions(VOLTHEMEM, ON, elem, keyMap, scale);
  images->boutonVolThemePOff = genererBoutonOptions(VOLTHEMEP, OFF, elem, keyMap, scale);
  images->boutonVolThemePOn = genererBoutonOptions(VOLTHEMEP, ON, elem, keyMap, scale);
  images->boutonVolFXMOff = genererBoutonOptions(VOLFXM, OFF, elem, keyMap, scale);
  images->boutonVolFXMOn = genererBoutonOptions(VOLFXM, ON, elem, keyMap, scale);
  images->boutonVolFXPOff = genererBoutonOptions(VOLFXP, OFF, elem, keyMap, scale);
  images->boutonVolFXPOn = genererBoutonOptions(VOLFXP, ON, elem, keyMap, scale);
  images->boutonResetOff = genererBoutonOptions(RESET, OFF, elem, keyMap, scale);
  images->boutonResetOn = genererBoutonOptions(RESET, ON, elem, keyMap, scale);

  images->fondInputOptions = genererFondInputOptions(elem, images->fondOptions, scale);
  images->boutonOkInpOptOff = genererBoutonInputOptions(OKINPOPT, OFF, elem, scale);
  images->boutonOkInpOptOn = genererBoutonInputOptions(OKINPOPT, ON, elem, scale);
  images->touche1Off = genererBoutonInputOptions(TOUCHE1, OFF, elem, scale);
  images->touche1On = genererBoutonInputOptions(TOUCHE1, ON, elem, scale);
  images->touche2Off = genererBoutonInputOptions(TOUCHE2, OFF, elem, scale);
  images->touche2On = genererBoutonInputOptions(TOUCHE2, ON, elem, scale);
  images->touche3Off = genererBoutonInputOptions(TOUCHE3, OFF, elem, scale);
  images->touche3On = genererBoutonInputOptions(TOUCHE3, ON, elem, scale);

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

ALLEGRO_BITMAP *genererFondOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, int recharge, float scale)
{
  //on crée un image aux dimensions de l'écran dans lequel on va dessiner le menu d'options
  ALLEGRO_BITMAP *fondOptions = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
  al_set_target_bitmap(fondOptions); //on cible l'image crée pour le dessin
  if(fondPrecedent != NULL)
    al_draw_bitmap(fondPrecedent, 0, 0, 0); //on dessine le fond précédent le menu d'options (donc le menu principal ou la pause)

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Gameplay"

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectBOptionsOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectIOptionsRotater;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "ROTATION DROITE");

  rect = elem->rectIOptionsSoftd;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "SOFT DROP");

  rect = elem->rectIOptionsLeft;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "MOUVEMENT GAUCHE");

  rect = elem->rectIOptionsRight;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "MOUVEMENT DROITE");

  rect = elem->rectIOptionsHardd;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "HARD DROP");

  rect = elem->rectIOptionsRotatel;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "ROTATION GAUCHE");

  rect = elem->rectIOptionsPause;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "PAUSE");

  rect = elem->rectIOptionsGhost;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "PIECE FANTOME");

  rect = elem->rectIOptionsChange;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "PIECE SUIVANTE");

  rect = elem->rectBOptionsVolThemeM;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "VOLUME DU THEME");

  rect = elem->rectBOptionsVolThemeP;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBOptionsVolFXM;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectOptions->x + (11 * scale), rect->y, 0, "VOLUME DES FX");

  rect = elem->rectBOptionsVolFXP;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectBOptionsReset;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maintenant on va écrire "OPTIONS" dans le rectPrincipal
  rect = elem->rectOptions;
  font = al_load_ttf_font("media_files/Gameplay.ttf", (45 * scale), 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, ((rect->x2 - rect->x)/2) + rect->x, rect->y + (28 * scale), ALLEGRO_ALIGN_CENTRE, "OPTIONS");

  //on libère la mémoire
  al_destroy_font(font);

  return fondOptions; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererFondInputOptions(elements *elem, ALLEGRO_BITMAP *fondPrecedent, float scale)
{
  //on crée un image aux dimensions de l'écran dans laquelle on va dessiner l'inputOptions
  ALLEGRO_BITMAP *fondInputOptions = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale);
  al_set_target_bitmap(fondInputOptions); //on cible l'image crée pour le dessin
  al_draw_bitmap(fondPrecedent, 0, 0, 0); //on dessine le fond précédent

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway"

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectInputOptions;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectBInputOptionsOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  rect = elem->rectIInputOptionsTouche1;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + (11 * scale), rect->y, 0, "TOUCHE 1");

  rect = elem->rectIInputOptionsTouche2;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + (11 * scale), rect->y, 0, "TOUCHE 2");

  rect = elem->rectIInputOptionsTouche3;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  al_draw_text(font, bleuActif, elem->rectInputOptions->x + (11 * scale), rect->y, 0, "TOUCHE 3");

  //on libère la mémoire
  al_destroy_font(font);

  return fondInputOptions; //on renvoit l'image créée
}

ALLEGRO_BITMAP *genererBoutonOptions(int typeDeBouton, int onOff, elements *elem, int keyMap[16][3], float scale)
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
      rect = elem->rectBOptionsOk;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit OK en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (18 * scale), ALLEGRO_ALIGN_CENTRE, "OK");
      break;
    case IROTATER:
      rect = elem->rectIOptionsRotater;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ISOFTD:
      rect = elem->rectIOptionsSoftd;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ILEFT:
      rect = elem->rectIOptionsLeft;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IRIGHT:
      rect = elem->rectIOptionsRight;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IHARDD:
      rect = elem->rectIOptionsHardd;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IROTATEL:
      rect = elem->rectIOptionsRotatel;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IPAUSE:
      rect = elem->rectIOptionsPause;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case IGHOST:
      rect = elem->rectIOptionsGhost;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case ICHANGE:
      rect = elem->rectIOptionsChange;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Raleway-Bold.ttf", (15 * scale), 0); //on charge la police "Raleway-Bold"
      strTouche(typeDeBouton, keyMap, str);
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, str);
      break;
    case VOLTHEMEM:
      rect = elem->rectBOptionsVolThemeM;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (15 *scale), 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "-");
      break;
    case VOLTHEMEP:
      rect = elem->rectBOptionsVolThemeP;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (15 *scale), 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "+");
      break;
    case VOLFXM:
      rect = elem->rectBOptionsVolFXM;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (15 *scale), 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "-");
      break;
    case VOLFXP:
      rect = elem->rectBOptionsVolFXP;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (15 *scale), 0); //on charge la police "Raleway-Bold"
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), 0, ALLEGRO_ALIGN_CENTRE, "+");
      break;
    case RESET:
      rect = elem->rectBOptionsReset;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", 30 * scale, 0); //on charge la police "Gameplay"
      //on écrit le mot "aide" en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (18 * scale), ALLEGRO_ALIGN_CENTRE, "RESET");
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

ALLEGRO_BITMAP *genererBoutonInputOptions(int typeDeBouton, int onOff, elements *elem, float scale)
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
      rect = elem->rectBInputOptionsOk;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      font = al_load_ttf_font("media_files/Gameplay.ttf", (30 * scale), 0); //on charge la police "Gameplay"
      //on écrit OK en bleu au milieu de l'image
      al_draw_text(font, bleuActif, ((rect->x2 - rect->x - (rect->t * 2))/2), ((rect->y2 - rect->y - (rect->t * 2))/2) - (18 * scale), ALLEGRO_ALIGN_CENTRE, "OK");
      break;
    case TOUCHE1:
      rect = elem->rectIInputOptionsTouche1;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      break;
    case TOUCHE2:
      rect = elem->rectIInputOptionsTouche2;
      //on crée la surface intérieure du bouton
      bouton = al_create_bitmap((rect->x2 - rect->x - (rect->t * 2)), (rect->y2 - rect->y - (rect->t * 2)));
      al_set_target_bitmap(bouton); //on cible l'image du bouton pour dessiner dessus
      al_clear_to_color(couleurDeFond); //on remplie par la couleur déterminée au-dessus
      break;
    case TOUCHE3:
      rect = elem->rectIInputOptionsTouche3;
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

packSTLInput *genererPackSTLInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score, int modeDeJeu, float scale)
{
  packSTLInput *images = malloc(sizeof(packSTLInput));

  images->fond = genererFondSTLInput(fondPrecedent, elem, score, modeDeJeu, scale);
  images->boutonOkOff = genererBoutonOk(OFF, elem->rectBSTLOk, scale);
  images->boutonOkOn = genererBoutonOk(ON, elem->rectBSTLOk, scale);

  return images; //on revoit la structure d'images
}

void destroyPackSTLInput(packSTLInput *images)
{
  al_destroy_bitmap(images->fond);
  al_destroy_bitmap(images->boutonOkOff);
  al_destroy_bitmap(images->boutonOkOn);
  free(images);
}

ALLEGRO_BITMAP *genererFondSTLInput(ALLEGRO_BITMAP *fondPrecedent, elements *elem, int score, int modeDeJeu, float scale)
{
  ALLEGRO_BITMAP *fond = al_create_bitmap(SCREEN_W * scale, SCREEN_H * scale); //on crée l'image de fond
  al_set_target_bitmap(fond); //on cible l'image créée
  if(fondPrecedent != NULL) //dans le cas où c'est la première fois qu'on génère le pack
    al_draw_bitmap(fondPrecedent, 0, 0, 0); //on copie l'écran de fin de partie

  ALLEGRO_COLOR bleuActif = al_map_rgb(104, 120, 166); //couleur de la partie active de la fenêtre
  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  ALLEGRO_COLOR fondInput = al_map_rgb(162, 195, 232); //fond de la zone d'input

  //on crée un pointeur pour raccourcir l'écriture de "elem->rectX->n"
  coord *rect = NULL;

  rect = elem->rectSTLInput;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, bleuFond);

  rect = elem->rectISTLInput;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse
  //fond du rectangle
  al_draw_filled_rectangle(rect->x + rect->t, rect->y + rect->t, rect->x2 - rect->t, rect->y2 - rect->t, fondInput);

  rect = elem->rectBSTLOk;
  al_draw_filled_rectangle(rect->x, rect->y, rect->x + rect->t, rect->y2, bleuActif); //barre verticale gauche
  al_draw_filled_rectangle(rect->x2 - rect->t, rect->y, rect->x2, rect->y2, bleuActif); //barre verticale droite
  al_draw_filled_rectangle(rect->x + rect->t, rect->y, rect->x2 - rect->t, rect->y + rect->t, bleuActif); //barre horizontale haute
  al_draw_filled_rectangle(rect->x + rect->t, rect->y2 - rect->t, rect->x2 - rect->t, rect->y2, bleuActif); //barre horizontale basse

  //maitenant qu'on a fini de dessiner le fond, on va écrire dans le cadre
  rect = elem->rectSTLInput; //on se place au bon endroit
  ALLEGRO_FONT *font = al_load_ttf_font("media_files/Gameplay.ttf", (25 * scale), 0); //on charge la police "Gameplay"
  //on déclare les string dont on va se servir pour écrire dans le cadre
  char strScore[7], strTemps[9], strLignes[9];
  //puis les int
  int minutes, secondes, dixiemes;

  //on détermine le mode de jeu
  switch(modeDeJeu)
  {
    case MARATHON: //si on est en mode marathon
      al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (30 * scale), ALLEGRO_ALIGN_CENTRE, "NOUVEAU SCORE!");
      sprintf(strScore, "%d", score); //on transforme le int de score en string
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + (75 * scale), ALLEGRO_ALIGN_CENTRE, strScore);
      break;
    case SPRINT: //si on est en mode sprint
      al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (30 * scale), ALLEGRO_ALIGN_CENTRE, "NOUVEAU TEMPS!");
      minutes = (score/3600);
      secondes = ((score % 3600)/60);
      dixiemes = ((score % 60)/6);
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
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + (75 * scale), ALLEGRO_ALIGN_CENTRE, strTemps);
      break;
    case ULTRA: //si on est en mode ultra
      al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (30 * scale), ALLEGRO_ALIGN_CENTRE, "NOUVEAU SCORE!");
      sprintf(strLignes, "%d", score);
      al_draw_text(font, al_map_rgb(0, 0, 0), rect->x + ((rect->x2 - rect->x)/2), rect->y + (75 * scale), ALLEGRO_ALIGN_CENTRE, strLignes);
      break;
    default: //si c'est la première fois qu'on génère le pack d'images
      al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (30 * scale), ALLEGRO_ALIGN_CENTRE, "NADA");
      break;
  }

  //puis on demande au joueur d'entrer ses initiales
  font = al_load_ttf_font("media_files/Gameplay.ttf", (18 * scale), 0); //on charge la police "Gameplay"
  al_draw_text(font, bleuActif, rect->x + ((rect->x2 - rect->x)/2), rect->y + (140 * scale), ALLEGRO_ALIGN_CENTRE, "ENTREZ VOS INITIALES:");

  //on libère la mémoire
  al_destroy_font(font);

  return fond;
}

void genererFondDujeu(ALLEGRO_BITMAP *fond)
{
  al_set_target_bitmap(fond);

  ALLEGRO_COLOR bleuFond = al_map_rgb(206, 224, 245); //couleur de fond
  al_clear_to_color(bleuFond); //on met un fond bleu très très clair

  //on dessine des lignes en diagonale de px de large sur le fond (CA FAIT JOLI gnééééééé)
  ALLEGRO_COLOR bleuLignes = al_map_rgb(190, 208, 232); //on crée une nuance de bleu
  int x = 0, x2 = 4, y = 8, y2 = 0;
  for(y; y <= al_get_bitmap_height(fond); y+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x2+=4;
  }
  for(x2; x2 <= al_get_bitmap_width(fond); x2+=4)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }
  for(y2; y2 <= al_get_bitmap_height(fond); y2+=8)
  {
    al_draw_line(x, y, x2, y2, bleuLignes, 1.5);
    x+=4;
  }
}

packImages *genererPackImages(elements *elem, int keyMap[16][3], float scale)
{
  //allocation
  packImages *images = malloc(sizeof(packImages));

  //génération des images
  images->imagesMenu = genererPackMenu(elem, scale);
  images->imagesPartie = genererPackPartie(elem, MARATHON, scale);
  images->imagesOptions = genererPackOptions(elem, images->imagesMenu->fondMenu, keyMap, scale);
  images->imagesSTLInput = genererPackSTLInput(NULL, elem, 0, 0, scale);
}

void regenererPackImages(packImages *images, elements *elem, int regen, int modeDeJeu, ALLEGRO_BITMAP *fondPrecedent, int keyMap[16][3], int score, float scale)
{
  //on regarde quel type de régénération la fonction est censée exécuter
  switch(regen)
  {
    case PIMENU:
      destroyPackMenu(images->imagesMenu);
      images->imagesMenu = genererPackMenu(elem, scale);
      break;
    case PIPARTIE:
      destroyPackPartie(images->imagesPartie);
      images->imagesPartie = genererPackPartie(elem, modeDeJeu, scale);
      break;
    case PIOPTIONS:
      destroyPackOptions(images->imagesOptions);
      images->imagesOptions = genererPackOptions(elem, fondPrecedent, keyMap, scale);
      break;
    case PISTLINPUT:
      destroyPackSTLInput(images->imagesSTLInput);
      images->imagesSTLInput = genererPackSTLInput(fondPrecedent, elem, score, modeDeJeu, scale);
      break;
    case ALL:
      destroyPackImages(images); //on détruit les images de chaque structure
      images->imagesMenu = genererPackMenu(elem, scale);
      images->imagesPartie = genererPackPartie(elem, modeDeJeu, scale);
      images->imagesOptions = genererPackOptions(elem, fondPrecedent, keyMap, scale);
      images->imagesSTLInput = genererPackSTLInput(fondPrecedent, elem, score, modeDeJeu, scale);
      break;
  }
}

void destroyPackImages(packImages *images)
{
    destroyPackMenu(images->imagesMenu);
    destroyPackPartie(images->imagesPartie);
    destroyPackOptions(images->imagesOptions);
    destroyPackSTLInput(images->imagesSTLInput);
}

void drawBlock(int typeDeBloc, float posX, float posY, float scale)
{
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
  al_draw_filled_rectangle(posX + 3 * scale, posY + 3 * scale, posX + 23 * scale, posY + 22 * scale, couleurPrincipale); //on dessine le rectangle central
  al_draw_filled_rectangle(posX + 3 * scale, posY + 0 * scale, posX + 25 * scale, posY + 3 * scale, couleurClaire); //barre claire horizontale
  al_draw_filled_rectangle(posX + 22 * scale, posY + 3 * scale, posX + 25 * scale, posY + 22 * scale, couleurClaire); //barre claire verticale

  al_draw_filled_rectangle(posX + 0 * scale, posY + 0 * scale, posX + 3 * scale, posY + 22 * scale, couleurFoncee); //barre foncée horizontale
  al_draw_filled_rectangle(posX + 0 * scale, posY + 22 * scale, posX + 25 * scale, posY + 25 * scale, couleurFoncee); //barre foncée verticale

  al_draw_filled_triangle(posX + 0 * scale, posY + 0 * scale, posX + 3 * scale, posY + 0 * scale, posX + 3 * scale, posY + 3 * scale, couleurClaire); //triangle clair gauche
  al_draw_filled_triangle(posX + 22 * scale, posY + 22 * scale, posX + 25 * scale, posY + 22 * scale, posX + 25 * scale, posY + 25 * scale, couleurClaire); //triangle clair droit
}

void drawHorBarre(float posX, float posY, float scale)
{
  al_draw_filled_rectangle(posX, posY, posX + (28 * scale), posY + (3 * scale), al_map_rgb(0, 0, 0));
}

void drawVerBarre(float posX, float posY, float scale)
{
  al_draw_filled_rectangle(posX, posY, (posX + 3 * scale), posY + (28 * scale), al_map_rgb(0, 0, 0));
}

void drawTransHorBarre(float posX, float posY, float scale)
{
  al_draw_filled_rectangle(posX, posY, posX + (28 * scale), posY + (3 * scale), al_map_rgba(0, 0, 0, 128));
}

void drawTransVerBarre(float posX, float posY, float scale)
{
  al_draw_filled_rectangle(posX, posY, (posX + 3 * scale), posY + (28 * scale), al_map_rgba(0, 0, 0, 128));
}
