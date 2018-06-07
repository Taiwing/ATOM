#include "nc.h"
#include "init_ncurses.h"
#include "windows.h"
#include "menus.h"
#include "panels.h"

PANEL *current;
PANEL *old_pan;
PANEL *pan[5]; 			 /*base, panels, sub-pan, pop-pan sub-pop-pan, dialog_pan*/
WINDOW **win;
MENU **men;

int main(void)
{
	/*initializations*/
	init_ncurses();
	win = init_win();
	men = init_men();
	init_panels(pan, &current, &old_pan);
}
