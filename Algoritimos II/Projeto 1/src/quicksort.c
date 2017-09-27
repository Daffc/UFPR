#include "particiona.h"
#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort e devolve v */

int *quicksort(int v[], int a, int b) 
{
  long long 	m;

  if (a >= b)
  {
  	return v;
  }
  
  m = particiona(v, a, b, v[b]);

  quicksort(v, a, m-1);
  quicksort(v, m+1, b);

  return v;
}
