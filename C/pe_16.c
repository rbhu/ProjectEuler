#include <stdio.h>
#include <stdlib.h>

void double_string(char str[305]);

int main ( int argc , char * argv[] )
{
  // Part 1: double a number given it as a string
  char str[305];
  str[304] = '1';
  for (int i = 0; i < 304; i++) {
    str[i] = '\0';
  }
  printf("%s\n", str);


  double_string(str);
}

int get_length( int num ) {
  if (num < 10) return 1;
  else return 2;
}

void double_string(char str[305]) {
  char hold[2];
  int sto[305];
  int i = 304;
  int num;
  for (int i = 0; i < 305; i++) { sto[i] = 0; }

  while (str[i]!= '\0') {
    printf("%d ", i);
    printf("%c ", str[i]);
    num = str[i] - '0';
    num = (num * 2) + sto[i];
    int len = get_length(num);
    sprintf(hold, "%d", num);




    printf("%s\n", hold);
    i--;
  }
}
