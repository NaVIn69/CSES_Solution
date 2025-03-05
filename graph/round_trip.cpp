#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
vector<vector<int>>g;
vector<int>vis,dis;
vector<int>parent;

// here we mark the nodes with 3 number 
// 1 ->means i dont traverse
//2 -> we are travelling all the child of that nodes
// 3-> means we have been travelled all the child node of that node
bool is_cycle=false;
void dfs(int sc_node,int par){
    vis[sc_node]=1;
    parent[sc_node]=par;
    for(auto v:g[sc_node]){
        if(!vis[v]){
           dfs(v,sc_node);
        }else if(v!=par){
            if(is_cycle==false){
               vector<int>cycle;
               int temp=sc_node;
               cycle.push_back(v);
               while(temp!=v){
                  cycle.push_back(temp);
                  temp=parent[temp];
               }
               cycle.push_back(v);
               reverse(cycle.begin(),cycle.end());
               cout<<cycle.size()<<endl;
               for(auto x:cycle){
                cout<<x<<" ";
               }
               cout<<endl;
            }
            is_cycle=true;
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
 vis.assign(n+1,0);  // measn we havent travels the child node of that node

 parent.assign(n+1,-1);
//    for(int i=1;i<=n;i++){
//     cout<<i<<"-> ";
//       for(int j=0;j<g[i].size();j++){
//           cout<<g[i][j]<<" ";
//       }
//       cout<<endl;
//    }
 for(int i=1;i<=n;i++){
    if(!vis[i]){
        // every sc_node of component has the -1 as the parent node
        dfs(i,-1);
        // if(is_cycle) break;
    }
 }
//  for(int i=1;i<=n;i++){
//     cout<<vis[i]<<" ";
//  }

 if(is_cycle==false){
    cout<<"IMPOSSIBLE"<<endl;
 }
 cout<<(make_pair(1,2)==make_pair(1,2))<<endl;
 cout<<(make_pair(1,2)==make_pair(2,1))<<endl;


}
signed main(){
    solve();
}