#include <stdio.h>
#include <stdlib.h>
int num_length(int num)
{
   if ( num < 10 )   return 1;
   if ( num < 100 )  return 2;
   else return 3;

}

void add_column(int array[101][52], int index) {
  int sum = 0;
  for (int i = 0; i < 101; i++) {
    sum +=  (array[i][index]);
    // printf("%d ", sum);
  }
  // printf("\n\n");
  int length = num_length(sum);
  for (int i = 0; i < length; i++) {
    if (!i) {
      array[100][index - i] = sum % 10;
    }
    else { array[100][index - i] += sum % 10; }
    sum /= 10;
  }
}

int main () {

  FILE *fp = fopen("pe_13.txt", "r");
  int array[101][52];
  char c[50];

  for (int i = 0; i < 100; i++) {
    fgets(c, 55, fp);
    // printf("%s\n", c);
    for (int j  = 2; j < 52; j++) {
      array[i][j] = c[j-2] - '0';

    }

  }

  for (int i = 0; i < 52; i++) {
    array[100][i] = 0;
  }


  for (int i = 51; i >= 2; i--) {
    add_column(array, i);
  }

  for (int c = 0; c < 60; c++) {
    printf("%d", array[100][c]);
  }




  return 0;


}
