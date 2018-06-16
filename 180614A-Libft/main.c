#include "libf4.h"

/*TEST includes*/
#include <stdio.h>
#include <string.h>

/*TEST function for ft_striter*/
void	from_42(char *och)
{
	static char nch = 42;

	*och = nch++;
}

/*TEST function for ft_striteri*/
void	indexator(unsigned int i, char *och)
{
	*och = 48+(i%10);
}

/*TEST function for ft_strmap*/
char	letterize(char c)
{
	return (c > 47 && c < 58 ? c+49 : c);
}

/*TEST function for ft_strmapi*/
char	ft_rcmodalpha(unsigned int i, char c)
{
	return (97 + ((c+42+i) % 26));
}

int		main(void)
{
	/*ft_strlen TEST*/
	char lol[] = "lol";
	printf("ft_strlen TEST:\nlol: %li\n\n", ft_strlen(lol));

	/*ft_strdup TEST*/
	char *dup = ft_strdup(lol);
	printf("ft_strdup TEST:\nlol: %s\n\n", dup);

	/*ft_memalloc TEST*/
	char *str = (char *)ft_memalloc(12);
	printf("ft_memalloc TEST:\n12: ");
	for (int i = 0; i < 12; i++)
		str[i] == 0 ? printf("0") : printf("1");
	printf("\n\n");

	/*ft_memdel TEST*/
	ft_memdel((void *)&str);
	printf("ft_memdel TEST:\n");
	printf("%s\n\n", (str ? "ERROR!" : "ALL RIGHT MATE"));

	/*ft_strnew TEST*/
	str = ft_strnew(16);
	printf("ft_strnew TEST:\n16: ");
	for (int i = 0; i < 16; i++)
		printf("%d", (str[i] != 0));
	printf("\n\n");

	/*ft_strdel TEST*/
	ft_strdel(&str);
	printf("ft_strdel TEST:\n");
	printf("%s\n\n", (str ? "ERROR!" : "ALL RIGHT MATE"));

	/*ft_strclr TEST*/
	str = ft_strnew(21);
	strcat(str, "Hello, I'm a string!");
	printf("ft_strclr TEST:\n");
	printf("\"%s\": ", str);
	ft_strclr(str);
	for (int i = 0; i < 21; i++)
		printf("%d", (str[i] != 0));
	printf("\n\n");

	/*ft_striter TEST*/
	strcat(str, "Hello, I'm a string!");
	printf("ft_striter TEST:\n");
	ft_striter(str, &from_42);
	printf("\"%s\"\n\n", str);

	/*ft_striteri TEST*/
	printf("ft_striteri TEST:\n");
	ft_striteri(str, &indexator);
	printf("\"%s\"\n\n", str);

	/*ft_strmap TEST*/
	printf("ft_strmap TEST:\n");
	char *lett = ft_strmap(str, &letterize);
	printf("\"%s\"\n\n", lett);

	/*ft_strmapi TEST*/
	printf("ft_strmapi TEST:\n");
	char *crypted = ft_strmapi(lett, &ft_rcmodalpha);
	printf("\"%s\"\n\n", crypted);

	/*ft_strequ TEST*/
	printf("ft_strequ TEST:\n");
	printf("\"%s\" %s \"%s\"\n", lett, ft_strequ(lett, lett) ? "=" : "!=", lett);
	printf("\"%s\" %s \"%s\"\n\n", lett, ft_strequ(lett, crypted) ? "=" : "!=", crypted);

	/*ft_strnequ TEST*/
	char bar[] = "OLOLOLOL this is a troll!!!";
	char foo[] = "OLOLOLOL what the fuck ?";
	printf("ft_strnequ TEST:\n");
	printf("0: \"%s\" %s \"%s\"\n", foo, ft_strnequ(foo, bar, 0) ? "=" : "!=", bar);
	printf("9: \"%s\" %s \"%s\"\n", foo, ft_strnequ(foo, bar, 9) ? "=" : "!=", bar);
	printf("10: \"%s\" %s \"%s\"\n", foo, ft_strnequ(foo, bar, 10) ? "=" : "!=", bar);
	printf("100: \"%s\" %s \"%s\"\n\n", foo, ft_strnequ(foo, bar, 100) ? "=" : "!=", bar);

	/*ft_strsub TEST*/
	printf("ft_strsub TEST:\n");
	char *sub = ft_strsub(bar, 0, ft_strlen(bar));
	printf("sub %d-%li: \"%s\" \"%s\"\n", 0, ft_strlen(bar), bar, sub);
	ft_strdel(&sub);
	sub = ft_strsub(bar, 2, 5);
	printf("sub %d-%d: \"%s\" \"%s\"\n\n", 2, 5, bar, sub);

	/*ft_strjoin TEST*/
	printf("ft_strjoin TEST:\n");
	char *join = ft_strjoin(foo, bar);
	printf("\"%s\" + \"%s\" = %s\n", foo, bar, join);
	ft_strdel(&join);
	join = ft_strjoin(foo, sub);
	printf("\"%s\" + \"%s\" = %s\n\n", foo, sub, join);

	/*ft_strtrim TEST*/
	printf("ft_strtrim TEST:\n");
	char notrimed[] = " \t\t   OLOLOL OLOLZ   ";
	char trimmed[] = "Hello, I'm a trimmed string!";
	char *trim = ft_strtrim(notrimed);
	printf("\"%s\": \"%s\"\n", notrimed, trim);
	ft_strdel(&trim);
	trim = ft_strtrim(trimmed);
	printf("\"%s\": \"%s\"\n", trimmed, trim);
	ft_strdel(&trim);
	trim = ft_strtrim(" ");
	printf("\"%s\": \"%s\"\n", " ", trim ? trim : "NULL");

	/*ft_strsplit TEST*/
	printf("ft_strsplit TEST:\n");
	char tospl[] = "*salut*les***etudiants*";
	char **split = ft_strsplit(tospl, '*');
	printf("\"%s\"\nsplit:\n", tospl);
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	char tospl2[] = "the###first#byte######is#good#";
	ft_memdel((void **)&split);
	split = ft_strsplit(tospl2, '#');
	printf("\"%s\"\nsplit:\n", tospl2);
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	char normal[] = "Hello, I'm a string!";
	ft_memdel((void **)&split);
	split = ft_strsplit(normal, '~');
	printf("\"%s\"\nsplit:\n", normal);
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	printf("\"%s\"\nsplit:\n", "empty string");
	ft_memdel((void **)&split);
	split = ft_strsplit("", '~');
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	printf("\n");

	/*ft_itoa TEST*/
	printf("ft_itoa TEST\n");
	char *nbr = ft_itoa(42);
	printf("%d: %s\n", 42, nbr);
	ft_strdel(&nbr);
	nbr = ft_itoa(-725058);
	printf("%d: %s\n", -725058, nbr);
	ft_strdel(&nbr);
	nbr = ft_itoa(0);
	printf("%d: %s\n\n", 0, nbr);

	/*ft_putchar TEST*/
	printf("ft_putchar TEST:\n");
	char ptch[] = "Hello, I'm a string!\n";
	for (int i = 0; ptch[i]; i++)
		ft_putchar(ptch[i]);
	ft_putchar('\n');

	/*ft_putstr TEST*/
	ft_putstr("ft_putstr TEST:\n\n");

	/*ft_putendl TEST*/
	ft_putendl("ft_putendl TEST:\n");

	return 0;
}
