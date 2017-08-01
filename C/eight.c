#include <stdio.h>
#include <stdlib.h>

long getProduct(int array[13]){
  long product = 1;
  for (int i = 0 ; i < 13; i ++) {
    product *= array[i];
  }
  return product;
}

int main () {
  setbuf(stdout, NULL);
  FILE *file;
  int array[13];
  long highestProduct = 0;
  file = fopen("./eight.txt", "r");
  char c;


  for (int i = 0; i < 13; i++){
    c = fgetc(file);
    array[i] = c - '0';
  }
  highestProduct = getProduct(array);

  int i = 0;
  while ((c = fgetc(file)) != EOF){
    array[i%13] = c - '0';
    i++;
    // printf("%d mod 13: %d\n", i, i%13);
    long prod = getProduct(array);
    if (prod > highestProduct) highestProduct = prod;
  }

  printf("The highest product is: %ld\n", highestProduct);


}
