#include <stdbool.h>
#include <stdio.h>

/*
For com I contando até 100
Este será o valor dos primos, e atualizará apenas após um primo ser encontrado

For com J contando até achar um primo
O J representará um numero que vai começar a ser contado com o valor do primo
anterior, e vai subir, até um novo primo ser encontrado

O K representará um numero que vai começar a ser contado do 2, e irá ser
percorrido até o valor do J-1. Se o K chegar ao valor do J-1 sem encontrar
nenhum multiplo, o J será considerado primo, e o I++. Se o K chegar ao valor do
J-1 encontrnado multiplos, o J será considerado composto, e não será atribuido
como primo, e o J++
*/

int main(void) {
  int prime[9999], num, i, divisor, tic=2;
  bool active;

  prime[0] = 2;
  num = 3;

  printf("%d\t\t", prime[0]);
  
  for (i = 1; i < 442; i++) {  
    active = true;

    while (active == true) {
      for (divisor = 2; divisor < num ; divisor++) {
        if (num % divisor == 0) {
          active = false;
        }
        if (active == true && divisor == num - 1) {
          prime[i] = num;
          if(tic<5){
            printf("%d\t\t", prime[i]);
            tic++;
          }else{
            printf("%d\n", prime[i]);
            tic = 1;

          }
          
        }
      }

      num++;
    }

    
  }
  return 0;
}