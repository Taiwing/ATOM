#include "include/configuration.h"
#include "include/fenetre.h"

gameConfig *initialiserConfigJeu()
{
  gameConfig *config = malloc(sizeof(gameConfig)); //on crée la structure
  config->sound = malloc(sizeof(soundConfig)); //on crée la structure
  chargerGameConfig(config); //on charge les valeurs depuis le fichier de configuration
  return config;
}

void chargerGameConfig(gameConfig *config)
{
  //on ouvre le fichier de configuration en lecture
  FILE *conf = fopen("game_files/game.conf", "r");

  char param[20] = "", val[20] = ""; //va nous servir à lire le fichier
  char valNum[3][4] = {""}; //va enregistrer les valeurs numériques des touches en string
  char valNumRes[2][6] = {""}; //va enregistrer les valeurs numériques des résolutions en string

  fseek(conf, 12, SEEK_SET); //on se déplace jusqu'au premier paramètre de configuration

  for(int i = 0; i < 4; i++) //on lit les quatre paramètres de résolution
  {
    fscanf(conf, "%s %s %s", param, valNumRes[WIDTH], valNumRes[HEIGHT]);
    param[strlen(param)] = '\0';
    for(int j = 0; j < 2; j++)
    {
      config->res[i][j] = atoi(valNumRes[j]);
    }
  }
  printf("RESOLUTION_MIN  %dx%d\nRESOLUTION_MAX  %dx%d\nRESOLUTION_DEF  %dx%d\nRESOLUTION_CUR  %dx%d\n", config->res[0][0], config->res[0][1], config->res[1][0], config->res[1][1], config->res[2][0], config->res[2][1], config->res[3][0], config->res[3][1]);

  fseek(conf, 8, SEEK_CUR); //on se déplace jusqu'au premier paramètre de configuration sonore

  for(int i = 0; i < 3; i++) //on lit les 3 paramètres sonores
  {
    fscanf(conf, "%s %s", param, val); //on récupère la ligne
    if(val[0] == 'O' && val[1] == 'N') //si val vaut "ON"
      config->sound->soundOnOff[i] = true; //le son est activé
    else
      config->sound->soundOnOff[i] = false; //le son est desactivé
    param[strlen(param)] = '\0';
    val[strlen(val)] = '\0';
  }

  for(int i = 0; i < 2; i++) //on lit les deux paramètres de volume
  {
    fscanf(conf, "%s %s", param, val);
    param[strlen(param)] = '\0';
    val[strlen(val)] = '\0';
    config->sound->volume[i] = atof(val);
  }

  fseek(conf, 7, SEEK_CUR); //on se déplace jusqu'au prochain paramètre de configuration

  for(int i = 0; i < 9; i++) //on lit les 9 paramètres d'input
  {
    fscanf(conf, "%s %s %s %s", param, valNum[0], valNum[1], valNum[2]);
    param[strlen(param)] = '\0';
    for(int j = 0; j < 3; j++)
    {
      config->keyMap[i][j] = atoi(valNum[j]);
    }
  }

  fclose(conf);

  //paramètres de triche
  config->cheatFunctions = false; //on met le paramètre de triche à faux par défaut
  for(int i = 9; i < 16; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(j == 0)
      {
        switch(i)
        {
          case CHANGEZ:
            config->keyMap[i][j] = ALLEGRO_KEY_Z;
            break;
          case CHANGES:
            config->keyMap[i][j] = ALLEGRO_KEY_S;
            break;
          case CHANGET:
            config->keyMap[i][j] = ALLEGRO_KEY_T;
            break;
          case CHANGEI:
            config->keyMap[i][j] = ALLEGRO_KEY_I;
            break;
          case CHANGEO:
            config->keyMap[i][j] = ALLEGRO_KEY_O;
            break;
          case CHANGEJ:
            config->keyMap[i][j] = ALLEGRO_KEY_J;
            break;
          case CHANGEL:
            config->keyMap[i][j] = ALLEGRO_KEY_L;
            break;
        }
      }
      else
        config->keyMap[i][j] = 0;
    }
  }

}

void enregistrerGameConfig(gameConfig *config)
{
  FILE *emptConf = fopen("game_files/templates/game.conf.EMPTY", "r"); //on ouvre le fichier de configuration vide en lecture

  char buffer[23][64] = {""}; //on utilise ce buffer pour lire le fichier vide

  //on copie le fichier vide dans le fichier courant
  for(int i = 0; i < 23; i++) //on récupère les données du fichier par défaut pour les mettre dans le fichier actuel
  {
    fgets(buffer[i], 64, emptConf);
  }
  fclose(emptConf); //on a plus besoin du fichier vide

  //maintenant on va créer un ensemble de string qu'on va remplir avec le contenu de la structure de configuration
  char strConfig[18][20] = {""};

  //on rempit le tableau de string
  for(int i = 0; i < 18; i++)
  {
    if(i < 4) //si on est dans la partie résolution
    {
      sprintf(strConfig[i], "%d\t%d", config->res[i][WIDTH], config->res[i][HEIGHT]);
    }
    else if(i >= 4 && i < 7) //si on est dans la partie onOff de la configuration du son
    {
      if(config->sound->soundOnOff[i])
        sprintf(strConfig[i], "ON");
      else
        sprintf(strConfig[i], "OFF");
    }
    else if(i == 7 || i == 8) //si on est dans la partie volume
    {
      sprintf(strConfig[i], "%f", config->sound->volume[i - 7]);
      strConfig[i][3] = '\0';
    }
    else if(i > 8 && i < 18) //si on est dans la partie input
    {
      sprintf(strConfig[i], "%d\t%d\t%d", config->keyMap[i - 9][0], config->keyMap[i - 9][1], config->keyMap[i - 9][2]);
    }
  }

  //maintenant on inclut les données de configuration dans le buffer
  int curseur = 0; //va servir à lire la chaîne de caractère
  for(int i = 0; i < 18; i++)
  {
    if(i < 4)
    {
      curseur = 16; //représente la position du point dans le fichier vide
      for(int j = 0; j < strlen(strConfig[i]); j++)
      {
        buffer[i + 1][curseur] = strConfig[i][j];
        curseur++;
      }
    }
    if(i >= 4 && i < 9)
    {
      curseur = 14; //représente la position du point dans le fichier vide
      for(int j = 0; j < strlen(strConfig[i]); j++)
      {
        buffer[i + 3][curseur] = strConfig[i][j];
        curseur++;
      }
    }
    else
    {
      curseur = 18; //représente la position du point dans le fichier vide
      for(int j = 0; j < strlen(strConfig[i]); j++)
      {
        buffer[i + 5][curseur] = strConfig[i][j];
        curseur++;
      }
    }
  }

  //puis on remplit le fichier de configuration
  FILE *conf = fopen("game_files/game.conf", "w+"); //ouvrir le fichier de configuration actuel en écriture en supprimant son contenu

  for(int i = 0; i < 23; i++)
  {
    fputs(buffer[i], conf);

    if(i != 0 && i != 5 && i != 6 && i != 12 && i != 13)
    {
      fputc('\n', conf);
    }
  }

  fclose(conf);
}

void resetGameConfig(gameConfig *config)
{
  FILE *origConf = fopen("game_files/templates/game.conf.DEFAULT", "r"); //on ouvre le fichier de configuration par défaut en lecture
  FILE *actConf = fopen("game_files/game.conf", "w+"); //on ouvre le fichier de configuration actuel en écriture en supprimant son contenu
  char str[64] = ""; //va nous servir à lire le fichier

  for(int i = 0; i < 23; i++) //on récupère les données du fichier par défaut pour les mettre dans le fichier actuel
  {
    fgets(str, 64, origConf);
    fputs(str, actConf);
  }

  //on uoblie pas de fermer les fichiers
  fclose(origConf);
  fclose(actConf);

  chargerGameConfig(config); //puis on recharge la structure de configuration

  testRes(config->res); //on regarde si la configuration par défaut peut être chargée
}

void destroyGameConfig(gameConfig *config)
{
  free(config->sound);
  free(config);
}
