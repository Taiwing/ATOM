#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "error.h"
# include "utils.h"

void ft_tail(int fc, char **fv, int c);

#endif
