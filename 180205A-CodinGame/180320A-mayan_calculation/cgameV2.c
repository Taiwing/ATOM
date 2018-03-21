#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long int read(char **num, int S, char **numeral, int L, int H);
long long int op(long long int num1, long long int num2, char operation[2]);
void print_n(long long int n, char **numeral, int L, int H);

int main()
{
	int L, H;
	scanf("%d%d", &L, &H);
	char **numeral = (char **)malloc(20 * sizeof(char *));
	for(int i = 0; i < 20; i++)
	{
		numeral[i] = (char *)malloc(((H*L)+1) * sizeof(char));
		numeral[i][H*L] = '\0';
	}
	for(int i = 0; i < H; i++)
	{
		char nm[2049];
		scanf("%s", nm);
		for(int j = 0; j < 20; j++)
			for(int k = 0; k < L; k++)
				numeral[j][(i*L)+k] = nm[(j*L)+k];
	}
	int S1;
	scanf("%d", &S1);
	char **num1 = (char **)malloc((S1/H) * sizeof(char *));
	for(int i = 0; i < S1; i++)
	{
		if(!(i%H))
		{
			num1[i/H] = (char *)malloc(((H*L)+1) * sizeof(char));
			num1[i/H][H*L] = '\0';
		}
		char num1Line[L+1];
		scanf("%s", num1Line);
		for(int j = 0; j < L; j++)
			num1[i/H][((i%H)*L)+j] = num1Line[j];
	}
	int S2;
	scanf("%d", &S2);
	char **num2 = (char **)malloc((S2/H) * sizeof(char *));
	for(int i = 0; i < S2; i++)
	{
		if(!(i%H))
		{
			num2[i/H] = (char *)malloc(((H*L)+1) * sizeof(char));
			num2[i/H][H*L] = '\0';
		}
		char num2Line[L+1];
		scanf("%s", num2Line);
		for(int j = 0; j < L; j++)
			num2[i/H][((i%H)*L)+j] = num2Line[j];
	}
	char operation[2];
	scanf("%s", operation);

		/*TEST*/
		/*for(int i = 0; i < 20; i++)
		{
			printf("\nnumber %d:\n", i);
			printf("%s\n", numeral[i]);
		}
		for(int i = 0; i < S1/H; i++)
		{
			printf("\nnumber %d:\n", i);
			printf("%s\n", num1[i]);
		}
		for(int i = 0; i < S2/H; i++)
		{
			printf("\nnumber %d:\n", i);
			printf("%s\n", num2[i]);
		}*/

	long long int num[3];
	num[0] = read(num1, S1, numeral, L, H);
	num[1] = read(num2, S2, numeral, L, H);
	num[2] = op(num[0], num[1], operation);

		/*TEST*/
		printf("\n%lli %s %lli = %lli\n", num[0], operation, num[1], num[2]);

	print_n(num[2], numeral, L, H);

	return 0;
}

long long int read(char **num, int S, char **numeral, int L, int H)
{
	int n;
	long long int ret = 0;
	for(int i = 0; i < S/H; i++)
	{
		n = 0;
		for(; strcmp(numeral[n], num[i]); n++);
		for(int j = 0; j < (S/H)-(i+1); j++) n*=20;
		ret+=n;
	}
	return ret;
}

long long int op(long long int num1, long long int num2, char operation[2])
{
	switch(operation[0])
	{
		case '*': return num1*num2;
		case '/': return num1/num2;
		case '+': return num1+num2;
		case '-': return num1-num2;
	}
}

void print_n(long long int n, char **numeral, int L, int H)
{
	if(n > 19)
	{
		print_n(n/20, numeral, L, H);
		n%=20;
	}

	for(int i = 0; i < H; i++)
		for(int j = 0; j < L; j++)
		{
			printf("%c", numeral[n][(i*L)+j]);
			if(j == (L-1)) printf("\n");
		}
}
