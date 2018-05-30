#ifndef PANEL_H
#define PANEL_H

#include "interface.h"

typedef struct panel {
	/*content*/
	char *title;
	char **items; 																						/*NULL terminated*/

	/*panel attributes*/
	int centered_title;
	int save_quit;
	void (*savef)(struct panel *, tagst *ts);										/*save function*/

	/*interactions*/ /*NULL: nothing*/
	int *tickboxes; 												 /*-1: no box 0: unticked 1: ticked*/
	int *fieldw;										/*-1: no field 0: field x: field of width x*/
	char **fields;																								 /*field data*/
	char ***lists;														 /*lists of comma seperated words*/
	struct interfunk {
		struct panel *child;																			/*panel to open*/
		void (*customf)(void *);												 /*or function to execute*/
	} **funkies;

	/*auto generated data*/
	int n_items;
	int height;
	int width;
	WINDOW *win;
} panel;


panel *init_panel(char *title, char **items);		 /*create the panel structure*/
void set_panel_attributes(panel *pan, int centered_title, int save_quit,
													void (*savef)(struct panel *, tagst *ts));
void set_panel_interactions(panel *pan, int *tickboxes, int *fields,
														char ***lists, struct interfunk **funkies);
void display_panel(tagst *ts, panel *pan); 					 /*display selected panel*/
void load_panel(panel *pan);				/*create a window when panel is displayed*/
void panel_input(tagst *ts, panel *pan);									/*handle user input*/

#endif
