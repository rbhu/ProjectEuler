/*
Multiples of 3 and 5: Find the sum of all multiples of 3 or 5 below 1000
*/

// This library is required for the printf function
#include <stdio.h>

// Argc = argument count, the number of arguments including the program name
// Argv = argument vector, an array of all arguments
int main ( int argc , char * argv[] )
{
  // integer variable to hold our result
  int total = 0;

  // loop through all numbers up to 1000
  for (int i = 0; i < 1000; i++) {

    // logic
    if (!(i%5) || !(i%3)) total = total + i;
  }

  printf("The sum of all multiples of 3 or 5 below 1000 is: %d\n", total);
}
