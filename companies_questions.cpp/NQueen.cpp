#include<bits/stdc++.h>
using namespace std;

//is safe for row-wise placement
bool isSafe(int row,int col,int n,vector<vector<char>> &board){
    
  //check if there is any queen in that col
  for (int i = 0; i < row;i++){
       if(board[i][col]=='Q')
         return false;
  }

  //check if there is any queen that row
  for (int j = 0; j < col;j++){
     if(board[row][j]=='Q')
       return false;
  }

  for (int i = row,j = col; (i >= 0 && j >= 0);i--,j--){
      if(board[i][j]=='Q')
        return false;
  }

  for (int i = row, j = col; (i >= 0 && j < n); i--,j++){
    if(board[i][j]=='Q')
      return false;
  }

  return true;
}

//placing row-wise 
void NQueen(int idx,int n,vector<vector<char>> &board){
    if(idx==n){
      for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
          cout << board[i][j] << " ";
        }
        cout << endl;
      }
      return;
    }

    for (int j = 0; j < n;j++){
         if(isSafe(idx,j,n,board)){
           board[idx][j] = 'Q';
           NQueen(idx + 1, n, board);
           board[idx][j] = '.';
         }
    }
}

bool isSafe2(int row,int col,int n,vector<vector<char>> &board){
  for (int i = 0; i < row;i++){
      if(board[i][col]=='Q')
        return false;   
  }

  for (int j = 0; j < col;j++){
     if(board[row][j]=='Q')
       return false;
  }

  for (int i = row, j = col; (i >= 0 && j >= 0);i--,j--){
     if(board[i][j]=='Q')
       return false;
  }

  for (int i = row, j = col; (i < n && j >= 0); i++,j--){
      if(board[i][j]=='Q')
        return false;
  }

    return true;
}

//placing column-wise
void NQueen2(int col,int n,vector<vector<char>> &board){
    if(col==n){
      for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
          cout << board[i][j] << " ";
        }
        cout << endl;
      }

      cout << endl;
      return;
    }

    for (int i = 0; i < n;i++){
      if(isSafe2(i,col,n,board)){
        board[i][col] = 'Q';
        NQueen2(col + 1, n, board);
        board[i][col] = '.';
      }
    }
}

int main(){
  int n;
  cin >> n;

  vector<vector<char>> board(n, vector<char>(n, '.'));
  NQueen2(0,n, board);
  return 0;
}