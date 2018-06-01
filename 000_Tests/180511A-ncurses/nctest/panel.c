#include "panel.h"

#include <stdlib.h>	/*TEMP: REPLACE MALLOC BY SALLOC*/

panel *init_panel(char *title, char **items)
{
	panel *pan = (panel *)malloc(sizeof(panel));

	/*content*/
	pan->title = title;
	pan->items = items;

	/*default attribute and interaction values*/
	pan->centered_title = 0;
	pan->save_quit = 0;
	pan->savef = NULL;
	pan->tickboxes = NULL;
	pan->fieldw = NULL;
	pan->lists = NULL;
	pan->funkies = NULL;

	for(int i = 0; 1; i++)
		if(items == NULL || items[i] == NULL)
		{
			pan->n_items = i;
			break;
		}

	return pan;
}

void set_panel_attributes(panel *pan, int centered_title, int save_quit,
													void (*savef)(struct panel *, tagst *ts))
{
	pan->centered_title = centered_title;
	pan->save_quit = save_quit;
	pan->savef = savef;
}

void set_panel_interactions(panel *pan, int *tickboxes, int *fieldw,
														char ***lists, struct interfunk **funkies)
{
	pan->tickboxes = tickboxes;
	pan->fieldw = fieldw;
	pan->lists = lists;
	pan->funkies = funkies;
}

void load_panel(panel *pan)
{
	int max = 0;

	/*height*/
	pan->height = 2;
	pan->height += (pan->n_items ? pan->n_items : 1);
	pan->height += (pan->save_quit ? 2 : 0);

	/*width*/
	for(int i = 0; i < pan->n_items; i++)
	{
		int iw = strlen(pan->items[i]) + 2;					 /*2: spaces around the items*/
		iw += pan->tickboxes && pan->tickboxes[i] != -1 ? 4 : 0;		 /*4: tickbox*/
		iw += pan->fieldw && pan->fieldw[i] != -1 ?
					(pan->fieldw[i] == 0 ? 10 : pan->fieldw[i])			/*10: default field*/
					: 0;
		max = iw > max ? iw : max;
	}
	max = pan->title && strlen(pan->title) > max ? strlen(pan->title) : max;
	max = pan->save_quit && 10 > max ? 10 : max;
	max = pan->n_items == 0 && 40 > max ? 40 : max;
	pan->width = max + 2;

	/*fields*/
	if(pan->fieldw)
	{
		int c = 0;
		for(int i = 0; i < pan->n_items; i++)
			c += pan->fieldw[i] != -1 ? 1 : 0;

		if(c > 0)
		{
			pan->fields = (char **)malloc((c+1) * sizeof(char *));
			int i = 0;
			size_t size;
			for(int j = 0; j < pan->n_items; j++)
				if(pan->fieldw[j] != -1)
				{
					size = (pan->fieldw[j] == 0 ? 10 : pan->fieldw[j]) + 1;
					pan->fields[i] = (char *)malloc(size);
					memset((void *)(pan->fields[i]), 0, size);
					i++;
				}
			pan->fields[i] = NULL;
		}
		else
			pan->fields = NULL;
	}

	/*window*/
	pan->win = newwin(pan->height, pan->width,
										(LINES/2)-(pan->height/2),
										(COLS/2)-(pan->width/2));
	wattron(pan->win, COLOR_PAIR(3) | A_REVERSE);
	keypad(pan->win, TRUE);
}

void panel_input(tagst *ts, panel *pan)
{
	int limit = pan->n_items + pan->save_quit;

	switch(ts->c)
	{
		case KEY_UP:
			if(ts->hlight == 0)
				ts->hlight = limit-1;
			else if(ts->hlight > 0)
				(ts->hlight)--;
			break;
		case KEY_DOWN:
			if(ts->hlight < limit-1)
				(ts->hlight)++;
			else
				ts->hlight = 0;
			break;
		case KEY_LEFT:
			if(pan->save_quit && ts->hlight == limit)
				(ts->hlight)--;
			break;
		case KEY_RIGHT:
			if(pan->save_quit && ts->hlight == limit-1)
				(ts->hlight)++;
			break;
		case 10:
			/*TODO: do_interaction(ts, pan);*/
			break;
	}
}

/*TODO: make this multiplke functions and put them into an other file*/
void display_panel(tagst *ts, panel *pan)
{
	/*background*/
	for(int i = 0; i < pan->height-1; i++)
		mvwhline(pan->win, i, 0, ' ', pan->width);
	box(pan->win, 0, 0);

	/*title*/
	if(pan->title && pan->centered_title)
	{
		int l = strlen(pan->title);
		mvwprintw(pan->win, 0, (pan->width/2)-((l+(l%2))/2), pan->title);
	}
	else if(pan->title)
		mvwprintw(pan->win, 0, 2, pan->title);

	/*items*/
	for(int i = 0; i < pan->n_items; i++)
		if(ts->hlight == i)
		{
			wattroff(pan->win, A_REVERSE);
			mvwprintw(pan->win, i+1, 2, pan->items[i]);
			wattron(pan->win, A_REVERSE);
		}
		else
			mvwprintw(pan->win, i+1, 2, pan->items[i]);

	/*tickboxes*/
	if(pan->tickboxes)
		for(int i = 0; i < pan->n_items; i++)
			if(pan->tickboxes[i] != -1)
			{
				if(ts->hlight == i)
				{
					wattroff(pan->win, A_REVERSE);
					mvwprintw(pan->win, i+1, 2+strlen(pan->items[i])+1,
									 (pan->tickboxes[i] == 0 ? "[ ]" : "[x]"));
					wattron(pan->win, A_REVERSE);
				}
				else
					mvwprintw(pan->win, i+1, 2+strlen(pan->items[i])+1,
									 (pan->tickboxes[i] == 0 ? "[ ]" : "[x]"));
			}

	/*fields*/	/*TODO: ADD CURSOR*/
	if(pan->fieldw)
		for(int i = 0; i < pan->n_items; i++)
			if(pan->fieldw[i] != -1)
			{
				if(ts->hlight == i)
				{
					wattroff(pan->win, A_REVERSE);
					mvwhline(pan->win, i+1, 2+strlen(pan->items[i])+1, 0,
									(pan->fieldw[i] == 0 ? 10 : pan->fieldw[i]));
					wattron(pan->win, A_UNDERLINE);
					mvwprintw(pan->win, i+1, 2+strlen(pan->items[i])+1,
									 (pan->fields[i] ? pan->fields[i] : "\0"));
					wattroff(pan->win, A_UNDERLINE);
					wattron(pan->win, A_REVERSE);
				}
				else
				{
					mvwhline(pan->win, i+1, 2+strlen(pan->items[i])+1, 0,
									(pan->fieldw[i] == 0 ? 10 : pan->fieldw[i]));
					wattron(pan->win, A_UNDERLINE);
					mvwprintw(pan->win, i+1, 2+strlen(pan->items[i])+1,
									 (pan->fields[i] ? pan->fields[i] : "\0"));
					wattroff(pan->win, A_UNDERLINE);
				}
			}

	/*lists*/ /*TODO*/

	/*save_quit*/
	if(pan->save_quit)
		for(int i = 0; i < 2; i++)
		{
			if(ts->hlight == (i == 0 ? pan->n_items : pan->n_items+1))
				wattroff(pan->win, A_REVERSE);

			mvwprintw(pan->win, pan->n_items+2,
							 (pan->width/2)-(i == 0 ? 5 : -1),
							 (i == 0 ? "save" : "quit"));

			if(ts->hlight == (i == 0 ? pan->n_items : pan->n_items+1))
				wattron(pan->win, A_REVERSE);
		}

	wrefresh(pan->win);
}

void do_interaction(tagst *ts, panel *pan)
{
	
}
