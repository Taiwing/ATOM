#include <stdarg.h>
#include <stdio.h>

char	*fetch_arg(va_list cur, int l)
{
	int		i;
	char	*ret;

	i = 0;
	while (++i < l + 1)
		ret = va_arg(cur, char *);
	va_end(cur);
	return (ret);
}

void	print_strs(int l, char *lol, ...)
{
	va_list	cur;
	va_list	ref;
	va_list	tmp;
	int		i;

	va_start(cur, lol);
	va_copy(ref, cur);
	printf("0: %s\n", lol);
	i = 0;
	while (++i < l)
		printf("%d: %s\n", i, va_arg(cur, char *));
	while (l > 2)
	{
		va_copy(tmp, ref);
		printf("%d: %s\n", l - 1, fetch_arg(tmp, l - 1));
		l -= 2;
	}
	va_end(cur);
	va_end(tmp);
}

int	main(void)
{
	char *lol = "afusayfouysa";
	char *foo = "mais ril est foo !!!";
	char *bar = "do you even lift bro ???";
	char *gay = "gaaaaaaaay";
	char *toc = "iron_chad nation bruh !!!";
	char *wtf = "what the fucking fuck ?!";
	char *fih = "fire in the haaaaaaaaaaall";
	char *sex = "apache helicopter bruh";
	char *dum = "achtually, gender is a spectrum...";
	char *stf = "shut the fuck up !!!";
	char *wut = "there is only two genders";
	
	print_strs(11, lol, foo, bar, gay, toc, wtf, fih, sex, dum, stf, wut);
	print_strs(1, lol);
	return (0);
}
