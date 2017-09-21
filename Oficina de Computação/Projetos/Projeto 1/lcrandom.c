//DOUGLAS AFFONSO CLEMENTINO  -- GRR20175877

#include <stdio.h>
#include "lcrandom.h"

unsigned long X = 0, A = 40692, C = 127, M = 10000000;

unsigned long lcrandom ()
{
		X = (A * X + C) % M;

		return X;
}

//Função que atribuirá valor passado para a variável X, 
//que define a pisição de início da geração dos valores randômicos.
void lcrandom_seed (unsigned long s) 
{
	X = s;
}

// informa o valor máximo que pode ser gerado (o mínimo é sempre zero)
unsigned long lcrandom_max () 
{
	return M - 1;
}

void lcrandom_parms (unsigned long a, unsigned long c, unsigned long m) 
{	
	A = a;
	C = c;
	M = m;
}