#ifndef DATA_FILES_H
#define DATA_FILES_H

//structure constituant chaque maillon de la file de données qu'on va créer
typedef struct Element Element; //on crée l'alias de la structure qu'on va fabriquer
struct Element //puis on définit la structure
{
  int nombre; //on crée la variable int qu'on va stocker
  Element *suivant; //et un pointeur vers l'élément suivant de la file
}; //ne pas oublier le ';' après la définition d'une structure

//structure gérant la chaîne
typedef struct File File;
struct File
{
  Element *premier; //pointe vers le premier maillon de la file (celui qui est rentré en premier)
};

File *initialiser(); //fonction de création de file
void enfiler(File *file, int nvNombre); //fonction ajoutant un élément à la file
int defiler(File *file); //fonction faisant défiler la file (on enlève le premier élément de celleci et on le renvoit)

#endif
