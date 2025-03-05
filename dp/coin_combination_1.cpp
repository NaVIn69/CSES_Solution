#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int mod=1e9+7;
int n,x;
int arr[105];
int dp[1000100];

int rec(int sum){
 // this return the number of ways to make sum using array element
 if(sum<0){
    return 0;
 }
if(sum==0){
    return 1;
}
if(dp[sum]!=-1){
    return dp[sum];
}
// choice 
// every element 
int ans=0;
for(int ch=0;ch<n;ch++){
    if(arr[ch]<=sum){
        ans=ans%mod+rec(sum-arr[ch])%mod;
    }
}
return dp[sum]=ans%mod;

}
void solve(){
  cin>>n>>x;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
 
  memset(dp,-1,sizeof(dp));
  int ans=rec(x);
  cout<<(ans%mod+mod)%mod<<endl;



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}