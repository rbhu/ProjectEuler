// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <stdio.h> // print functions and file reading

// prototypes
int num_length(int num);
void add_column(int array[101][52], int index);

int main () {
  // file with the 100 50-digit numbers
  FILE *fp = fopen("pe_13.txt", "r");

  // array and string, gives enough room for additional row to hold results
  // and 2 spaces for the natural size increase of the string
  int array[101][52];
  char c[50];

  // loop through the lines of file
  for (int i = 0; i < 100; i++) {
    fgets(c, 55, fp); // get a line

    for (int j  = 2; j < 52; j++) {
      array[i][j] = c[j-2] - '0'; // populate line with real numbers from file
    }
  }

  // initialise row for storing carried amounts to 0
  for (int i = 0; i < 52; i++) {
    array[100][i] = 0;
  }

  // from the last column to the first, add each in a downwards manner
  for (int i = 51; i >= 2; i--) {
    add_column(array, i);
  }

  // print the resulting number
  for (int c = 0; c < 60; c++) {
    printf("%d", array[100][c]);
  }

  fclose(fp); // safety
  return 0;
}

// returns the length of a number (1, 2, or 3 digits)
int num_length(int num)
{
  if ( num < 10 )   return 1;
  if ( num < 100 )  return 2;
  else return 3;
}

// adds a column of digits and distributes accordingly the correct carry column
// e.g. if we get 564 as our result, want to set row 100 column i to 4, add 6 to column i-1,
// and add 5 to column i - 2. If these carry values surpass 10, they are dealt with anyway when
// that column undergoes addition
void add_column(int array[101][52], int index) {
  int sum = 0;
  for (int i = 0; i < 101; i++) {
    sum +=  (array[i][index]);
  }

  // place the carries appropriately
  int length = num_length(sum);
  for (int i = 0; i < length; i++) {
    if (!i) {
      array[100][index - i] = sum % 10;
    }
    else { array[100][index - i] += sum % 10; }
    sum /= 10;
  }
}
