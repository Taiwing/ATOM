#ifndef FETCH_H
# define FETCH_H
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "params.h"

void	fetch(va_list ref, int n, int cast, void *ptr);

#endif
