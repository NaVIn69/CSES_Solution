#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve(){
int c1,c2;
cin>>c1>>c2;
int maxi=max(c1,c2);
int mini=min(c1,c2);
if(maxi>2*mini){
    cout<<"NO"<<endl;
    return;
}
int a1=2,b1=1,a2=1,b2=2;
int d=3;
int k1=a1*c2-a2*c1;
int k2=b1*c2-b2*c1;
if(k1%d==0&&k2%d==0){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}

}
signed  main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}