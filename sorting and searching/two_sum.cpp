#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
ll n,sum;
cin>>n>>sum;
ll arr[n];
vector<pair<ll,ll>>a;
for(ll i=0;i<n;i++){
    cin>>arr[i];
    pair<int,int>p;
    p.first=arr[i];
    p.second=i+1;
    a.push_back(p);
}


sort(a.begin(),a.end());
ll s=0;
ll e=n-1;
while(s<e){
    ll sum_ele=a[s].first+a[e].first;
   if(sum_ele==sum){
    cout<<a[s].second<<" "<<a[e].second<<'\n';
    return;
   }else if(sum_ele>sum){
    e--;
   }else{
    s++;
   }
}
cout<<"IMPOSSIBLE"<<'\n';

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}