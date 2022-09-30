#include <stdio.h>

int main(){
  int i,j;
  int v;
  int N;
  do{
    printf("\n Enter the size of the matrix (1-10):");
    scanf("%d", &N);
  } while(N<1 || N>10);

  for (i=0; i<N; i++)
    {
      for (j=0; j < N; j++)
	{
	  v = (i==j)? 1: 0;
	  printf(" %d ", v);
	  if (j==2 && i==2)
	    return 0;
	}
      printf("\n");
    }
  return 0;
}
