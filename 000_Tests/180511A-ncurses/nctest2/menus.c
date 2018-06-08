#include "menus.h"

static MENU *gen_M_QBAR(WINDOW *mainwin);
static MENU *gen_M_ELEM_LIST(WINDOW *mainwin);
static MENU *gen_M_SAVE_QUIT(WINDOW *mainwin);
static MENU *gen_M_OK_CANCEL(WINDOW *mainwin);
static MENU *gen_M_OPTIONS(WINDOW *mainwin);
static MENU *gen_M_PROP1(WINDOW *mainwin);
static MENU *gen_M_PROP2(WINDOW *mainwin);
static MENU *gen_M_PROP3(WINDOW *mainwin);
static MENU *gen_M_CONFIGURATION(WINDOW *mainwin);
static MENU *gen_M_COLSC1(WINDOW *mainwin);
static MENU *gen_M_COLSC2(WINDOW *mainwin);
static MENU *gen_M_COLSC3(WINDOW *mainwin);
static MENU *gen_M_COLSC4(WINDOW *mainwin);
static MENU *gen_M_SORT_BY(WINDOW *mainwin);
static MENU *gen_M_MODIFY_TAG(WINDOW *mainwin);
static MENU *gen_M_ADD_TAG(WINDOW *mainwin);
static MENU *gen_M_COLORS(WINDOW *mainwin);
static MENU *gen_M_CATEGORIES(WINDOW *mainwin);
static MENU *gen_M_ADD_CATEGORY(WINDOW *mainwin);

MENU **init_men(void)
{
	MENU **men = (MENU **)malloc(M_COUNT * sizeof(MENU *));

	for(int i = 0; i < M_COUNT; i++)												/*not generated yet*/
		men[i] = NULL;

	return men;
}

MENU *genmen(int mennb, WINDOW *mainwin, void *data)
{
	switch(mennb)
	{
		case M_QBAR:
			return gen_M_QBAR(mainwin);
			break;
		case M_ELEM_LIST:
			return gen_M_ELEM_LIST(mainwin);
			break;
		case M_SAVE_QUIT:
			return gen_M_SAVE_QUIT(mainwin);
			break;
		case M_OK_CANCEL:
			return gen_M_OK_CANCEL(mainwin);
			break;
		case M_OPTIONS:
			return gen_M_OPTIONS(mainwin);
			break;
		case M_PROP1:
			return gen_M_PROP1(mainwin);
			break;
		case M_PROP2:
			return gen_M_PROP2(mainwin);
			break;
		case M_PROP3:
			return gen_M_PROP3(mainwin);
			break;
		case M_CONFIGURATION:
			return gen_M_CONFIGURATION(mainwin);
			break;
		case M_COLSC1:
			return gen_M_COLSC1(mainwin);
			break;
		case M_COLSC2:
			return gen_M_COLSC2(mainwin);
			break;
		case M_COLSC3:
			return gen_M_COLSC3(mainwin);
			break;
		case M_COLSC4:
			return gen_M_COLSC4(mainwin);
			break;
		case M_SORT_BY:
			return gen_M_SORT_BY(mainwin);
			break;
		case M_MODIFY_TAG:
			return gen_M_MODIFY_TAG(mainwin);
			break;
		case M_ADD_TAG:
			return gen_M_ADD_TAG(mainwin);
			break;
		case M_COLORS:
			return gen_M_COLORS(mainwin);
			break;
		case M_CATEGORIES:
			return gen_M_CATEGORIES(mainwin);
			break;
		case M_ADD_CATEGORY:
			return gen_M_ADD_CATEGORY(mainwin);
			break;
		default:
			return NULL;
			break;
	}
}

static MENU *gen_M_QBAR(WINDOW *mainwin)
{
	
	return NULL;
}

static MENU *gen_M_ELEM_LIST(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_SAVE_QUIT(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_OK_CANCEL(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_OPTIONS(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_PROP1(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_PROP2(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_PROP3(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_CONFIGURATION(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_COLSC1(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_COLSC2(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_COLSC3(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_COLSC4(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_SORT_BY(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_MODIFY_TAG(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_ADD_TAG(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_COLORS(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_CATEGORIES(WINDOW *mainwin)
{
	return NULL;
}

static MENU *gen_M_ADD_CATEGORY(WINDOW *mainwin)
{
	return NULL;
}
