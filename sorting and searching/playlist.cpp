#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
int n;
int arr[200200];
bool check(int mid){

    // here we check can we find the one subarray of length mid with all distnict element
    map<int,int>mpp;
    int cnt=0;
    int ans=0;
    for(int i=0;i<mid;i++){
        if(mpp.find(arr[i])==mpp.end()){
            cnt++;
        }else{
        
            cnt=i-mpp[arr[i]];
            ans=max(ans,cnt);
        }
        mpp[arr[i]]=i;
        
    }
    ans=max(ans,cnt);
  
    if(ans>=mid) return 1;
  for(int i=0;i<n-mid;i++){
    mpp[arr[i]]--;
    if(mpp[arr[i]]==0){
        cnt--;
    }
    if(mpp.find(arr[i+mid])==mpp.end()){
        cnt++;
    }else{
        cnt=i-mpp[arr[i]];
        // ans=max(ans,cnt);
    }
    ans=max(ans,cnt);
    mpp[arr[i]]=i;
  }
  ans=max(ans,cnt);
  if(ans>=mid) return 1;
  else return 0;
 

}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mid=4;
     map<int,int>mpp;
    int cnt=0;
    int ans=0;
    for(int i=0;i<mid;i++){
        if(mpp.find(arr[i])==mpp.end()){
            cnt++;
        }else{
        
            cnt=i-mpp[arr[i]];
            ans=max(ans,cnt);
        }
        mpp[arr[i]]=i;
        
    }
    ans=max(ans,cnt);
    // cout<<ans<<endl;
    // cout<<cnt<<endl;
  
    // if(ans>=mid) return 1;
    // here cnt tells me the unique element in mid range 
  for(int i=0;i<n-mid;i++){

   if(mpp[arr[i]]==i){
    cnt--;
   }
    if(mpp.find(arr[i+mid])==mpp.end()){
        cout<<arr[i]<<endl;
        cnt++;
    }else{
        cnt=i-mpp[arr[i]];
        // ans=max(ans,cnt);
    }
    ans=max(ans,cnt);
    mpp[arr[i]]=i;
    // cout<<arr[i]<<" "<<ans<<endl;
  }
  ans=max(ans,cnt);
//    cout<<ans<<endl;
 
    //  int l=1;
    //  int h=n;
    //  int ans=1;
    //  while(l<=h){
    //     int mid=l+(h-l)/2;
    //     cout<<mid<<endl;
    //     if(check(mid)){
    //       ans=mid;
    //       l=mid+1;
    //     }else{
    //         h=mid-1;
    //     }
    //  }
    //  cout<<ans<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}