/*
higest product in grid of numbers, 20x20 including diagonals
*/

#include <stdio.h>
#include <string.h> // need for strok
#include <stdlib.h> // need for atoi

long getHighestProduct(long array[20][20]); //signature

int main ( int argc, char argv[] ) {

  FILE *fp = fopen("pe_11.txt", "r"); // open file for reading in digits
  char str[60]; // string with ample size
  long array[20][20]; // array to store grif
  int i = 0; // counter for lines of the file

  while (1) {

    if (fgets(str, 65, fp) == NULL) break; // if end of file, break out of loop
    array[i][0] = atol(strtok(str, " ")); // tokenise each line with ' ' delimter
    printf("row %d: %d ", i, array[i][0]); // debug print

    // loop through rest of digits on the line
    for (int j = 1; j < 20; j++) {
      array[i][j] = atoi(strtok(NULL, " ")); // have to change param of strok to NULL here not sure why
      printf("%d ", array[i][j]); // debug print
    }

    printf("\n");
    i = i + 1;
  }
  // once array is populated, can easily find highest product of 4 nums
  long highest = getHighestProduct(array);
  printf("\nThe highest product of 4 adjacent numbers is: %ld\n", highest);

  // close file for safety
  fclose(fp);

  return 0;
}

// function to get highest prod
long getHighestProduct(long array[20][20]) {

  long prod = 0; // stores each possible product
  long highest = 0; // stores the HIGHEST product so far

  // collection of loops to deal with up-down, left-right, and the two diagonals
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 20; j++) {
      prod = (array[i][j] * array[i+1][j] * array[i+2][j] * array[i+3][j]);
      if (prod > highest) {
        highest = prod;
      }
    }
  }

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 17; j++) {
      prod = (array[i][j] * array[i][j+1] * array[i][j+2] * array[i][j+3]);
      if (prod > highest) {
        highest = prod;
      }
    }
  }


  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < 17; j++) {
      prod = (array[i][j] * array[i+1][j+1] * array[i+2][j+2] * array[i+3][j+3]);
      if (prod > highest) {
        highest = prod;
      }
    }
  }


  for (int i = 3; i < 20; i++) {
    for (int j = 0; j < 17; j++) {
      prod = (array[i][j] * array[i-1][j+1] * array[i-2][j+2] * array[i-3][j+3]);
      if (prod > highest) {
        highest = prod;
      }
    }
  }

  return highest;


}
