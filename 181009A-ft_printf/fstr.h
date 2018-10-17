#ifndef FT_FSTR
# define FT_FSTR

typedef struct	s_fstr
{
	char		*str;
	wchar_t		*wstr;
	char		minus;
	int			len;
	int			field_width;
}				t_fstr;

t_fstr			*init_fstr(void);
void			del_fstr(t_fstr *str);
void			print_fstr(t_fstr *str);

#endif
