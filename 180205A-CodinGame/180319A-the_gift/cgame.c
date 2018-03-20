#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b);
void share(int *ppood, int *budget, int N, int C);

int main()
{
	int N, C, capital = 0;
	scanf("%d", &N);
	scanf("%d", &C);
	int *budget = (int *)malloc(N * sizeof(int));
	int *ppood = (int *)malloc(N * sizeof(int));
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &budget[i]);
		capital += budget[i];
		ppood[i] = 0;
	}

	if(capital < C)
		printf("IMPOSSIBLE\n");
	else
	{
		qsort(budget, N, sizeof(int), cmp);
		share(ppood, budget, N, C);
		for(int i = 0; i < N; i++)
			printf("%d\n", ppood[i]);
	}

	return 0;
}

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void share(int *ppood, int *budget, int N, int C)
{
	int av, rest, N2 = N, N3 = N;
	if(C > N)
	{
		av = C/N;
		rest = C%N;
	}
	else
	{
		av = 1;
		rest = 0;
		N3 = C;
	}

	for(int i = 0; i < N3; i++)
	{
		ppood[i] += av;
		if(ppood[i] > budget[i])
		{
			rest += ppood[i]-budget[i];
			ppood[i] = budget[i];
			N2--;
		}
	}

	if(C < N)
		qsort(ppood, N, sizeof(int), cmp);

	if(rest == 1)
		ppood[N-1]++;
	else if(rest > 1)
		share(&ppood[N-N2], &budget[N-N2], N2, rest);
}
