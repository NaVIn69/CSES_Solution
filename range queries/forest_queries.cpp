#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;

int binpow(int a,int p,int mod){

if(p==0) return 1%mod;

if(p%2) return (a%mod *binpow(a,p-1,mod))%mod;

else{
int temp=binpow(a,p/2,mod);
return (temp*temp)%mod;
}

}
int arr[1005][1005];
int p[1005][1005];
// here we have to find the minimum value in the range of q queries
void solve(){
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        char ch;
        cin>>ch;
        if(ch=='*'){
            arr[i][j]=1;
        }else{
            arr[i][j]=0;
        }
    }
  }
  // here we made a 2d prefix array
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
          p[i][j] = arr[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    }
  }
  
  while(q--){
      int y1,x1,y2,x2;

      cin>>y1>>x1>>y2>>x2;
      cout<<p[y2][x2]-p[y1-1][x2]-p[y2][x1-1]+p[y1-1][x1-1]<<endl;
  }


    

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t--){
        solve();
    }
}