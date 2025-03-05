#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// here we have to apply the bellman ford 
int n,m;
vector<pair<pair<int,int>,int>>edge;
vector<int>dis,par;
void solve(){
    cin>>n>>m;
  
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        edge.push_back({{a,b},-x});
    }
    // here we have to get the maximum distance node , that why we we do like something
    dis.assign(n+1,1e18);
    par.assign(n+1,-1);
    dis[1]=0;
    // here we have to run for n-1 time and each time one least one edge is going to relax
   for(int i=0;i<n-1;i++){
    for(auto e:edge){
        int a=e.first.first;
        int b=e.first.second;
        int w=e.second;
        // when we  are relaxing the edge a to b having weight equal to w // we must have the correct distance of a 
        if(dis[a]!=1e18){
        dis[b]=min(dis[b],dis[a]+w);
    }// means there is path from a to b 
    } 
   }
   // 
//    cout<<"first bellman"<<endl;
//    for(int i=1;i<=n;i++){
//     cout<<dis[i]<<" ";
//    }
//    cout<<endl;

   // for finding the negative cycle
//    cout<<"second bellman"<<endl;
   for(int i=0;i<n-1;i++){
       for(auto e:edge){
         int a=e.first.first;
         int b=e.first.second;
         int w=e.second;
         if(dis[a]!=1e18){
         if(dis[b]>dis[a]+w){ // still we can relax it then we mark it with 
            dis[b]=-1e18;
         }
        } // means we have path from a to b having the weight equal to w
       }
   }
//    for(int i=1;i<=n;i++){
//     cout<<dis[i]<<" ";
//    }
//    cout<<endl;


// self loop 
if(n==1&&edge[0].second<0) cout<<"-1"<<endl;
 else  if(dis[n]==-1e18){
    cout<<"-1"<<endl;
   }else{
    cout<<-1*dis[n]<<endl;
   }
  
  


}
signed main(){
    solve();
}