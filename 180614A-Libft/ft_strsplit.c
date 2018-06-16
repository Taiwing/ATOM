#include "libf4.h"

char	**ft_strsplit(char const *s, char c)
{
	static size_t	size = 0;
	char			**split;
	size_t			l;

	l = 0;
	while (*s == c)
		s++;
	while (s[l] && s[l] != c)
		l++;
	if (l)
	{
		size++;
		split = s[l] ? ft_strsplit(s+l, c) : (char **)malloc(size * sizeof(char *));
		
	}

}

char    **ft_strsplit(char const *s, char c)
{
	char	**split;
	char	*copy;
	size_t	size;
	size_t	l;

	size = 0;
	l = ft_strlen(s);
	copy = ft_strsub(s, 0, l);	/*TODO: replace by strcpy*/
	while (l--)
	{
		copy[l] = copy[l] == c ? 0 : copy[l];
		size += copy[l] && copy[l+1] == 0 ? 1 : 0;
	}
	split = (char **)ft_memalloc((size+1) * sizeof(char *));
	l = ft_strlen(s);
	

}
