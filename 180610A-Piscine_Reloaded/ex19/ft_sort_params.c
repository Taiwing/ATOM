#include <libf3.h>

static int	ft_loc_strcmp(char *s1, char *s2);

int			main(int argc, char *argv[])
{
	int		small;
	char	*ptr;

	argv++;
	while (*argv)
	{
		small = argc * 0; /*olololol I'm using argc !!!!!*/
		while (argv[small])
		{
			/*compare small and small+1*/
			/*if small+1 is bigger or NULL exchange argv[small] and argv[small+1]*/
			if(!argv[small+1] || ft_loc_strcmp(argv[small], argv[small+1]) <= 0)
			{
				ptr = argv[small];
				argv[small] = argv[small+1];
				argv[small+1] = ptr;
			}
			small++; /*anyway, increment small*/
			if (!argv[small-1]) /*if NULL has been exchanged*/
			{
				while (*argv[small])	/*print small*/
					ft_putchar(*argv[small]++);
				ft_putchar('\n');
				small--; /*stop the loop*/
			}
		}
	}
}

static int	ft_loc_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2 && *++s1 == *++s2);
	return *s1-*s2;
}
