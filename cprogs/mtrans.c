#include <stdio.h>
#define srow 4
#define scol 3

void print(const int* array, int row, int col);

void transpose(const int* array, int* dest); 
void transpose2(int array[][scol], int dest[][srow]); 


int main(){
  int source[srow][scol] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int des[scol][srow];

  print(&source[0][0], srow, scol);
  transpose((int *)source, (int *)des);
  printf(" \n ");
  print((int *)des, scol, srow);
  transpose2(source, des);
  printf(" \n ");
  print((int *)des, scol, srow);

  return 0;
}

void print(const int* array, int row, int col)
{
  int i, j;
  for(i=0;i<row;i++)
        {
	  for(j=0;j<col;j++)
	    printf(" %d ", *(array + i*col + j)); 
	  printf(" \n " );
	}
  return;
}


void transpose(const int* array, int* dest){
  int i, j;
    for(i=0;i<scol;i++)
      for(j=0;j<srow;j++)
	*(dest + i*srow + j) = *(array + j*scol + i);  
  return; 
}

  
void transpose2(int array[srow][scol], int dest[scol][srow]){
  int i, j;
    for(i=0;i<scol;i++)
      for(j=0;j<srow;j++)
	dest[i][j] = array[j][i];
  return; 
}

