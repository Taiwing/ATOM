typedef struct Coordonnees Coordonnees; //"typedef" permet de créer un alias. Ici l'ordinateur comprendra "struct Coordonnees" quand "Coordonnees" sera tapé
struct Coordonnees //crée une "structure" (type de variable personnalisée), de nom Coordonnees
{
  int x;
  int y;
};

typedef struct Personne Personne;
struct Personne
{
  char nom[100];
  char prenom[100];
  char adresse[1000];

  int age;
  int garcon; //boléen: garçon = 1; fille = 0
};

void initialiserCoordonnees(Coordonnees *point);
