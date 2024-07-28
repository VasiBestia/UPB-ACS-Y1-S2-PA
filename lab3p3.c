#include <stdio.h>
#include <stdlib.h>

int* getPointerToMedianValue(int* vector, int size) {
  return (int*)(vector + size / 2);
}

void deleteMedianValue(int* vector, int* ptrToMedianValue, int* size) {
  int index = ptrToMedianValue - vector;  // Get the index of the median value
  for (int i = index; i < *size - 1; i++) {
    vector[i] = vector[i + 1];  // Shift the elements to the left
  }

  *size = *size - 1;  // Decrease the size of the vector

  vector = (int*)realloc(
      vector, (*size) * sizeof(int));  // Reallocate memory for the vector
  if (vector == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
}

int main() {
  int* vector;                         // Declare a pointer to an integer
  vector = (int*)malloc(sizeof(int));  // Allocate memory for the vector
  if (vector == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  int aux;  // Auxiliary variable to read the input
  int size = 0;

  scanf("%d", &aux);
  while (aux) {
    vector[size++] = aux;
    vector = (int*)realloc(
        vector, (size + 1) * sizeof(int));  // Reallocate memory for the vector
    if (vector == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
    scanf("%d", &aux);
  }

  if ((size - 1) % 2) {
    printf("!! The vector should have an odd number of elements !!\n");
    while (aux == 0) {
      scanf("%d", &aux);
    }
    vector[size++] = aux;
    vector = (int*)realloc(
        vector, (size + 1) * sizeof(int));  // Reallocate memory for the vector
    if (vector == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  int* ptrToMedianValue = getPointerToMedianValue(vector, size);
  printf("The median value is: %d at adress %p\n", *ptrToMedianValue,
         ptrToMedianValue);

  deleteMedianValue(vector, ptrToMedianValue,
                    &size);  // Delete the median value from the vector

  printf("The vector after deleting the median value is:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");

  free(vector);  // Free the memory
  return 0;
}