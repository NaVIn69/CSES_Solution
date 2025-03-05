// find the kth element in the multiplication table
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll mid,ll n,ll k){
    // direct count kr rhe hai row me jakr
    ll cnt=0;
    for(int i=1;i<=n;i++){
     cnt+=min(n,mid/i);
    }
    return cnt>=k;
}
void solve(){
ll n,k;
cin>>n;
 k=((n*n)+1)/2;
ll s=1;
ll e=n*n;
ll ans=0;
while(s<=e){
    ll mid=s+(e-s)/2;
    if(check(mid,n,k)){
        ans=mid;
        e=mid-1;

    }else{
        s=mid+1;
    }
}
cout<<ans<<'\n';

}
int main(){
    solve();
}