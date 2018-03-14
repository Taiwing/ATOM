#include "affichePendu.h"

void affichePendu(const int coupsRestants)
{
  printf("\n\n\n\n\n\n\n\n\n");                     // 10

  switch(coupsRestants)
  {
  case 10:
    printf("\n\n\n\n\n\n\n\n\n\n\n"); // remplace les lignes non-affichées
    break;
  case 9:
    printf("\n");
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 8:
    printf(" -----------------\n");     // 8
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 7:
    printf(" -----------------\n");     // 8
    printf("   |  /\n");  // 9 -> 7
    printf("   | /\n");   // 9 -> 7
    printf("   |/\n");    // 9 -> 7
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 6:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/\n");    // 9 -> 7
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 5:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 4:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 3:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |         __|\n");     // 9 -> 4 -> 3
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 2:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |         __|__\n");     // 9 -> 4 -> 3 -> 2
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |\n");     // 9
    printf("  /|\\\n");   // 9
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 1:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |         __|__\n");     // 9 -> 4 -> 3 -> 2
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |          /\n");     // 9 -> 1
    printf("  /|\\        /\n");   // 9 -> 1
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  case 0:
    printf(" -----------------\n");     // 8
    printf("   |  /        |\n");       // 9 -> 7 -> 6
    printf("   | /         |\n");       // 9 -> 7 -> 6
    printf("   |/         / \\\n");     // 9 -> 7 -> 5
    printf("   |          \\ /\n");     // 9 -> 5
    printf("   |         __|__\n");     // 9 -> 4 -> 3 -> 2
    printf("   |           |\n");       // 9 -> 4
    printf("   |           |\n");       // 9 -> 4
    printf("   |          / \\\n");     // 9 -> 1 -> 0
    printf("  /|\\        /   \\\n");   // 9 -> 1 -> 0
    printf(" / | \\\n");                // 9
    printf("/  |  \\\n");               // 9
    break;
  }

  printf("~~~~~~~~~~~~~~~~~~~~~\n");  // 10
  printf("~~~~~~~~~~~~~~~~~~~~~\n");  // 10
  printf("~~~~~~~~~~~~~~~~~~~~~\n");  // 10
}
