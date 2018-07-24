#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

#define EVEN_MSG "I have a pair number of arguments.\n"
#define ODD_MSG "I have an impair number of arguments.\n"
#define EVEN(nbr) !(nbr%2)
#define SUCCESS 0
enum boolean {FALSE, TRUE};
typedef int t_bool;

void ft_putstr(char *str);
t_bool ft_is_even(int nbr);

#endif
