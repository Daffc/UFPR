#include "quicksort-insercao.h"
#include "biblioteca.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000000
int		vetor[MAX];

int main()
{
	

	for (int i = 0; i < MAX; ++i)
	{
		vetor[i] = sorteia(0, 100);	
	}
	
	// for (int i = 0; i < MAX; ++i)
	// {
	// 	printf("%d ", vetor[i]);
	// }

	printf("\n//////////////////\n");
	
	quicksort_insercao(vetor, 0, MAX - 1, 100);

	// for (int i = 0; i < MAX; ++i)
	// {
	// 	printf("%d ", vetor[i]);
	// }
	// printf("\n");

	return 0;
}