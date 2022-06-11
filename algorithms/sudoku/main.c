#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>

void display(char grid[9][9]) {
  printf("-------------\n");
  for (int i = 0; i < 9; i++) {
    printf("|");
    for (int j = 0; j < 9; j++) {
      printf("%c", grid[i][j]);
      if ((j+1) % 3 == 0) printf("|");
      if (j == 8) printf("\n");
    }
    if ((i+1) % 3 == 0) printf("-------------\n");
  }
}


bool is_valid(char grid[9][9], int r, int c, int k) {
  bool nr = true;
  for (int _c = 0; _c < 9; _c++) {
    if (k == grid[r][_c]) {
      nr = false;
      break;
    }
  }

  bool nc = true;
  for (int i = 0; i < 9; i++) {
    if (k == grid[i][c]) {
      nc = false;
      break;
    }
  }

  bool nb = true;
  for (int i = r/3*3; i < r/3*3+3; i++) {
    for (int j = c/3*3; j < c/3*3+3; j++) {
      if (k == grid[i][j]) {
        nb = false; 
        break;
      }
    }
  }
  
  return nr && nc && nb;
}


int msleep(long tms)
{
    struct timespec ts;
    int ret;

    if (tms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = tms / 1000;
    ts.tv_nsec = (tms % 1000) * 1000000;

    do {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);

    return ret;
}

bool solve(char grid[9][9], int r, int c) {
  system("clear");
  display(grid);
  msleep(10);
  if (r == 9) return true;
  else if (c == 9) return solve(grid, r+1, 0);
  else if (grid[r][c] != '.') return solve(grid, r, c+1);
  else {
    for (char k = '1'; k <= '9'; k++) {
      if (is_valid(grid, r, c, k)) {
        grid[r][c] = k;
        if (solve(grid, r, c+1)) return true;
        grid[r][c] = '.';
      }
    }
    return false;
  }
}


int main() {
  char grid[9][9] = {
    {'.', '.', '.', '.', '8', '.', '.', '.', '7'},
    {'.', '2', '6', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '1', '.', '.'},
    {'.', '1', '.', '.', '.', '.', '5', '.', '.'},
    {'.', '.', '9', '.', '5', '.', '.', '.', '4'},
    {'6', '.', '.', '2', '.', '.', '.', '.', '.'},
    {'7', '.', '.', '.', '.', '.', '4', '.', '.'},
    {'.', '.', '.', '1', '.', '.', '.', '.', '5'},
    {'.', '.', '3', '.', '.', '.', '.', '.', '2'},
  };

  display(grid); 

  printf("\n%d\n", solve(grid, 0, 0));

  display(grid);

  return 0;
}
