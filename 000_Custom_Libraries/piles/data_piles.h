#ifndef DATA_PILES_H
#define DATA_PILES_H

//structure constituant chaque maillon de la pile de données qu'on va créer
typedef struct Element Element; //on crée l'alias de la structure qu'on va fabriquer
struct Element //puis on définit la structure
{
  int nombre; //on crée la variable int qu'on va stocker
  Element *suivant; //et un pointeur vers l'élément suivant de la pile
}; //ne pas oublier le ';' après la définition d'une structure

//structure gérant la chaîne
typedef struct Pile Pile;
struct Pile
{
  Element *premier; //pointe vers le premier maillon de la pile (celui du dessus)
};

Pile *initialiser(); //fonction de crétion de pile
void empiler(Pile *pile, int nvNombre); //on met un nombre au-dessus de la pile
int depiler(Pile *pile); //on enlève le premier élément de la pile et on le renvoit
void afficherPile(Pile *pile); //va nous permettre de visualiser le résultat

#endif
