#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
ll n,k;
cin>>n>>k;
ll a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
// pointers
    ll head=-1,tail=0;
    // datastrcutre
    ll sum=k;

    ll ans = 0;
    // TP: O(N*(H+A+T))
    
    while(tail<n){
        // eat as many element as possible.
        while(head+1<n && (sum>=a[head+1])){
            // O(H)
            sum-=a[head+1];
            head++;
        }
        // save the current best length for this tail.
        // O(A)
        int len = head-tail+1;
      if(sum==0) ans++;
        // move tail one step forward.
        // O(T)
        if(tail<=head){
           sum+=a[tail];
            tail++;
        }else{ // when empty
            tail++;
            head = tail-1; // set window as 0 length empty.
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