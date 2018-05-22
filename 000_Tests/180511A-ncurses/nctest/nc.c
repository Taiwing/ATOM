#include <string.h>
#include <signal.h>			/*to handle the resizing of the terminal*/
#include <ncurses.h>

/*TODO*/
/*remake the printing functions so they don't need global variables*/
/*print "tag_folders" in cyan*/

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

char *commands[] = {
	" help ",
	" options ",
	" properties ",
	" query "
};

char *command_buttons[] = {
	" 1",
	" 2",
	" 3",
	" 4"
};

/*global variable for the handle_winch function*/
WINDOW *win[3]; /*qbar, elem_list, commands and maybe add a command line*/

typedef struct tag_status
{
	/*interaface variables*/
	int curwin;																								 /*current window*/
	int hlight;															/*element highlighted on the screen*/
	int choice;																		 /*element chosen by the user*/
	int c;																												 /*user input*/

	/*qbar*/
	int qbc;																								/*number of queries*/
	int curq;													/*current query, if any (else curq == -1)*/

	/*elem_list*/
	int elc;																							 /*number of elements*/
	int attrc;							 /*number of listed attributes (name, size, etc...)*/
}	tagst;

void generate_win(WINDOW *win[3]);
void handle_winch(int sig);
void mvhlight(WINDOW *wind, tagst *ts);
void print_tag_screen(WINDOW *win[3], tagst *ts);
void print_qbar(WINDOW *qbar_win, tagst *ts);
void print_elem_list(WINDOW *elist_win, tagst *ts);
void print_command_bar(WINDOW *cmdbar_win, tagst *ts);

int main(void)
{
	tagst ts;
	struct sigaction sa;

	/*tag status initialization*/
	ts.curwin = 0;			/*0 for the example, but on elem_list window by default*/
	ts.hlight = 0;						 /*0 for the example, but no highlight by default*/
	ts.choice = -1;																							/*no choice yet*/
	ts.curq = 2;					/*2 for the example, but no query yet (-1) by default*/
	ts.qbc = 4;														/*4 for the example, but 0 by default*/
	ts.elc = 4;														/*4 for the example, but 0 by default*/
	ts.attrc = 3;					/*3 for the example, but 2 by default (name and size)*/

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
	init_pair(1, COLOR_CYAN, COLOR_BLACK);											/*like this one*/
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);										 /*and this one*/
	generate_win(win);

	print_tag_screen(win, &ts);

	while(1)
	{
		ts.c = wgetch(win[ts.curwin]);
		mvhlight(win[ts.curwin], &ts);
		print_tag_screen(win, &ts);
		if(ts.choice != -1)	/* User did a choice come out of the infinite loop */
			break;
	}

	mvprintw(LINES-1, 0,
					 "You chose choice %d wich is %s and LINES = %d and COLS = %d\n",
					 ts.choice+1, qbar[ts.choice], LINES, COLS);
	refresh();
	getch(); /*pause*/
	endwin();

	return 0;
}

void generate_win(WINDOW *wind[3])
{
	wind[0] = newwin(1, COLS, 0, 0);					/*qbar*/
	wind[1] = newwin(LINES-2, COLS, 1, 0);		/*elem_list*/
	wind[2] = newwin(1, COLS, LINES-1, 0);		/*commands*/

	for(int i = 0; i < 3; i++)	/*we get F1, F2, etc... and the arrows*/
		keypad(wind[i], TRUE);
}

void handle_winch(int sig)
{
	for(int i = 0; i < 3; i++)
		delwin(win[i]);
	endwin();
	refresh();
	clear();
	generate_win(win);
}

void mvhlight(WINDOW *wind, tagst *ts)
{
	switch(ts->curwin)
	{
		case 0:	/*qbar*/
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
			break;
		case 1:	/*elem_list*/
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
			break;
	}
}

void print_tag_screen(WINDOW *win[3], tagst *ts)
{
	print_qbar(win[0], ts);
	print_elem_list(win[1], ts);
	print_command_bar(win[2], ts);
}

void print_qbar(WINDOW *qbar_win, tagst *ts)
{
	int x = 0;

	wattron(qbar_win, COLOR_PAIR(1));
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
	wattroff(qbar_win, COLOR_PAIR(1));

	wrefresh(qbar_win);
}

void print_elem_list(WINDOW *elist_win, tagst *ts)
{
	int colsize = (COLS-ts->attrc+1)/ts->attrc;
	int rest = (COLS-ts->attrc+1)%ts->attrc;

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

void print_command_bar(WINDOW *cmdbar_win, tagst *ts)
{
	int x = 0;

	wattron(cmdbar_win, COLOR_PAIR(2));
	for(int i = 0; i < 4; i++)
	{
		wattron(cmdbar_win, A_BOLD);
		mvwprintw(cmdbar_win, 0, x, command_buttons[i]);
		wattroff(cmdbar_win, A_BOLD);
		x+=2;
		wattron(cmdbar_win, A_REVERSE);
		mvwprintw(cmdbar_win, 0, x, commands[i]);
		wattroff(cmdbar_win, A_REVERSE);
		x+=strlen(commands[i]);
	}
	wattroff(cmdbar_win, COLOR_PAIR(2));

	wrefresh(cmdbar_win);
}
