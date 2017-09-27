#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inser��o e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) 
{
	
	long	meio;
	

	// Caso m seja maior que o numero de elementos do vetor analizado, 
	// quicksort se encerra e vetor � ordenado por insertion sort.

	if (m >= (b - a) + 1)
	{
		return insercao(v,a,b);
	}	

	meio = particiona(v, a, b, v[b]);

	quicksort_insercao(v, a, meio-1, m);
	quicksort_insercao(v, meio+1, b, m);

	return v;
}
