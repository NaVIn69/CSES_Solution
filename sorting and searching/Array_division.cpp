#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[1000000];
bool check(ll mid){
    ll sum=mid;
    ll cnt=1;
    for(ll i=0;i<n;i++){
        if(sum>=a[i]){
            sum-=a[i];
        }else{
          cnt++;
          if(cnt>k){
            return 0;
          }
          sum=mid;
          if(sum>=a[i]){
            sum-=a[i];
          }else{
            return 0;
          }
        }
    }
    return 1;
}
void solve(){
cin>>n>>k;
ll s=1;
ll e=2e5*1e9;
for(ll i=0;i<n;i++){
    cin>>a[i]; 
   
}
ll ans=0;
while(s<=e){
    ll mid=s+(e-s)/2;
    if(check(mid)){
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