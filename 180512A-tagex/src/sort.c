#include "include/sort.h"

/*TODO: implement tagvalue_sort*/

static int cmp_septf(const void *e1, const void *e2);
static int septf_sort(tag_elem **elem_list, int elc);
static int cmp_alphanum(const void *e1, const void *e2);
static void alphanum_sort(tag_elem **elem_list, int elc, int sep);
static int cmp_size(const void *e1, const void *e2);
static void size_sort(tag_elem **elem_list, int elc, int sep);

void sort_elem_list(tag_elem **elem_list, int elc, uint8_t sortmode)
{
	int sep = 0; /*separator (first non tag element)*/

	if(sortmode & SEPTF || sortmode & SIZE) /*size sort implies septf sort*/
		sep = septf_sort(elem_list, elc);
	if(sortmode & ALPHANUM || sortmode & TAG_VALUE) /*temp*/
		alphanum_sort(elem_list, elc, sep);
	if(sortmode & SIZE)
		size_sort(elem_list, elc, sep);
}

static int cmp_septf(const void *e1, const void *e2)
{
	tag_elem *el1, *el2;
	el1 = *((tag_elem **)e1);
	el2 = *((tag_elem **)e2);
	int ineq = (el1->type != el2->type);

	if(el1->type == TAG && ineq)
		return -1;
	else if(el1->type == REGFILE && ineq)
		return 1;
	else
		return 0;
}

static int septf_sort(tag_elem **elem_list, int elc)
{
	int sep = 0;

	qsort((void *)elem_list, (size_t)elc, sizeof(tag_elem *), cmp_septf);

	for(int i = 0; i < elc; i++)
		if(elem_list[i]->type != TAG)
		{
			sep = i;
			break;
		}

	return sep;
}

static int cmp_alphanum(const void *e1, const void *e2)
{
	tag_elem *el1, *el2;
	el1 = *((tag_elem **)e1);
	el2 = *((tag_elem **)e2);

	return strcmp(el1->name, el2->name);
}

static void alphanum_sort(tag_elem **elem_list, int elc, int sep)
{
	/*WARINING: if sep == 0, I don't know what the first qsort does*/
	qsort((void *)elem_list, (size_t)sep, sizeof(tag_elem *), cmp_alphanum);
	qsort((void *)(elem_list+sep), (size_t)(elc-sep),
				sizeof(tag_elem *), cmp_alphanum);
}

static int cmp_size(const void *e1, const void *e2)
{
	tag_elem *el1, *el2;
	el1 = *((tag_elem **)e1);
	el2 = *((tag_elem **)e2);

	return (int)(el1->size - el2->size);
}

static void size_sort(tag_elem **elem_list, int elc, int sep)
{
	/*WARINING: if sep == 0, I don't know what the first qsort does*/
	qsort((void *)elem_list, (size_t)sep, sizeof(tag_elem *), cmp_size);
	qsort((void *)(elem_list+sep), (size_t)(elc-sep),
				sizeof(tag_elem *), cmp_size);
}
