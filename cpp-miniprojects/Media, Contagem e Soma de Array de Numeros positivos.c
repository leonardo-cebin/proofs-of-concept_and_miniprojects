#include <stdio.h>

int main(void) {
  int ahay[900], i = 0, j, k, sum = 0, median, average, count, on = 1;
  while (on == 1) {
    scanf("%d", &ahay[i]);

    if (ahay[i] <= 0) {
      on = 0;
      ahay[i] = 0;
    } else {
      i++;
      sum += ahay[i - 1];
    }
  }

  count = i;
  average = sum / count;

  printf("\n\nSum: %d\t", sum);
  printf("Count: %d\t", count);
  printf("Average: %d\t", average);

  return 0;
}