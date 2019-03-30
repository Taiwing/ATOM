#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
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

char *join(const char *s1, const char *s2, const char *s3)
{
	char *new;
   
	if (!(new = malloc(strlen(s1) + strlen(s2) + strlen(s3)+ 1)))
		return (NULL);
	strcpy(new, s1);
	strcat(new, s2);
	strcat(new, s3);
	return (new);
}

int	main(int argc, char **argv)
{
	char		*end;
	long double		d;
	int			prec;
	char		*flags;
	char		*conv;
	char		*mine	= "MINE [%-25s] >> %";
	char		*orig	= "ORIG [%-25s] >> %";
	char		*e		= ".*e";
	char		*f		= ".*f";
	char		*g		= ".*g";
	char		*Le		= ".*Le";
	char		*Lf		= ".*Lf";
	char		*Lg		= ".*Lg";
	char		*fmt[12];
	int			i;

	if (argc < 4)
	{
		test_limits();
		printf("%.18000Lf\n", LDBL_MIN);
		ft_printf("%.18000Lf\n", LDBL_MIN);
		printf("\nusage: ./a.out prec flags args\n");
		return(0);	
	}
	prec = atoi(*++argv);
	flags = *++argv;
	i = -1;
	while (++i < 12)
	{
		if (i < 2)
			conv = e;
		else if (i < 4)
			conv = f;
		else if (i < 6)
			conv = g;
		else if (i < 8)
			conv = Le;
		else if (i < 10)
			conv = Lf;
		else
			conv = Lg;
		if (!(fmt[i] = join(i % 2 ? orig : mine, flags, conv)))
			return (1);
	}
	while (*++argv)
	{
		end = *argv + ft_strlen(*argv);
		d = strtold(*argv, &end);
		ft_printf(fmt[0], fmt[0], prec, (double)d);
		ft_printf("\n");
		printf(fmt[1], fmt[1], prec, (double)d);
		printf("\n");
		ft_printf(fmt[2], fmt[2], prec, (double)d);
		ft_printf("\n");
		printf(fmt[3], fmt[3], prec, (double)d);
		printf("\n");
		ft_printf(fmt[4], fmt[4], prec, (double)d);
		ft_printf("\n");
		printf(fmt[5], fmt[5], prec, (double)d);
		printf("\n");
		ft_printf(fmt[6], fmt[6], prec, d);
		ft_printf("\n");
		printf(fmt[7], fmt[7], prec, d);
		printf("\n");
		ft_printf(fmt[8], fmt[8], prec, d);
		ft_printf("\n");
		printf(fmt[9], fmt[9], prec, d);
		printf("\n");
		ft_printf(fmt[10], fmt[10], prec, d);
		ft_printf("\n");
		printf(fmt[11], fmt[11], prec, d);
		printf("\n");
		//study(d);
	}
	return (0);
}
