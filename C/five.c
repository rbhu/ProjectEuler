// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>


int evenlyDiv(int num) {
  for (int i = 1; i <= 20; i++) {
    if (num%i) return 0;
  }
  return 1;
}

int main (int argc, char argv[]) {
  int num = 20;
  int found = 0;
  while (!found) {
    if (evenlyDiv(num)) {
      printf("The answer is: %d\n", num);
      found = 1;
    }
    else num++;
  }
  return 0;
}
