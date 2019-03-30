#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "bint.h"
#include "bint_mathconsts.h"
#include "dragon4.h"
#include "ft_printf.h"

void	show_bint(t_bint b, int raw)
{
	t_u32	i;
	
	printf("ARR_SIZE = %u\n", (b[0] & ARR_SIZE) >> 16);
	printf("NBR_LENGTH = %u\n", b[0] & NBR_LENGTH);
	if (raw == 1)
	{
		printf("raw mem: ");
		i = -1;
		while (++i < (b[0] & NBR_LENGTH) + 1)
			printf("%.8x ", b[i]);
	}
	else if (raw == 0)
	{
		printf("val: ");
		i = (b[0] & NBR_LENGTH) + 1;
		while (--i > 0)
			printf("%.8x ", b[i]);
	}
	else if (raw == 2)
	{
		printf("val: ");
		i = (b[0] & NBR_LENGTH) + 1;
		while (--i > 0)
			printf("%.8x", b[i]);
	}
	else if (raw == 3)
	{
		printf("raw mem: ");
		i = -1;
		printf("const unsigned int	g_pow10[%d] = {\n", (b[0] & NBR_LENGTH) + 1);
		while (++i < (b[0] & NBR_LENGTH) + 1)
		{
			if (b[i])
				printf("%#.8x,%c", b[i], (i + 1) % 6 ? ' ' : '\n');
			else
				printf("0x00000000,%c", (i + 1) % 6 ? ' ' : '\n');
		}
		printf("\n};\n");
	}
	else if (raw == 3)
	printf("\n");
}


//bint main
/*int		main(int argc, char **argv)
{
	t_u32	i;
	t_u64	nbr;
	t_u32	exp;
	t_u32	quotient;
	t_u32	b[BINT_SIZE];
	t_u32	n[BINT_SIZE];
	t_u32	p[BINT_SIZE];
	t_u32	t[BINT_SIZE];
	t_u32	m[BINT_SIZE];
	t_u32	a[BINT_SIZE];
	t_u32	d[2];

	if (argc < 2)
		return (1);
	bintinit(b, 0);
	atobint(b, argv[1]);
	printf("input bint:\n");
	show_bint(b, argc == 3);
	srand(time(NULL));
	nbr = rand();
	printf("\nrandom u32:\nraw value: %ju\n", nbr);
	bintinit(n, 0);
	bintset(nbr, n);
	show_bint(n, argc == 3);
	nbr += nbr << 32;
	printf("\nrandom u64:\nraw value: %ju\n", nbr);
	bintset(nbr, n);
	show_bint(n, argc == 3);
	printf("\nshift left 1 block:\n");
	if (!shiftleft_bint(n, 32))
		printf("FAIL !\n");
	else
		show_bint(n, argc == 3);
	printf("\nshift left 1 bit:\n");
	if (!shiftleft_bint(n, 1))
		printf("FAIL !\n");
	else
		show_bint(n, argc == 3);
	printf("\nshift left 3 blocks and 5 bits:\n");
	if (!shiftleft_bint(n, 101))
		printf("FAIL !\n");
	else
	printf("\n");
}


//bint main
int		main(int argc, char **argv)
{
	t_u32	i;
	t_u64	nbr;
	t_u32	exp;
	t_u32	quotient;
	t_u32	b[BINT_SIZE];
	t_u32	n[BINT_SIZE];
	t_u32	p[BINT_SIZE];
	t_u32	t[BINT_SIZE];
	t_u32	m[BINT_SIZE];
	t_u32	a[BINT_SIZE];
	t_u32	d[2];

	if (argc < 2)
		return (1);
	bintinit(b, 0);
	atobint(b, argv[1]);
	printf("input bint:\n");
	show_bint(b, argc == 3);
	srand(time(NULL));
	nbr = rand();
	printf("\nrandom u32:\nraw value: %ju\n", nbr);
	bintinit(n, 0);
	bintset(nbr, n);
	show_bint(n, argc == 3);
	nbr += nbr << 32;
	printf("\nrandom u64:\nraw value: %ju\n", nbr);
	bintset(nbr, n);
	show_bint(n, argc == 3);
	printf("\nshift left 1 block:\n");
	if (!shiftleft_bint(n, 32))
		printf("FAIL !\n");
	else
		show_bint(n, argc == 3);
	printf("\nshift left 1 bit:\n");
	if (!shiftleft_bint(n, 1))
		printf("FAIL !\n");
	else
		show_bint(n, argc == 3);
	printf("\nshift left 3 blocks and 5 bits:\n");
	if (!shiftleft_bint(n, 101))
		printf("FAIL !\n");
	else
		show_bint(n, argc == 3);
	bintinit(p, 0);
	exp = 0;
	while (exp < 161)
	{
		printf("\n2^%d:\n", exp);
		pow2_bint(p, exp);
		show_bint(p, argc == 3);
		exp += 32;
	}
	bintinit(t, 0);
	exp = 0;
	while (exp < 512)
	{
		printf("\n10^%d:\n", exp);
		pow10_bint(t, exp);
		show_bint(t, argc == 3);
		exp = exp < 8 ? exp + 1 : (exp * 2) + 1;
	}
	exp = 0;
	while (exp < 300)
	{
		nbr = (rand() % 10000) + 1;
		printf("\n%ju * 10^%d:\n", nbr, exp);
		bintset(nbr, n);
		multpow10_bint(t, n, exp);
		show_bint(t, argc == 3);
		exp = (exp * 2) + 1;
	}
	bintinit(d, 0);
	bintset(2, d);
	printf("\nb:\n");
	show_bint(b, argc == 3);
	bintinit(m, 0);
	bintinit(a, 0);
	bintcpy(b, a);
	bintcpy(b, m);
	bintcpy(b, n);
	bintcpy(b, p);
	exp = 0;
	while (exp < 257)
	{
		i = exp;
		exp += 16;
		while (++i < exp + 1)
		{
			bintclr(t);
			mult_bint(t, d, m);
			bintcpy(t, m);
			bintclr(t);
			mult2_bint(t, n);
			bintcpy(t, n);
			smult2_bint(p);
			bintclr(t);
			add_bint(t, a, a);
			bintcpy(t, a);
		}
		bintcpy(b, t);
		shiftleft_bint(t, exp);
		printf("\nb * 2^%d: ", exp);
		if (bintcmp(t, m))
			printf("FAILED mult !!!");
		else if (bintcmp(t, n))
			printf("FAILED mult2 !!!");
		else if (bintcmp(t, p))
			printf("FAILED smult2 !!!");
		else if (bintcmp(t, a))
			printf("FAILED add !!!");
		else
			printf("OK");
	}
	printf("\n\nb * 2^%d (shiftleft):\n", exp);
	show_bint(t, argc == 3);
	printf("\nb * 2^%d (mult):\n", exp);
	show_bint(m, argc == 3);
	printf("\nb * 2^%d (mult2):\n", exp);
	show_bint(n, argc == 3);
	printf("\nb * 2^%d (smult2):\n", exp);
	show_bint(p, argc == 3);
	printf("\nb * 2^%d (add):\n", exp);
	show_bint(a, argc == 3);
	printf("\nb * b * 2^%d:\n", exp);
	mult_bint(m, b, a);
	show_bint(m, argc == 3);
	nbr = 0;
	quotient = 0;
	printf("\ndivmod_max9 tests:\n");
	while (++nbr < 10)
	{
		printf("\nnbr = %ju: ", nbr);
		bintset(nbr, n);
		mult_bint(t, m, n);
		exp = rand();
		bintset(exp, a);
		add_bint(n, t, a);
		quotient = divmod_max9_bint(n, m);
		if (quotient != nbr)
			printf("quotient FAILED !!!");
		else if (bintcmp(n, a))
			printf("remainder FAILED !!!");
		else
			printf("OK");
	}
	add_bint(p, t, a);
	printf("\n\ndividend ((m * 9) + exp):\n");
	show_bint(p, argc == 3);
	printf("\ndivisor (m):\n");
	show_bint(m, argc == 3);
	printf("\nquotient: %u\n", quotient);
	printf("\nremainder orig:\n");
	show_bint(a, argc == 3);
	printf("\nremainder after divmod:\n");
	show_bint(n, argc == 3);
	return (0);
}*/
/*
//double main
int double_main(int argc, char **argv)
{
	double			d;
	unsigned char	*str;
	char			buf[4096];
	int				exp10;
	int				size;

	if (argc < 2)
		return (1);
	while (*++argv)
	{
		exp10 = 0;
		d = atof(*argv);
		size = dragon4(d, 6, buf, &exp10);
		printf("d in hex: %#.16lx\n", *(unsigned long int *)&d);
		str = (unsigned char *)&d + 8;
		ft_printf("d in bin: ");
		while (str > (unsigned char *)&d)
			ft_printf(" %.8hhb", *--str);
		ft_printf("\n");
		printf("%f: %.*s (10^%d)\n", d, size, buf, exp10);
	}
	ft_printf("sizeof(long double): %zu\n", sizeof(long double));
	return (0);
}


// long double main
int long_double_main(int argc, char **argv)
{
	long double		d;
	unsigned char	*str;
	char			*end;

	if (argc < 2)
		return (1);
	while (*++argv)
	{
		end = *argv + strlen(*argv);
		d = strtold(*argv, &end);
		str = (unsigned char *)&d + 16;
		ft_printf("d in bin: ");
		while (str > (unsigned char *)&d)
			ft_printf(" %.8hhb", *--str);
		ft_printf("\n");
		printf("%f\n", (double)d);
	}
	ft_printf("sizeof(long double): %zu\n", sizeof(long double));
	return (0);
}
*/
/*int main(int argc, char **argv)
{
	if (double_main(argc, argv))
		return (1);
	else if (long_double_main(argc, argv))
		return (1);
	//test
	char	inf[] = "+inf";
	char	*end = inf + 4;
	double	d = strtod(inf, &end);
	printf("LONG_DOUBLE CAST: %+Lf\n", (long double)d);
	printf("%1$e\n%1$f\n%1$g\n", 12.34);
	printf("%1$e\n%1$f\n%1$g\n", 12.34);
	printf("%1$e\n%1$f\n%1$g\n", 12345678.34);
	return (0);
}*/

//test maxpow10
int		main(int argc, char **argv)
{
	t_u32	b[BINT_SIZE];
	bintinit(b, 0);
	pow10_bint(b, 8191);
	show_bint(b, argc < 2 ? 0 : atoi(*++argv));
	return (0);
}

/*int		main(int argc, char **argv)
{
	t_u32	b[BINT_SIZE];
	int		exp;
	int		mode;
	mode = argc < 2 ? 0 : atoi(*++argv);
	bintinit(b, 0);
	exp = 511;
	pow10_bint(b, exp++);
	smult10_bint(b);
	printf("10^%d:\n", exp);
	show_bint(b, mode);
	while (exp++ < 1024)
		smult10_bint(b);
	printf("10^%d:\n", --exp);
	show_bint(b, mode);
	while (exp++ < 2048)
		smult10_bint(b);
	printf("10^%d:\n", --exp);
	show_bint(b, mode);
	while (exp++ < 4096)
		smult10_bint(b);
	printf("10^%d:\n", --exp);
	show_bint(b, mode);
	return (0);
}*/
