#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000000];

void solve(){
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort(arr,arr+n);
if(arr[0]!=1){
    cout<<"1"<<endl;
    return;
}

int prefix_sum=0;
for(int i=0;i<n;i++){
    if(arr[i]>prefix_sum+1){
        cout<<prefix_sum+1<<endl;
        return;
    }
    prefix_sum+=arr[i];
}
cout<<prefix_sum+1<<endl;



}
signed main(){
    solve();
}