#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int			l;
	char		*cpy;
	char		**tb;
	static int	i = 0;

	i++;
	while (*s == c)
		s++;
	l = 0;
	while (s[l] && s[l] != c)
		l++;
	cpy = l ? ft_strncpy(ft_strnew(l + 1), s, l) : NULL;
	tb = l ? ft_strsplit(s + l, c) : (char **)malloc(i * sizeof(char *));
	tb[--i] = cpy;
	return (tb);
}
