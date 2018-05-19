#ifndef SORT_H
#define SORT_H

#include "main.h"
#include "elem_list.h"

/*sorting modes*/
#define DEFAULT 		0x03	/*SEPTF + ALPHANUM*/
#define SEPTF				0x01	/*separate tags and files*/
#define ALPHANUM		0x02
#define SIZE				0x04
#define TAG_VALUE		0x08

void sort_elem_list(tag_elem **elem_list, int elc, uint8_t sortmode);

#endif
