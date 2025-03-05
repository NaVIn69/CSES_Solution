#include<bits/stdc++.h>
using namespace std;
void solve(){
string a;
cin>>a;
int cnt=1;
int ans=INT_MIN;
for(int i=0;i<a.size();i++){
    if(i==a.size()-1){
        continue;
    }
    if(a[i]==a[i+1]){
        cnt++;
    }else{
        ans=max(cnt,ans);
        cnt=1;
    }
}
ans=max(ans,cnt);
cout<<ans<<endl;
}
int main(){
  solve();
}