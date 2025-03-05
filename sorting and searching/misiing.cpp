#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000000];
bool check(int mid){
    sort(a,a+n);
    int cnt=0;
    map<int,int>mpp;
    for(int i=1;i<(1<<18);i++){
        int sum=0;
        // subset ka sum pata chal rha hai
        for(int j=0;j<n;j++){
            if((i>>j)&1){
            sum+=a[j];
            }
        }
       
        
        if(sum<=mid){
            if(mpp[sum]==0){
            mpp[sum]++;
            cnt++;
            }
        }
        
        if(sum>mid){
           break;
        }
    
 
    }
    return cnt==mid;
}
void solve(){
cin>>n;
int e=0;
for(int i=0;i<n;i++){
    cin>>a[i];
    e+=a[i];
}
int sum=e;
int s=1;
int ans=1;
while(s<=e){
    int mid=s+(e-s)/2;
    if(check(mid)){
        ans=mid;
       s=mid+1;
    }else{
       e=mid-1;
    }
}
if(ans==sum){
cout<<ans+1<<endl;
}else{
    cout<<ans<<endl;
}
 
}
signed main(){
    solve();
}