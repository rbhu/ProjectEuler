// summation of all primes below 2,000,000
#include <stdio.h>
#include <math.h>

//primality tester
int isPrime(long num){
  long val = (long)(sqrt((float) num));
  for (long i = 2; i <= val; i++) {
    if (!(num%i)) {
      return 0;
    }
  }
  return 1;
}

// loop to two million
int main () {
  long total = 2;
  for (int i = 3; i < 2000000; i+=2) {
    if (isPrime(i)) {
      total += i;
    }
  }
  printf("The answer is %ld\n", total);
}
