#ifndef PANEL_H
#define PANEL_H

#include "interface.h"

/*TODO: see if this structure is appropriate for this part of the program*/
/*if it is indeed appropriate, implement the corresponding functions*/
typedef struct panel {
	/*content*/
	char *title;
	char **items; 																						/*NULL terminated*/

	/*interactions*/ /*NULL: nothing*/
	int *tickboxes; 												 /*-1: no box 0: unticked 1: ticked*/
	int *fields;										 /*-1: no field 0: field x: filed of size x*/
	char ***lists;														 /*lists of comma seperated words*/
	struct interfunk {
		struct panel *child;																			/*panel to open*/
		void (*customf)(void *);												 /*or function to execute*/
	} **funkies;

	/*panel attributes*/
	int centered_title;
	int save_quit;
	void (*savef)(struct panel *, tagst *ts);										/*save function*/

	/*auto generated data*/
	int n_items;
	int height;
	int width;
	WINDOW *win;
} panel;

panel *init_panel(char **content, int *tickboxes, int *fields,
									char ***lists, struct interfunk **funkies);

#endif
