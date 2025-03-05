#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[200200];
void solve(){
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>arr[i];
 }
 sort(arr,arr+n);

    int k=arr[n/2];
    int cost=0;
    for(int i=0;i<n;i++){
        cost+=abs(arr[i]-k);
    }
    cout<<cost<<endl;

  
}
signed main(){
    solve();
}