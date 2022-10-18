#include <stdio.h>

#define N 4


void printBoard(int board[N][N]);
void initBoard(int board[N][N]);
int checkSafe(int board[N][N], const int row, const int col);
int solve(int board[N][N], int col);

int main(){
	int board[N][N];	// board[i][j] = 1 there is a queen ; 0 means no queen
	initBoard(board);
	printBoard(board);
	solve(board,0);
	printf("\n Solution \n");
	printBoard(board);

}


int solve(int board[N][N], int col){
	if (col==N)
		retun 1; // done
	else{
		// col < N
		// try each row
		for (int row =0; row < N; row+)
		{
			if (checkSafe(board, row,col))
			{
				// place tentatively
				print (" \n Placeing at %d %d \n", row, col);
				board[row][col] = 1;
				// solve smaller
				if (solve(board, col+1) == 1 )
					return 1;
				else 
				{
					print (" \n Backtracking \n", row, col);
					board[row][col] = 0;
					print(board);
				}
			}
		}
		// no row worked for this col
		return 0;


	}


}



int checkSafe(int board[N][N], const int row, const int col)
{
	// return 1 if new queen can be placed at row, col
	// otherwise return 0;
	int i,j;
	for (i=0;i<N;i++)
	{
		if(board[row][i]==1)
			return 0;
	}
	for (i=0;i<N;i++)
	{
		if(board[i][col]==1)
			return 0;
	}
	for (i=row,j=col; i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==0)
			return 0;
	}
	for (i=row,j=col; i<N && j>=0;i++,j--)
	{
		if(board[i][j]==0)
			return 0;
	}
	return 1;

}

void initBoard(int board[N][N]){
	int i,j;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			board[i][j] = 0;
	return;	
}

void printBoard(int board[N][N]){
	int i,j;
	printf(" \n");
	for (i=0;i<N;i++){
		for (j=0;j<N;j++)
			printf(" %d ", board[i][j]);
		printf(" \n");
	}
}