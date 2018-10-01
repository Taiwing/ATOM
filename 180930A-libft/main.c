#include "libft.h"

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
	/*ft_memset TEST*/
	char *mems = ft_strdup("Hello, I'm a string!");
	printf("ft_memset TEST:\n\"%s\": ", mems);
	printf("\"%s\"\n\n", (char *)ft_memset((void *)mems, 'a', 13));

	/*ft_bzero TEST*/
	printf("ft_bzero TEST:\n");
	ft_bzero((void *)mems, 13);
	for (int i = 0; i < 21; i++)
		printf("%c", (mems[i] ? mems[i] : '0'));
	printf("\n\n");

	/*ft_memcpy TEST*/
	printf("ft_memcpy TEST:\n");
	printf("\"%s\"\n\n", (char *)ft_memcpy((void *)mems, (void *)(mems+13), 7));

	/*memccpy TEST*/
	printf("memccpy TEST:\n");
	char *memcc = strdup("Hello, I'm a string!");
	char *dest = ft_strnew(20);
	char *res = memccpy(dest, memcc, 'a', 6);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc, dest, res);
	ft_strclr(dest);
	res = memccpy(dest, memcc, 'a', 15);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc, dest, res);
	ft_strclr(dest);
	dest[12] = 'L';
	dest[13] = 'O';
	dest[14] = 'L';
	res = memccpy(dest, memcc, 'a', 15);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc, dest, res);
	ft_memset((void *)dest, 0, 12);
	res = memccpy(dest, memcc, 'a', 12);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc, dest, res);
	ft_strdel(&dest);
	dest = ft_strnew(12);
	res = memccpy(dest, memcc, 'a', 12);
	printf("\"%s\": \"%s\" \"%s\"\n\n", memcc, dest, res);

	/*ft_memccpy TEST*/
	printf("ft_memccpy TEST:\n");
	char *memcc2 = strdup("Hello, I'm a string!");
	char *dest2 = ft_strnew(20);
	char *res2 = ft_memccpy(dest2, memcc2, 'a', 6);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc2, dest2, res2);
	ft_strclr(dest2);
	res2 = ft_memccpy(dest2, memcc2, 'a', 15);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc2, dest2, res2);
	ft_strclr(dest2);
	dest2[12] = 'L';
	dest2[13] = 'O';
	dest2[14] = 'L';
	res2 = ft_memccpy(dest2, memcc2, 'a', 15);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc2, dest2, res2);
	ft_memset((void *)dest2, 0, 12);
	res2 = ft_memccpy(dest2, memcc2, 'a', 12);
	printf("\"%s\": \"%s\" \"%s\"\n", memcc2, dest2, res2);
	ft_strdel(&dest2);
	dest2 = ft_strnew(12);
	res2 = ft_memccpy(dest2, memcc2, 'a', 12);
	printf("\"%s\": \"%s\" \"%s\"\n\n", memcc2, dest2, res2);

	/*memmove TEST*/
	char *memm = strdup("Hello, I'm a string!");
	printf("memmove TEST:\n");
	printf("NO OVERLAP: \"%s\": ", memm);
	printf("\"%s\"\n", (char *)memmove((void *)memm, (void *)memm+13, 6));
	printf("OVERLAP:    \"%s\": ", memm);
	printf("\"%s\"\n\n", (char *)memmove((void *)memm, (void *)memm+5, 10));

	/*ft_memmove TEST*/
	printf("ft_memmove TEST:\n");
	printf("NO OVERLAP: \"%s\": ", memcc);
	printf("\"%s\"\n", (char *)ft_memmove((void *)memcc, (void *)memcc+13, 6));
	printf("OVERLAP:    \"%s\": ", memcc);
	printf("\"%s\"\n\n", (char *)ft_memmove((void *)memcc, (void *)memcc+5, 10));

	/*memchr TEST*/
	printf("memchr TEST:\n");
	char *memch = ft_strdup("Hello, I'm a string!");
	printf("\"%s\":\n", memch);
	printf("a: %s\n", (char *)memchr((void *)memch, 'a', 42));
	printf("z: %s\n", (char *)memchr((void *)memch, 'z', 42));
	printf("I (n = 8): %s\n", (char *)memchr((void *)memch, 'I', 8));
	printf("I (n = 7): %s\n", (char *)memchr((void *)memch, 'I', 7));
	printf("I (n = 6): %s\n", (char *)memchr((void *)memch, 'I', 6));
	printf("H (n = 0): %s\n\n", (char *)memchr((void *)memch, 'H', 0));

	/*ft_memchr TEST*/
	printf("ft_memchr TEST:\n");
	printf("\"%s\":\n", memch);
	printf("a: %s\n", (char *)ft_memchr((void *)memch, 'a', 42));
	printf("z: %s\n", (char *)ft_memchr((void *)memch, 'z', 42));
	printf("I (n = 8): %s\n", (char *)ft_memchr((void *)memch, 'I', 8));
	printf("I (n = 7): %s\n", (char *)ft_memchr((void *)memch, 'I', 7));
	printf("I (n = 6): %s\n", (char *)ft_memchr((void *)memch, 'I', 6));
	printf("H (n = 0): %s\n\n", (char *)ft_memchr((void *)memch, 'H', 0));

	/*memcmp TEST*/
	printf("memcmp TEST:\n");
	char *memcm = strdup("Hello, I'm a sOT A STRING!!!!!! AHAHAHAH");
	printf("cmp: \"%s\" \"%s\"\n", memch, memcm);
	printf("n = 42: %d\n", memcmp((void *)memch, (void *)memcm, 42));
	printf("n = 0: %d\n", memcmp((void *)memch, (void *)memcm, 0));
	printf("n = 13: %d\n", memcmp((void *)memch, (void *)memcm, 13));
	printf("n = 14: %d\n", memcmp((void *)memch, (void *)memcm, 14));
	printf("n = 15: %d\n\n", memcmp((void *)memch, (void *)memcm, 15));

	/*ft_memcmp TEST*/
	printf("ft_memcmp TEST:\n");
	printf("cmp: \"%s\" \"%s\"\n", memch, memcm);
	printf("n = 42: %d\n", ft_memcmp((void *)memch, (void *)memcm, 42));
	printf("n = 0: %d\n", ft_memcmp((void *)memch, (void *)memcm, 0));
	printf("n = 13: %d\n", ft_memcmp((void *)memch, (void *)memcm, 13));
	printf("n = 14: %d\n", ft_memcmp((void *)memch, (void *)memcm, 14));
	printf("n = 15: %d\n\n", ft_memcmp((void *)memch, (void *)memcm, 15));

	/*ft_strlen TEST*/
	char lol[] = "lol";
	printf("ft_strlen TEST:\nlol: %li\n\n", ft_strlen(lol));

	/*ft_strdup TEST*/
	char *dup = ft_strdup(lol);
	printf("ft_strdup TEST:\nlol: %s\n\n", dup);

	/*ft_strcpy TEST*/
	char *scpy = (char *)malloc(ft_strlen(memch)+1);
	printf("ft_strcpy TEST:\n%s\n\n", ft_strcpy(scpy, memch));

	/*ft_strncpy TEST*/
	free(scpy);
	scpy = (char *)malloc(42);
	printf("ft_strncpy TEST:\n");
	printf("n = 42: %s\n", ft_strncpy(scpy, memch, 42));
	ft_memset((void *)scpy, '6', 41);
	scpy[41] = 0;
	printf("ft_memset scpy: %s\n", scpy);
	printf("n = strlen(memch): %s\n\n", ft_strncpy(scpy, memch, ft_strlen(memch)));

	/*ft_strcat TEST*/
	bzero((void *)scpy+ft_strlen(memch), 42-ft_strlen(memch));
	printf("ft_strcat TEST:\n");
	printf("\"%s\" + \" lol\" =\n", scpy);
	printf("\"%s\"\n\n", ft_strcat(scpy, " lol"));

	/*ft_strncat TEST*/
	printf("ft_strncat TEST:\n");
	char adds[] = " #metoo!";
	printf("\"%s\" + \"%s\" =\n", scpy, adds);
	printf("n = 8: \"%s\"\n", ft_strncat(scpy, adds, 8));
	bzero((void *)scpy+ft_strlen(memch), 42-ft_strlen(memch));
	printf("\"%s\" + \"%s\" =\n", scpy, adds);
	printf("n = 4: \"%s\"\n", ft_strncat(scpy, adds, 4));
	bzero((void *)scpy+ft_strlen(memch), 42-ft_strlen(memch));
	printf("n = 12: \"%s\"\n\n", ft_strncat(scpy, adds, 12));

	/*ft_strlcat TEST*/
	bzero((void *)scpy+ft_strlen(memch), 42-ft_strlen(memch));
	char cat[] = " I'm a Tail!";
	printf("ft_strlcat TEST:\n");
	printf("\"%s\" + \"%s\" =\n", memch, cat);
	size_t ret = ft_strlcat(scpy, cat, 42);
	printf("\"%s\"\nlength = %li\n", scpy, ret);
	char *end = (char *)malloc(11);
	memset((void *)end, 42, 10);
	end[10] = 0;
	printf("TEST: scpy = %li && end = %li\n", ft_strlen(scpy), ft_strlen(end));
	printf("TEST: end = \"%s\"\n", end);
	ret = ft_strlcat(scpy, end, 42);
	printf("\"%s\"\nlength = %li\n\n", scpy, ret);

	/*ft_strchr TEST*/
	printf("ft_strchr TEST:\n");
	char hell[] = "Hello, I'm a string!";
	ft_putendl(hell);
	printf("I: %s\n", ft_strchr(hell, 'I'));
	printf("z: %s\n\n", ft_strchr(hell, 'z'));

	/*ft_strrchr TEST*/
	printf("ft_strrchr TEST:\n");
	ft_putendl(hell);
	printf("' ': %s\n", ft_strrchr(hell, ' '));
	printf("z: %s\n\n", ft_strrchr(hell, 'z'));

	/*ft_strstr TEST*/
	printf("ft_strstr TEST:\n");
	char first[] = "string";
	char second[] = "string!";
	char third[] = "lol";
	char fourth[] = "strink";
	ft_putendl(hell);
	printf("\"%s\": \"%s\"\n", first, ft_strstr(hell, first));
	printf("\"%s\": \"%s\"\n", second, ft_strstr(hell, second));
	printf("\"%s\": \"%s\"\n", third, ft_strstr(hell, third));
	printf("\"%s\": \"%s\"\n\n", fourth, ft_strstr(hell, fourth));

	/*ft_strnstr TEST*/
	printf("ft_strnstr TEST:\n");
	char nsecond[] = "string";
	char nthird[] = "string!";
	char nfourth[] = "strink";
	ft_putendl((char const *)hell);
	printf("len = 18 \"%s\": \"%s\"\n", nsecond, ft_strnstr(hell, nsecond, 18));
	printf("len = 19 \"%s\": \"%s\"\n", nsecond, ft_strnstr(hell, nsecond, 19));
	printf("len = 20 \"%s\": \"%s\"\n", nsecond, ft_strnstr(hell, nsecond, 20));
	printf("len = 19 \"%s\": \"%s\"\n", nthird, ft_strnstr(hell, nthird, 19));
	printf("len = 20 \"%s\": \"%s\"\n", nthird, ft_strnstr(hell, nthird, 20));
	printf("len = 21 \"%s\": \"%s\"\n", nthird, ft_strnstr(hell, nthird, 21));
	printf("len = 18 \"%s\": \"%s\"\n", nfourth, ft_strnstr(hell, nfourth, 18));
	printf("len = 19 \"%s\": \"%s\"\n", nfourth, ft_strnstr(hell, nfourth, 19));
	printf("len = 20 \"%s\": \"%s\"\n\n", nfourth, ft_strnstr(hell, nfourth, 20));

	/*ft_strcmp TEST*/
	printf("ft_strcmp TEST:\n");
	char strf[] = "YEAH DUDE, BEST MOTHERFUCKING STRING EVER!";
	char *strs = strdup(strf);
	char strff[] = "YEAH DUDE, BEST MOTHERFUCKING STRING EVER";
	char strfs[] = "YEAH DUDE, BEST MOTHERFUCKING STRING EVER ";
	char strft[] = "YEAH DUDE, BEST MOTHERFUCKING STRING EVER! ";
	printf("strcmp\n\"%s\"\n\"%s\"\n%d\n", strf, strs, ft_strcmp(strf, strs));
	printf("strcmp\n\"%s\"\n\"%s\"\n%d\n", strf, strff, ft_strcmp(strf, strff));
	printf("strcmp\n\"%s\"\n\"%s\"\n%d\n", strf, strfs, ft_strcmp(strf, strfs));
	printf("strcmp\n\"%s\"\n\"%s\"\n%d\n\n", strf, strft, ft_strcmp(strf, strft));

	/*ft_strncmp TEST*/
	printf("ft_strncmp TEST:\n");
	printf("strncmp 100\n\"%s\"\n\"%s\"\n%d\n", strf, strs, ft_strncmp(strf, strs, 100));
	printf("strncmp 41\n\"%s\"\n\"%s\"\n%d\n", strf, strff, ft_strncmp(strf, strff, 41));
	printf("strncmp 42\n\"%s\"\n\"%s\"\n%d\n", strf, strfs, ft_strncmp(strf, strfs, 42));
	printf("strncmp 42\n\"%s\"\n\"%s\"\n%d\n\n", strf, strft, ft_strncmp(strf, strft, 42));

	/*ft_atoi TEST*/
	printf("ft_atoi TEST:\n");
	printf("42: %d\n", ft_atoi("42"));
	printf("-306: %d\n", ft_atoi("-306"));
	printf("-0000923: %d\n\n", ft_atoi("-0000923"));

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
	char lite[] = "Hello, I'm a literal string!";
	char *alls = ft_strdup("Hello, I'm an allocated string!");
	ft_putendl("ft_putendl TEST:");
	ft_putendl(lite);
	ft_putendl(alls);
	ft_putchar('\n');

	/*ft_putnbr TEST*/
	ft_putendl("ft_putnbr TEST:");
	ft_putstr("42: ");
	ft_putnbr(42);
	ft_putstr("\n-45902: ");
	ft_putnbr(-45902);
	ft_putstr("\n0: ");
	ft_putnbr(0);
	ft_putstr("\n\n");

	/*ft_put_fd TEST*/
	ft_putstr_fd("ft_put_fd TEST:\n", 2);
	ft_putendl_fd("ERROR (Ironically, it means it works)", 2);
	ft_putnbr_fd(42424242, 2);
	ft_putstr_fd("\n\n", 2);

	return 0;
}
