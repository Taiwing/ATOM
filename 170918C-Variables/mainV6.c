#include<stdio.h>
#include<stdlib.h>

int main()
{
  const int NOMBRE_DE_VIES_INITIALES = 5; /*ici on déclare une constante
  en MAJUSCULE pour mieux les reconnaître dans le code*/
  printf("valeur de la constante NOMBRE_DE_VIES_INITIALES: %d\n", NOMBRE_DE_VIES_INITIALES); /*affiche la valeur de la constante
  NOMBRE_DE_VIES_INITIALES grâce au symbole %d qui permet d'afficher un nombre entier à partir d'une variable ou constante*/
  int nombreDeVies = NOMBRE_DE_VIES_INITIALES; /*on donne la valeur de
  NOMBRE_DE_VIES_INITIALES à nombreDeVies, qui sera donc 5*/
  printf("valeur de la variable nombreDeVies après initialisation: %d\n", nombreDeVies); //affiche la valeur de nombreDeVies
  nombreDeVies = 4; //change la valeur de nombreDeVies à 4
  nombreDeVies = 3;
  printf("valeur de nombreDeVies après que le joueur se soit pris deux coups sur la gueule: %d\n", nombreDeVies);
  int niveau = 1;
  printf("valeur des variables nombreDeVies: %d et de niveau: %d\n", nombreDeVies, niveau); /*affiche la valeur de nombreDeVies
  puis de niveau successivement*/
  printf("\naprès tout ça, veuillez indiquer votre âge: ");
  int age;
  double poids; //"double" permet de retenir une variable décimale (un nombre à virgule espèce d'abruti)
  scanf("%d", &age); /*"scanf" permet de faire l'inverse de "prinf", à savoir de rentrer des informations dans le programme au lieu
  d'en sortir. Pour indiquer la valeur d'une variable numérique entière il faut donc utiliser %d comme pour "printf", la seule différence
  étant qu'on rajoute le symbole & avant le nom de la variable dont on va changer la valeur*/
  printf("\nPuis, si ce n'était pas assez personnel comme ça, veuillez maintenant indiquer votre poids: ");
  scanf("%lf", &poids); /*on rajoute un l devant le f contrairement aux valeurs entières parce que WTF not ?
  NE PAS OUBLIER LE SYMBOLE & AVANT LE NOM DE LA VARIABLE DANS SCANF ESPECE D'ABRUTI!!!!!!!*/
  printf("\nAHAHAHAHAH !!! Maintenant on sait que vous êtes un vieux gros lard de %d ans et de %f kilos\n", age, poids); /*Ici on affiche
  successivement les valeurs de age et poids, l'une étant entière et donc s'affichant via %d et l'autre étant décimale d'affichant via %f*/
  return 0;
}
