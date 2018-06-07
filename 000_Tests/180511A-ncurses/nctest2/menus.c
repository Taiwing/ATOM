#include "menus.h"

MENU **init_men(void)
{
	MENU **men = (MENU **)malloc(M_COUNT * sizeof(MENU *));

	for(int i = 0; i < M_COUNT; i++)												/*not generated yet*/
		men[i] = NULL;

	return men;
}
