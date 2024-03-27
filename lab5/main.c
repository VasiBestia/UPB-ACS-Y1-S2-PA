#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cozi.h"

int main() {
  srand(time(NULL));
  int n1, n2;
  n1 = rand() % 21 + 70;
  n2 = rand() % 21 + 70;

  Queue* lane1 = createQueue();
  Queue* lane2 = createQueue();

  printf("-- Before running --\nn1: %d\nn2: %d\n", n1, n2);
  printf("--------------------\n");

  for (int i = 0; i < n1; i++)
    enQueue(lane1, i + 1);

  for (int i = 0; i < n2; i++)
    enQueue(lane2, i + 1);

  // The car is added to the lane with the smallest number of cars
  if (n1 < n2)
    enQueue(lane1, 0);
  else
    enQueue(lane2, 0);

  bool foundCar = false;
  int debugStep = 0;

  while (!foundCar) {
    int prevN1 = n1;
    int prevN2 = n2;
    int exitCarsLane1 = rand() % 7 + 1;
    int exitCarsLane2 = rand() % 7 + 1;

    for (int i = 0; i < exitCarsLane1 && !foundCar; i++) {
      if (isEmpty(lane1) || n1 == 1)
        foundCar = true;
      deQueue(lane1);
      n1--;
    }

    for (int i = 0; i < exitCarsLane2 && !foundCar; i++) {
      if (isEmpty(lane2) || n2 == 1)
        foundCar = true;
      deQueue(lane2);
      n2--;
    }

    if (prevN1 < prevN2)
      deQueueRear(lane1);
    else
      deQueueRear(lane2);

    if (n1 < n2)
      enQueue(lane1, 0);
    else
      enQueue(lane2, 0);

    printf("[Debug step %d] Generated %d %d - Remaining %d %d\n", ++debugStep,
           exitCarsLane1, exitCarsLane2, n1, n2);
  }
  printf("-------------------\n");
  printf("-- After running --\nn1: %d\nn2: %d\n", n1, n2);

  return 0;
}