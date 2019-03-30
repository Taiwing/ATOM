#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int		main(void)
{
	char *tab[10] = {
		"ok                                                   |",
		"lol                                                  |",
		"what do you say ?                                    |",
		"does it work ?                                       |",
		"I hope it does dude.                                 |",
		"but I think it wont                                  |",
		"I am not a pessismist but it is hard to do this shit |",
		"I don't have any idea for what to write now          |",
		"slkjfsoahfa;slhyfg                                   |",
		"pleeeeeeeease appear                                 |"
	};

	ft_printf("vanilla:\n");
	ft_printf("%10t%s", (void *)tab);
	ft_printf("\n\n\npretext and aftertext:");
	ft_printf("%10t\n lol ? %s\nDO YOU PRINT ?\n", (void *)tab);
	ft_printf("\n\npretext 2 per lines:");
	ft_printf("%10.2t\n%s %s", (void *)tab);
	ft_printf("\n\n\nvanilla plus afterchar:\n");
	ft_printf("%#10t%s\n", (void *)tab);
	ft_printf("\n\npretext plus afterchar:\n");
	ft_printf("%#10t| %s\n", (void *)tab);
	ft_printf("\n\ntrailing conversion:\n");
	ft_printf("%#10t%s%2$s", (void *)tab, " \"trailing string\"\n");

	int	num[10] = { 120, 444, 333, 666, 21003, 123456789, 0, 87, 5, 99 };

	ft_printf("\n\nvanilla:\n");
	ft_printf("%10t%d", (void *)num);
	ft_printf("\n\n\npretext and aftertext:");
	ft_printf("%10t\n lol ? %d\nDO YOU PRINT ?\n", (void *)num);
	ft_printf("\n\npretext 2 per lines:");
	ft_printf("%10.2t\n%d %d", (void *)num);
	ft_printf("\n\n\nvanilla plus afterchar:\n");
	ft_printf("%#10t%d\n", (void *)num);
	ft_printf("\n\npretext plus afterchar:\n");
	ft_printf("%#10t| %d\n", (void *)num);

	char *dtab[10][5] = {
		{"1", "2", "3", "4", "5"},
		{"red", "white", "blue", "purple", "green"},	
		{"iran", "guatemala", "grenade", "congo", "chili"},
		{"doctor", "who", "sucks", "right", "now"},
		{"anais", "vient", "me", "voir", "quand j'ecris ca"},
		{"does", NULL, "it", NULL, "work?"},
		{"humpty", "dumpy", "sat", "on", "a wall"},
		{"smooooooooke", "on", "the", "waaaaaaaater", "fiiiire"},
		{"in", "the", "skyyyyyy", "ta ta ta", "ta ta ta ta"},
		{"woof", "this", "is", "almost", "over"}
	};
	
	//void	*tmp = (void *)dtab;
	char	***ptr = (char ***)malloc(10 * sizeof(char **));
	int i = 0, j;
	
	while (i < 10)
	{
		j = 0;
		ptr[i] = (char **)malloc(5 * sizeof(char *));
		while (j < 5)
		{
			ptr[i][j] = dtab[i][j];
			j++;
		}
		i++;
	}		

	/*i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 5)
			ft_printf("%s ", ptr[i][j++]);
		ft_printf("\n");
		i++;
	}*/		

	ft_printf("\n\ndouble pointer of strings plus trailing character:\n");
	ft_printf("%#10t|%5t %s\n", (void *)ptr);
	ft_printf("\n\ndouble tab plus trailing character:\n");
	ft_printf("%#50t| %s\n", (void *)dtab);
	
	return (0);
}
