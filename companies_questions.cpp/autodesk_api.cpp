// there is given a query array it contains a two types of queries q1=[type,idx,newValue] and q2=[type,targetSum];
// now you are given a two array one is primary array and other is secondary array ;
// perform query on these array if q[idx] type==1 then update the neValue of query in the primary array at idx  like if q1=[1,2,10]
// this means update the primary array as primary[2]=10;
// q2 type==0 which conatins a target sum. we have to return the number of combination that can be formed form
// primary[i]+secondary[i]=target; return a vector conatining the result of type 2 query

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  vector<int> performQuery(vector<int> &primary,vector<int> &secondary,vector<vector<int>> queries){
    vector<int> ans;
    for(auto q:queries){
       if(q[0]==1){
         primary[q[1]] = q[2];
       }
       else{
         int target = q[1];
         int temp = 0;
         for (int i = 0; i < primary.size();i++){
           for (int j = 0; j < secondary.size();j++){
                if(primary[i]+secondary[j]==target && i!=j){
                  temp++;
                }
           }
         }

         ans.push_back(temp);
       }
    }
    return ans;
  }

vector<int> performQueryOptimised(vector<int> &primary,vector<int> &secondary,vector<vector<int>> &queries){
    vector<int> ans;
    unordered_map <int, int> mp;

    // store the freq of secondary[j];
    // because we only need secondary[j]=target-primary[i]; that is our need
    for(auto it:secondary) mp[it]++;

    for(auto q:queries){
       if(q[0]==1){
         primary[q[1]] = q[2];
       }
       else{
         int target = q[1];
         int temp = 0;
         for (int i = 0;i<primary.size();i++){
           int need = target - primary[i];
           if(mp.count(need)){
             temp += mp[need];
           }
         }
         ans.push_back(temp);
       }
       
    }
    return ans;
  }

};
int main(){
 int t;
 cin >> t;
while(t--){
  int n;
  cin >> n;

  int k;
  cin >> k;

  vector<vector<int>> queries;
  for (int i = 0; i < k; i++)
  {
    vector<int> temp;
    int type;
    cin >> type;
    if (type == 1)
    {
      int idx, newValue;
      cin >> idx >> newValue;
      temp.push_back(type);
      temp.push_back(idx);
      temp.push_back(newValue);
    }
    else
    {
      int tar;
      cin >> tar;
      temp.push_back(type);
      temp.push_back(tar);
    }
    queries.push_back(temp);
  }

  vector<int> primary(n);
  vector<int> secondary(n);

  for (int i = 0; i < n; i++)
  {
    cin >> primary[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> secondary[i];
  }

  Solution Sol;
  vector<int> ans = Sol.performQueryOptimised(primary, secondary, queries);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

 return 0;
}