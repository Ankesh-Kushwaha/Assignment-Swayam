#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &cost,vector<vector<int>> &dp){
    if(i==grid.size()-1)
      return grid[i][j]; //reaches at the last row

    if(dp[i][j]!=-1)
      return dp[i][j];

    int ans = INT_MAX;
    for (int k = 0; k < grid[0].size();k++){
      int next = solve(i + 1, k, grid, cost,dp);
      int movecost = cost[grid[i][j]][k];
      int curr = grid[i][j];

      ans = min(ans, (next + movecost + curr));
    }
    return dp[i][j]=ans;
}

int main(){
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid(m, vector<int>(n));

  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> cost(m * n, vector<int>(n, 0));
  for (int i = 0; i < m * n;i++){
    for (int j = 0; j < n;j++){
      cin >> cost[i][j];
    }
  }

  int minCost = INT_MAX;
  vector<vector<int>> dp(m, vector<int>(n,-1));
  for (int j = 0; j < n; j++)
  {
    minCost = min(minCost, solve(0, j, grid, cost, dp));
  }
  cout << minCost << endl;
  return 0;
}

// Single File Programming Question
// Problem Statement

// Karan is traversing a magical grid of size m x n, filled with unique integers from 0 to m*n-1. He can move from a cell in row x to any cell in row x + 1. Every such move has a cost defined in a separate matrix called moveCost, where moveCost[i][j] is the cost to move from a cell with value i to column j of the next row. 

// Write a program to ensure that Karan finds a path from any cell in the first row to any cell in the last row with the minimum total cost, which is the sum of all visited cell values and the costs of the transitions.

// Example 1:

// Input: grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]

// Output: 17

// Explanation: The path with the minimum possible cost is the path 5 -> 0 -> 1.

// - The sum of the values of cells visited is 5 + 0 + 1 = 6.

// - The cost of moving from 5 to 0 is 3.

// - The cost of moving from 0 to 1 is 8.

// So the total cost of the path is 6 + 3 + 8 = 17.



// Example 2:

// Input: grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]

// Output: 6

// Explanation: The path with the minimum possible cost is the path 2 -> 3.

// - The sum of the values of cells visited is 2 + 3 = 5.

// - The cost of moving from 2 to 3 is 1.

// So the total cost of this path is 5 + 1 = 6.

// Input format :
// The first line contains two space-separated integers m and n denoting the number of rows and columns of the grid.

// Next m lines: Each line contains n space-separated integers representing the grid.

// Next m * n lines: Each line contains n space-separated integers representing the moveCost matrix.

// Output format :
// The output prints a single integer representing the minimum cost to reach any cell in the last row from any cell in the first row.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 2 ≤ m, n ≤ 50

// 0 ≤ grid [i] [j] < m * n

// 0 ≤ moveCost [i] [j] ≤ 100

// Sample test cases :
// Input 1 :
// 3 2
// 5 3
// 4 0
// 2 1
// 9 8
// 1 5
// 10 12
// 18 6
// 2 4
// 14 3
// Output 1 :
// 17   in c++


