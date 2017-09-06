#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long getHighestProduct(long array[20][20]) {
  long highest = 0;
  long prod = 0;
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

  printf("%ld", highest);
  return highest;


}


int main ( int argc, char argv[] ) {
  FILE *fp = fopen("pe_11.txt", "r");
  char str[60];
  long array[20][20];
  int i = 0;

  while (1) {
    if (fgets(str, 65, fp) == NULL) break;


    array[i][0] = atol(strtok(str, " "));
    printf("row %d: %d ", i, array[i][0]);
    for (int j = 1; j < 20; j++) {
      array[i][j] = atoi(strtok(NULL, " "));
      printf("%d ", array[i][j]);
    }
    printf("\n");
    i = i + 1;
  }

  long highest = getHighestProduct(array);
  printf("The highest product of 4 adjacent numbers is: %ld\n", highest);
  fclose(fp);

  return 0;
}
