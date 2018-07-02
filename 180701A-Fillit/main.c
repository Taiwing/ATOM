#include "main.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("usage: fillit FILE", 2);
		return 1;
	}
	/*TODO: replace the fallowing test with a check_file function*/
	else if (ft_strcmp(argv[1], "valid_file") != 0)
	{
		ft_putendl_fd("ERROR: invalid Tetromino File", 2);
		return 1;
	}

	return 0;
}
