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
// here we have to find the minimum value in the range of q queries
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+1]={0};
    int prefix[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // we have to find the next smaller array
    // we have to fins the previous smaller array
    while(q--){
        int a,b;
        cin>>a>>b;

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