#include <stdio.h>
int isPrime(int num){
  for (int i = 2; i < num; i++) {
    if (!(num%i)) return 0;
  }
  return 1;
}
int main () {
  int num = 2;
  int primeCount = 0;
  while (!(primeCount == 10001)) {
    if (isPrime(num)) primeCount++;
    num++;
  }
  printf("The 10,001st prime is: %d\n", num-1);
}
