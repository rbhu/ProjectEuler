// What is the largest prime factor of the number 600851475143?

#include <stdio.h>

// Signatures for functions used in main
int is_prime(int num);
int get_next_prime(int num);


int main (int argc, char argv[]) {
  long num = 600851475143; // num to find largest prime factor of
  int prime = 2; // first prime

  while (num != 1) { // all numbers eventually factorise to 1
    if (!(num%prime)) { // if num divides by current prime, divide it
      num /= prime;
    }
    else prime = get_next_prime(prime); // if not, get next prime in sequence and try again
  }
  // returns the result
  printf("The largest prime factor is: %d\n", prime);

  return 0;
}

// Function to get the next prime number in the sequence
int get_next_prime(int num) {
  int primeFound = 0;
  while (!primeFound) {
    num++;
    if (is_prime(num)) primeFound = 1;
  }
  return num;
}

// Checks for primality of a number
int is_prime(int num){
  for (int i = 2; i < num; i++) { // could check up to half or sqrt
    if (!(num%i)) return 0;
  }
  return 1;
}
