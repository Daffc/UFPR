//DOUGLAS AFFONSO CLEMENTINO  -- GRR20175877

#include <stdio.h>
#include "lcrandom.h"

#define COMPRIMENTO  	100
#define REPETICOES 		1000000

//Função que recebe vetor e zera todos os valores de seus indices.
void zera_vetor(unsigned long *);							

//Função que soma quantidade de vezes em que o valor do index é sorteado e atribui a posição deste mesmo index.
void atribui_valores(unsigned long *);

//Função que retorna o maior valor guardado no vetor passado.
unsigned long procura_maior(unsigned long *);

//Função que ira printar o histograma.
void imprime_resultados(unsigned long *, unsigned long);


int main ()
{
	
	unsigned long 	contador[COMPRIMENTO], 	//Vetor que armazenará a quantidade de repetições dos seus indeces;
					maior = 0;				//Variável usilizada para armazenar o maior o vaor a quantidade de vezes em quer apartece o valor mais repetido sorteado pelo algoitimo pseudoaleatório.
	

	zera_vetor(contador);

	atribui_valores(contador);
	
	maior = procura_maior(contador);

	imprime_resultados(contador, maior);
}

void zera_vetor(unsigned long vet[])
{
	int 			i;

	//Laço para tornar zero todos os valoes do vetor contador.
	for (i = 0; i < COMPRIMENTO; ++i)
	{
		vet[i]=0;
	}
}

void atribui_valores(unsigned long vet[])
{
	int 			i;

	//Laço onde será resgatado o valor pseudorandômico e este sera atribuido a sua devida posição no vetor contador["valor_pseudorandomico" mod 100].
	for (i = 0; i < REPETICOES; ++i)
	{
		vet[(lcrandom() % 100)]++;
	}
}


unsigned long procura_maior(unsigned long vet[])
{	
	int 			i;
	unsigned long 	m = 0;					//Variável que armazenará maior valor encontrado no vetor.

	//Laço para procurar o maior valor contido no vetor contado.
	for (i = 0; i < COMPRIMENTO; ++i)
	{
		if (vet[i] > m)
		{
			m = vet[i];
		}
	}

	return m;
}

void imprime_resultados(unsigned long vet[], unsigned long m)
{
	unsigned long 	escala;					//Variável utilizada prar auxiliar na mudança de escala para geração do histograma.
	
	int 			i, 						//Variáveis i e j utilizadas no controle dos laçoes de repetição.
					j;

	
	//-------------------- 		INÍCIO DO CABEÇALHO DO HISTOGRAMA. 		--------------------

	printf("  0   10   20   30   40   50   60   70   80   90   100");

	printf("\n  +");
	for (i = 10; i <= 100; i+=10)
	{
		printf("----+");
	}
	printf("\n");
	//-------------------- 		FIM DE CABEÇALHO DO HISTOGRAMA. 		--------------------

	//-------------------- 		INÍCIO DO CONTEÚDO DO HISTOGRAMA. 		--------------------
	
	for (i = 0; i < COMPRIMENTO; ++i)
	{
		printf("%2d|", i);

		escala = (vet[i] * 100) / m;

		//Laço usado para printar * correspontendes a porcentagem da frequência do valor vet[i] em relação a maior frequência encontrada. 
		for (j = 0; j < (escala / 2); ++j)
		{
			printf("*");
		}

		printf("\n");
	}

	//-------------------- 			FIM DO CONTEUDO DO HISTOGRAMA. 		--------------------

	//-------------------- 				INÍCIO DO RODAPÉ. 				--------------------

	printf("  +");
	for (i = 10; i <= 100; i+=10)
	{
		printf("----+");
	}
	printf("\n");
	//-------------------- 					FIM RODAPÉ. 				--------------------
}