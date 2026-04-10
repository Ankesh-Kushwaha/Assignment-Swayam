// this technique is use in the question where queries are given and we need to perform sum
// operations on them and we need a slightly better complexity  if there is a Q  query need to be
// performed on a N size array then the overall complexity of the code reaches to O(Q*N);
// so using this technique we can reduced the complexity to slightly less that is some around
// O(Q*sqrt(N));what we do in this case instead of performing query on the whole array we break
// it into a block size of ceil(sqrt(N));

//core idea behind this technique
// Divide array into blocks of size ≈ √N to speed up queries.
// Precompute values (sum/min/max etc.) for each block.
// Range query: process partial edges normally + full blocks using precomputed values → O(√N).
// Update: modify element and update its block → O(1).
// Reduces complexity from O(Q·N) to O(Q·√N).
// Useful when both queries and updates exist but Segment Tree feels heavy.
// Works well for range sum, min/max, frequency-based queries.
// Not ideal for very large constraints or complex updates → use Segment Tree then.
// Core idea: jump block-by-block instead of element-by-element.

#include<bits/stdc++.h>
using namespace std;
class squareRootDecomposition{
    public:
      vector<int> blocks;
      int blockSize;
      vector<int> ans;

      vector<int> implementation(vector<vector<int>> &queries, vector<int> &nums)
      {
        int n = nums.size();
        blockSize = ceil(sqrt(n));
        blocks.resize(blockSize + 1, 0); // because if n=8 then instead of making block of 2.666 which form a block of 2 size we prefer forming a block size of 3;

        //we stored the sum in a block like if we have size of nums is 0.........9
        //then block size is 3 so we stored sum of 0...2 in blocks[0], 3....5 in blocks[1] and so on
        for (int i = 0; i < n;i++){
          blocks[(i / blockSize)] += nums[i];
        }
  
      //performing query      
        for(auto q:queries){
          int sum = 0;
          int l = q[0];
          int r = q[1];
          int startBlock=l/blockSize;
          int endBlock = r / blockSize;
          //case 1 when left and right  lies in the same block 
         //in this case we simply  return the sum from left to right 
          if(startBlock==endBlock){ //lies inside the same block
            for (int i = l; i <= r;i++){
              sum += nums[i];
            }
          }
          else{
            // case 2 when the queries are overlapping in this case we need three part
            // 1.left (left to end of the startBlock);
            int endofStartBlock = (startBlock + 1) * blockSize - 1;
            // add the left sum
            for (int i = l; i <= endofStartBlock; i++)
            {
              sum += nums[i];
            }

            //2.middle part requires only O(1) access 
            //from startBlock+1 to endBlock-1
            for (int i = startBlock + 1; i <= endBlock - 1;i++){
              sum += blocks[i];
            }

            // 3 right side ( from start index of endblock  to right);
            int startofendBlock = (endBlock * blockSize);
            for (int i = startofendBlock;i<=r;i++){
              sum += nums[i];
            }
          }
          ans.push_back(sum);
        }
        return ans;
      }
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,q;
    cin >> n>>q;

    vector<vector<int>> queries;

    for (int i = 0; i < q; i++)
    {
      int left, right;
      cin >> left >> right;
      queries.push_back({left, right});
    }

    vector<int> nums(n);
    for (int i = 0;i<n;i++){
      cin >> nums[i];
    }

    squareRootDecomposition srd;
    vector<int> ans = srd.implementation(queries, nums);

    for (int i = 0; i < ans.size();i++){
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}