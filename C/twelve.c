// triangular number divisible by 500 things
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int has500divisors(long tri) {
  int count = 0;
  for (long i = 1; i <= sqrt(tri); i++) {
    if (!(tri%i)) {
      count++;
      if (i != tri/i) {
        count++;
      }
    }
  }
  // printf("\n");
  if (count >= 500) return 1;
  else return 0;
}


int main (int argc, char *argv[]){
  long tri = 0;
  int i = 1;

  while (1) {
    tri += i;
    // printf("Tri: %d    \nDivisors: ", tri);
    if (has500divisors(tri)) break;
    i++;
    // printf("\n");
  }

  printf("The first triangular number with 500 divisors is: %ld\n", tri);


}
