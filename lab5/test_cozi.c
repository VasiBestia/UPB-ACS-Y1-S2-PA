#include <stdio.h>
#include <stdlib.h>
#include "cozi.h"

#define ARR_SIZE 10

int main() {
  Queue* q = createQueue();

  int array[ARR_SIZE];
  for (int i = 0; i < ARR_SIZE; i++) {
    array[i] = i + 1;
    enQueue(q, array[i]);
  }

  printf("%d\n", deQueue(q));
  return 0;
}