#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>

/**
 * Computes the n-th Jacobsthal number using an iterative 
 * method
 */
long long jacobsthalIterative(int n);

long long jacobsthalMemoization(int n, long long *table);

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
  
  //set up our "table" which is of size n + 1 since we
  //compute values from J(0) to J(n) inclusive
  long long *table = (long long *) malloc(sizeof(long long) * (n+1));
  //initialize the table values
  //base cases:
  table[0] = 0;
  table[1] = 1;
  //initialize all other values to -1 as a flag value to indicate
  // it has not yet been computed
  for(int i=2; i<=n; i++) {
    table[i] = -1;
  }

  time_t start, end;
  start = time(NULL);
  long long iterativeResult = jacobsthalIterative(n); 
  //TODO: call your function here
  long long memoizationResult = jacobsthalMemoization(n, table);
  end = time(NULL);

  int time = (end - start);

  printf("Iterative:   Jacobsthal(%d) = %lld\n", n, iterativeResult);
  printf("Memoization: Jacobsthal(%d) = %lld\n", n, memoizationResult);

  printf("Total Computation Time: %d seconds\n", time);

  return 0;
}

//TODO: write your memoization-based Jacobsthal function here
long long jacobsthalMemoization(int n, long long *table) {
  if(table[n] != -1) {
    return table[n];
  } else {
    long long a = jacobsthalMemoization(n-1, table);
    long long b = jacobsthalMemoization(n-2, table);
    long long result = a + 2 * b;
    table[n] = result;
    return result;
  }
}

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