#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
int n,target;
cin>>n>>target;
int a[n];
vector<pair<int,int>>v(n,{0,0});
for(int i=0;i<n;i++){
    cin>>a[i];
    v[i].first=a[i];
    v[i].second=i+1;
}
sort(v.begin(),v.end());
   // int ans=LONG_LONG_MAX;
    for(int j=0;j<n;j++){
        int i=0;
        int k=n-1;
        //int sum=0;
        while(i<j&&j<k){
             
             int sum=v[i].first+v[j].first+v[k].first;
            if(sum==target){
                cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<" "<<endl;
                return;
            }else if(sum>target){
               k--;
            }else{
                i++;
            }
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}