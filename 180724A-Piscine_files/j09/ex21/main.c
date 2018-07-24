#include "ft_ultimate_fight.h"

int main(void)
{
  t_perso donnie_matrix;
  t_perso frau_farbissina;

  ft_initialize_perso(&donnie_matrix, "Donnie Matrix", 22);
  ft_initialize_perso(&frau_farbissina, "Frau Farbissina", 22);

  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK7);
  ft_ultimate_fight(&frau_farbissina, &donnie_matrix, PUNCH);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&frau_farbissina, &donnie_matrix, KICK);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK9);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK12);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK4);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, KICK);
  ft_ultimate_fight(&donnie_matrix, &frau_farbissina, HEADBUTT);
}
