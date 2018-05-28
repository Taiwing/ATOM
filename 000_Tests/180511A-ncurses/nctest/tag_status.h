#ifndef TAG_STATUS_H
#define TAG_STATUS_H

typedef struct tag_status
{
	/*interaface variables*/
	int curwin;																								 /*current window*/
	int old_curwin;						 /*save curwin when a function panel is displayed*/
	int hlight;															/*element highlighted on the screen*/
	int old_hlight;						 /*save hlight when a function panel is displayed*/
	int choice;																		 /*element chosen by the user*/
	int c;																												 /*user input*/
	int panel_ev;										 /*signals when a penel is opened or closed*/

	/*qbar*/
	int qbc;																								/*number of queries*/
	int curq;													/*current query, if any (else curq == -1)*/

	/*elem_list*/
	int elc;																							 /*number of elements*/
	int attrc;							 /*number of listed attributes (name, size, etc...)*/

	/*function panels*/
	int func;																				/*currently displayed panel*/

	/*subfunction panels*/
	int sub_func;																 /*currently displayed subpanel*/
}	tagst;

#endif
