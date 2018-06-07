#ifndef MENUS_H
#define MENUS_H

#include "nc.h"

/*every menu of the program*/
enum menus_list {
	M_QBAR, M_ELEM_LIST,																							 /*W_BASE*/
	M_SAVE_QUIT, M_OK_CANCEL,																		 /*INTERACTIONS*/
	M_OPTIONS,																											/*W_OPTIONS*/
	M_PROP1, M_PROP2, M_PROP3,																	 /*W_PROPERTIES*/
	M_CONFIGURATION,																					/*W_CONFIGURATION*/
	M_COLSC1, M_COLSC2, M_COLSC3, M_COLSC4,										 /*W_COLOR_SCHEME*/
	M_SORT_BY,																											/*W_SORT_BY*/
	M_MODIFY_TAG,																								 /*W_MODIFY_TAG*/
	M_ADD_TAG,																											/*W_ADD_TAG*/
	M_COLORS,																												 /*W_COLORS*/
	M_CATEGORIES,																								 /*W_CATEGORIES*/
	M_ADD_CATEGORY,																						 /*W_ADD_CATEGORY*/

	/*TOTAL*/
	M_COUNT
};

MENU **init_men(void);

#endif
