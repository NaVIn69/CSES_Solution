#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
ll n,k;
cin>>n>>k;
ll a[n];
for(ll i=0;i<n;i++){
    cin>>a[i];
}
// take two pointer
ll head=-1, tail=0;
 // data structure is used 
 map<int,int>mpp;
 ll dist_cnt=0;

 // ans to store
 ll ans=0;

 while(tail<n){
    // eat as many as possible element
    while(head+1<n && (mpp[a[head+1]]!=0 || dist_cnt<k)){
        if(mpp[a[head+1]]==0) dist_cnt++;
        mpp[a[head+1]]++;
        head++;
    }
    // store the best answer for this tail
    int len=head-tail+1;
    // update ans
    ans+=len;
    // move the tail one step forward
    if(tail<=head){
        mpp[a[tail]]--;
        if(mpp[a[tail]]==0) dist_cnt--;
        tail++;
    }else{
        tail++;
        head=tail-1;
    }
 }
 cout<<ans<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}