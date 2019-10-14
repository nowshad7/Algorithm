#include<bits/stdc++.h>
#define N 5
using namespace std;

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;


    for (i = 0; i < N; i++)
        if (board[i][col])
            return false;


    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;


    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}



bool solve(int arr[N][N],int row )
{
  if(row == N) return true;

  for(int i=0;i<N;i++)
  {
    if(isSafe(arr,row,i))
    {
      arr[row][i] = 1;
      if(solve(arr,row+1))
        return true;
      arr[row][i] = 0;
    }

  }
  return false;

}


void nqueen()
{
  int arr[N][N];
  memset(arr,0,sizeof arr);

  if(!solve(arr,0))
  {
    cout<<"No Solution\n";
    return;
  }

  printSolution(arr);

}


int main()
{

 nqueen();


  return 0;
}
