#include "ft_fight.h"

void ft_fight(t_perso *att, t_perso *def, char *attack)
{
  int l[3];

  l[0] = 0;
  while(attack[l[0]])
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
    write(1, attack, l[0]);
    write(1, def->name, l[2]);
    write(1, ".\n", 2);
    def->life = (l[0]<23) ? def->life-(35-((l[0]-20)*10)) : def->life-5;
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
