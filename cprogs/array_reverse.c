#include <stdio.h>
int reverse(int *array, int size);
int print(int *array, int size);

int main(){
  int numbers[10] = {6,7,8,9,1,2,3,4,0,0};
  printf("\n Before \n");
  print(numbers,10);
  reverse(numbers,10);
  printf("\n After \n");
  print(numbers,10);

  return 0;
}

int print(int *array, int size)
  {
    int i;
    for (i=0;i<size;i++)
      printf(" %d ", array[i]);
    return 0;
  }


int reverse(int *array, int size)
{
  

  return 0;
}
