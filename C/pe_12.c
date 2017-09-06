// triangular number divisible by 500 things (nth trianglular number is sum from 1 to n)

#include <stdio.h> // print function
#include <math.h> // need for square root

int has_500_divisors(long tri); // signature / prototype

int main ( int argc , char *argv[] )
{
  long tri = 0;
  int i = 1;

  while (1) {
    tri += i; // next triangle number
    if (has_500_divisors(tri)) break;
    i++;
  }
  // Print solution
  printf("The first triangular number with 500 divisors is: %ld\n", tri);

}

// function to check if a given triangular has 500 divisors
int has_500_divisors(long tri) {
  int count = 0;
  // only need to ccount up to sqrt of tri
  for (long i = 1; i <= sqrt(tri); i++) {

    if (!(tri%i)) { // if divisible by i
      count++;
      if (i != tri/i) { // if not a square then we have 2 divisors, the second being larger than the sqrt
        count++;
      }
    }
  }

  // trivial
  if (count >= 500) return 1;
  else return 0;
}
