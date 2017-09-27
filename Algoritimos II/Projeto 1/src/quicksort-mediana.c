#include "particiona.h"
#include "biblioteca.h"


/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(int v[], int a, int b, int c) 
{

	if (compara(v[a], v[b]) == 1)
	{
		troca(v,a,b);
	}
	
	if (compara(v[a], v[c]) == 1)
	{
		troca(v,a,c);
	}

	if (compara(v[b], v[c]) == 1)
	{
		troca(v,b,c);
	}

	return b;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) 
{
	int 		mediana_v,
	  			m;

	if (a >= b)
	{
		return v;
	} 

	mediana_v = mediana(v, sorteia(a,b), sorteia(a,b), sorteia(a,b));

	troca(v, b, mediana_v);

	m = particiona(v, a, b,v[b]);  

  	quicksort_mediana(v, a, m-1);
	quicksort_mediana(v, m+1, b);
	  
	return v; 
}


