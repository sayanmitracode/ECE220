#include <stdio.h>
#define srow 4
#define scol 3

void print(const int* array, int row, int col);

void transpose(const int* array, int* dest); 

// void transpose(const int array[][scol], int dest[][srow]); 

int main(){
  int source[srow][scol] = {1,2,3,4,5,6,7,8,9,10,11,12};
  int dest[scol][srow];
  print(&source[0][0], srow, scol);
  printf("\n Transposed \n");
  // transpose(source, dest);
  transpose((int *)source, (int *)dest);
  print((int *)dest, scol, srow);
  

  int a[4];
  int b[5];
  int *p_array[2];
  p_array[0] = &a[0]; /* p_array[0] = a; */
  p_array[1] = &b[0];	/* p_array[1] = b; */

  int *q_array[2] = {a,b};


  return 0;

}


void print(const int* array, int row, int col)
{
  int i,j;
  for (i=0;i<row; i++)
    {
    for (j=0;j<col;j++)
      printf(" %d ", *(array + i*col + j));
    printf("\n");
    }
  return;
}

// void transpose(const int array[][scol], int dest[][srow]){
void transpose(const int* array, int* dest){
  int i,j;
  for (i=0;i<srow; i++)
    for (j=0; j<scol; j++)
      //      dest[j][i] = array[i][j];
      *(dest + j*srow + i) = *(array + i*scol +j); 
  return;
}

