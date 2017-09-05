// pythagorean triplet such that a^2 + b^2 = c^2 and a+b+c = 1000, what is abc?

#include <stdio.h>
//trivial
int main ()
{
  for (int a = 0; a < 998; a++) {
    for (int b = a + 1; b < 999; b++) {
      for (int c = b + 1; c < 1000; c++) {
        if ((a*a + b*b == c*c) && (a + b + c == 1000)) {
          printf("abc = %d\n", a*b*c);
          a = 998, b = 999, c = 1000;
        }
      }
    }
  }
  return 0;
}
