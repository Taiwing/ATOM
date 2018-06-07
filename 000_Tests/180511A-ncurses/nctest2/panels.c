#include "panels.h"

void init_panels(PANEL **pan, PANEL **current, PANEL **old_pan)
{
	for(int i = 0; i < 5; i++)
		pan[i] = NULL;
	*current = NULL;
	*old_pan = NULL;
}
