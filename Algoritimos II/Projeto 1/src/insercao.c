#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo m�todo da sele��o e devolve v */


// Fun��o interna que procura e retorna local onde valor x deve ser inserido no 
// vetor v de forma ordenada.
int busca (int x, int v[], int a, int b)
{
	if (a > b)
	{
		return a-1;
	}
	if (compara(x,v[b]) >= 0)
	{
		return b;
	}

	return busca(x,v,a,b-1);
}

// Fun��o interna que insere valor b no vetor v[a .. b-1] de forma ordenada.
int *insere	(int v[], unsigned int a, unsigned int b)
{
	long 	p = busca(v[b],v,a,b-1),
			i;

	// La��o para "empurar" para posi��es maiores valores maiores 
	// que o valor a ser inserido no vetor. 
	for (i = b; i > p+1 ; --i)
	{
		troca(v,i,i -1);
	}

	return v;
}

/*******************************************************/
int *insercao(int v[], unsigned int a, unsigned int b) 
{

	if (a >= b)
	{
		return v;
	}

	insercao(v,a,b-1);
	insere(v, a, b);

  	return v;
}
