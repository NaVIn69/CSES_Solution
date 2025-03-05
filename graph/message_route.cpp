#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to print the path from source node to the last node
int n,m;
vector<vector<int>>g;
vector<int>vis,dis,par;
void bfs(int sc_node){
  vis.assign(n+1,0);
  dis.assign(n+1,1e9);
  par.assign(n+1,-1);
  queue<int>q;
  q.push(sc_node);
  dis[sc_node]=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    if(vis[node])continue;
    vis[node]=1; 
    for(auto v:g[node]){
        if(!vis[v]&&dis[v]>dis[node]+1){
            dis[v]=dis[node]+1;
            par[v]=node;
            q.push(v);
         }
      } 
   }
   


}
void solve(){
cin>>n>>m;
g.resize(n+1);
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
bfs(1);

if(dis[n]==1e9){
  // here we cant reach that end node
  cout<<"IMPOSSIBLE"<<endl;
  return;
}
cout<<dis[n]+1<<endl;
vector<int>path;
int temp=n;
while(temp!=1){
  path.push_back(temp);
  temp=par[temp];
}
path.push_back(1);
reverse(path.begin(),path.end());
for(auto x:path){
  cout<<x<<" ";
}
cout<<endl;


}
signed main(){
  solve();
}