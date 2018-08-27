#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# define MIN(C) (C > 64 && C < 91 ? C + 32 : C)

void	ft_putnext(char ***next);
char	***next_level(char **tab);
void	ft_show_tab(char **tab);
int		ft_strlen(char *str);
int		ft_strccmp(char *s1, char *s2);
int		ft_strlcmp(char *s1, char *s2);
void	ft_putstr(char *str);
char	**ft_split_whitespaces(char *str);

#endif
