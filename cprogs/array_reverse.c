#include <stdio.h>
int reverse(int *array, int size);
int reverseptr(int *array, int size);
int print(int *array, int size);

int main(){
  int numbers[10] = {9,8,7,6,5,4,3,2,1,0};
  printf("\n Before \n");
  print(numbers,10);
  reverse(numbers,10);
  printf("\n After \n");
  print(numbers,10);

  printf("\n After Again\n");
  reverseptr(numbers,10);
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
  int i ;
  int temp;
  for (i=0; i< size/2; i++)
    {
      temp = array[i];
      array[i] = array[size - 1 -i];
      array[size - 1 -i] = temp;
    }
  return 0;
      
}

int reverseptr(int *array, int size)
{
  int i,temp;
  for (i=0; i< size/2; i++)
    {
      temp = *(array + i);
      *(array + i) = *(array + size - 1 -i);
      *(array + size - 1 -i) = temp;
    }
  return 0;
}




/*
int reverse(int *array, int size)
{
  int i;
  int temp;
  for (i=0;i<size/2;i++)
    {
      temp = *(array +i);
      *(array + i) = *(array + size-1-i);
      *(array + size-1-i) = temp;
    }

  return 0;
}

*/
