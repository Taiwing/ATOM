#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "ft_printf.h"

int main()
{
	float f[] = {
		0.0, 1.0, FLT_MAX, 0.0 / 0.0, 1.0/0.0, -1.0/0.0
	};
	int i;

	for (i = 0; i < 6; i++) {
		float x = f[i];

		int is_nan = (x != x);
		int is_inf = (x < -FLT_MAX || x > FLT_MAX);

		printf("%20g%4d%4d\n", x, is_nan, is_inf);
	}

	double d = DBL_MAX;
	ft_printf("f only  MINE> %f\n", d);
	printf("f only  ORIG> %f\n", d);
	ft_printf("lf only MINE> %lf\n", d);
	printf("lf only ORIG> %lf\n", d);
	return 0;
}
