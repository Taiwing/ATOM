#include "ft_ultimate_fight.h"

const char *moveString[] = {
  " donne un judo punch a ",
  " donne un judo headbutt a ",
  " donne un judo kick a ",
  " donne un judo chop ichi a ",
  " donne un judo chop ni a ",
  " donne un judo chop san a ",
  " donne un judo chop shi a ",
  " donne un judo chop go a ",
  " donne un judo chop roku a ",
  " donne un judo chop shichi a ",
  " donne un judo chop hachi a ",
  " donne un judo chop ku a ",
  " donne un judo chop ju a ",
  " donne un judo chop hyaku a ",
  " donne un judo chop sen a "
};

const int movePower[] = {5, 20, 15, 13, 3, 18, 9, 11, 13, 8, 6, 11, 9, 18, 10};

void ft_ultimate_fight(t_perso *att, t_perso *def, int i)
{
  int l[3];

  l[0] = 0;
  while(moveString[i][l[0]])
    l[0]++;
  l[1] = 0;
  while(att->name[l[1]])
    l[1]++;
  l[2] = 0;
  while(def->name[l[2]])
    l[2]++;

  if(att->life > 0 && def->life > 0)
  {
    write(1, att->name, l[1]);
    write(1, moveString[i], l[0]);
    write(1, def->name, l[2]);
    write(1, ".\n", 2);
    def->life -= movePower[i];
    if(def->life <= 0)
    {
      write(1, def->name, l[2]);
      write(1, " est mort.\n", 11);
    }
  }
}

void ft_initialize_perso(t_perso *perso, char *name, int age)
{
  perso->name = name;
  perso->age = age;
  perso->life = 100.0;
}
