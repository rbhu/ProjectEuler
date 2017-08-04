#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( int argc, char argv[] ) {
  FILE *fp = fopen("eleven.txt", "r");
  char str[60];
  int array[20][20];
  int i = 0;

  while (1) {
    if (fgets(str, 65, fp) == NULL) break;

    printf("%d: %s\n", i, str);
    array[i][0] = atoi(strtok(str, " "));
    for (int j = 1; j < 20; j++) {
      array[i][j] = atoi(strtok(NULL, " "));
    }
    i = i + 1;
  }
  fclose(fp);

  return 0;
}
