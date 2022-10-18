#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int a, int b) {
  if (n == 1) {
    printf("Move disc of size 1 from %d to %d\n", a, b);
    return;
  }

  hanoi(n-1, a, 3-a-b);
  printf("Move disc of size %d from %d to %d\n", n, a, b);
  hanoi(n-1, 3-a-b, b);
}

int main()
{
  hanoi(6,1,2);
  return 0;
}