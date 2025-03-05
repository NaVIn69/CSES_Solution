#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
int n;
int dp[1000005];
int rec(int i){
    // this give me the total number of ways to form i to n using the (1.....6);
    if(i>n) return 0;
    if(i==n){
        return 1;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    // transition
    int ans=0;
    for(int ch=1;ch<=6;ch++){
        ans=ans%mod+rec(i+ch)%mod;
    }
    return dp[i]=ans;

}
void solve(){
cin>>n;
memset(dp,-1,sizeof(dp));
cout<<(rec(0)%mod+mod)%mod<<endl;


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}