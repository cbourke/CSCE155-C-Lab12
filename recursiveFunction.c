/**
 * Demonstration of a recursive function.
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * A (linear homogeneous) recursive function
 */ 
long recursiveFunction(int n);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  time_t start, end;
  start = time(NULL);
  long result = recursiveFunction(n);
  end = time(NULL);

  int time = (end - start);

  printf("f(%d) = %ld\n", n, result);

  printf("Computation Time: %d seconds\n", time);

  return 0;
}

long recursiveFunction(int n) {
  if (n == 0) {
    return 2;
  } else if (n == 1) {
    return 2;
  } else {
    return recursiveFunction(n - 1) + (recursiveFunction(n - 2) / 2);
  }
}
