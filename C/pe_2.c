/*
Even Fibonacci numbers
*/

#include <stdio.h>

int main () {
  long sum = 2; // based on first 2 terms being given
  long prev_terms[2];
  prev_terms[0] = 1;
  prev_terms[1] = 2; // array holding current and previous term
  while (prev_terms[1] < 4000000) { // while fibs don't exceed 4mill
    prev_terms[1] = prev_terms[0] + prev_terms[1];
    prev_terms[0] = prev_terms[1] - prev_terms[0];
    // calculation here doesn't require a spare hold variable
    if (!(prev_terms[1]%2)) sum += prev_terms[1];
    // if term is even add to sum
  }
  printf("The sum of even fib numbers under 4 million is: %ld\n", sum); // output answer
}
