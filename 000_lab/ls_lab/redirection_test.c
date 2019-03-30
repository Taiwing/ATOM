#include <termios.h>
#include <stdio.h>
#include <errno.h>

/*TODO: use tcgetattr to test if the output is being redirected or not*/

int	main(void)
{
	struct termios	t;
	int				ret;
	
	printf("stdout is a terminal: ");
	ret = tcgetattr(1, &t);
	if (!ret)
		printf("yes\n");
	else if (ret == -1)
	{
		printf("no ");
		if (errno == EBADF)
			printf("EBADF\n");
		else if (errno == ENOTTY)
			printf("ENOTTY\n");
	}
	return (0);
}
