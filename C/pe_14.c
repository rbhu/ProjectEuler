#include <stdio.h>


int collatz(int num);
int of_collatz_form(int num);

int main () {
  int highest = 1;
  int num = 0;
  int val = 2;
  for (int i = 3; i < 1000000; i+=3) {
    if (of_collatz_form(i)) continue;
    num = collatz(i);
    if (num > highest) highest = num, val = i;
  }
  printf("The number producing the longest collatz chain is: \n\t\t%d\n"
  "Which has a length of: \n\t\t%d\n", val, highest);
}


int collatz(int num) {
  int count = 1;
  // printf("Collatz chain for %d:  ", num);
  while (num != 1) {
    printf("%d -> ", num);
    if (!(num%2)) num/=2;
    else num *=3, num++;
    count++;
  }
  printf("%d\n", num);
  printf("The length of this chain: %d\n\n", count);
  return count;
}

int of_collatz_form(int num) {
  if (!num%2) return 1;
  if (!(num-1)%3) return 1;
  return 0;
}
