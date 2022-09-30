#include <stdio.h>
int swap(int* a, int* b);

int main()
{
  int A = 5;
  int B = 10;
  printf(" \n before A = %d, B = %d", A, B);
  swap(&A,&B);
  printf(" \n after swap A = %d, B = %d \n", A, B);
  return 0;

}


int swap(int* a, int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  printf(" \n  inside swap function A = %d, B = %d \n", *a, *b);

  return 0;
}
