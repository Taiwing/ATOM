#ifndef WINDOWS_H
#define WINDOWS_H

#include "nc.h"

/*every panelable windows*/
enum windows_list {
	/*MAIN WINDOW*/
	W_BASE,

	/*PANELS*/
	W_FOLD, W_OPTIONS, W_PROPERTIES, W_QUERY,

	/*SUB_PANELS*/
	W_CONFIGURATION, W_COLOR_SCHEME, W_SORT_BY,

	/*POP_PANELS*/
	W_MODIFY_TAG, W_ADD_TAG, W_COLORS, W_CATEGORIES, W_ADD_CATEGORY,

	/*SUB_POP_PANELS*/
	W_VALUE_TYPE, W_CATEGORY_X,

	/*DIALOG_PANELS*/
	W_WARNING,

	/*TOTAL*/
	W_COUNT
};

WINDOW **init_win(void);
WINDOW *genwin(int winnb, void *data);

#endif
