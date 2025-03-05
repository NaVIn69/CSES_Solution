#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[1000001];
int n,t;
bool check(int x){
    int total_product=0;
    for(int i=0;i<n;i++){
        total_product+=(x/arr[i]);
        if(total_product>=t){
            return 1;
        }
    }
    return 0;
}
void solve(){
cin>>n>>t;

for(int i=0;i<n;i++){
    cin>>arr[i];
}
int l=0;
int hi=arr[0]*t;
int ans=hi;
while(l<=hi){
    int mid=l+(hi-l)/2;
    if(check(mid)){
        ans=mid;
        hi=mid-1;
    }else{
        l=mid+1;
    }
}
cout<<ans<<endl;

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