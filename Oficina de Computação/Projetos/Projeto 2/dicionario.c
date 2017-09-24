// DOUGLAS AFFONSO CLEMENTINO
// GRR20175877

#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"

#define TAM_PALAVRA 23

long              linhas = 0;

int               max_comprimento = 0;

unsigned char     *ponto_dicionario;

FILE              *arquivo;


/*--------------------------------  FUNÇÔES ACESSÍVEIS APENAS EM DICIONARIO.C --------------------------------*/

// Função para comparar duas strings indicadas, e retorna 1, caso a string a seja maior que a string b, -1 
// caso a string a seja menor que a string b e 0 caso as strings sejam iguais.

int compara(const void *a, const void *b)
{   
   int i = 0;

   const unsigned char  *bb = (const unsigned char*)(b),
                        *aa = (const unsigned char*)(a);

   // Laço repete enquanto não for o fim da primeira string.
   while( *(aa + i) != '\0')
   {
      // Caso a segunda string chegue ao fim antes da primeira, significa que asegunda string é menos que a primeira,
      // logo retorna-se 1 (a > b).
      if (*(bb + i) == '\0')
      {
         return 1;
      }

      // Caso o caractere analisado na string a tenha valor maior do que o de mesme posição na string b,
      // deve se retornar 1 (a > b).
      if (*(aa + i) > *(bb + i) )
      {
         return 1;
      }
      // Caso o caractere analisado na string a tenha valor menor do que o de mesme posição na string b,
      // deve se retornar -1 (a < b).
      if (*(aa + i) < *(bb + i) )
      {
         return -1;
      }

      i++;
   }

   // Caso o vetor a tenha chegado ao seu fim porem o vetor b ainda não tenha chegado, 
   // deve-se retorna o valor -1. (a < b).
   if (*(bb + i) != '\0')
   {
      return -1;
   }


   // Caso nenhum dos casos anteriores tenham acontecido, as strings a e b são iguais, 
   // portanto deve-se retornar 0.
   return 0;
}


// Função recebe ponteiros para stream, linhas e mar_comprimento e aliza palavras contidas na stream e 
// muda valores de linha, para quantidade de palavras contidas no dicionário e de max_comprimento para 
// o tamanho da maior palavra contida no dicionario.
void dimencao_dicionario(FILE *corrente, long *lin, int *col)
{
   int            c,
                  maior = 0,
                  cont_c = 0;

   long           cont_l = 0;


   // Comando para reiniciar ponteiro de stream caso este não esteja na posição inicial.
   rewind(corrente);

   c = getc(corrente); 
   
   // Laço de repetição que percorrera todo arquivo e contara a quantidade de quebras de 
   // linha encontradas.
   while(c != EOF)
   {
      if (c == '\n')
      {
         cont_l ++;         
         if (cont_c > maior)
         {
            maior = cont_c;
         }
         cont_c = 0;
      }
      else
      {
         cont_c ++;
      }

      c = getc(corrente);
   }

   // Retorna a quantidade de quabras de linha encontradas, que é igual a quantidade de palavras 
   // armazenadas no dicionário.
   *lin = cont_l;
   *col = maior;
}

// Função que verifica se ocaractere é maiusculo ou minúsculo, caso seja maiúsculo ele converte 
// para o seu correnpondente minúsculo.
unsigned char verifica_converte(int letra)
{
   // Converte todos os caracteres minúsculos (ascentuados ou não)  em caracteres maiúsculos.
   if (((letra >=65) && (letra <=90)) || ((letra >= 192) && (letra <= 220)))
   {
      letra = letra + 32;
   }

   return letra;
}

void aloca_strings(unsigned char *ponto, FILE *corrente)
{
   int            c,
                  cont;

   // Comando para reiniciar ponteiro de stream caso este não esteja na posição inicial.
   rewind(corrente);

   c = getc(corrente); 
   
   // Laço de repetição que percorrera todo arquivo e conara a quantidade de quebras de 
   // linha encontradas.
   while(c != EOF)
   {
      cont = 0;
      
      // Enquanto caractere analizado diferente de quebra de linha concatena na string indicada.
      while(c != '\n')
      {
         
         c = verifica_converte(c);

         *(ponto + cont) = c;
         cont ++;
         c = getc(corrente);

      }

      // Colocar caractere \0 no fim da string construida.
      *(ponto + (cont + 1)) = '\0';


      ponto = ponto + (max_comprimento);

      c = getc(corrente);
   }
}

/* -------------------------------- FUNÇÔES QUE PODEM SER CHAMADAS EXTERNAMENTE --------------------------------*/
void libera_dicionario()
{
   free(ponto_dicionario);
   ponto_dicionario= NULL;
   linhas = 0;
}

void carrega_dicionario(char caminho[])
{
   arquivo = fopen(caminho, "r");

   if (!arquivo)
   {
      perror("Erro ao abrir arquivo.");
      exit(1);
   }

   // Dunção que ira pegar comprimento da maior palavra do dicionário e o numero de palavras contidas
   // no dicionário e salvalas nas variáveis max_comprimento e linhas respectivamente.
   dimencao_dicionario(arquivo, &linhas, &max_comprimento);

   // Reserva-se espaço na memória de acordo com as dimenções estabelecidas anteriormente.
   ponto_dicionario = malloc(linhas * max_comprimento);

   // Função para carregar palavras do dicionário em malloc indicado acima.
   aloca_strings(ponto_dicionario, arquivo);

   // Fecha-se a Stream com o arquivo dicionário.
   fclose(arquivo);
   arquivo = NULL;

   // Ordena vetor de strings dicionário.  
   qsort(ponto_dicionario, linhas, max_comprimento, compara);
}

char procura_palavra(unsigned char  palavra[], int comprimento)
{
   unsigned char  verificador[max_comprimento],
                  *resposta;;

   int            i;


   // Transfere caractere por caractere a string recebida por parâmetro para o vetor auxiliar enquando converte, 
   // se necessário, caracteres para minúsculos.
   for (i = 0; i < comprimento; ++i)
   {
      verificador[i] = verifica_converte(palavra[i]);
   }

   //coloca-se caractere \0 no final da string indicada.
   verificador[i] = '\0';

   // Execulta busca binário por palavra contida no vetor verificador em vetor de strings dicionário. 
   // Caso seja achada a palavra, resposta armazenará o endereço para ela no vetor de Palavras, caso 
   // contrário resposta será um vetor nulo. 
   resposta = (unsigned char*) bsearch (verificador, ponto_dicionario, linhas, max_comprimento, compara);
   if( resposta != NULL ) 
   {
      return (1);
   }

   return(0);
}