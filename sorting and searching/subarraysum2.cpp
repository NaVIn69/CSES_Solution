#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[1000001];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int>mpp;
    int sum=0;
    int cnt=0;
    mpp[sum]=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        int find=sum-x;
        if(mpp.find(find)!=mpp.end()){
            cnt+=mpp[find];
        }
        mpp[sum]++;
    }
    cout<<cnt<<endl;
}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while(t--){
        solve();
    }
}