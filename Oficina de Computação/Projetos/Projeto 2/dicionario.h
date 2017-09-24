// DOUGLAS AFFONSO CLEMENTINO
// GRR20175877

#ifndef _DICIONARIO_

#define _DICIONARIO_

// Função que retorna ponteiro de início de onde o vetor de Palavras que contem o dicionário será alocado.
// Esta função recebe como parâmetros uma string caminho, que indica o caminho do arquivo que contem as 
// palavras do dicionário. 

void carrega_dicionario(char caminho[]);

// Função recebe string a ser verificada e seu comprimento e verifica se a string pertence ao dicioário 
// anteriormente inicializado ou não. Caso palavra pertenca, função devolve valor 1, caso não pertença 
// devolve valor 0;

char procura_palavra(unsigned char palavra[], int comprimento);

// Função que libera espaço armazenado pelo dicionário da memória e torna nulo o ponteiro para o extinto malloc.

void libera_dicionario();

#endif
