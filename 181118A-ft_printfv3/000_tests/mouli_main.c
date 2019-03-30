#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("ORIG>		%p\n", NULL);
	ft_printf("MINE>		%p\n", NULL);
	printf("ORIG>		%\n");
	ft_printf("MINE>		%\n");
	printf("ORIG>		%llO, %llO\n", 0, USHRT_MAX);
	ft_printf("MINE>		%llO, %llO\n", 0, USHRT_MAX);
	printf("ORIG>		%jO, %jO\n", 0, USHRT_MAX);
	ft_printf("MINE>		%jO, %jO\n", 0, USHRT_MAX);
	printf("ORIG>		%zO, %zO\n", 0, USHRT_MAX);
	ft_printf("MINE>		%zO, %zO\n", 0, USHRT_MAX);
	/*printf("ORIG>		{%5p}\n", 0);
	  ft_printf("MINE>		{%5p}\n", 0);
	  printf("ORIG>		{%03c}\n", 0);
	  ft_printf("MINE>		{%03c}\n", 0);*/
	printf("ORIG>		{%-15Z}\n", 123);
	ft_printf("MINE>		{%-15Z}\n", 123);
	printf("ORIG>		%.0p, %.p\n", 0, 0);
	ft_printf("MINE>		%.0p, %.p\n", 0, 0);
	printf("ORIG>		%.p, %.0p\n", 0, 0);
	ft_printf("MINE>		%.p, %.0p\n", 0, 0);
	printf(		"ORIG> % p|%+p\n", 42, 42);
	ft_printf(		"MINE> % p|%+p\n", 42, 42);
	printf("ORIG>		{%3*p}\n", 10, 0);
	ft_printf("MINE>		{%3*p}\n", 10, 0);
	printf("ORIG>		{%3*d}\n", 0, 0);
	ft_printf("MINE>		{%3*d}\n", 0, 0);
	printf("ORIG>		{%3*Z %d}\n", 0, 42);
	ft_printf("MINE>		{%3*Z %d}\n", 0, 42);
	printf("ORIG>		{%3h* %d}\n", 0, 42);
	ft_printf("MINE>		{%3h* %d}\n", 0, 42);
	printf("ORIG>		{%f}{%F}\n", 1.42, 1.42);
	ft_printf("MINE>		{%f}{%F}\n", 1.42, 1.42);


	/*	printf("ORIG> %03c\n", 0);
		ft_printf("MINE> %03c\n", 0);
		printf("ORIG> %05.c\n", 0);
		ft_printf("MINE> %05.c\n", 0);

		printf("ORIG> %03C\n", 0);
		ft_printf("MINE> %03C\n", 0);
		printf("ORIG> %05.C\n", 0);
		ft_printf("MINE> %05.C\n", 0);

		printf("ORIG> %03s\n", "l");
		ft_printf("MINE> %03s\n", "l");
		printf("ORIG> %05.s\n", "l");
		ft_printf("MINE> %05.s\n", "l");

		printf("ORIG> %03S\n", L"l");
		ft_printf("MINE> %03S\n", L"l");
		printf("ORIG> %05.S\n", L"l");
		ft_printf("MINE> %05.S\n", L"l");

		printf("ORIG> %03%\n", 0);
		ft_printf("MINE> %03%\n", 0);
		printf("ORIG> %05.%\n", 0);
		ft_printf("MINE> %05.%\n", 0); */

	printf("{%-15Z}\n", 123);
	printf("{%-15y");
	printf("}\n", 123);
	ft_printf("{%-15Z}\n", 123);

	printf("{%015Z}\n", 123);
	printf("{%015y");
	printf("}\n", 123);
	ft_printf("{%015Z}\n\n\n", 123);

	/*printf("%s", "{%3*d}: 0, 0\n");
	  printf(		"ORIG>	{%3*d}\n", 0, 0);
	  ft_printf(	"MINE>	{%3*d}\n", 0, 0);
	  printf("%s", "{%*3d}: 0, 0\n");
	  printf(		"ORIG> {%*3d}\n", 0, 0);
	  ft_printf(	"MINE> {%*3d}\n", 0, 0);
	  printf("%s", "{%*3d}: 5, 0\n");
	  printf(		"ORIG> {%*3d}\n", 5, 0);
	  ft_printf(	"MINE> {%*3d}\n", 5, 0);
	  printf("%s", "{%05.*d}: -15, 42\n");
	  printf(		"ORIG> {%05.*d}\n", -15, 42);
	  ft_printf(	"MINE> {%05.*d}\n", -15, 42);*/

	 ft_printf("MINE> %ll#x\n", 9223372036854775807);
	 printf("ORIG> %ll#x\n", 9223372036854775807);
	 ft_printf("MINE> %ll#x\n", 9223372036854775807);
	 printf("ORIG> %ll#x\n", 9223372036854775807);
	 ft_printf("MINE> %5+d\n", 42);
	 printf("ORIG> %5+d\n", 42);
	 ft_printf("MINE> %5+d\n", -42);
	 printf("ORIG> %5+d\n", -42);
	 ft_printf("MINE> %-5+d\n", 42);
	 printf("ORIG> %-5+d\n", 42);
	 ft_printf("MINE> %-5+d\n", -42);
	 printf("ORIG> %-5+d\n", -42);
	 ft_printf("MINE> %zhd\n", 4294967296);
	 printf("ORIG> %zhd\n", 4294967296);
	 ft_printf("MINE> %jzd\n", 9223372036854775807);
	 printf("ORIG> %jzd\n", 9223372036854775807);
	 ft_printf("MINE> %jhd\n", 9223372036854775807);
	 printf("ORIG> %jhd\n", 9223372036854775807);
	 ft_printf("MINE> %lhl\n", 9223372036854775807);
	 printf("ORIG> %lhl\n", 9223372036854775807);
	 ft_printf("MINE> %lhlz\n", 9223372036854775807);
	 printf("ORIG> %lhlz\n", 9223372036854775807);
	 ft_printf("MINE> %zj\n", 9223372036854775807);
	 printf("ORIG> %zj\n", 9223372036854775807);
	 ft_printf("MINE> %lhh\n", 2147483647);
	 printf("ORIG> %lhh\n", 2147483647);
	 ft_printf("MINE> %hhld\n", 128);
	 printf("ORIG> %hhld\n", 128);
	 ft_printf("MINE> %hhl#x\n", 128);
	 printf("ORIG> %hhl#x\n", 128);
	 ft_printf("MINE> %hhl0#*x\n", 6, 128);
	 printf("ORIG> %hhl0#*x\n", 6, 128);
	 ft_printf("MINE> %hhlh0#*x\n", 6, 128);
	 printf("ORIG> %hhlh0#*x\n", 6, 128);
	 ft_printf("MINE> %####0000 33..1..#00d\\n\n", 256);
	 printf("ORIG> %####0000 33..1..#00d\\n\n", 256);
	 ft_printf("MINE> %####0000 33..1d\n", 256);
	 printf("ORIG> %####0000 33..1d\n", 256);
	 ft_printf("MINE> %###-#0000 33...12..#0+0d\n", 256);
	 printf("ORIG> %###-#0000 33...12..#0+0d\n", 256);

		return (0);
}
