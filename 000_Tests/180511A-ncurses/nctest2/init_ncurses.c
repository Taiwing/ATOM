#include "init_ncurses.h"
#include "nc.h"

/*TODO: add a tagst argument for the color configuration*/

void init_ncurses(void)
{
	initscr();																						/*initializes ncurses*/
	cbreak();																					/*line buffering disabled*/
	noecho();																		/*no fucking echo while getch()*/
	curs_set(0);																		 /*NO FUCKING CURSOR EITHER*/
	start_color();																		 /*so we can create pairs*/
	init_pair(1, COLOR_WHITE, COLOR_BLACK);											/*like this one*/
	init_pair(2, COLOR_CYAN, COLOR_BLACK);											 /*and this one*/
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);										 /*and this one*/
}
