#include "configuration.h"

gameConfig *initialiserConfigJeu()
{
  gameConfig *config = malloc(sizeof(gameConfig)); //on crée la structure
  config->sound = malloc(sizeof(soundConfig)); //on crée la structure
  chargerGameConfig(config); //en l'absence de fichier de configuration, on charge les valeurs par défaut
  return config;
}

void chargerGameConfig(gameConfig *config)
{
  //on ouvre le fichier de configuration en lecture
  FILE *conf = fopen("game.conf", "r");

  char param[20] = "", val[20] = ""; //va nous servir à lire le fichier
  char valNum[3][4] = {""}; //va enregistrer les valeurs numériques en string

  fseek(conf, 7, SEEK_SET); //on se déplace jusqu'au premier paramètre de configuration

  for(int i = 0; i < 3; i++) //on lit les 3 premiers paramètres du fichier (indiquant quels sons sont activés)
  {
    fscanf(conf, "%s %s", param, val); //on récupère la ligne
    if(val[0] == 'O' && val[1] == 'N') //si val vaut "ON"
      config->sound->soundOnOff[i] = true; //le son est activé
    else
      config->sound->soundOnOff[i] = false; //le son est desactivé
    param[strlen(param)] = '\0';
    val[strlen(val)] = '\0';
    printf("%s: %s\n", param, val);
  }

  for(int i = 0; i < 2; i++) //on lit les deux paramètres de volume
  {
    fscanf(conf, "%s %s", param, val);
    param[strlen(param)] = '\0';
    val[strlen(val)] = '\0';
    printf("%s: %s\n", param, val);
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
      printf("%s: %d\n", param, config->keyMap[i][j]);
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
  FILE *emptConf = fopen("game.conf.EMPTY", "r"); //on ouvre le fichier de configuration vide en lecture

  char buffer[17][64] = {""}; //on utilise ce buffer pour lire le fichier vide

  //on copie le fichier vide dans le fichier courant
  for(int i = 0; i < 17; i++) //on récupère les données du fichier par défaut pour les mettre dans le fichier actuel
  {
    fgets(buffer[i], 64, emptConf);
  }
  fclose(emptConf); //on a plus besoin du fichier vide

  //maintenant on va créer un ensemble de string qu'on va remplir avec le contenu de la structure de configuration
  char strConfig[14][20] = {""};

  //on rempit le tableau de string
  for(int i = 0; i < 14; i++)
  {
    if(i < 3) //si on est dans la partie onOff de la configuration du son
    {
      if(config->sound->soundOnOff[i])
        sprintf(strConfig[i], "ON");
      else
        sprintf(strConfig[i], "OFF");
    }
    else if(i == 3 || i == 4) //si on est dans la partie volume
    {
      sprintf(strConfig[i], "%f", config->sound->volume[i - 3]);
      strConfig[i][3] = '\0';
    }
    else if(i > 4 && i < 14)
    {
      sprintf(strConfig[i], "%d\t%d\t%d", config->keyMap[i - 5][0], config->keyMap[i - 5][1], config->keyMap[i - 5][2]);
    }
  }

  //maintenant on inclut les données de configuration dans le buffer
  int curseur = 0; //va servir à lire la chaîne de caractère
  for(int i = 0; i < 14; i++)
  {
    if(i < 5)
    {
      curseur = 14;
      for(int j = 0; j < strlen(strConfig[i]); j++)
      {
        buffer[i + 1][curseur] = strConfig[i][j];
        curseur++;
      }
    }
    else
    {
      curseur = 18;
      for(int j = 0; j < strlen(strConfig[i]); j++)
      {
        buffer[i + 3][curseur] = strConfig[i][j];
        curseur++;
      }
    }
  }

  //puis on remplit le fichier de configuration
  FILE *conf = fopen("game.conf", "w+"); //ouvrir le fichier de configuration actuel en écriture en supprimant son contenu

  for(int i = 0; i < 17; i++)
  {
    fputs(buffer[i], conf);

    if(i != 0 && i != 6 && i != 7)
    {
      fputc('\n', conf);
    }
  }

  fclose(conf);
}

void resetGameConfig(gameConfig *config)
{
  FILE *origConf = fopen("game.conf.DEFAULT", "r"); //on ouvre le fichier de configuration par défaut en lecture
  FILE *actConf = fopen("game.conf", "w+"); //on ouvre le fichier de configuration actuel en écriture en supprimant son contenu
  char str[64] = ""; //va nous servir à lire le fichier

  for(int i = 0; i < 17; i++) //on récupère les données du fichier par défaut pour les mettre dans le fichier actuel
  {
    fgets(str, 64, origConf);
    fputs(str, actConf);
  }

  //on uoblie pas de fermer les fichiers
  fclose(origConf);
  fclose(actConf);

  chargerGameConfig(config); //puis on recharge la structure de configuration
}

void destroyGameConfig(gameConfig *config)
{
  free(config->sound);
  free(config);
}
