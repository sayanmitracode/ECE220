#include <stdio.h>
#define size 12

void print(int array[size]);

int linsearch(int array[size], int x);
int binarysearch(int array[size], int x);
int bubbleSort(int array[size]);
int insertionSort(int array[size]);

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
  print(unsorted);
  insertionSort(unsorted);
  // bubbleSort(unsorted);
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


int bubbleSort(int array[size]){
  for (int i=0;i<size;i++)
    for (int j=0;j<size-1;j++)
      if (array[j+1] < array[j])
	swap(&array[j+1], &array[j]);
  return 0;
}


int insertionSort(int array[size]){
  int i, j, temp, empty,k;
  for(i=1;i<size;i++)
  {
    temp = array[i];
    printf("\n after inserting %d :", temp);
    empty = i;
    for(j=i-1;j>=0;j--)
    {
      if(temp < array[j])
      {
        //shift element to the right
        array[j+1] = array[j];
        //update empty position
        empty = j;
      }
    }
    //insert at the proper location
    array[empty] = temp;
    print(array); 
  }

  printf("sorted array: \n");
  print(array); 
  return 0;
}


void swap(int * a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
