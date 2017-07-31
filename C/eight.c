#include <stdio.h>

int main () {
  setbuf(stdout, NULL);
  FILE *file;
  file = fopen("./eight.txt", "r");
  char c;
  while (fgetc(file) != EOF) {
    c = fgetc(file);
    printf("%c ", c);
  }





}
