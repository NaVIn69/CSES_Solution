#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<pair<int,int>>comp;
// here we store the component number with one of the node jha se road connect hoga
void dfs(int sc_node,int comp){
     vis[sc_node]=comp;
     for(auto v:g[sc_node]){
        if(!vis[v]){
            dfs(v,comp);
        }
     }
}

void solve(){
 cin>>n>>m;
 g.resize(n+1);
 vis.resize(n+1);
 for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
 }
 int com=0;
 for(int i=1;i<=n;i++){
   if(!vis[i]){
    com++;
    dfs(i,com);
   
    comp.push_back({com,i});
    // here we are pushing the  com ,i
   }

 }
 cout<<com-1<<endl;
 for(int i=1;i<comp.size();i++){
    cout<<comp[i-1].second<<" "<<comp[i].second<<endl;
 }





}
signed main(){
    solve();
}