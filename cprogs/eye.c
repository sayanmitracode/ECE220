#include <stdio.h>
#define N 5

int main(){
  int i, j, v;
  for (i=0;i<N;i++)
    {
    for (j=0;j<N;j++)
      {
	v = (i==j)? 1:0;
	printf(" %d ", v);
      }
    printf("\n");
    }
  return 0;
}
