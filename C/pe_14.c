#include <stdio.h>

// protoype for a collatzer
int collatz(int i);

// global array variable as stored on heap
int lengths[1000000];

int main ()
{
  int len; // holds collatz-length of a number
  int highest = 0; // holds highest collatz-length for comparing
  long high_num; // holds integer corresponding to highest collatz-length

  // initialise the lengths array to 0
  for (long i = 0; i < 1000000; i++) { lengths[i] = 0; }

  // loop though all pos integers below 1,000,000
  for (long i = 1; i < 1000000; i++)
  {
    len = collatz(i); // get collatz length of i
    lengths[i] = len; // update lengths array for efficiency in collatz function

    if (len > highest) highest = len, high_num = i; // comparing to find longest collatz
  }

  // Format the result
  printf("\n----------------------------------"
  "\nThe integer under 1 million with the longest collatz sequence is: %d.\n"
  "It has %d terms.\n"
  "----------------------------------\n", high_num, highest);
}

// Function which returns the collatz length
int collatz  (int i)
{
  int count = 1; // count set to 1 to include initial term
  long num = i; // want to modify some variable that isn't i
  while (num != 1) {
    // printf("%d -> ", num);
    if (num <= 1000000) { // if within range of array
      if (lengths[num] != 0){ // and if we have a cached array value for efficiency
        // printf("accessing lengths[] at index: %d\n", num);
        return (count + lengths[num] - 1); // make use of the cache
      }
    }
    // otherwise follow the collatz rules
    if (!(num%2)) num/=2;
    else num*=3, num++;
    count++;
  }
  // printf("1");
  return count;

}
