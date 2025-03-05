#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n,m,k;
vector<vector<pair<int,int>>>g;
vector<int>path;
vector<int>dis;

void solve(){
cin>>n>>m>>k;
g.resize(n+1);

// directed graph;
for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back({b,c});
}
// here we use the dijkstra k times to find the k smallest path every time  
// from which path i get the smallest path i have to 

  
}

signed main(){
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  int t=1;
  cin>>t;
  while(t--){
    solve();
  }
}