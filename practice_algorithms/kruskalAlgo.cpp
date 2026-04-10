#include<bits/stdc++.h>
using namespace std;

class dsu{
  int n;
  vector<int> par;
  vector<int> rank;
  vector<int> sz;

public:
  dsu(int n){
    this->n = n;
    par.resize(n, 0);
    rank.resize(n, 0);
    sz.resize(n, 1);
    for (int i = 0; i < n;i++){
      par[i] = i;
    }
  }

  int findPar(int x){
    if(par[x]==x)
      return x;
    return par[x] = findPar(par[x]);
  }

  void unionByRank(int u,int v){
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if(ulp_u==ulp_v)
      return;
    
    if(rank[ulp_u]<rank[ulp_v]){
      par[ulp_u] = ulp_v;
    }  
    else if(rank[ulp_u]>rank[ulp_v]){
      par[ulp_v] = ulp_u;
    }
    else{
      par[ulp_u] = ulp_v;
      rank[ulp_v]++;
    }
  }

  void unionBysize(int u,int v){
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if(ulp_u==ulp_v)
      return;
    
    if(sz[ulp_u]<sz[ulp_v]){
      par[ulp_u] = ulp_v;
      sz[ulp_v] += sz[ulp_u];
    }
    else{
      par[ulp_v] = ulp_u;
      sz[ulp_u] += sz[ulp_v];
    }
  }
};

class solution{
    public:
    int KruskalAlgo(vector<vector<pair<int,int>>> &arr){
      vector<pair<int, pair<int, int>>> edges;
      int V = arr.size();
      dsu ds(V);

      for (int i = 0; i < V;i++){
        for(auto &p : arr[i]){
          int u = i;
          int v = p.first;
          int wt = p.second;
          if(i<v)
          {
            edges.push_back({wt, {u, v}});
          }
        }
      }

      // sort the edges on the basis of wt;
      sort(edges.begin(), edges.end());
      int maxWt = 0;

      for (int i = 0; i < edges.size();i++){
        int wt = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if(ds.findPar(u)!=ds.findPar(v)){
          maxWt += wt; //add to the mst
          ds.unionByRank(u, v);
        }
      }
      return maxWt;
    }
};

int main(){
  int k;
  cin >> k;
  while(k--){
    int V;
    cin >> V;
    vector<vector<pair<int,int>>> arr(V);
    for (int i = 0; i < V;i++){
      int v, wt;
      cin >> v >> wt;
      arr[i].push_back({v, wt});
      arr[v].push_back({i, wt});
    }

    solution s;
    cout<<s.KruskalAlgo(arr)<<endl;
  }
  return 0;
}