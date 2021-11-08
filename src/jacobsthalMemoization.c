#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Computes the n-th Jacobsthal number using an iterative
 * method
 */
long long jacobsthalIterative(int n);

//TODO: place your prototype and documentation here
//      Hint: it should return a long long (integers)
//            it should take a cache (array) of long longs as well

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

  //TODO: set up our table/cache which is of size n + 1 since we
  //compute values from J(0) to J(n) inclusive

  //TODO: initialize the table values
  //      1. take care of the base cases
  //      2. set all other values to a flag value (-1) to indicate
  //         the value has not yet been computed and cached

  time_t start, end;
  start = time(NULL);
  long long iterativeResult = jacobsthalIterative(n);
  //TODO: call your function here

  end = time(NULL);

  int time = (end - start);

  printf("Iterative:   Jacobsthal(%d) = %lld\n", n, iterativeResult);
  printf("Memoization: Jacobsthal(%d) = %lld\n", n, memoizationResult);

  printf("Total Computation Time: %d seconds\n", time);

  return 0;
}

//TODO: write your memoization-based Jacobsthal function here

long long jacobsthalIterative(int n) {
  if(n <= 1) {
    return n;
  }
  long long prev = 0;
  long long curr = 1;
  for(int i=2; i<=n; i++) {
    long long t = 2 * prev + curr;
    prev = curr;
    curr = t;
  }
  return curr;
}
