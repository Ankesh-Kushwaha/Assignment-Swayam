//place knight on a chess board of N * N board where no two knight can attack each other
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> not_safe_move = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isSafe(int row,int col,int n,vector<vector<char>> &board){
     for(auto d: not_safe_move){
       int new_x = row + d[0];
       int new_y = col + d[1];

       if((new_x>=0 && new_x<n) && (new_y>=0 && new_y<n)){
           if(board[new_x][new_y]=='K')
             return false;
       }
     }

    return true;
}

void print(vector<vector<char>> &board){
  int n = board.size();
  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << "___________________________" << endl;
}

//place knight row-wise
void placeKnight(int row,int col,int kinghtPlaced,int n,vector<vector<char>>&board){
   if(kinghtPlaced==n){
     print(board);
     return;
   }

   if(row==n)
     return;

   int next_row = row + (col + 1) / n;
   int next_col = (col + 1) % n;

   // keep the knight at the present cell;
   if(isSafe(row,col,n,board)){
     board[row][col] = 'K';
     kinghtPlaced++;
     placeKnight(next_row, next_col,kinghtPlaced, n, board);
     board[row][col] = '.';
     kinghtPlaced--;
   }

   // skip do not place on current cell;
   placeKnight(next_row, next_col,kinghtPlaced, n, board);
}

int main(){
  int n;
  cin >> n;
  vector<vector<char>> board(n, vector<char>(n, '.'));
  placeKnight(0,0,0,n,board);
  return 0;
}