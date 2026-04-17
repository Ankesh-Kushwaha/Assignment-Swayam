#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &arr)
{
  if (i == j)
    return 0;

  int maxi = INT_MAX;

  for (int k = i; k < j; k++)
  { 
    int steps = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr) + solve(k + 1, j, arr);

    maxi = min(maxi, steps);
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int minOps = solve(1, n - 1, arr); 
  cout << minOps << endl;

  return 0;
}