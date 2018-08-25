#include "ft_rot42.h"

char *ft_rot42(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if((str[i] > 64 && str[i] < 75) || (str[i] > 96 && str[i] < 107))
			str[i] += 16;
		else
			str[i] = str[i] < 91 ? 64+(16-(90-str[i])) : 96+(16-(122-str[i]));
	}
	return str;
}
