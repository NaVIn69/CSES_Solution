#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>dis,vis;

// when we got odd cycle , then we cant divided the team into two teams
bool check=true;
// here we assume that , we can divided the graph into two team
void dfs(int sc_node,int col){
     vis[sc_node]=col;
   for(auto x:g[sc_node]){
      if(!vis[x]){
         dfs(x,3-col);
      }else if(vis[x]==vis[sc_node]){
        // means we have been visited and here we find the odd cycle
        check=false;
        break;
      }
   }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dis.assign(n+1,1e9);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
       dfs(i,1);
    if(check==false){
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
}

}
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<" ";
    }
    cout<<endl;




}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}