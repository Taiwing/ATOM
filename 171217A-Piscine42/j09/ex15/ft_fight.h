#ifndef FT_FIGHT_H
#define FT_FIGHT_H
#include "ft_perso.h"
#include <unistd.h>

#define PUNCH " donne un judo punch a "
#define KICK " donne un judo kick a "
#define HEADBUTT " donne un judo headbutt a "

void ft_fight(t_perso *attacker, t_perso *defender, char *attack);
void ft_initialize_perso(t_perso *perso, char *name, int age);

#endif
