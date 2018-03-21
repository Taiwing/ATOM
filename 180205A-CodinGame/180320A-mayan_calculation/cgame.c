#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int read(char **num, int S, char **numeral, int L, int H);
int op(int num1, int num2, char operation[2]);
void print_n(int result, char **numeral, int L, int H);

int main()
{
	int L, H;
	scanf("%d%d", &L, &H);
	char **numeral = (char **)malloc(H * sizeof(char *));
	for(int i = 0; i < H; i++)
	{
		numeral[i] = (char *)malloc(((20*L)+1) * sizeof(char));
		scanf("%s", numeral[i]);
	}
	int S1;
	scanf("%d", &S1);
	char **num1 = (char **)malloc(S1 * sizeof(char *));
	for(int i = 0; i < S1; i++)
	{
		num1[i] = (char *)malloc((L+1) * sizeof(char));
		scanf("%s", num1[i]);
	}
	int S2;
	scanf("%d", &S2);
	char **num2 = (char **)malloc(S2 * sizeof(char *));
	for(int i = 0; i < S2; i++)
	{
		num2[i] = (char *)malloc((L+1) * sizeof(char));
		scanf("%s", num2[i]);
	}
	char operation[2];
	scanf("%s", operation);

	int num[3];
	num[0] = read(num1, S1, numeral, L, H);
	num[1] = read(num2, S2, numeral, L, H);
	num[2] = op(num[0], num[1], operation);

	print_n(num[2], numeral, L, H);

	return 0;
}

int read(char **num, int S, char **numeral, int L, int H)
{
	int n, ret = 0;
	for(int i = 0; i < S/H; i++)
	{
		n = 0;
		/*reading op*/
		for(int j = 0; j < (S/H)-(i+1); j++) n*=20;
		ret+=n;
	}
	return ret;
}

int op(int num1, int num2, char operation[2])
{
	switch(operation[0])
	{
		case '*': return num1*num2;
		case '/': return num1/num2;
		case '+': return num1+num2;
		case '-': return num1-num2;
	}
}

void print_n(int result, char **numeral, int L, int H)
{

}
