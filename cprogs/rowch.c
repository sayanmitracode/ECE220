#define M 3 /* row size */
#define N 4 /* col size */
#include <stdio.h>

void printmatrix(int matrix[N][N]);
void rowexchange(int matrix[N][N], int row1, int row2);
void rowexchange_ptr(int* matrix, int row1, int row2);


int main()
{
  int matrix[N][N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  printf("\n Before first swap \n");
  printmatrix(matrix);
  printf("\n After first swap \n");
  rowexchange(matrix,1,2);
  printmatrix(matrix);
  printf("\n After second swap \n");
  rowexchange_ptr((int *)matrix,1,2);
  printmatrix(matrix);
  return 0;
}

void printmatrix(int matrix[N][N])
{
  int i, j;
  for (i = 0; i < N; i++)
    {
    for (j = 0; j < N; j++)
      printf(" %2d", matrix[i][j]);
    printf("\n");
    }
  return;
}

void rowexchange(int matrix[N][N], int row1, int row2)
{
  int temp;
  int i;
  for (i=0;i<N;i++)
    {
      temp = matrix[row1][i];
      matrix[row1][i] =  matrix[row2][i];
      matrix[row2][i] = temp;
    }
  return;
}


void rowexchange_ptr(int* matrix, int row1, int row2)
{
  int temp;
  int i;
  for (i=0;i<N;i++)
    {
      temp = *(matrix + N*row1 + i);
      *(matrix + N*row1 + i) =  *(matrix + N*row2 + i);
      *(matrix + N*row2 + i) = temp;
    }
  return;
}

