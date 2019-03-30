#include "libft.h"

int		main(int argc, char **argv)
{
	char	*str;
	int		ret;
	int		n;
	size_t	len;

	if (argc < 3)
		return (1);
	len = ft_strlen(argv[1]);
	ft_printf("ft_sprintf test:\n");
	str = (char *)malloc(len + 1);
	ret = ft_sprintf(str, "%s", argv[1]);
	ft_printf("ret = %d\n", ret);
	if (ret != -1)
		ft_printf("result = '%s'\n", str);
	ft_bzero((void *)str, len);
	ft_strdel(&str);
	ft_printf("\nft_snprintf test:\n");
	str = (char *)malloc(len + 1);
	n = ft_atoi(argv[2]);
	ret = ft_snprintf(str, n, "%s", argv[1]);
	ft_printf("ret = %d\n", ret);
	if (ret != -1)
		ft_printf("result = '%s'\n", str);
	ft_bzero((void *)str, len);
	ft_strdel(&str);
	ft_printf("\nft_asprintf test:\n");
	ret = ft_asprintf(&str, "%s", argv[1]);
	ft_printf("ret = %d\n", ret);
	if (ret != -1)
		ft_printf("result = '%s'\n", str);
	ft_bzero((void *)str, len);
	ft_strdel(&str);
	return (0);
}
