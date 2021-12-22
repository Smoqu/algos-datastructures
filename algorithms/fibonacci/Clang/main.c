#include <stdio.h>

void fibonacci(int n)
{
  int i = 1;

  int bef_previous = 1;
  int previous = 1;

  while (i < n) {
    printf("%d\n", previous);
    int prev_copy = previous;

    previous += bef_previous;
    bef_previous = prev_copy;

    i++;
  }

}


int main() 
{

  fibonacci(10);

  return 0;
}




