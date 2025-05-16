/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "racional.h"


/* Verifica se o número dado pelo usuário está dentro do intervalo
 * aborta o programa se não estiver */
int verifica_intervalo(long int x, int a, int b)
{
  if (x <= a || x >= b)
  {
    printf("%ld é inválido, ele deveria satisfazer  %d < x < %d.\n", x, a, b) ;
    return 1 ;
  }

  return 0 ;
}


/* programa principal */
int main ()
{
  int n ;
  long max, min ;
  struct racional r1, r2 ;

  srand (0) ; /* use assim, com zero */
 
  scanf("%d %ld", &n, &max) ;

  if (verifica_intervalo(n, 0, 100))
    return 1 ; 

  if (verifica_intervalo(max, 0, 30)) 
    return 1;

  min = -max ;

  for(int i = 1; i <= n; ++i)
  {
    printf("%d: ", i) ; 

    r1 = sorteia_r(min, max) ; 
    r2 = sorteia_r(min, max) ; 

    imprime_r(r1) ;
    imprime_r(r2) ;

    if (!valido_r(r1) || !valido_r(r2)) //Se r1 ou r2 forem inválidos as operações
					//seguintes serão inválidas
    {
      printf("NUMERO INVALIDO\n") ;
      return 1 ;
    }

    if (!valido_r(divide_r(r1, r2))) //Mesmo que r1 e r2 não sejam inválidos
				   //a divisão deles pode ser
    {
      printf("DIVISAO INVALIDA\n") ;
      return 1 ;
    }

    imprime_r(soma_r(r1, r2)) ;
    imprime_r(subtrai_r(r1, r2)) ;
    imprime_r(multiplica_r(r1, r2)) ;
    imprime_r(divide_r(r1, r2)) ;
    printf("\n") ;

  }

  return (0) ;
}
