#include "include/tag.h"

static char *getvalue(char *line, size_t l);

void tag_restore(glob_optarg *glo)
{
	FILE *bckup = fopen(glo->backup, "r");
	char *line = NULL, *file = NULL, *value, *name;
	ssize_t vallen, l;
	size_t size = 0;
	void *v;

	while((l = getline(&line, &size, bckup)) != -1)
	{
		if(strstr(line, "# file: ") == line)
		{
			line[--l] = '\0';
			if(!filerrck(line+8, OPT_SET))
			{
				if(file) free(file);
				file = strcpy((char *)salloc(strlen(line+8)+1), line+8);
			}
		}
		else if(strcmp(line, "\n") != 0 && file)
		{
			line[--l] = '\0';
			value = NULL;
			v = NULL;
			vallen = 0;
			if((value = getvalue(line, l)))
			{
				vallen = atohx(&v, value);
				*(value-3) = '\0';
			}
			name = (char *)salloc(strlen(line)+LU+1);
			strcpy(name, USER); /*adding "user." prefix*/
			strcat(name, line); /*and the name of the tag*/
			setxattr(file, name, v, vallen, 0);
			free(name);
			if(v) free(v);
		}

		if(line)
		{
			free(line);
			line = NULL;
			l = 0;
		}
	}

	fclose(bckup);
}

static char *getvalue(char *line, size_t l)
{
	for(char *p = line+l-1; p >= line; p--) /*make this loop into a function*/
	{
		if(*p == 'x' && p-line >= 3 && line+l-1-p >= 6
		&& *(p-1) == '0' && *(p-2) == ' ')
			return (p+1);
		else if(!(isdigit(*p) || (*p >= 'a' && *p <= 'f')))
			break;
	}

	return NULL;
}
