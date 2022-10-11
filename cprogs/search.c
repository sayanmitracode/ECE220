#include <stdio.h>
#define size 12

void print(const int* array, int row, int col);
int linsearch(const int* array, int x);
int binsearch(const int* array, int x);
void swap(int *a, int *b);
void bubbleSort(int * array);
int IsSorted(int * array);


// void transpose(const int array[][scol], int dest[][srow]); 

int main(){
  int source[size] = {1,12,31,42,53,61,79,81,98,102,112,120};
  printf(" \n Found item %d in array at position %d \n", 42,linsearch(source,42));
  printf(" \n Found item %d in array at position %d \n", 120,binsearch(source,120));
  int bad[size] = {1,42,53,12,81,98,102,79,120,112,31,61};
  printf(" \n bad is sorted : %d", IsSorted(bad));
  bubbleSort(bad);
  printf(" \n bad is sorted : %d", IsSorted(bad));
  printf(" \n Found item %d in array at position %d \n", 61,binsearch(source,61));
 
  return 0;
}

int linsearch(const int* array, int x){
  int i=0;
  while(i<size)
    {
      if(*(array +i) == x)
	return i;
      i++;
    }
  return -1;
}

int binsearch(const int* array, int x){
  int start = 0;
  int end = size-1;
  int mid = size/2;
  while(end >=start)
    {
      printf("\n [%d %d %d] \n", start, mid, end); 
      if (array[mid] == x)
	return mid;
      else if (array[mid] > x)
	end = mid-1;
      else // x > array[mid]
	start = mid+1;
      mid = (start+end)/2;
    }
  return -1;
}


void bubbleSort(int * array){
  int i,j;
  for (i=0;i<size;i++)
    for (j=0;j<size-1;j++)
      if (array[j+1] < array[j])
	swap(&array[j], &array[j+1]);
  return;
}

int IsSorted(int * array){
  int i;
  for (i=0;i<size-1;i++)
    if(array[i+1] < array[i])
      return -1;
  return 1;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}
