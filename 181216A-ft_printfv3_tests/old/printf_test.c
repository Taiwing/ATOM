#include <stdio.h>

int	main(void)
{
	int a = 42;
	int b = -650;
	unsigned int d = 650;
	double c = 299792458;
	int	width = 15;

	printf("%%*d             test int a: %*d\n", width, a);
	printf("%%*d             test int b: %*d\n", width, b);
	printf("%%*u             test int d: %*u\n", width, d);
    printf("%%*o             test int a: %*o\n", width, (unsigned int)a);
    printf("%%*o             test int d: %*o\n", width, d);
    printf("%%#*x            test int a: %#*x\n", width, (unsigned int)a);
    printf("%%#*x            test int d: %#*x\n", width, d);
	printf("%%*.8e           test dou c: %*.8e\n", width, c);
	printf("%%*.0f           test dou c: %*.0f\n\n", width, c);
	
    printf("%%-*d            test int a: %-*d\n", width, a);
    printf("%%-*d            test int b: %-*d\n", width, b);
	printf("%%-*u            test int d: %-*u\n", width, d);
    printf("%%-*o            test int a: %-*o\n", width, (unsigned int)a);
    printf("%%-*o            test int d: %-*o\n", width, d);
    printf("%%#-*x           test int a: %#-*x\n", width, (unsigned int)a);
    printf("%%#-*x           test int d: %#-*x\n", width, d);
    printf("%%-*.8e          test dou c: %-*.8e\n", width, c);
    printf("%%-*.0f          test dou c: %-*.0f\n\n", width, c);

    printf("%%0*d            test int a: %0*d\n", width, a);
    printf("%%0*d            test int b: %0*d\n", width, b);
	printf("%%0*u            test int d: %0*u\n", width, d);
    printf("%%0*o            test int a: %0*o\n", width, (unsigned int)a);
    printf("%%0*o            test int d: %0*o\n", width, d);
    printf("%%#0*x           test int a: %#0*x\n", width, (unsigned int)a);
    printf("%%#0*x           test int d: %#0*x\n", width, d);
    printf("%%0*.8e          test dou c: %0*.8e\n", width, c);
    printf("%%0*.0f          test dou c: %0*.0f\n\n", width, c);

    printf("%%2$*1$d         test int a: %2$*1$d\n", width, a);
    printf("%%2$*1$d         test int b: %2$*1$d\n", width, b);
    printf("%%2$*1$u         test int d: %2$*1$u\n", width, d);
    printf("%%2$*1$o         test int a: %2$*1$o\n", width, (unsigned int)a);
    printf("%%2$*1$o         test int d: %2$*1$o\n", width, d);
    printf("%%2$#*1$x        test int a: %2$#*1$x\n", width, (unsigned int)a);
    printf("%%2$#*1$x        test int d: %2$#*1$x\n", width, d);
    printf("%%2$*1$.8e       test dou c: %2$*1$.8e\n", width, c);
    printf("%%2$*1$.0f       test dou c: %2$*1$.0f\n\n", width, c);

	printf("error tests:\n\n");

	printf("%%2$*1$d 3 args  test int a: %2$*1$d\n", width, a, d);
	printf("%%2$*1$d 1 arg   test width: %2$*1$d|\n", width-1);
	printf("%%2$*1$ld 1 arg  test width: %2$*1$ld|\n", width-1);
	printf("%%2$*1$o 1 arg   test width: %2$*1$o|\n", width-1);
	printf("%%2$*1$lo 1 arg  test width: %2$*1$lo|\n", width-1);
	printf("%%2$*1$u 1 arg   test width: %2$*1$u|\n", width-1);
	printf("%%2$*1$lu 1 arg  test width: %2$*1$lu|\n", width-1);
	printf("%%2$*1$x 1 arg   test width: %2$*1$x|\n", width-1);
	printf("%%2$*1$X 1 arg   test width: %2$*1$X|\n", width-1);
	printf("%%2$*1$c 1 arg   test width: %2$*1$c|\n", width-1);
	printf("%%2$*1$lc 1 arg  test width: %2$*1$lc|\n", width-1);
	printf("%%2$*1$s 1 arg   test width: %2$*1$s|\n", width-1);
	printf("%%2$*1$ls 1 arg  test width: %2$*1$ls|\n", width-1);
	printf("%%2$*1$p 1 arg   test width: %2$*1$p|\n\n", width-1);
	
    printf("%%2$#*1$d 1 arg  test width: %2$#*1$d|\n", width-1);
    printf("%%2$#*1$ld 1 arg test width: %2$#*1$ld|\n", width-1);
    printf("%%2$#*1$o 1 arg  test width: %2$#*1$o|\n", width-1);
    printf("%%2$#*1$lo 1 arg test width: %2$#*1$lo|\n", width-1);
    printf("%%2$#*1$u 1 arg  test width: %2$#*1$u|\n", width-1);
    printf("%%2$#*1$lu 1 arg test width: %2$#*1$lu|\n", width-1);
    printf("%%2$#*1$x 1 arg  test width: %2$#*1$x|\n", width-1);
    printf("%%2$#*1$X 1 arg  test width: %2$#*1$X|\n", width-1);
    printf("%%2$#*1$c 1 arg  test width: %2$#*1$c|\n", width-1);
    printf("%%2$#*1$lc 1 arg test width: %2$#*1$lc|\n", width-1);
    printf("%%2$#*1$s 1 arg  test width: %2$#*1$s|\n", width-1);
    printf("%%2$#*1$ls 1 arg test width: %2$#*1$ls|\n", width-1);
    printf("%%2$#*1$p 1 arg  test width: %2$#*1$p|\n\n", width-1);

    printf("%%2$#0*1$d 1 arg  test width: %2$#0*1$d|\n", width-1);
    printf("%%2$#0*1$ld 1 arg test width: %2$#0*1$ld|\n", width-1);
    printf("%%2$#0*1$o 1 arg  test width: %2$#0*1$o|\n", width-1);
    printf("%%2$#0*1$lo 1 arg test width: %2$#0*1$lo|\n", width-1);
    printf("%%2$#0*1$u 1 arg  test width: %2$#0*1$u|\n", width-1);
    printf("%%2$#0*1$lu 1 arg test width: %2$#0*1$lu|\n", width-1);
    printf("%%2$#0*1$x 1 arg  test width: %2$#0*1$x|\n", width-1);
    printf("%%2$#0*1$X 1 arg  test width: %2$#0*1$X|\n", width-1);
    printf("%%2$#0*1$c 1 arg  test width: %2$#0*1$c|\n", width-1);
    printf("%%2$#0*1$lc 1 arg test width: %2$#0*1$lc|\n", width-1);
    printf("%%2$#0*1$s 1 arg  test width: %2$#0*1$s|\n", width-1);
    printf("%%2$#0*1$ls 1 arg test width: %2$#0*1$ls|\n", width-1);
    printf("%%2$#0*1$p 1 arg  test width: %2$#0*1$p|\n\n", width-1);

    printf("%%2$#-0*1$d 1 arg  test width: %2$#-0*1$d|\n", width-1);
    printf("%%2$#-0*1$ld 1 arg test width: %2$#-0*1$ld|\n", width-1);
    printf("%%2$#-0*1$o 1 arg  test width: %2$#-0*1$o|\n", width-1);
    printf("%%2$#-0*1$lo 1 arg test width: %2$#-0*1$lo|\n", width-1);
    printf("%%2$#-0*1$u 1 arg  test width: %2$#-0*1$u|\n", width-1);
    printf("%%2$#-0*1$lu 1 arg test width: %2$#-0*1$lu|\n", width-1);
    printf("%%2$#-0*1$x 1 arg  test width: %2$#-0*1$x|\n", width-1);
    printf("%%2$#-0*1$X 1 arg  test width: %2$#-0*1$X|\n", width-1);
    printf("%%2$#-0*1$c 1 arg  test width: %2$#-0*1$c|\n", width-1);
    printf("%%2$#-0*1$lc 1 arg test width: %2$#-0*1$lc|\n", width-1);
    printf("%%2$#-0*1$s 1 arg  test width: %2$#-0*1$s|\n", width-1);
    printf("%%2$#-0*1$ls 1 arg test width: %2$#-0*1$ls|\n", width-1);
    printf("%%2$#-0*1$p 1 arg  test width: %2$#-0*1$p|\n\n", width-1);

    printf("%%2$*1$e 1 arg   test width: %2$*1$e|\n", width-1);
    printf("%%2$*1$E 1 arg   test width: %2$*1$E|\n", width-1);
    printf("%%2$*1$f 1 arg   test width: %2$*1$f|\n", width-1);
    printf("%%2$*1$F 1 arg   test width: %2$*1$F|\n", width-1);
    printf("%%2$*1$g 1 arg   test width: %2$*1$g|\n", width-1);
    printf("%%2$*1$G 1 arg   test width: %2$*1$G|\n", width-1);
    printf("%%2$*1$a 1 arg   test width: %2$*1$a|\n", width-1);
    printf("%%2$*1$A 1 arg   test width: %2$*1$A|\n\n", width-1);
	
	printf("   %%2$d %%d %%d %%5$d %%4$d %%d:     %2$d %d %d %5$d %4$d %d\n", 1, 2, 3, 4, 5);
	printf("  %%2$d %%d %%*d %%5$d %%4$d %%d:     %2$d %d %*d %5$d %4$d %d\n", 1, 2, 3, 4, 5);
	printf(" %%2$d %%d %%*d %%5$d %%4$d %%*d:  %2$d %d %*d %5$d %4$d %*d\n", 1, 2, 3, 4, 5);
	printf("%%2$#0*1$x 1 arg  test width: %2$#0*1$x|\n", width-1, 0);
	printf("%%2$#0*1$x 1 arg  test width: %2$#0*1$x|\n", width-1, 1);
	printf("%%'d test: %'d\n", 299792458);

	return (0);
}
