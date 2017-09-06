#include <stdio.h>
#include <stdlib.h>

long get_product(int array[13]);

int main () {
  //initialise and open files
  FILE *file;
  file = fopen("./pe_8.txt", "r");
  int array[13];
  long highestProduct = 0;
  char c;

  // fill array with first 13 chars
  for (int i = 0; i < 13; i++){
    c = fgetc(file);
    array[i] = c - '0'; // give chars number equivalent values
  }
  highestProduct = get_product(array); // get initial product

  int i = 0;
  while ((c = fgetc(file)) != EOF){
    array[i%13] = c - '0'; // in a linked-list-esque manner, cycle through reading new chars
    i++;
    // printf("%d mod 13: %d\n", i, i%13);
    long prod = get_product(array);
    if (prod > highestProduct) highestProduct = prod; // check for new highest prod
  }
  printf("The highest product is: %ld\n", highestProduct);
}

// multiplies values in array and returns result
long get_product(int array[13]){
  long product = 1;
  for (int i = 0 ; i < 13; i ++) {
    product *= array[i];
  }
  return product;
}
