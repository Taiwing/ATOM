#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include "get_conv.h"
# include "convert.h"
# include "fstr.h"

t_fstr	*parser(char **fmt, va_list cur, va_list ref);

#endif
