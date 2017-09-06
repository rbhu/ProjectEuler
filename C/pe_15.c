/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there in a 20x20 grid?
*/


/*
The best way to solve this is to use a recursive approach
*/

#define TOP 21
#include <stdio.h>


int main () {

  // grid to count number of paths to each cell
  long grid[TOP][TOP];

  // initialise grids to 0, or 1 on the top and left edges (boundary conditions)
  for (int i = 0; i < TOP; i++) {
    for (int j = 0; j < TOP; j++) {
      if ((i == 0) || (j == 0)) grid[i][j] = 1;
      else grid[i][j] = 0;
    }
  }

  // for rest of grid positions calculate number of routes to each point
  for (int i = 1; i < TOP; i++) {
    for (int j = 1; j < TOP; j++) {
      grid[i][j] = grid[i-1][j] + grid[i][j-1];
    }
  }
  printf("The number of routes from (0,0) to (%d, %d) is: %ld\n", TOP-1, TOP-1, grid[TOP-1][TOP-1]);
}
