#ifndef FT_FIGHT_H
#define FT_FIGHT_H
#include "ft_perso.h"
#include <unistd.h>

enum move {PUNCH, HEADBUTT, KICK, KICK1, KICK2, KICK3, KICK4, KICK5, KICK6,
           KICK7, KICK8, KICK9, KICK10, KICK11, KICK12};

void ft_ultimate_fight(t_perso *att, t_perso *def, int i);
void ft_initialize_perso(t_perso *perso, char *name, int age);

#endif
