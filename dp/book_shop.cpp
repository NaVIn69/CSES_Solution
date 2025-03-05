#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,x;
int price[1005];
int pages[1005];
int dp[1001][100005];
int rec(int level,int left){
    // this return maximum page from (level....n) using left price
    if(left<0) return 0;
    if(level==n){
        return 0;
    } 
   
    if(dp[level][left]!=-1){
        return dp[level][left];
    }
    // transition
    int ans=rec(level+1,left);
    if(price[level]<=left){
        ans=max(ans,pages[level]+rec(level+1,left-price[level]));
    }
    return dp[level][left]=ans;
}
void solve(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    
   memset(dp,-1,sizeof(dp));
    cout<<rec(0,x)<<endl;
 
 
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
