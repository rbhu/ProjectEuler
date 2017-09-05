#include <stdio.h>

// What is the largest prime factor of the number 600851475143 ?



int isPrime(int num){
  for (int i = 2; i < num; i++) {
    if (!(num%i)) return 0;
  }
  return 1;
}

int getNextPrime(int num) {
  int primeFound = 0;
  while (!primeFound) {
    num++;
    if (isPrime(num)) primeFound = 1;
  }
  return num;
}

int main (int argc, char argv[]) {
  long num = 600851475143;
  int prime = 2;

  while (num != 1) {
    if (!(num%prime)) {
      num /= prime;
    }
    else prime = getNextPrime(prime);
  }
  printf("The largest prime factor is: %d\n", prime);

  return 0;
}
