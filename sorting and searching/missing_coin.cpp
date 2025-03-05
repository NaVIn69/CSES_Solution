#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[100100];

bool check(int mid){

}
void solve(){
  cin>>n;
  int mini=INT_MAX;
  int tot=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mini=min(mini,arr[i]);
    tot+=arr[i];
  }
  sort(arr,arr+n);
  int l=mini;
  int h=tot;
  int ans=0;
  while(l<=h){
    int mid=(l+h)/2;
    if(check(mid)){
      ans=mid;
      h=mid-1;
    }else{
        l=mid+1;
    }
  }
  cout<<ans<<endl;

}
signed main(){
    solve();
}