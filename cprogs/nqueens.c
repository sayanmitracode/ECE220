#include <stdio.h>

#define N 4


void printBoard(int board[N][N]);
void initBoard(int board[N][N]);
int checkSafe(int board[N][N], const int row, const int col);
int solve(int board[N][N], int col);

int main(){
	int board[N][N];
	initBoard(board);
	printBoard(board);
	solve(board,0);
	printf("\n Solution \n");
	printBoard(board);

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

int solve(int board[N][N], int col){
	// returns 1 if this and all the following cols could be 
	// placed
	if (col >=N)
		// Done
		return 1;
	else{
		// col < N
		// try placing in each row of this col
		for (int row=0;row<N;row++)
		{
			if (checkSafe(board,row,col))
			{	
				// it is safe to place at row, col
				// guess placing queen in row, col
				printf("\n Placed queen in %d,%d \n", row,col);
				board[row][col] = 1;
				// solve smaller problem
				if (solve(board,col+1) == 1)
					return 1;
				else
				{
					// placing in row, col did not work
					// need to back track
					printf("\n Backtracking from \n");
					printBoard(board);
					board[row][col] = 0;
				}
			}
		}
		// none of the rows worked
		return 0;
	}
}

int checkSafe(int board[N][N], const int row, const int col)
{
	// check whether a new queen can be place in row,col
	// return 0 if no
	int i, j;
	for (i=0;i<N;i++)
		if (board[row][i]==1)
			return 0;
	for (i=0;i<N;i++)
		if (board[i][col]==1)
			return 0;
	// upper left diagonal	
	for (i=row, j=col;i>=0 && j >=0; i--,j--)
		if (board[i][j]==1)
			return 0;
	// lower left diagonal
	for (i=row, j=col;i<N && j >=0; i++,j--)
		if (board[i][j]==1)
			return 0;
	return 1;	
}
