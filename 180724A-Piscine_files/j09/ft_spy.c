#include <unistd.h>
#include <libft/libft.h>
#define LOW(C) (C > 64 && C < 91 ? C + 32 : C)
#define WHITE(C) (C == 0 || C == 9 || C == 10 || C == 32 ? 1 : 0)

int spy(char **v);
int find_word(char *to_find, char *str);

int main(int argc, char **argv)
{
	if(spy(++argv))
		write(1, "Alert!!!\n", 9);

	return 0;
}

int spy(char **v)
{
	while(*v)
	{
		if(find_word("president", *v) || find_word("attack", *v)
			|| find_word("powers", *v))
			return 1;
		v++;
	}

	return 0;
}

int find_word(char *to_find, char *str)
{
	char	*ptr;

	/*TEST*/
	ft_putstr("TEST 1 (to_find): ");
	ft_putstr(to_find);
	ft_putchar('\n');
	ft_putstr("TEST 1 (str): ");
	ft_putstr(str);
	ft_putchar('\n');

	ptr = str;
	while (*ptr && (LOW(*ptr)) != *to_find)
		ptr++;
	if ((LOW(*ptr)) == *to_find && (ptr == str || (WHITE(*(ptr-1)))))
	{
		while (*ptr && *to_find && (LOW(*ptr)) == *to_find)
		{
			to_find++;
			ptr++;
		}
	}

	/*TEST*/
	ft_putstr("TEST 2 (to_find): ");
	ft_putstr(*to_find ? to_find : "NULL");
	ft_putchar('\n');
	ft_putstr("TEST 2 (ptr): ");
	ft_putstr(*ptr ? ptr : "NULL");
	ft_putchar('\n');

	return (*to_find == 0 && (WHITE(*ptr)));
}
