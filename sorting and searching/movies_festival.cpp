#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        arr[i]={l,r};
    }
    sort(arr.begin(),arr.end());

}

signed main(){
    solve();
}