#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
   int n;
   cin>>n;
   vector<pair<int,int>>event;
   for(int i=0;i<n;i++){
      int l,r;
      cin>>l>>r;
      event.push_back({l,1});
      event.push_back({r,-1});
   }
   sort(event.begin(),event.end());
//    for(int i=0;i<2*n;i++){
//     cout<<event[i].first<<" "<<event[i].second<<endl;
//    }
   int maxi=0;
   int cnt=0;
   for(int i=0;i<2*n;i++){
      cnt+=event[i].second;
      maxi=max(cnt,maxi);

   }
   cout<<maxi<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}