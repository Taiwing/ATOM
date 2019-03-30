#include <inttypes.h>
#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_printf("mine: %hU\n", 4294967296);
	printf("orig: %hU\n\n", 4294967296);
	
	ft_printf("mine: %hhU\n", 4294967296);
	printf("orig: %hhU\n\n", 4294967296);
	
	ft_printf("mine: %hhO\n", 4294967296);
	printf("orig: %hhO\n\n", 4294967296);
	
	ft_printf("mine: %hhD\n", 4294967296);
	printf("orig: %hhD\n\n", 4294967296);
	
	ft_printf("mine: %lU\n", 4294967296);
	printf("orig: %lU\n\n", 4294967296);
	
	ft_printf("mine: %llU\n", 4294967296);
	printf("orig: %llU\n\n", 4294967296);
	
	ft_printf("mine: %jU\n", 4294967296);
	printf("orig: %jU\n\n", 4294967296);
	
	ft_printf("mine: %jU\n", UINTMAX_MAX);
	printf("orig: %jU\n\n", UINTMAX_MAX);
	
	ft_printf("mine: %zU\n", 4294967296);
	printf("orig: %zU\n\n", 4294967296);
	
	ft_printf("mine: %zD\n", -666);
	printf("orig: %zD\n\n", -666);
	
	ft_printf("mine: %zd\n", -342);
	printf("orig: %zd\n\n", -342);
	
	return (0);
}
