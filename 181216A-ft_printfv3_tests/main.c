#include <stdio.h>
#include <float.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include "ft_printf.h"

#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_RESET   "\x1b[0m"

#define	CONVERSIONS	"dDibBoOuUxXeEfFgGcCsSpPt%"
#define	FLAGS		"#0-+ "
#define	CAST		"hljzL"
#define	SPACES		"                                                         "

int		ret_orig;
int		ret_mine;
char	buf_orig[16384];
char	buf_mine[16384];
int		margin;
int		show;

#define	PRINTF_TEST(format, arg) {\
	ret_orig = sprintf(buf_orig, format, arg);\
	ret_mine = ft_sprintf(buf_mine, format, arg);\
	margin = ft_printf("TEST:\t[%s]", format);\
	ft_printf("%.*s", 50 - margin, SPACES);\
	if (ret_orig == ret_mine\
		&& (ret_orig == -1 || !strncmp(buf_orig, buf_mine, ret_orig)))\
	{\
		ft_printf(C_GREEN"OK\n"C_RESET);\
		if (show && ret_orig != -1)\
			ft_printf("%.*s\n", ret_orig, buf_orig);\
		else if (show)\
			ft_printf("ERROR\n");\
	}\
	else\
	{\
		ft_printf(C_RED "FAILED\n" C_RESET);\
		ft_printf("ret_orig = %d\n", ret_orig);\
		ft_printf("ret_mine = %d\n", ret_mine);\
		ft_printf("ORIG>\t");\
		if (ret_orig != -1)\
		{\
			ft_printf("%.*s", ret_orig, buf_orig);\
			ft_printf("\n");\
		}\
		else\
			ft_printf("ERROR\n");\
		ft_printf("MINE>\t");\
		if (ret_mine != -1)\
		{\
			ft_printf("%.*s", ret_mine, buf_mine);\
			ft_printf("\n");\
		}\
		else\
			ft_printf("ERROR\n");\
	}\
}

void	test_mandatory(void)
{
	PRINTF_TEST("%s", "poney");
	PRINTF_TEST("%s" "4", "poney");
	PRINTF_TEST("%s", "poney truite");
	PRINTF_TEST("%4s", "poney truite");
	PRINTF_TEST("%22s", "poney truite");
	PRINTF_TEST("%.s", "poney truite");
	PRINTF_TEST("%.4s", "poney truite");
	PRINTF_TEST("%.20s", "poney truite");
	PRINTF_TEST("%20.0s", NULL);
	PRINTF_TEST("%-12s*", NULL);
	PRINTF_TEST("%20.0s*", "toy story");
	PRINTF_TEST("{%05.s}", 0);
	PRINTF_TEST("{%.0s}", 0);
	PRINTF_TEST("%s", NULL);
 	PRINTF_TEST("%025s", "steak hache");
	PRINTF_TEST("% 4.8hi", (short)-2345);
	PRINTF_TEST("%d", 42);
	PRINTF_TEST("%d", INT_MIN);
	PRINTF_TEST("%d", INT_MAX);
	PRINTF_TEST("%.8d", 25);
	PRINTF_TEST("%.08d", 25);
	PRINTF_TEST("%8d", -2525);
	PRINTF_TEST("%.12d", 50);
	PRINTF_TEST("%.8d", 585);
	PRINTF_TEST("%-.8d", 585);
	PRINTF_TEST("%-8d", 585);
	PRINTF_TEST("%zhd", 4294967296);
	PRINTF_TEST("% 03d", 0);
	PRINTF_TEST("%o", 0);
	PRINTF_TEST("%+o", 0);
	PRINTF_TEST("%o", -1);
	PRINTF_TEST("%x", 42);
	PRINTF_TEST("%#x", 2147);
	PRINTF_TEST("%x", -42);
	PRINTF_TEST("%-15x*", 542);
	PRINTF_TEST("%#.x", 1);
	PRINTF_TEST("%X", INT_MAX);
	PRINTF_TEST("%c", 'G');
	PRINTF_TEST("%5c", 'G');
	PRINTF_TEST("%c", NULL);
	PRINTF_TEST("%5c", 0);
	PRINTF_TEST("%1c", 0);
	PRINTF_TEST("%.2c", NULL);
	PRINTF_TEST("%.1c", NULL);
	PRINTF_TEST("%.3c", NULL);
	PRINTF_TEST("{%3c}", 0);
	PRINTF_TEST("{%03c}", 0);
	PRINTF_TEST("%c", 0);
	PRINTF_TEST("{%05.c}", 0);
	PRINTF_TEST("%p", 0);
	PRINTF_TEST("{%05.%}", 0);
	PRINTF_TEST("{%10R}", 42);
	PRINTF_TEST("{%-10R}", 42);
	PRINTF_TEST("{%05.Z}", 0);
	PRINTF_TEST("%o", 42);
	PRINTF_TEST("%f", 42.00);
	PRINTF_TEST("{%f}", 1.42);
    PRINTF_TEST("%f", FLT_MIN);
    PRINTF_TEST("%f", FLT_MAX);
    PRINTF_TEST("%f", DBL_MIN);
    PRINTF_TEST("%f", DBL_MAX);
    PRINTF_TEST("%Lf", LDBL_MIN);
}

void	test_bonus(int ac, char **av)
{
	ft_printf("implemented in original funcion:\n");
	PRINTF_TEST("%D", 42);
	PRINTF_TEST("%D", INT_MIN);
	PRINTF_TEST("%D", INT_MAX);
	PRINTF_TEST("%.8D", 25);
	PRINTF_TEST("%.08D", 25);
	PRINTF_TEST("%8D", -2525);
	PRINTF_TEST("%.12D", 50);
	PRINTF_TEST("%.8D", 585);
	PRINTF_TEST("%-.8D", 585);
	PRINTF_TEST("%-8D", 585);
	PRINTF_TEST("%zhD", 4294967296);
	PRINTF_TEST("% 03D", 0);
	PRINTF_TEST("%U", 42);
	PRINTF_TEST("%U", 4294967295);
	PRINTF_TEST("%hhU", ULONG_MAX);
	PRINTF_TEST("%U", 4294967296);
	PRINTF_TEST("%zU", 4294967296);
	PRINTF_TEST("%.2zU", 4294967296);
	PRINTF_TEST("%.0U*", 0);
	PRINTF_TEST("%0U*", 0);
	PRINTF_TEST("%O", 42);
	PRINTF_TEST("%O", 4294967295);
	PRINTF_TEST("%hhO", ULONG_MAX);
	PRINTF_TEST("%O", 4294967296);
	PRINTF_TEST("%zO", 4294967296);
	PRINTF_TEST("%.2zO", 4294967296);
	PRINTF_TEST("%.0O*", 0);
	PRINTF_TEST("%0O*", 0);
	PRINTF_TEST("%S", L"chewing gum🤗 🤗 🤗 🤗\0");
	PRINTF_TEST("%45S", L"chewing gum🤗 🤗 🤗 🤗\0");
	PRINTF_TEST("%5S", L"🤗");
	PRINTF_TEST("%5S", L"©");
	PRINTF_TEST("%5S", L"ᚙ");
	PRINTF_TEST("%S", L"123456🤗");
	PRINTF_TEST("%S", L"🤗🤗🤗🤗");
	PRINTF_TEST("%S", L"🤗🤗");
	PRINTF_TEST("%2S", L"🤗🤗🤗🤗");
	PRINTF_TEST("%S", L"米");
	PRINTF_TEST("%15S", NULL);
	PRINTF_TEST("%.3S", NULL);
	PRINTF_TEST("%.10S", L"Valgrind ©©©©");
	PRINTF_TEST("%.5S", L"Valgrind ©©©©");
	PRINTF_TEST("%.11S", L"Valgrind ©©©©");
	PRINTF_TEST("%.12S", L"Valgrind ©©©©");
	PRINTF_TEST("%.12S", L"Valgrind ©🀙");
	PRINTF_TEST("%030S", L"©©©");
	PRINTF_TEST("{%05.S}", L"42 c est cool");
	PRINTF_TEST("{%.22S}", L"🤗🤗🤗🤗🤗©©");
	PRINTF_TEST("%ls", L"chewing gum🤗 🤗 🤗 🤗\0");
	PRINTF_TEST("%45ls", L"chewing gum🤗 🤗 🤗 🤗\0");
	PRINTF_TEST("%5ls", L"🤗");
	PRINTF_TEST("%5ls", L"©");
	PRINTF_TEST("%5ls", L"ᚙ");
	PRINTF_TEST("%ls", L"123456🤗");
	PRINTF_TEST("%ls", L"🤗🤗🤗🤗");
	PRINTF_TEST("%ls", L"🤗🤗");
	PRINTF_TEST("%2ls", L"🤗🤗🤗🤗");
	PRINTF_TEST("%15ls", NULL);
	PRINTF_TEST("%.3ls", NULL);
	PRINTF_TEST("%.10ls", L"Valgrind ©©©©");
	PRINTF_TEST("%.5ls", L"Valgrind ©©©©");
	PRINTF_TEST("%.11ls", L"Valgrind ©©©©");
	PRINTF_TEST("%.12ls", L"Valgrind ©©©©");
	PRINTF_TEST("%.12ls", L"Valgrind ©🀙");
	PRINTF_TEST("%030ls", L"©©©");
	PRINTF_TEST("{%05.ls}", L"42 c est cool");
	PRINTF_TEST("{%.22ls}", L"🤗🤗🤗🤗🤗©©");
	PRINTF_TEST("%C", 'G');
	PRINTF_TEST("%C", L'©');
	PRINTF_TEST("%C", L'ߺ');
	PRINTF_TEST("%C", L'ࠀ');
	PRINTF_TEST("%C", L'🤗');
	PRINTF_TEST("%C", L'©');
	PRINTF_TEST("%C", L'©');
	PRINTF_TEST("%C", L'¡');
	PRINTF_TEST("%C", 173);
	PRINTF_TEST("%C", 35);
	PRINTF_TEST("%C", -5);
	PRINTF_TEST("%C", 255);
	PRINTF_TEST("%C", 256);
	PRINTF_TEST("%C", 35);
	PRINTF_TEST("%e", 1.000);
	PRINTF_TEST("%e", 4242.42424242);
	PRINTF_TEST("%e", 0.0004242);
	PRINTF_TEST("%.3e", 0.0004242);
	PRINTF_TEST("%10.2e", 0.0004242);
	PRINTF_TEST("%#5.12e", 0.0004242);
	PRINTF_TEST("%#5.12e", 0.0004242);
    PRINTF_TEST("%e", FLT_MIN);
    PRINTF_TEST("%e", FLT_MAX);
	PRINTF_TEST("%e", DBL_MIN);
    PRINTF_TEST("%e", DBL_MAX);
    PRINTF_TEST("%Le", LDBL_MIN);
    PRINTF_TEST("%Le", LDBL_MAX);
	PRINTF_TEST("%g", 42.000);
	PRINTF_TEST("%g", 42.420);
    PRINTF_TEST("%g", FLT_MIN);
    PRINTF_TEST("%g", FLT_MAX);
    PRINTF_TEST("%g", DBL_MIN);
    PRINTF_TEST("%g", DBL_MAX);
    PRINTF_TEST("%Lg", LDBL_MIN);
    PRINTF_TEST("%Lg", LDBL_MAX);

	ft_printf("\n\nnot implemented in original function:\n");
	ft_printf("\nt conversion:\n");
	ft_printf("\targv:\n");
	ft_printf("%#*t\t\t%s\n", ac, av);

	unsigned int		int_tab[10] = {
		0, 1, UINT_MAX, UINT_MAX, INT_MIN, INT_MIN, 6, 654676, 42, 9
	};
	ft_printf("\n\tunsigned int array (with 2 fields):\n");
	ft_printf("%#10.2t\t\tfirst field: %08x\tsecond field: %u\n", int_tab);

	ft_printf("b conversion:\n");
	ft_printf("\t\tunsigned int array:\n");
	ft_printf("\t\tdec: %#3t%-32u \n", int_tab + 5);
	ft_printf("\t\tbin: %#3t%.32b \n", int_tab + 5);

	int	fd = open("fdtest", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	ft_dprintf(fd, "test dprintf:\n");
	ft_dprintf(fd, "\n\tunsigned int array (with 2 fields):\n");
	ft_dprintf(fd, "%#10.2t\t\tfirst field: %08x\tsecond field: %u\n", int_tab);
	close(fd);
}

int		main(int argc, char **argv)
{
	show = argc > 1;
	setlocale(LC_ALL, "");
	if (show && !strcmp(argv[1], "bonus"))
		test_bonus(argc, argv);
	else
		test_mandatory();
	return (0);
}
