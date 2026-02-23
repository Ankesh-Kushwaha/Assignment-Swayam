#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
   public:
     int n;
     vector<int> par;
     vector<int> Rank;
     vector<int> Size;

     DisjointSet(int n){
       this->n = n;
       par.resize(n+1);
       Rank.resize(n+1, 0);
       Size.resize(n + 1, 1); //initally each node has a size of 1

       for (int i = 0; i <=n;i++){
         par[i] = i; //assign each node to it as parent of itself
         Rank[i] = 0;//initially all are at the same level
       }
     }

     int findPar(int x){
          if(par[x]==x)
            return x;
          return par[x] = findPar(par[x]);
     }
     

     void unionByRank(int u,int v){
       int ulParU = findPar(u);
       int ulParV = findPar(v);
      
       if(ulParU==ulParV)
         return;

       if (Rank[ulParU] == Rank[ulParV]){
         par[ulParV] = ulParU;
         Rank[ulParU]++;
       }
       else if(Rank[ulParU]>Rank[ulParV]){
         par[ulParV] = ulParU;
       }
       else{
         par[ulParU] = ulParV;
       }
     }


    void unionBySize(int u,int v){
      int ulp_u = findPar(u);
      int ulp_v = findPar(v);

      if(ulp_u==ulp_v)
        return;
      
      if(Size[ulp_u]<Size[ulp_v]){
        par[ulp_u] = ulp_v;
        Size[ulp_v] += Size[ulp_u];
      } 
      else{
        par[ulp_v] = ulp_u;
        Size[ulp_u] += Size[ulp_v];
      } 
    }


     void print(){
       for (int i = 0; i <=n;i++){
         cout << par[i] << " ";
       }

       cout << endl;
       for (int i = 0; i <= n;i++){
         cout << Size[i] << " ";
       }
     }
};
int main(){
  DisjointSet dj(7);
  dj.unionBySize(1,2);
  dj.unionBySize(2,3);
  dj.unionBySize(4,5);
  dj.unionBySize(6,7);
  dj.unionBySize(5,6);
  dj.unionBySize(3,7);
  
  if(dj.findPar(3)==dj.findPar(7)){
    cout << "same" << endl;
  }
  else{
    cout << "not same" << endl;
  }
  dj.print();
  return 0;
}