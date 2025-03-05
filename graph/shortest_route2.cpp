#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m,q;
vector<vector<int>>g;
vector<vector<int>>dis;
vector<int>vis;
void solve(){
    cin>>n>>m>>q;
    g.resize(n+1);
    dis.assign(n+1,vector<int>(n+1,1e18));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        g[b].push_back(a);
        dis[a][b]=min(dis[a][b],c);
        dis[b][a]=min(dis[b][a],c);
    }
   

    for(int i=1;i<=n;i++){
       dis[i][i]=0;
    }
    // here we have to find the all pair shortest path
    // floyed warshall
    // here we moving from i to j using the nodes k ..... -> 

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(dis[i][j]>dis[i][k]+dis[k][j]){
                dis[i][j]=dis[i][k]+dis[k][j];

               }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int a,b;
        cin>>a>>b;
        // cout<<dis[a][b]<<" ";
      if(dis[a][b]==1e18){
        cout<<"-1"<<endl;
      }else{
        cout<<dis[a][b]<<endl;
      }
    }


}
signed main(){
    solve();
}