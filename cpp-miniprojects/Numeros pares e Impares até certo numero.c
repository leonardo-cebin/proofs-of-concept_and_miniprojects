#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int userInput, oper, i = 1;

  printf("Insira um numero inteiro: ");
  scanf("%d", &userInput);

  while (i < userInput) {

    if (userInput % 2 == 1) {
      // Impares
      printf("%d\t\t\t\t%d\n", i, i + 1);
      i += 2;

    } else if (userInput % 2 == 0) {
      // Pares
      printf("%d\t\t\t\t%d\n", i, i + 1);
      i += 2;
    }
  }

  return 0;
}