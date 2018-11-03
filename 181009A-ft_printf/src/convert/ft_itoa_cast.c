#include "ft_itoa_cast.h"

char	g_bstr[2][17] = {"0123456789abcdef", "0123456789ABCDEF"};

static void	malloc_n_int(void **n, int cast)
{
	if (cast == T_INT)
		*(int **)n = (int *)malloc(sizeof(int));
	else if (cast == (T_INT | C_UNSIGNED))
		*(t_uint **)n = (t_uint *)malloc(sizeof(t_uint));
	else if (cast == (T_INT | C_SHORT))
		*(t_shint **)n = (t_shint *)malloc(sizeof(t_shint));
	else if (cast == (T_INT | C_SHORT | C_UNSIGNED))
		*(t_ushint **)n = (t_ushint *)malloc(sizeof(t_ushint));
	else if (cast == (T_INT | C_LONG))
		*(t_lint **)n = (t_lint *)malloc(sizeof(t_lint));
	else if (cast == (T_INT | C_LONG | C_UNSIGNED))
		*(t_ulint **)n = (t_ulint *)malloc(sizeof(t_ulint));
	else if (cast == (T_INT | C_LONG_LONG))
		*(t_llint **)n = (t_llint *)malloc(sizeof(t_llint));
	else if (cast == (T_INT | C_LONG_LONG | C_UNSIGNED))
		*(t_ullint **)n = (t_ullint *)malloc(sizeof(t_ullint));
}

static void	malloc_n(void **n, int cast)
{
	if (cast & T_INT)
		malloc_n_int(n, cast);
	else if (cast == T_SIZE_T)
		*(ssize_t **)n = (ssize_t *)malloc(sizeof(ssize_t));
	else if (cast == (T_SIZE_T | C_UNSIGNED))
		*(size_t **)n = (size_t *)malloc(sizeof(size_t));
	else if (cast == T_INTMAX_T)
		*(intmax_t **)n = (intmax_t *)malloc(sizeof(intmax_t));
	else if (cast == (T_INTMAX_T | C_UNSIGNED))
		*(uintmax_t **)n = (uintmax_t *)malloc(sizeof(uintmax_t));
	else if (cast == T_CHAR)
		*(char **)n = (char *)malloc(sizeof(char));
	else if (cast == (T_CHAR | C_UNSIGNED))
		*(t_uchar **)n = (t_uchar *)malloc(sizeof(t_uchar));
}

static char	*ft_itoa_base(va_list cur, va_list ref, t_params *conv, int cast)
{
	void	*n;
	char	*str;
	int		base;

	malloc_n(&n, cast);
	fetch(conv->arg ? ref : cur, conv->arg, cast, n);
	base = 10;
	base = conv->type == 'o' ? 8 : base;
	base = conv->type == 'x' || conv->type == 'X' ? 16 : base;
	if (cast == (T_INT | C_UNSIGNED))
		str = ft_itoa_base_uint(*(t_uint *)n, base, conv->type == 'X');
	else if (cast == (T_INT | C_SHORT | C_UNSIGNED))
		str = ft_itoa_base_ushint(*(t_ushint *)n, base, conv->type == 'X');
	else if (cast == (T_INT | C_LONG | C_UNSIGNED))
		str = ft_itoa_base_ulint(*(t_ulint *)n, base, conv->type == 'X');
	else if (cast == (T_INT | C_LONG_LONG | C_UNSIGNED))
		str = ft_itoa_base_ullint(*(t_ullint *)n, base, conv->type == 'X');
	else if (cast == (T_SIZE_T | C_UNSIGNED))
		str = ft_itoa_base_size_t(*(size_t *)n, base, conv->type == 'X');
	else if (cast == (T_INTMAX_T | C_UNSIGNED))
		str = ft_itoa_base_uintmax_t(*(uintmax_t *)n, base, conv->type == 'X');
	else if (cast == (T_CHAR | C_UNSIGNED))
		str = ft_itoa_base_uchar(*(t_uchar *)n, base, conv->type == 'X');
	free(n);
	return (str);
}

static char	*ft_itoa_signed(va_list cur, va_list ref, t_params *conv, int cast)
{
	void	*n;
	char	*str;

	malloc_n(&n, cast);
	fetch(conv->arg ? ref : cur, conv->arg, cast, n);
	if (cast == T_INT)
		str = ft_itoa_int(*(int *)n);
	else if (cast == (T_INT | C_SHORT))
		str = ft_itoa_shint(*(t_shint *)n);
	else if (cast == (T_INT | C_LONG))
		str = ft_itoa_lint(*(t_lint *)n);
	else if (cast == (T_INT | C_LONG_LONG))
		str = ft_itoa_llint(*(t_llint *)n);
	else if (cast == T_SIZE_T)
		str = ft_itoa_ssize_t(*(ssize_t *)n);
	else if (cast == T_INTMAX_T)
		str = ft_itoa_intmax_t(*(intmax_t *)n);
	else if (cast == T_CHAR)
		str = ft_itoa_char(*(char *)n);
	free(n);
	return (str);
}

char	*ft_itoa_cast(va_list cur, va_list ref, t_params *conv)
{
	int	cast;

	cast = (int)(conv->cast);
	if ((cast >> 5) == 0)
	{
		cast &= ~C_DEFAULT;
		cast |= T_INT;
	}
	if (conv->cast & C_UNSIGNED)
		return (ft_itoa_base(cur, ref, conv, cast));
	else
		return (ft_itoa_signed(cur, ref, conv, cast));
}
