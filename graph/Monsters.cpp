#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using state=pair<int,int>;
int n,m;
state st;
vector<vector<char>>g;
vector<vector<int>>dis_m,dis_p,vis;
vector<vector<pair<state,char>>>parent;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
char dir[]={'D','U','L','R'};
/*
   here dx represent the x and dy represent the y
   
   .--------->y(+ve)(right)
   .
   .
   .
   .
   x(+ve) Up
*/
void print_path(state st,state en){
    state temp=en;
    string direction="";
    while(temp!=st){
        pair<state,char> p= parent[temp.first][temp.second];
        direction+=p.second;
        temp=p.first;
    }
    reverse(direction.begin(),direction.end());
    for(auto c:direction){
        cout<<c;
    }
    cout<<endl;
}
void bfs(){
    dis_m.assign(n+1,vector<int>(m+1,1e9));
    dis_p.assign(n+1,vector<int>(m+1,1e9));
    vis.assign(n+1,vector<int>(m+1,0));
    parent.assign(n+1,vector<pair<state,char>>(m+1,{{-1,-1},'a'}));
    queue<state>q_monster,q_person;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
              q_monster.push({i,j});
              dis_m[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A'){
              q_person.push({i,j});
              st={i,j};
              dis_p[i][j]=0;
            }
        }
    }
    while(!q_monster.empty()){
       state node=q_monster.front();
       q_monster.pop();
       int x=node.first;
       int y=node.second;
       if(vis[x][y]) continue;
       vis[x][y]=1;
       for(int i=0;i<4;i++){
         int nx=x+dx[i];
         int ny=y+dy[i];
         if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
            if(!vis[nx][ny]&&dis_m[nx][ny]>dis_m[x][y]+1){
                // relax that edge
                dis_m[nx][ny]=dis_m[x][y]+1;
                q_monster.push({nx,ny});
            }
         }
       }
    }
    //
    vis.assign(n+1,vector<int>(m+1,0));
    while(!q_person.empty()){
        state node=q_person.front();
        q_person.pop();
        int x=node.first;
        int y=node.second;
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
          int nx=x+dx[i];
          int ny=y+dy[i];
          if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]!='#'){
             if(!vis[nx][ny]&&dis_p[nx][ny]>dis_p[x][y]+1){
                 // relax that edge
                 dis_p[nx][ny]=dis_p[x][y]+1;
                 parent[nx][ny]={{x,y},dir[i]};
                 q_person.push({nx,ny});
             }
          }
        }
     }
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis_p[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis_m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
     // here we have to cross check that , can person escape from one of the outer side of grid
     // first row and last row
     
     for(int i=0;i<m;i++){
         
         if(g[0][i]!='#'&&dis_p[0][i]<dis_m[0][i]){
            // agr person distacne kam hai from nearest monster which is at the escaping route
            // here we have to print the path
            cout<<"YES"<<endl;
            cout<<dis_p[0][i]<<endl;
            print_path(st,{0,i});
            return ;
            
         }else if(g[n-1][i]!='#'&&dis_p[n-1][i]<dis_m[n-1][i]){
            cout<<"YES"<<endl;
            cout<<dis_p[n-1][i]<<endl;
            print_path(st,{n-1,i});
            return ;
         }
     }
     for(int i=0;i<n;i++){
        if(g[i][0]!='#'&&dis_p[i][0]<dis_m[i][0]){
            cout<<"YES"<<endl;
            cout<<dis_p[i][0]<<endl;
            print_path(st,{i,0});
            return ;
        }else if(g[i][m-1]!='#'&&dis_p[i][m-1]<dis_m[i][m-1]){
            cout<<"YES"<<endl;
            cout<<dis_p[i][m-1]<<endl;
            print_path(st,{i,m-1});
            return ;
        }
     }
     cout<<"NO"<<endl;




}
void solve(){
    cin>>n>>m;
    g.assign(n+1,vector<char>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
  bfs();
    


}
signed main(){
    solve();
}