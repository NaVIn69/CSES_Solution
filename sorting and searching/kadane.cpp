#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
ll n;
cin>>n;
ll a[n];
for(ll i=0;i<n;i++) cin>>a[i];
ll sum=0;
ll maxi=INT_MIN;
for(ll i=0;i<n;i++){
sum=max(a[i],sum+a[i]);
maxi=max(sum,maxi);
}
cout<<maxi<<endl;

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}