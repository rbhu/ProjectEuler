// The largest palindrome product of 2 digit numbers is 91 * 99 = 9009
// Any non-prime number between 10000 (100 * 100) and 998001 (999 * 999)
// must be the product of 2 3-digit numbers. Therefore, counting down from 998001
// the first non-prime palindrome is the correct

#include <stdio.h>

// constant boundaries for our search
const long top = 998001;
const long bottom = 10000;
// prototypes (aka signatures)
int is_3_digits(int num);
int divides_by_two_3_digits(int num);
int is_palindrome(int num);

int main () {
  // count from upper boundary to lower
  for (int i = 998001; i > 10000; i--) {
    // if palindrome and can be written as product of two 3-digit numbers
    if (is_palindrome(i) && divides_by_two_3_digits(i)) {
      printf("The highest palindrome is: %d\n", i);
      // exit the for loop
      i = 0;
      break;
    }
  }
  return 0;
}

// checks whether a number is a 3-digit number
int is_3_digits(int num) {
  if ((100 <= num) && (num <= 999)) return 1;
  return 0;
}

// checks whether a number can be written as prod of 2 3-digit nums
int divides_by_two_3_digits(int num){
  for (int i = 100; i < 1000; i++) { // for all 3 digit numbs
    if (!(num%i) && is_3_digits(num/i)) { // if divisible by a num and the quotient has 3 digits
      printf("%d\n", i);
      return 1;
    }
  }
  return 0;
}

// checks if number is palindrome
int is_palindrome(int num) {
  char str[10];
  // convert to a string
  sprintf(str, "%d", num);
  int sizeStr = 0;
  // find number of non-null chars in string
  for (int i = 0; i < sizeof(str); i++) {
    if (str[i] == '\0') {
      sizeStr = i;
      break;
    }
  }
  // compare end letters inwardly with start letters
  for (int i = 0; i < sizeStr; i++) {
    if (str[i] != str[sizeStr - 1 - i]) {
      return 0;
    }
  }
  return 1;
}
