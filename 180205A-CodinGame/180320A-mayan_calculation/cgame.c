#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int L, H;
	scanf("%d%d", &L, &H);
	char **numeral = (char **)malloc(H * sizeof(char *));
	for (int i = 0; i < H; i++)
	{
		char numeral[2049];
		scanf("%s", numeral);
	}
	int S1;
	scanf("%d", &S1);
	for (int i = 0; i < S1; i++)
	{
		char num1Line[L+1];
		scanf("%s", num1Line);
	}
	int S2;
	scanf("%d", &S2);
	for (int i = 0; i < S2; i++)
	{
		char num2Line[L+1];
		scanf("%s", num2Line);
	}
	char operation[2];
	scanf("%s", operation);

	printf("result\n");

	return 0;
}
