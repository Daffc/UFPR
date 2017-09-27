#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* modifica v e devolve um �ndice m de forma que */
/* a-1 <= m <= b */
/* v[i] <= x, para todo a <= i <=m */
/* x < v[i], para todo m < i <=b */

int particiona(int v[], int a, int b, int x) 
{
	long long  	m,
				i;

	m = a - 1;

	//La�o de repeti��o que percorre todo o vetor e ao final tem como resultado os elementos 
	//menores ou iguais que o pivo em uma posi��o menor que a dele, os valores maiores que o 
	//pivo em posi��es maiores que a dele e o pivo entre estes dois grupos.
	for (i = a; i <= b; ++i)
	{
		if (compara(v[i], x) <= 0)
		{
			m = m + 1;
			troca(v, m, i);
		}
	}

  return m;
}