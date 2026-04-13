#include <iostream>
#include<vector>
using namespace std;

void print(vector<vector<char>> &board){
  int n=board.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"----------------------";
  cout<<endl;
}

bool isSafe(vector<vector<char>> &board,int row,int col){
  int n=board.size();
      //horizontal safety
  for(int j=0;j<n;j++){
     if(board[row][j]=='Q'){
      return false;
     }
  }

  //vertical safety;
  for(int i=0;i<row;i++){
       if(board[i][col]=='Q'){
        return false;
       }
  }
  
  //diagonally  safety
  //->diagonal left 
  for(int i=row,j=col;i>=0 && j>=0;i--,j--){
      if(board[i][j]=='Q'){
        return false;
      }
  }
   
  //diagonally right
   for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
          return false;
        }  
   }


   return true;
}

void nQueens(vector<vector<char>> &board,int row){
  int n=board.size();
   //base case
   if(row==n){
      print(board);
      return;
   }
    

     for(int j=0;j<n;j++){ //cols
      if(isSafe(board,row,j)){
            board[row][j]='Q';
            nQueens(board,row+1);
            board[row][j]='.';
      }
     }
     
}

int main(){
vector<vector<char>>board;
int n=4;

for(int i=0;i<n;i++){
  vector<char> newrow;
  for(int i=0;i<n;i++){
    newrow.push_back('.');
  }
  board.push_back(newrow);
}
  nQueens(board,0);
  return 0;
}