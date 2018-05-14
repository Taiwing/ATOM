#include "include/main.h"
#include "include/tagex.h"

int main(int argc, char **argv)
{
	char *root_dir = NULL;

	if(argc == 2 && isdir(argv[1]))
		root_dir = argv[1];
	else if(argc == 2)
	{
		fprintf(stderr, "%s: %s isn't a directory\n", argv[0], argv[1]);
		return EXIT_FAILURE;
	}
	else if(argc > 2)
	{
		fprintf(stderr, "%s: too many arguments\n", argv[0]);
		return EXIT_FAILURE;
	}
	else
	{
		root_dir = get_current_dir_name();
		if(root_dir == NULL || root_dir[0] != '/')
		{
			fprintf(stderr, "%s: couldn't open directory\n", argv[0]);
			return EXIT_FAILURE;
		}
	}

	ncint_tagex(root_dir);

	return EXIT_SUCCESS;
}
