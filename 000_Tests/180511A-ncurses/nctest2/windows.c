#include "windows.h"

static WINDOW *gen_W_BASE(void);
static WINDOW *gen_W_FOLD(void);
static WINDOW *gen_W_OPTIONS(void);
static WINDOW *gen_W_PROPERTIES(gettag *tags);
static WINDOW *gen_W_QUERY(void);
static WINDOW *gen_W_CONFIGURATION(void);
static WINDOW *gen_W_COLOR_SCHEME(void);
static WINDOW *gen_W_SORT_BY(void);
static WINDOW *gen_W_MODIFY_TAG(void);
static WINDOW *gen_W_ADD_TAG(void);
static WINDOW *gen_W_COLORS(void);
static WINDOW *gen_W_CATEGORIES(char **catlist);
static WINDOW *gen_W_ADD_CATEGORY(lout *tlist);
static WINDOW *gen_W_VALUE_TYPE(void);
static WINDOW *gen_W_CATEGORY_X(void);
static WINDOW *gen_W_WARNING(char *text);

WINDOW **init_win(void)
{
	WINDOW **win = (WINDOW **)malloc(W_COUNT * sizeof(WINDOW *));

	for(int i = 0; i < W_COUNT; i++)												/*not generated yet*/
		win[i] = NULL;

	return win;
}

WINDOW *genwin(int winnb, void *data)
{
	switch(winnb)
	{
		case W_BASE:
			return gen_W_BASE();
			break;
		case W_FOLD:
			return gen_W_FOLD();
			break;
		case W_OPTIONS:
			return gen_W_OPTIONS();
			break;
		case W_PROPERTIES:
			return gen_W_PROPERTIES((gettag *)data);
			break;
		case W_QUERY:
			return gen_W_QUERY();
			break;
		case W_CONFIGURATION:
			return gen_W_CONFIGURATION();
			break;
		case W_COLOR_SCHEME:
			return gen_W_COLOR_SCHEME();
			break;
		case W_SORT_BY:
			return gen_W_SORT_BY();
			break;
		case W_MODIFY_TAG:
			return gen_W_MODIFY_TAG();
			break;
		case W_ADD_TAG:
			return gen_W_ADD_TAG();
			break;
		case W_COLORS:
			return gen_W_COLORS();
			break;
		case W_CATEGORIES:
			return gen_W_CATEGORIES((char **)data);
			break;
		case W_ADD_CATEGORY:
			return gen_W_ADD_CATEGORY((lout *)data);
			break;
		case W_VALUE_TYPE:
			return gen_W_VALUE_TYPE();
			break;
		case W_CATEGORY_X:
			return gen_W_CATEGORY_X();
			break;
		case W_WARNING:
			return gen_W_WARNING((char *)data);
			break;
		default:
			return NULL;
			break;
	}
}

static WINDOW *gen_W_BASE(void)
{
	WINDOW *win = newwin(LINES, COLS, 0, 0);
	keypad(win, TRUE);
	return win;
}

static WINDOW *gen_W_FOLD(void)
{
	return NULL;
}

static WINDOW *gen_W_OPTIONS(void)
{
	return NULL;
}

static WINDOW *gen_W_PROPERTIES(gettag *tags)
{
	return NULL;
}

static WINDOW *gen_W_QUERY(void)
{
	return NULL;
}

static WINDOW *gen_W_CONFIGURATION(void)
{
	return NULL;
}

static WINDOW *gen_W_COLOR_SCHEME(void)
{
	return NULL;
}

static WINDOW *gen_W_SORT_BY(void)
{
	return NULL;
}

static WINDOW *gen_W_MODIFY_TAG(void)
{
	return NULL;
}

static WINDOW *gen_W_ADD_TAG(void)
{
	return NULL;
}

static WINDOW *gen_W_COLORS(void)
{
	return NULL;
}

static WINDOW *gen_W_CATEGORIES(char **catlist)
{
	return NULL;
}

static WINDOW *gen_W_ADD_CATEGORY(lout *tlist)
{
	return NULL;
}

static WINDOW *gen_W_VALUE_TYPE(void)
{
	return NULL;
}

static WINDOW *gen_W_CATEGORY_X(void)
{
	return NULL;
}

static WINDOW *gen_W_WARNING(char *text)
{
	return NULL;
}

/*void generate_fixed_windows(WINDOW ***winp)
{
	WINDOW **win = (WINDOW **)malloc(W_COUNT * sizeof(WINDOW *));
	win[W_QBAR] = newwin(1, COLS, 0, 0);
	win[W_ELEM_LIST] = newwin(LINES-2, COLS, 1, 0);
	win[W_FUNCTIONS] = newwin(1, COLS, LINES-1, 0);

	for(int i = 0; i < 3; i++)					 we get F1, F2, etc... and the arrows
		keypad(win[i], TRUE);

	for(int i = 3; i < W_COUNT; i++)												not generated yet
		win[i] = NULL;

	*winp = win;
}*/
