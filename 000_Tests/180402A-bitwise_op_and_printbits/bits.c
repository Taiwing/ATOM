#include <stdio.h>
#define CHUNK_SIZE	64

void print_bits(size_t const size, void const * const ptr);

int main(void)
{
	size_t newsize = 10120;
	printf("newsize = %lu\n", newsize);
	printf("bin: ");
	print_bits(sizeof(newsize), &newsize);
	printf("\n");

	size_t csize = CHUNK_SIZE-1;
	printf("csize = %lu\n", csize);
	printf("bin: ");
	print_bits(sizeof(csize), &csize);
	printf("\n");

	size_t sum = newsize + CHUNK_SIZE-1;
	printf("sum = %lu\n", sum);
	printf("bin: ");
	print_bits(sizeof(sum), &sum);
	printf("\n");

	size_t csize2 = ~(CHUNK_SIZE-1);
	printf("csize2 = %lu\n", csize2);
	printf("bin: ");
	print_bits(sizeof(csize2), &csize2);
	printf("\n");

	size_t nsum = sum & csize2;
	printf("sum & csize2 = %lu\n", nsum);
	printf("bin: ");
	print_bits(sizeof(nsum), &nsum);
	printf("\n");

	return 0;
}

void print_bits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for(i = size-1; i >= 0; i--)
	{
		for(j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}
