#include "ft_tail.h"

char *ft_strcpycat(char *base, char *to_add, int br)
{
	int i;
	int l;
	char *str;

	l = 0;
	while (base && base[l])
		l++;
	str = (char *)malloc(l + br + 1);
	i = 0;
	while (i < br)
		str[i++] = *to_add++;
	while (base && base[i - br])
	{
		str[i] = base[i - br];
		i++;
	}
	str[i] = 0;
	if (base)
		free(base);
	return (str);
}

void get_last_c_bytes(int fd, int *c, char **str)
{
	int br;
	char buffer[32];

	br = read(fd, buffer, 32);
	if (br == 32)
		get_last_c_bytes(fd, c, str);
	if (*c && br)
	{
		if (br <= *c)
			*str = ft_strcpycat(*str, buffer, br);
		else
			*str = ft_strcpycat(*str, buffer + br - *c, *c);
		(*c) -= br <= *c ? br : *c;
	}
}

void ft_print_name(char *name, int ifi)
{
	ft_putstr(ifi < 1 ? "\n==> " : "==> ");
	ft_putstr(name);
  ft_putstr(" <==\n");
}

void putfile(char *file, int c, int *ifi, int fc)
{
	int fd;
	char *str;

	str = 0;
	fd = open(file, O_RDONLY);
	if (fc > 1 && fd > 0)
		ft_print_name(file, (*ifi)--);
	else if (errno)
		print_file_error(file);
	get_last_c_bytes(fd, &c, &str);
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
	close(fd);
}

void ft_tail(int fc, char **fv, int c)
{
	int ifi;

	ifi = 1;
	while (*fv)
		putfile(*fv++, c, &ifi, fc);
}
