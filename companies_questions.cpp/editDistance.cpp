#include<bits/stdc++.h>
using namespace std;
int solve(string &s1,string &s2){
  int m = s1.length();
  int n = s2.length();

  vector<vector<int>> dp(m+1,vector<int>(n+1,0));
  
  //initialisation
  for (int i = 0; i <= m;i++){
    dp[i][0] = i;
  }

  for (int j = 0; j <= n;j++){
    dp[0][j] = j;
  }

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = 0 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = 1 + min({dp[i - 1][j - 1],
                              dp[i - 1][j],
                              dp[i][j - 1]});
        }
      }
    }
  return dp[m][n];
}

int main(){
  string line;
  getline(cin, line);

  string target;
  getline(cin, target);

  stringstream ss(line);
  string s;
  vector<string> arr;
  while(getline(ss,s,',')){
    arr.push_back(s);
  }


  int ans = INT_MAX;
  for(auto str:arr){
    int dis = solve(str, target);
    ans = min(ans, dis);
  }

  cout << ans << endl;
  return 0;
}

// Single File Programming Question
//     Problem Statement

//         A target word and a list of words are provided to you.The objective is to identify the word from the list closest to the target word in Levenshtein distance.The least amount of insertion,
//     deletion, or substitution needed to change one word into another is the Levenshtein distance.

//                   Example

//                       Input

//                           banana,
//     cherry, orange, pineapple

//                         penapple

//                             Output

//                                 pineapple

//                                     Explanation

//                                         The task is to find the word from the given list with the smallest Levenshtein distance with the target word "penapple".

//                     To calculate the Levenshtein distance,
//     the algorithm compares each word from the list with the target word and determines the number of operations(insertion, deletion, or substitution) required to transform the target word into each word from the list.

//     In this case,
//     we compare "penapple" with each word in the list:

// "banana" : To transform "penapple" into "banana", we need to substitute 'p' with 'b', insert 'n' at the second position, and delete 'e' and 'l'.This
//                                                                                                                                               requires 4 operations.
// "cherry": To transform "penapple" into "cherry", we need to substitute 'p' with 'c', insert 'h' at the second position, and delete 'n' and 'a'. This requires 4 operations.
// "orange": To transform "penapple" into "orange", we need to substitute 'p' with 'o', insert 'r' at the second position, and delete 'e', 'n', and 'a'. This requires 5 operations.
// "pineapple": To transform "penapple" into "pineapple", we need to substitute 'p' with 'p', insert 'i' at the second position, and delete 'e' and 'n'. This requires 3 operations.
// Among these words, "pineapple" has the smallest Levenshtein distance of 3, which is the fewest number of operations required to transform "penapple" into "pineapple".

// Input format :
// The first line of input consists of a comma-separated list of words, where each word is a string.

// The second line consists of a string, representing the target word to compare against the list.

// Output format :
// The output prints the word from the list that has the smallest Levenshtein distance to the target word.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ Length of each word ≤ 100

// 1 ≤ Number of words in the list ≤ 100

// The input words and the target word contain only lowercase and uppercase alphabetic characters (A-Z, a-z).

// Sample test cases :
// Input 1 :
// banana, cherry, orange, pineapple
// penapple
// Output 1 :
// pineapple
// Input 2 :
// dog, cat, bird, fish, lion
// bat
// Output 2 :
// cat
// Note :   in c++