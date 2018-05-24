#include <string.h>
#include <signal.h>			/*to handle the resizing of the terminal*/
#include <ncurses.h>

/*TODO*/
/*remake the printing functions so they don't need global variables*/
/*print "tag_folders" in cyan*/
/*reorganise all this shit, try to reduce the number of variables in tagst*/

char *qbar[] = {
	"tag_adress",
	"bar",
	"cur",
	"next"
};

char *attrbar[] = {
	"name",
	"size",
	"tag_value"
};

char *elem_names[] = {
	"next",
	"file1",
	"foo",
	"bar"
};

char *elem_sizes[] = {
	"10",
	"1024",
	"42",
	"3"
};

char *elem_tagvalues[] = {
	"-",
	"lol",
	"zKx",
	"zzw"
};

char *functions[] = {
	" help ",
	" options ",
	" properties ",
	" query ",
	" exit "
};

char *command_buttons[] = {
	"F1",
	"F2",
	"F3",
	"F4",
	"F5"
};

char *func_panel_help[] = {
	"help"
};

char *func_panel_options[] = {
	"options",
	"configuration",
	"color scheme",
	"sort by",
	"recursively unfold all tags",
	"unfold all tags",
	"unfold tag",
	"fold all tags",
	"fold tag"
};

char *func_panel_properties[] = {
	"properties",
	"name",
	"size",
	"path",
	"tags",
	"add tag(+)",
	"remove tag(-)",
	"save"
};

char *func_panel_query[] = {
	"query:"
};

/*global variable for the handle_winch function*/
WINDOW *win[5]; /*qbar, elem_list, functions, function_panel*/
/*and maybe add a command line*/

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

void generate_win(WINDOW *wind[5]);
void function_panel(WINDOW *wind[5], tagst *ts);
void sub_function_panel(WINDOW *wind[5], tagst *ts);
void handle_winch(int sig);
void mvhlight(tagst *ts);
void mvhlight_qbar(tagst *ts);
void mvhlight_elem_list(tagst *ts);
void mvhlight_funcpanel(tagst *ts);
void function_input(tagst *ts, int *noexit);
void print_tag_screen(WINDOW *wind[5], tagst *ts);
void print_qbar(WINDOW *qbar_win, tagst *ts);
void print_elem_list(WINDOW *elist_win, tagst *ts);
void print_funcbar(WINDOW *funcbar_win, tagst *ts);
void print_funcpanel(WINDOW *funcpanel, tagst *ts);
void print_subfuncpanel(WINDOW *subfunc, tagst *ts);

int main(void)
{
	tagst ts;
	int noexit = 1;
	struct sigaction sa;

	/*tag status initialization*/
	ts.curwin = 0;			/*0 for the example, but on elem_list window by default*/
	ts.old_curwin = -1;															 /*no old_curwin by default*/
	ts.hlight = 0;						 /*0 for the example, but no highlight by default*/
	ts.old_hlight = -1;															 /*no old_hlight bu default*/
	ts.choice = -1;																							/*no choice yet*/
	ts.curq = 2;					/*2 for the example, but no query yet (-1) by default*/
	ts.panel_ev = 0;																						 /*0 by default*/
	ts.qbc = 4;														/*4 for the example, but 0 by default*/
	ts.elc = 4;														/*4 for the example, but 0 by default*/
	ts.attrc = 3;					/*3 for the example, but 2 by default (name and size)*/
	ts.func = -1;																/*no panel activated by default*/
	ts.sub_func = -1;												 /*no subpanel activated by default*/

	/*sigaction initalization*/
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = handle_winch;
	sigaction(SIGWINCH, &sa, NULL);

	/*ncurses initialization*/
	initscr();																						/*initializes ncurses*/
	cbreak();																					/*line buffering disabled*/
	noecho();																		/*no fucking echo while getch()*/
	curs_set(0);																		 /*NO FUCKING CURSOR EITHER*/
	start_color();																		 /*so we can create pairs*/
	init_pair(1, COLOR_WHITE, COLOR_BLACK);											/*like this one*/
	init_pair(2, COLOR_CYAN, COLOR_BLACK);											 /*and this one*/
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);										 /*and this one*/
	generate_win(win);

	print_tag_screen(win, &ts);

	while(noexit)
	{
		ts.c = wgetch(win[ts.curwin]);
		function_input(&ts, &noexit);
		function_panel(win, &ts);
		mvhlight(&ts);
		sub_function_panel(win, &ts);
		print_tag_screen(win, &ts);
		if(ts.choice != -1)
			noexit = 0;
	}

	if(ts.choice != -1)
	{
		mvprintw(LINES-1, 0,
			"You chose choice %d wich is %s and LINES = %d and COLS = %d\n",
			ts.choice+1, qbar[ts.choice], LINES, COLS);
			refresh();
			getch(); /*pause*/
	}
	endwin();

	return 0;
}

void generate_win(WINDOW *wind[5])
{
	wind[0] = newwin(1, COLS, 0, 0);																		 /*qbar*/
	wind[1] = newwin(LINES-2, COLS, 1, 0);													/*elem_list*/
	wind[2] = newwin(1, COLS, LINES-1, 0);													/*functions*/
	wind[3] = NULL;																						 /*function panel*/
	wind[4] = NULL;																					/*sub-funcion panel*/

	for(int i = 0; i < 3; i++)	/*we get F1, F2, etc... and the arrows*/
		keypad(wind[i], TRUE);
}

void function_panel(WINDOW *wind[5], tagst *ts)
{
	if(wind[3] && ts->func == -1)
	{
		delwin(wind[3]);
		wind[3] = NULL;
		ts->curwin = ts->old_curwin;
		ts->old_curwin = 3;
		ts->hlight = ts->old_hlight;
		ts->panel_ev = 1;
	}
	else if(wind[3] == NULL && ts->func != -1)
	{
		ts->old_curwin = ts->curwin;
		ts->curwin = 3;
		ts->old_hlight = ts->hlight;
		ts->hlight = 0;

		/*generate func_panel*/
		switch(ts->func)
		{
			case 1:	/*help*/
				wind[3] = newwin(9, 50, (LINES/2)-(9/2), (COLS/2)-(50/2));		 /*TEST*/
				break;
			case 2:	/*options*/
				wind[3] = newwin(10, 32, (LINES/2)-(10/2), (COLS/2)-(32/2));
				break;
			case 3:	/*properties*/
				wind[3] = newwin(9, 18, (LINES/2)-(9/2), (COLS/2)-(18/2));
				break;
			case 4:	/*query*/
				wind[3] = newwin(3, 50, (LINES/2)-(3/2), (COLS/2)-(50/2));
				break;
		}

		wattron(wind[3], COLOR_PAIR(3) | A_REVERSE);
		keypad(wind[3], TRUE);
	}
}

void sub_function_panel(WINDOW *wind[5], tagst *ts)
{
	if(wind[4] && ts->sub_func == -1)
	{
		delwin(wind[4]);
		wind[4] = NULL;
		(ts->curwin)--;
		ts->hlight = 0;
		ts->panel_ev = 1;
	}
	if(wind[4] == NULL && ts->sub_func != -1)
	{
		(ts->curwin)++;

		switch(ts->sub_func)
		{
			default:	/*TEST*/
				wind[4] = newwin(9, 50, (LINES/2)-(9/2), (COLS/2)-(50/2));
				break;
		}

		wattron(wind[4], COLOR_PAIR(3) | A_REVERSE);
		keypad(wind[4], TRUE);
		ts->panel_ev = 1;
	}
}

void handle_winch(int sig)
{
	for(int i = 0; i < 3; i++)
		delwin(win[i]);
	if(win[3])
		delwin(win[3]);
	if(win[4])
		delwin(win[4]);
	endwin();
	refresh();
	clear();
	generate_win(win);
}

void mvhlight(tagst *ts)
{
	switch(ts->curwin)
	{
		case 0:	/*qbar*/
			mvhlight_qbar(ts);
			break;
		case 1:	/*elem_list*/
			mvhlight_elem_list(ts);
			break;
		case 3: /*funcpanel*/
			mvhlight_funcpanel(ts);
			break;
		case 4: /*subfuncpanel*/
			//TODO: mvhlight_subfuncpanel(ts);
			break;
	}
}

void mvhlight_qbar(tagst *ts)
{
	switch(ts->c)
	{
		case KEY_LEFT:
			if(ts->hlight == 0)
				ts->hlight = ts->qbc-1;
			else
				(ts->hlight)--;
			break;
		case KEY_RIGHT:
			if(ts->hlight == ts->qbc-1)
				ts->hlight = 0;
			else
				(ts->hlight)++;
			break;
		case KEY_DOWN:
			if(ts->elc != 0)
			{
				(ts->curwin)++;
				ts->hlight = 0;
			}
			break;
		case 10:
			ts->choice = ts->hlight;
			break;
	}
}

void mvhlight_elem_list(tagst *ts)
{
	switch(ts->c)
	{
		case KEY_UP:
			if(ts->hlight == 0 && ts->qbc != 0)
			{
				(ts->curwin)--;
				ts->hlight = 0;
			}
			else if(ts->hlight > 0)
				(ts->hlight)--;
			break;
		case KEY_DOWN:
			if(ts->hlight < (ts->elc-1))
				(ts->hlight)++;
			break;
		case 10:
			ts->choice = ts->hlight;
			break;
	}
}

void mvhlight_funcpanel(tagst *ts)
{
	if(ts->func == 2 || ts->func == 3)
		switch(ts->c)
		{
			case KEY_UP:
				if(ts->hlight == 0)
					ts->hlight = (ts->func == 2 ? 7 : 6);
				else if(ts->hlight > 0)
					(ts->hlight)--;
				break;
			case KEY_DOWN:
				if(ts->hlight < (ts->func == 2 ? 7 : 6))
					(ts->hlight)++;
				else
					ts->hlight = 0;
				break;
			case 10:
				if(ts->func == 2 || ts->func == 3)
				{
					ts->sub_func = ts->hlight;
					ts->hlight = 0;
				}
				else if(ts->func == 3)
				{
					/*TODO: query validation*/
				}
				break;
		}
}

void function_input(tagst *ts, int *noexit)
{
	for(int i = 1; i < 6; i++)
		if(ts->c == KEY_F(i))
		{
			if(ts->func == -1 && i != 5)
				ts->func = i;
			else if(ts->func == -1 && ts->sub_func == -1 && i == 5)
				*noexit = 0;
			else if(ts->func != -1 && ts->sub_func == -1 && i == 5)
				ts->func = -1;
			else if(ts->sub_func != -1 && i == 5)
				ts->sub_func = -1;
			break;
		}
}

void print_tag_screen(WINDOW *wind[5], tagst *ts)
{
	print_qbar(wind[0], ts);
	print_elem_list(wind[1], ts);
	print_funcbar(wind[2], ts);
	if(ts->sub_func == -1)
		print_funcpanel(wind[3], ts);
	else
		print_subfuncpanel(wind[4], ts);
}

void print_qbar(WINDOW *qbar_win, tagst *ts)
{
	int x = 0;

	wattron(qbar_win, COLOR_PAIR(2));
	for(int i = 0; i < ts->qbc; i++)
	{
		if(ts->curq == i)
			wattron(qbar_win, A_BOLD);
		else
			wattroff(qbar_win, A_BOLD);
		if(ts->hlight == i && ts->curwin == 0) /* High light the present choice */
		{
			wattron(qbar_win, A_REVERSE);
			mvwprintw(qbar_win, 0, x, "%s", qbar[i]);
			wattroff(qbar_win, A_REVERSE);
		}
		else
			mvwprintw(qbar_win, 0, x, "%s", qbar[i]);

		x += strlen(qbar[i]) + 1;
	}
	wattroff(qbar_win, COLOR_PAIR(2));

	wrefresh(qbar_win);
}

void print_elem_list(WINDOW *elist_win, tagst *ts)
{
	int colsize = (COLS-ts->attrc+1)/ts->attrc;
	int rest = (COLS-ts->attrc+1)%ts->attrc;

	/*redraw the background if a function panel was closed or a sub was opened*/
	/*also redraw when the subfunc panel is closed*/
	if(ts->panel_ev)
	{
		wbkgd(elist_win, COLOR_PAIR(1));
		ts->panel_ev = 0;
	}

	/*print seperators*/
	for(int x = colsize+rest; x < COLS; x += colsize+1)
		mvwvline(elist_win, 0, x, 0, LINES-2);

	/*print the attribar*/
	for(int i = 0, tmpx = colsize+rest; i < ts->attrc; i++, tmpx += colsize+1)
	{
		int x;
		if(tmpx == colsize+rest) /*if it is the first column*/
			x = (tmpx/2)-(strlen(attrbar[i])/2);
		else
			x = (tmpx-colsize)+(colsize/2)-(strlen(attrbar[i])/2);
		mvwprintw(elist_win, 0, x, attrbar[i]);
	}

	/*print the list*/
	for(int i = 0; i < ts->attrc; i++)
	{
		int x = i == 0 ? 1 : (colsize+1)*(i+1);
		for(int j = 0; j < ts->elc; j++)
		{
			if(ts->hlight == j && ts->curwin == 1)
				wattron(elist_win, A_REVERSE);

			switch(i)
			{
				case 0: mvwprintw(elist_win, j+1, x, elem_names[j]);
					break;
				case 1: mvwprintw(elist_win, j+1, x-strlen(elem_sizes[j]),
													elem_sizes[j]);
					break;
				case 2: mvwprintw(elist_win, j+1, x-strlen(elem_tagvalues[j]),
													elem_tagvalues[j]);
					break;
			}

			if(ts->hlight == j && ts->curwin == 1)
				wattroff(elist_win, A_REVERSE);
		}
	}

	wrefresh(elist_win);
}

void print_funcbar(WINDOW *funcbar_win, tagst *ts)
{
	int x = 0;

	wattron(funcbar_win, COLOR_PAIR(3));
	for(int i = 0; i < 5; i++)
	{
		wattron(funcbar_win, A_BOLD);
		mvwprintw(funcbar_win, 0, x, command_buttons[i]);
		wattroff(funcbar_win, A_BOLD);
		x+=2;
		wattron(funcbar_win, A_REVERSE);
		mvwprintw(funcbar_win, 0, x, functions[i]);
		wattroff(funcbar_win, A_REVERSE);
		x+=strlen(functions[i]);
	}
	wattroff(funcbar_win, COLOR_PAIR(3));

	wrefresh(funcbar_win);
}

void print_funcpanel(WINDOW *funcpanel, tagst *ts)
{
	if(ts->func != -1)
	{
		for(int i = 0; i < getmaxy(funcpanel); i++)
			mvwhline(funcpanel, i, 0, ' ', getmaxx(funcpanel)+1);
		box(funcpanel, 0, 0);
	}

	switch(ts->func)
	{
		case 1:	/*help*/
			/*nothing for now*/
			break;
		case 2:	/*options*/
			mvwprintw(funcpanel, 0, (32/2)-((strlen(func_panel_options[0])+1)/2),
								func_panel_options[0]);
			for(int y = 1; y < 9; y++)
				if(ts->hlight == (y-1))
				{
					wattroff(funcpanel, A_REVERSE);
					mvwprintw(funcpanel, y, 2, func_panel_options[y]);
					wattron(funcpanel, A_REVERSE);
				}
				else
					mvwprintw(funcpanel, y, 2, func_panel_options[y]);
			break;
		case 3:	/*properties*/
			mvwprintw(funcpanel, 0, (18/2)-(strlen(func_panel_properties[0])/2),
								func_panel_properties[0]);
			for(int y = 1; y < 8; y++)
				if(ts->hlight == (y-1))
				{
					wattroff(funcpanel, A_REVERSE);
					mvwprintw(funcpanel, y, 2, func_panel_properties[y]);
					wattron(funcpanel, A_REVERSE);
				}
				else
					mvwprintw(funcpanel, y, 2, func_panel_properties[y]);
			break;
		case 4:	/*query*/
			/*TODO: add a cursor*/
			box(funcpanel, 0, 0);
			mvwprintw(funcpanel, 0, 2, func_panel_query[0]);
			break;
	}

	if(ts->func != -1)
		wrefresh(funcpanel);
}

void print_subfuncpanel(WINDOW *subfunc, tagst *ts)
{
	for(int i = 0; i < getmaxy(subfunc); i++)
		mvwhline(subfunc, i, 0, ' ', getmaxx(subfunc)+1);
	box(subfunc, 0, 0);

	switch(ts->sub_func)
	{
		default:	/*TEST*/
			mvwprintw(subfunc, 0, 23, "TEST");
			break;
	}

	wrefresh(subfunc);
}
