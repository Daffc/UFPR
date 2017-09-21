//DOUGLAS AFFONSO CLEMENTINO  -- GRR20175877

#include <stdio.h>
#include "lcrandom.h"

//Constante igual a metado do tamanho do M analizado;
#define TAM 1073741824

//Vetor que reserva indeces iguais a metade de M;
unsigned char vet[TAM];

int main ()
{

	//Chama função para alterar os valores de A, C e M consecutivamente.
	lcrandom_parms(1103515245,12345,2147483648);

	unsigned long 		i, 				//Variável contadora;		
						aux;			//Variável que armazenará valor sorteado por lcrandom().

	char			prosseguir = 0;		//Variável de controle para laço de verificação de repetições.


	//Laço de repetição prar igualar a 1 o valor de todos os indices de vet[].
	for (i = 0; i < TAM; ++i)
	{
		vet[i] = 1;
	}

	i = 0;

	//Laço de repetição para guardar quais endereços já foram sorteados e verificar caso algum dos endereços seja sorteado novamente.
	do
	{
		aux = lcrandom();

		//Caso o varlor soteado seja menor que a metade de M então a posição sorteada terá seu valor multiplicado por 2.
		if (aux < TAM) 
		{
			vet[aux] *= 2;

			//Caso o valor analizado tenha sido sorteado mais de uma vez (tenha sido multiplicado por 4) o laço de repetição deve ser interrompido.
			if((vet[aux] / 2) == 2 || (vet[aux ] / 2) == 6) 
			{
				prosseguir++;
			}
		}

		else
		{
			//Caso o varlor soteado seja maior ou igual que a metade de M então a posição sorteada tera seu valor multiplicado por 3.
			vet[(aux % TAM)] *= 3;

			//Caso o valor analizado tenha sido sorteado mais de uma vez (tenha sido multiplicado por 9) o laço de repetição deve ser interrompido.
			if ((vet[(aux % TAM)] / 9) >= 1 )
			{
				prosseguir++;
			}
		}
		i++;
	} while (!(prosseguir));

	//Imprime que a quantidade de vezes que foram gerados valos não repetidos pelo alguritmo pseudoaleatério (i - 1 pois no caso de parada i tambem sera incrementado).
	printf("%lu\n", i - 1);
}