#include<bits/stdc++.h>
using namespace std;
class diffArray{
  public:
  void implementation(vector<int> &nums,vector<vector<int>> &queries){
    vector<int> diff(nums.size(), 0);

    for(auto q:queries){
      int l = q[0];
      int r = q[1];
      int val = q[2];

      diff[l] += val;
      if(r+1<nums.size()){
        diff[r+1] -= val;
      }
    }
   
    //commulative sum
    for (int i = 0; i < nums.size();i++){
          if(i>0){
            diff[i] = diff[i] + diff[i - 1];
          }
    }

    for (int i = 0; i < nums.size();i++){
      nums[i] += diff[i];
    }
  }
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++){
      cin >> nums[i];
    }

    int q;
    cin >> q;
    vector<vector<int>> queries;
    for (int i = 0; i < q;i++){
      int l, r,val;
      cin >> l >> r>>val;
      queries.push_back({l,r,val});
    }

    diffArray da;
    da.implementation(nums, queries);
    for (int i = 0; i < n;i++){
      cout << nums[i] << " ";
    }
    cout << endl;
  }
  return 0;
}