#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n;
int arr[200200];
pair<int,int>brr[200200];
bool check(int mid){
    // can we collect the all number in the mid rounds
    int cnt=1;
    for(int i=1;i<n;i++){
        if(brr[i].second>brr[i-1].second){
            continue;
        }else{
            cnt++;
        }
    }
   
    if(cnt<=mid) return 1;
    return 0;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    brr[i]={arr[i],i};
  }
  sort(brr,brr+n); 
  int l=0;
  int h=n;
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