#include <stdio.h>
#define size 12

void print(int array[size]);

int linsearch(int array[size], int x);
int binarysearch(int array[size], int x);
int bubblesort(int array[size]);
void swap(int * a, int* b);



int main(){
  int array[size] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int unsorted[size] = {21,12,31,24,105,16,97,18,9,110,211,32};
  int x;
  print(array);
  printf("\n Enter a number to search \n");
  scanf("%d", &x);
  printf(" \n Item %d found in array at position %d \n", x, linsearch(array, x));
  printf("\n Enter a number to search in unsorted\n");
  bubblesort(unsorted);
  // unsorted has been sorted // 
  print(unsorted);
  scanf("%d", &x);
  printf(" \n Item %d found in array at position %d \n", x, binarysearch(unsorted, x));


}


void print(int array[size])
    {
      for(int i=0; i<size;i++)
	printf(" %d ", array[i]);
      printf("\n");
      return;
    }

int linsearch(int array[size], int x){
  int i=0;
  while(i<size){
      if(array[i] == x)
	return i;
      i++;
    }
  return -1;
}

int binarysearch(int array[size], int x)
{
  int start = 0;
  int end = size -1;
  int mid = (start + end)/2;
  while (end >= start){
    printf(" [%d %d %d]\n", start, mid, end);
    if (array[mid] == x)
      return mid;
    else if (array[mid] > x)
      end = mid -1;
    else // array[mid] < x
      start = mid + 1;
    mid = (start + end) / 2;
  }
  return -1;
}


int bubblesort(int array[size]){
  for (int i=0;i<size;i++)
    for (int j=0;j<size-1;j++)
      if (array[j+1] < array[j])
	swap(&array[j+1], &array[j]);
  return 0;
}



void swap(int * a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
