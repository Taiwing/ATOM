#include "libft/libft.h"

static int	locstrcmp(char *s1, char *s2);
static void	sort_argv(char **argv);

int	main(int argc, char **argv)
{
	sort_argv(argv+1);
	while (*++argv)
	{
		while (**argv)
			ft_putchar(*(*argv)++);
		ft_putchar('\n');
	}
	return 1;
}

static int	locstrcmp(char *s1, char *s2)
{
	return (*s1 && *s2 && *s1 == *s2 ? locstrcmp(s1+1, s2+1) : *s1 - *s2);
}

static void	sort_argv(char **argv)
{
	char	*sptr;
	char	**min;
	char	**vptr;

	while (*argv)
	{
		min = 0;
		vptr = argv;
		while (*++vptr)
		{
			if (locstrcmp(*argv, *vptr) > 0)
				min = vptr;
		}
		if (min)
		{
			sptr = *argv;
			*argv = *min;
			*min = sptr;
		}
		argv++;
	}
}
