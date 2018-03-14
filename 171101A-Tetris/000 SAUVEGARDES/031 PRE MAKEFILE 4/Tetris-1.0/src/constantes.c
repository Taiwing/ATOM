#include "include/main.h"

//on définit chacun des tétrominos
packTetro *chargerTetrominos()
{
  //on crée la structure qui va contenir les tétrominos
  packTetro *sac = malloc(sizeof(*sac));

  //on initialise les tétros à VIDE
  for(int i = 0; i < 7; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      for(int y = 0; y < 4; y++)
      {
        for(int x = 0; x < 4; x++)
        {
          switch(i)
          {
            case JAUNE_O:
              sac->p_jaune_O[j][x][y] = VIDE;
              break;
            case CYAN_I:
              sac->p_cyan_I[j][x][y] = VIDE;
              break;
            case MAUVE_T:
              sac->p_mauve_T[j][x][y] = VIDE;
              break;
            case VIOLET_J:
              sac->p_violet_J[j][x][y] = VIDE;
              break;
            case ORANGE_L:
              sac->p_orange_L[j][x][y] = VIDE;
              break;
            case VERT_S:
              sac->p_vert_S[j][x][y] = VIDE;
              break;
            case ROUGE_Z:
              sac->p_rouge_Z[j][x][y] = VIDE;
              break;
          }
        }
      }
    }
  }

  //liste des différentes permutation de chacun des tetrominos
  sac->p_jaune_O[POS1][1][1] = JAUNE;
  sac->p_jaune_O[POS1][2][1] = JAUNE;
  sac->p_jaune_O[POS1][1][2] = JAUNE;
  sac->p_jaune_O[POS1][2][2] = JAUNE;
  sac->p_jaune_O[POS2][1][1] = JAUNE;
  sac->p_jaune_O[POS2][2][1] = JAUNE;
  sac->p_jaune_O[POS2][1][2] = JAUNE;
  sac->p_jaune_O[POS2][2][2] = JAUNE;
  sac->p_jaune_O[POS3][1][1] = JAUNE;
  sac->p_jaune_O[POS3][2][1] = JAUNE;
  sac->p_jaune_O[POS3][1][2] = JAUNE;
  sac->p_jaune_O[POS3][2][2] = JAUNE;
  sac->p_jaune_O[POS4][1][1] = JAUNE;
  sac->p_jaune_O[POS4][2][1] = JAUNE;
  sac->p_jaune_O[POS4][1][2] = JAUNE;
  sac->p_jaune_O[POS4][2][2] = JAUNE;

  sac->p_cyan_I[POS1][0][1] = CYAN;
  sac->p_cyan_I[POS1][1][1] = CYAN;
  sac->p_cyan_I[POS1][2][1] = CYAN;
  sac->p_cyan_I[POS1][3][1] = CYAN;
  sac->p_cyan_I[POS2][2][0] = CYAN;
  sac->p_cyan_I[POS2][2][1] = CYAN;
  sac->p_cyan_I[POS2][2][2] = CYAN;
  sac->p_cyan_I[POS2][2][3] = CYAN;
  sac->p_cyan_I[POS3][0][2] = CYAN;
  sac->p_cyan_I[POS3][1][2] = CYAN;
  sac->p_cyan_I[POS3][2][2] = CYAN;
  sac->p_cyan_I[POS3][3][2] = CYAN;
  sac->p_cyan_I[POS4][1][0] = CYAN;
  sac->p_cyan_I[POS4][1][1] = CYAN;
  sac->p_cyan_I[POS4][1][2] = CYAN;
  sac->p_cyan_I[POS4][1][3] = CYAN;

  sac->p_mauve_T[POS1][1][1] = MAUVE;
  sac->p_mauve_T[POS1][0][2] = MAUVE;
  sac->p_mauve_T[POS1][1][2] = MAUVE;
  sac->p_mauve_T[POS1][2][2] = MAUVE;
  sac->p_mauve_T[POS2][1][1] = MAUVE;
  sac->p_mauve_T[POS2][1][2] = MAUVE;
  sac->p_mauve_T[POS2][2][2] = MAUVE;
  sac->p_mauve_T[POS2][1][3] = MAUVE;
  sac->p_mauve_T[POS3][0][2] = MAUVE;
  sac->p_mauve_T[POS3][1][2] = MAUVE;
  sac->p_mauve_T[POS3][2][2] = MAUVE;
  sac->p_mauve_T[POS3][1][3] = MAUVE;
  sac->p_mauve_T[POS4][1][1] = MAUVE;
  sac->p_mauve_T[POS4][0][2] = MAUVE;
  sac->p_mauve_T[POS4][1][2] = MAUVE;
  sac->p_mauve_T[POS4][1][3] = MAUVE;

  sac->p_violet_J[POS1][0][1] = VIOLET;
  sac->p_violet_J[POS1][0][2] = VIOLET;
  sac->p_violet_J[POS1][1][2] = VIOLET;
  sac->p_violet_J[POS1][2][2] = VIOLET;
  sac->p_violet_J[POS2][1][1] = VIOLET;
  sac->p_violet_J[POS2][2][1] = VIOLET;
  sac->p_violet_J[POS2][1][2] = VIOLET;
  sac->p_violet_J[POS2][1][3] = VIOLET;
  sac->p_violet_J[POS3][0][2] = VIOLET;
  sac->p_violet_J[POS3][1][2] = VIOLET;
  sac->p_violet_J[POS3][2][2] = VIOLET;
  sac->p_violet_J[POS3][2][3] = VIOLET;
  sac->p_violet_J[POS4][1][1] = VIOLET;
  sac->p_violet_J[POS4][1][2] = VIOLET;
  sac->p_violet_J[POS4][0][3] = VIOLET;
  sac->p_violet_J[POS4][1][3] = VIOLET;

  sac->p_orange_L[POS1][2][1] = ORANGE;
  sac->p_orange_L[POS1][0][2] = ORANGE;
  sac->p_orange_L[POS1][1][2] = ORANGE;
  sac->p_orange_L[POS1][2][2] = ORANGE;
  sac->p_orange_L[POS2][1][1] = ORANGE;
  sac->p_orange_L[POS2][1][2] = ORANGE;
  sac->p_orange_L[POS2][1][3] = ORANGE;
  sac->p_orange_L[POS2][2][3] = ORANGE;
  sac->p_orange_L[POS3][0][2] = ORANGE;
  sac->p_orange_L[POS3][1][2] = ORANGE;
  sac->p_orange_L[POS3][2][2] = ORANGE;
  sac->p_orange_L[POS3][0][3] = ORANGE;
  sac->p_orange_L[POS4][0][1] = ORANGE;
  sac->p_orange_L[POS4][1][1] = ORANGE;
  sac->p_orange_L[POS4][1][2] = ORANGE;
  sac->p_orange_L[POS4][1][3] = ORANGE;

  sac->p_vert_S[POS1][1][1] = VERT;
  sac->p_vert_S[POS1][2][1] = VERT;
  sac->p_vert_S[POS1][0][2] = VERT;
  sac->p_vert_S[POS1][1][2] = VERT;
  sac->p_vert_S[POS2][1][1] = VERT;
  sac->p_vert_S[POS2][1][2] = VERT;
  sac->p_vert_S[POS2][2][2] = VERT;
  sac->p_vert_S[POS2][2][3] = VERT;
  sac->p_vert_S[POS3][1][2] = VERT;
  sac->p_vert_S[POS3][2][2] = VERT;
  sac->p_vert_S[POS3][0][3] = VERT;
  sac->p_vert_S[POS3][1][3] = VERT;
  sac->p_vert_S[POS4][0][1] = VERT;
  sac->p_vert_S[POS4][0][2] = VERT;
  sac->p_vert_S[POS4][1][2] = VERT;
  sac->p_vert_S[POS4][1][3] = VERT;

  sac->p_rouge_Z[POS1][0][1] = ROUGE;
  sac->p_rouge_Z[POS1][1][1] = ROUGE;
  sac->p_rouge_Z[POS1][1][2] = ROUGE;
  sac->p_rouge_Z[POS1][2][2] = ROUGE;
  sac->p_rouge_Z[POS2][2][1] = ROUGE;
  sac->p_rouge_Z[POS2][1][2] = ROUGE;
  sac->p_rouge_Z[POS2][2][2] = ROUGE;
  sac->p_rouge_Z[POS2][1][3] = ROUGE;
  sac->p_rouge_Z[POS3][0][2] = ROUGE;
  sac->p_rouge_Z[POS3][1][2] = ROUGE;
  sac->p_rouge_Z[POS3][1][3] = ROUGE;
  sac->p_rouge_Z[POS3][2][3] = ROUGE;
  sac->p_rouge_Z[POS4][1][1] = ROUGE;
  sac->p_rouge_Z[POS4][0][2] = ROUGE;
  sac->p_rouge_Z[POS4][1][2] = ROUGE;
  sac->p_rouge_Z[POS4][0][3] = ROUGE;

  return sac; //BORDEL J'AI ENCORE OUBLIE LE RETURN QUEL COOOOOOOOOOON
}

void destroyTetrominos(packTetro *tetros)
{
  //on efface la structure de la mémoire
  free(tetros);
}
