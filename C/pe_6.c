#include <stdio.h>
// trivial
int main () {
  int sum = 0;
  int squareOfSum = 0;
  int sumOfSquares = 0;
  for ( int i = 1; i < 101; i++ ) {
    sum+=i;
    sumOfSquares+=i*i;
  }
  squareOfSum = sum*sum;
  printf("The answer is: %d\n", squareOfSum - sumOfSquares);
  return 0;
}
