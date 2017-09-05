#include <stdio.h>

// The largest palindrome product of 3 digit numbers is 91 * 99 = 9009
// Any non-prime number between 10000 (100 * 100) and 998001 (999 * 999)
// must be the product of 2 3-digit numbers. Therefore, counting down from 998001
// the first non-prime palindrome is the correct

const long top = 998001;
const long bottom = 10000;

int is3digits(int num) {
  if ((100 <= num) && (num <= 999)) return 1;
  return 0;
}

int dividesBytwo3Digits(int num){
  for (int i = 100; i < 1000; i++) {
    if (!(num%i) && is3digits(num/i)) {
      printf("%d\n", i);
      return 1;
    }
  }
  return 0;
}

int isPalindrome(int num) {
  // printf("The number is: %d\n", num);
  char str[10];
  sprintf(str, "%d", num);
  // printf("The string stores: %s\n", str);
  int sizeStr = 0;
  for (int i = 0; i < sizeof(str); i++) {
    if (str[i] == '\0') {
      sizeStr = i;
      break;
    }
  }
  // printf("The actual size of string is: %d\n", sizeStr);

  for (int i = 0; i < sizeStr; i++) {
    if (str[i] != str[sizeStr - 1 - i]) {
      return 0;
    }
  }
  return 1;


}
int main () {
  for (int i = 998001; i > 10000; i--) {
    if (isPalindrome(i) && dividesBytwo3Digits(i)) {
      printf("The highest palindrome is: %d\n", i);
      i = 0;
      break;
    }
  }

  return 0;
}
