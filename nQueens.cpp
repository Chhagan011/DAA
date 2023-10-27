#include <bits/stdc++.h>
using namespace std;
 
int N;
int board[15][15];

void printSolution()
{
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
           if(board[i][j])
            cout << "Q\t";
           else cout<<"-\t";
        printf("\n\n\n");
    }
    printf("\nMirror image is. \n\n");
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j >= 0; j--)
           if(board[i][j])
            cout << "Q\t";
           else cout<<"-\t";
        printf("\n\n\n");
    }
}
 
bool isSafe(int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
bool solveNQUtil(int col)
{
    if (col >= N)
        return true;
 
    for (int i = 0; i < N; i++) 
    {
         if (isSafe(i, col)) 
         {
            board[i][col] = 1;
            if (solveNQUtil(col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}
 
bool solveNQ()
{
	do{
		cout << "\nEnter number of Queens (<=15) : ";
		cin >> N;
		if(N > 15)
			cout << "Processing capacity is only upto 15 cells.\n";
		if(N <= 0)
			cout << "Enter a positive value.\n";
	}while(N<=0 || N>15);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			board[i][j] = 0;
	}
                       
    if (solveNQUtil(0) == false) 
    {
        cout << "Solution does not exist for given nuymber. \n";
        solveNQ();
        return false;
    }
 
    printSolution();
    return true;
}
 
int main()
{
    solveNQ();
    return 0;
}
