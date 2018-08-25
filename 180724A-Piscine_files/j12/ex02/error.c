#include "error.h"
#include "utils.h"

void ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void print_arg_error(int argc, char **argv)
{
	ft_puterr("ft_tail: ");
	if (argc < 4)
		ft_puterr("not enough arguments\n");
	else if (ft_strcmp(argv[1], "-c"))
		ft_puterr("option \"c\" not present\n");
	else
	{
		ft_puterr("incorrect number of bytes: \"");
		ft_puterr(argv[2]);
		ft_puterr("\"\n");
	}
}

void print_file_error(char *file)
{
	if (errno == EACCES)
	{
		ft_puterr("ft_tail: \'");
		ft_puterr(file);
		ft_puterr("\': Permission denied\n");
	}
	else
	{
		ft_puterr("ft_tail: couldn't open \'");
		ft_puterr(file);
		ft_puterr("\': file not found\n");
	}
	errno = 0;
}
