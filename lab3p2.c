#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));   // Seed the random number generator
  float matrix[5][5];  // Declare a 5x5 matrix

  // Fill the matrix with random numbers
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix[i][j] = rand();  // Random number between 0 and INT_MAX
    }
  }

  // Print the matrix
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  // Get min and max values for each column
  float min, max;
  for (int i = 0; i < 5; i++) {
    min = matrix[0][i];
    max = matrix[0][i];
    for (int j = 0; j < 5; j++) {
      if (matrix[j][i] < min) {
        min = matrix[j][i];
      }
      if (matrix[j][i] > max) {
        max = matrix[j][i];
      }
    }

    for (int j = 0; j < 5; j++) {
      matrix[j][i] = (matrix[j][i] - min) / (max - min);
    }
  }

  // Print the matrix
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}