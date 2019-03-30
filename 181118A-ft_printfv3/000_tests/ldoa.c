#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct			s_bitd
{
	unsigned long int	mantissa: 52;
	unsigned int		exponent: 11;
	unsigned int		sign: 1;
}						t_bitd;

void	test_limits_float(void)
{
	printf("float %%e:\n");
    printf("ORIG> FLT_MIN      = %e\n", FLT_MIN);
    ft_printf("MINE> FLT_MIN      = %e\n", FLT_MIN);
    printf("ORIG> FLT_MAX      = %e\n", FLT_MAX);
    ft_printf("MINE> FLT_MAX      = %e\n", FLT_MAX);
	
	printf("\nfloat %%f:\n");
    printf("ORIG> FLT_MIN      = %f\n", FLT_MIN);
    ft_printf("MINE> FLT_MIN      = %f\n", FLT_MIN);
    printf("ORIG> FLT_MAX      = %f\n", FLT_MAX);
    ft_printf("MINE> FLT_MAX      = %f\n", FLT_MAX);
	
	printf("\nfloat %%g:\n");
    printf("ORIG> FLT_MIN      = %g\n", FLT_MIN);
    ft_printf("MINE> FLT_MIN      = %g\n", FLT_MIN);
    printf("ORIG> FLT_MAX      = %g\n", FLT_MAX);
    ft_printf("MINE> FLT_MAX      = %g\n", FLT_MAX);
}

void	test_limits_double(void)
{
	printf("\ndouble %%e:\n");
    printf("\nORIG> DBL_MIN      = %e\n", DBL_MIN);
    ft_printf("MINE> DBL_MIN      = %e\n", DBL_MIN);
    printf("ORIG> DBL_MAX      = %e\n", DBL_MAX);
    ft_printf("MINE> DBL_MAX      = %e\n", DBL_MAX);
	
	printf("\ndouble %%f:\n");
    printf("\nORIG> DBL_MIN      = %f\n", DBL_MIN);
    ft_printf("MINE> DBL_MIN      = %f\n", DBL_MIN);
    printf("ORIG> DBL_MAX      = %f\n", DBL_MAX);
    ft_printf("MINE> DBL_MAX      = %f\n", DBL_MAX);
	
	printf("\ndouble %%g:\n");
    printf("\nORIG> DBL_MIN      = %g\n", DBL_MIN);
    ft_printf("MINE> DBL_MIN      = %g\n", DBL_MIN);
    printf("ORIG> DBL_MAX      = %g\n", DBL_MAX);
    ft_printf("MINE> DBL_MAX      = %g\n", DBL_MAX);
}

void	test_limits_long_double(void)
{
	printf("\nlong double %%e:\n");
    printf("\nORIG> LDBL_MIN      = %Le\n", LDBL_MIN);
    ft_printf("MINE> LDBL_MIN      = %Le\n", LDBL_MIN);
    printf("ORIG> LDBL_MAX      = %Le\n", LDBL_MAX);
    ft_printf("MINE> LDBL_MAX      = %Le\n", LDBL_MAX);
	
	printf("\nlong double %%f:\n");
    printf("\nORIG> LDBL_MIN      = %Lf\n", LDBL_MIN);
    ft_printf("MINE> LDBL_MIN      = %Lf\n", LDBL_MIN);
	
	printf("\nlong double %%g:\n");
    printf("\nORIG> LDBL_MIN      = %Lg\n", LDBL_MIN);
    ft_printf("MINE> LDBL_MIN      = %Lg\n", LDBL_MIN);
    printf("ORIG> LDBL_MAX      = %Lg\n", LDBL_MAX);
    ft_printf("MINE> LDBL_MAX      = %Lg\n", LDBL_MAX);
}

void	test_limits(void)
{
	test_limits_float();
	test_limits_double();
	test_limits_long_double();
}

void	study(double d)
{
	size_t			size;	
	t_bitd			b;
	char			*str;
	
	b = *(t_bitd *)&d;
	str = (char *)&d;
	ft_printf("sign: %u\n", b.sign);
	ft_printf("exponent: %u -> %.11b\n", b.exponent, b.exponent);
	ft_printf("mantissa: %lu -> %.52lb\n", b.mantissa, b.mantissa);
	size = sizeof(double);
	ft_printf("complete: ");
	while (size--)
		ft_printf("%.8hhb ", str[size]);
	ft_printf("\n");
}

double	ft_pow(double n, int y)
{
	double z;

	z = 1;
	while (y--)
		z *= n;
	return (z);
}

/*char	*ft_ftoa(float num, int prec)
{
	int		ipart;
	float	dpart;
	int		idec;
	char	*dec;
	char	*ret;

	ipart = num;
	dpart = num - ipart;
	printf("TEST dpart: %f\n", dpart);
	idec = dpart * ft_pow(10, prec);
	idec = idec < 0 ? idec * -1 : idec;
	ft_printf("TEST idec: %d\n", idec);
	ret = ft_itoa(ipart);
	if (prec)
	{
		ret = ft_stradd(&ret, ".", prec + 1);
		dec = ft_itoa(idec);
		ft_memset(ft_strchr(ret, 0), '0', prec);
		ft_strcpy(ft_strchr(ret, 0) - ft_strlen(dec), dec);
		free(dec);
	}
	return (ret);
}*/

long	get_dec(double n, int prec)
{
	double		dec;

	dec = ((n < 0.0f) ? -n : n);
	dec = (dec - (long)dec) * ft_pow(10, prec + 1);
	dec = ((long)dec % 10 > 4) ? dec / 10 + 1 : dec / 10;
	return ((int)dec);
}

char	*ft_ftoa(double num, int prec)
{
	int		ipart;
	long	dpart;
	char	*ptr;
	char	*ret;
	int		i;

	ipart = num;
	ret = ft_itoa(ipart);
	if (prec)
	{
		dpart = get_dec(num, prec);
		ret = ft_stradd(&ret, ".", prec + 1);
		ptr = ft_strchr(ret, 0);
		i = ft_pow(10, prec - 1);
		while (prec--)
		{
			ft_memset(ptr++, ((dpart / i) % 10) + 48, 1);
			i /= 10;
		}
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char		*str;
	char		*end;
	long double		d;
	int			prec;

	if (argc < 2)
	{
		test_limits();
		return(0);	
	}
	prec = argc > 2 ? atoi(*++argv) : 6;
	while (*++argv)
	{
		end = *argv + ft_strlen(*argv);
		d = strtold(*argv, &end);
		ft_printf("MINE> %.*e\n", prec, (double)d);
		printf("ORIG> %.*e\n", prec, (double)d);
		ft_printf("MINE> %.*f\n", prec, (double)d);
		printf("ORIG> %.*f\n", prec, (double)d);
		ft_printf("MINE> %.*g\n", prec, (double)d);
		printf("ORIG> %.*g\n", prec, (double)d);
		ft_printf("MINE> %.*Le\n", prec, d);
		printf("ORIG> %.*Le\n", prec, d);
		ft_printf("MINE> %.*Lf\n", prec, d);
		printf("ORIG> %.*Lf\n", prec, d);
		ft_printf("MINE> %.*Lg\n", prec, d);
		printf("ORIG> %.*Lg\n", prec, d);
		//study(d);
		free(str);
	}
	return (0);
}
