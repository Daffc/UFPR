// DOUGLAS AFFONSO CLEMENTINO
// GRR20175877

#include <stdio.h>
#include "dicionario.h"


int main()
{
   int            caractere,        // Variável utilizada para armazenar caractere lido.
                  comprimento;      // Variável utilizada para armazenar compriemnto da string a ser passada por parâmetro.


   unsigned char  armazenador[100]; // Variável para armazenar string a ser pesquisada.



   carrega_dicionario("/usr/share/dict/brazilian");

   caractere = getchar();


   // Laço de repetição lê entrada, caractere por caractere, até que seja identificado o fim de arquivo.

   while (caractere != EOF)
   {
      comprimento = 0;

      // Verifica se o caractere analisado é uma letra (exceçõe nos valores correspondentes aos simbolos 
      // de multiplicação (215) e de divisão (247) contidos entre as letras ascentuadas na codificação utilizada).
      // Enquanto forem letras, os caracteres são armazenados na string armazenador.
      
      while ((((caractere >=65) && (caractere <=90)) || ((caractere >=97) && (caractere <=122)) || ((caractere >= 192) && (caractere <= 223)) || ((caractere >=224) && (caractere <=255))) && !((caractere == 215) || (caractere == 247)))
      {
         armazenador[comprimento] = caractere;
         comprimento ++;
         
         caractere = getchar();
      }
      
      // Case seja encontrada uma string.
      if (comprimento != 0)
      {
         // Indicador de fim de string é colocado em posição apos ultimo caractere da string.
         armazenador[comprimento] = '\0';

         // Caso palavrea procurada seja encontrada string armazenados é impressa, caso não seja encontrada
         // string armazenador é impressa entre colchetes.
         if (procura_palavra(armazenador, comprimento))
         {
            printf("%s", armazenador);
         }
         else 
         {
            printf("[%s]", armazenador);
         }

      }

      printf("%c", caractere);

      caractere = getchar();
   }

   libera_dicionario();

   return 0;
}