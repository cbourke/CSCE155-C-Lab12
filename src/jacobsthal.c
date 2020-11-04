#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//TODO: place your prototype and documentation here

/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 *
 */
int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  time_t start, end;
  start = time(NULL);
  //TODO: call your function here
  long long result = 0;
  end = time(NULL);

  int time = (end - start);

  printf("Jacobsthal(%d) = %lld\n", n, result);

  printf("Computation Time: %d seconds\n", time);

  return 0;
}

//TODO: write your recursive Jacobsthal function here
