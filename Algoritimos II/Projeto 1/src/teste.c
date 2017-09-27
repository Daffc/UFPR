#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "biblioteca.h"
#include "selecao.h"
#include "insercao.h"
#include "quicksort.h"
#include "quicksort-insercao.h"
#include "quicksort-mediana.h"

/* -------------------------------------------------------------------------- */
const unsigned int N = 268435;    /* tamanho m�ximo do vetor               */
                                     /* 268435456 = 2^28 � o tamanho do vetor */

/* -------------------------------------------------------------------------- */
/* devolve 1 ou 0 conforme v[a..b] esteja ou n�o ordenado                     */

unsigned int verifica_ordenacao(int v[], unsigned int a, unsigned int b) {

  unsigned int i;

  for (i=a; i<b; ++i)
    if (v[i] > v[i+1])
      return 0;

  return 1;
}
/* -------------------------------------------------------------------------- */
/* preenche v[i] com i, para todo a <= i <= b                                 */

int *preenche(int v[], unsigned int a, unsigned int b) {

  unsigned int i;

  for (i=a; i<=b; ++i)
    v[i] = i;

  return v;
}
/* -------------------------------------------------------------------------- */
/* troca v[a] e v[b] entre si                                                 */

void troca_sem_contar(int v[], unsigned int a, unsigned int b) {

  int aux = v[a];
  
  v[a] = v[b];
  v[b] = aux;
}
/* -------------------------------------------------------------------------- */
/* embaralha v[a..b] usando semente para inicializar                          */
/* o gerador de n�meros pseudo-aleat�rios                                     */

int *embaralha(int v[], unsigned int a, unsigned int b, unsigned int semente) {

    unsigned int i;

    srand(semente);

    for (i=a; i<=b; ++i)
      troca_sem_contar(v,i,sorteia(a,b));

    return v;
}
/* -------------------------------------------------------------------------- */
/* executa selecao() n_execucoes vezes com vetores de tamanho n               */

unsigned int testa_selecao(unsigned int n_execucoes, unsigned int n) {

  unsigned int i;
  int v[N];

  preenche(v,0,n-1);

  zera_contadores();

  for (i=0; i<n_execucoes; ++i)
    if ( !verifica_ordenacao(selecao(embaralha(v,0,n-1,i),0,n-1),0,n-1) )
      return 0;

  return 1;
}
/* -------------------------------------------------------------------------- */
/* executa insercao() n_execucoes vezes com vetores de tamanho n              */

unsigned int testa_insercao(unsigned int n_execucoes, unsigned int n) {

  unsigned int i;
  int v[N];

  preenche(v,0,n-1);

  zera_contadores();

  for (i=0; i<n_execucoes; ++i)
    if ( ! verifica_ordenacao(insercao(embaralha(v,0,n-1,i),0,n-1),0,n-1) )
      return 0;

  return 1;
}
/* -------------------------------------------------------------------------- */
/* executa quicksort() n_execucoes vezes com vetores de tamanho n             */

unsigned int testa_quicksort(unsigned int n_execucoes, unsigned int n) {

  unsigned int i;
  int v[N];

  preenche(v,0,n-1);

  zera_contadores();

  for (i=0; i<n_execucoes; ++i)
    if ( ! verifica_ordenacao(quicksort(embaralha(v,0,n-1,i),0,n-1),0,n-1) )
      return 0;
  
  return 1;
}
/* -------------------------------------------------------------------------- */
/* executa quicksort_insercao() n_execucoes vezes com vetores de tamanho n    */

unsigned int testa_quicksort_insercao(unsigned int n_execucoes, 
                                      unsigned int n,
                                      unsigned int m) {

  unsigned int i;
  int v[N];

  preenche(v,0,n-1);

  zera_contadores();

  for (i=0; i<n_execucoes; ++i)
    if ( ! verifica_ordenacao(quicksort_insercao(embaralha(v,0,n-1,i),0,n-1,m),
                              0,
                              n-1) )
      return 0;
  
  return 1;
}
/* -------------------------------------------------------------------------- */
/* executa quicksort_mediana() n_execucoes vezes com vetores de tamanho n     */

unsigned int testa_quicksort_mediana(unsigned int n_execucoes, 
                                     unsigned int n,
                                     unsigned int k) {

  unsigned int i;
  int v[N];

  preenche(v,0,n-1);

  zera_contadores();

  for (i=0; i<n_execucoes; ++i)
    if ( ! verifica_ordenacao(quicksort_mediana(embaralha(v,0,n-1,i),0,n-1),
                              0,
                              n-1) )
      return 0;
  
  return 1;
}
/* -------------------------------------------------------------------------- */
int main(void) {
  
  unsigned int n_execucoes=32, /* n�mero de execu��es em cada teste */
    n=1024,                    /* n�mero de elementos no vetor      */
    m=n/16,
    k=5;


/* .......................................................................... */
  printf("selecao:");

  if ( ! testa_selecao(n_execucoes, n) )
    printf(" erro!\n");
  else
    printf("\n\tn: %u\n\texecu��es: %u\n\tcompara��es: %.2f\n\ttrocas: %.2f\n", 
           n, 
           n_execucoes,
           ((float)total_comparacoes())/n_execucoes,
           ((float)total_trocas())/n_execucoes);
    
/* .......................................................................... */
  printf("\ninsercao:");

  if ( ! testa_insercao(n_execucoes, n) )
    printf(" erro!\n");
  else
    printf("\n\tn: %u\n\texecu��es: %u\n\tcompara��es: %.2f\n\ttrocas: %.2f\n", 
           n, 
           n_execucoes,
           ((float)total_comparacoes())/n_execucoes,
           ((float)total_trocas())/n_execucoes);
    
/* .......................................................................... */
  printf("\nquicksort:");

  if ( ! testa_quicksort(n_execucoes, n) ) 
    printf(" erro!\n");
  else
    printf("\n\tn: %u\n\texecu��es: %u\n\tcompara��es: %.2f\n\ttrocas: %.2f\n", 
           n, 
           n_execucoes,
           ((float)total_comparacoes())/n_execucoes,
           ((float)total_trocas())/n_execucoes);
  
/* .......................................................................... */
  printf("\nquicksort com inser��o:");

  if ( ! testa_quicksort_insercao(n_execucoes, n, m) ) 
    printf(" erro!\n");
  else
    printf("\n\tn: %u\n\texecu��es: %u\n\tcompara��es: %.2f\n\ttrocas: %.2f\n", 
           n, 
           n_execucoes,
           ((float)total_comparacoes())/n_execucoes,
           ((float)total_trocas())/n_execucoes);
  
/* .......................................................................... */
  printf("\nquicksort com mediana:");

  if ( ! testa_quicksort_mediana(n_execucoes, n, k) ) 
    printf(" erro!\n");
  else
    printf("\n\tn: %u\n\texecu��es: %u\n\tcompara��es: %.2f\n\ttrocas: %.2f\n", 
           n, 
           n_execucoes,
           ((float)total_comparacoes())/n_execucoes,
           ((float)total_trocas())/n_execucoes);
  
/* .......................................................................... */
  return 0;
}
