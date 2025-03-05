#include<bits/stdc++.h>
using namespace std;
void solve(){
   int n,x;
   cin>>n>>x;
   int arr[n];
   pair<int,bool>brr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
    brr[i]={arr[i],false};
   }
 sort(arr,arr+n);
 sort(brr,brr+n);
  int cnt=0;
  for(int i=0;i<n;i++){
    if(brr[i].second) continue;
    int rem=x-arr[i];
    int idx=lower_bound(arr+i,arr+n,rem)-arr;
    if(arr[idx]==rem){
        brr[idx].second=true;
        cnt++;
    }else{
        idx--;
        brr[idx].second=true;
        cnt++;
    }
  }
  cout<<cnt<<endl;

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}