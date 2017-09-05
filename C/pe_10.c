#include <stdio.h>
#include <math.h>

int isPrime(long num){
  long val = (long)(sqrt((float) num));
  for (long i = 2; i <= val; i++) {
    if (!(num%i)) {
      return 0;
    }
  }

  return 1;
}
int main () {

  long total = 0;

  for (int i = 2; i < 2000000; i++) {
    if (isPrime(i)) {
      total += i;
    }
  }

  printf("The answer is %ld\n", total);
}
