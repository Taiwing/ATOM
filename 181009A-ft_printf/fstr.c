#include "fstr.h"

t_fstr		*init_fstr(void)
{
	t_fstr	*new;

	if (!(new = (t_fstr *)malloc(sizeof(t_fstr *))))
		return (NULL);
	new->str = NULL;
	new->wstr = NULL;
	new->minus = 0;
	new->len = 0;
	new->field_width = 0;
	return (new);
}


void		del_fstr(t_fstr *str)
{
	if (str->str)
		free(str->str);
	if (str->wstr)
		free(str->wstr);
	free(str);
}

static void	padding(int l, int fw)
{
	while (l++ < fw)
		write(1, " ", 1);
}

void		print_fstr(t_fstr *str)
{
	if (!str->minus)
		padding(str->len, str->field_width);
	if (str->len && str->str)
		write(1, str->str, str->len);
	if (str->len && str->wstr)	
		
}
