#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n);

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_itoa(atoi(argv[1])));
	return (0);
}
