#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
/*
if(k==1){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}*/
multiset<int>low;
multiset<int>high;
// first window
for(int i=0;i<k;i++){
    if(low.empty()) low.insert(a[i]);
    else if(a[i]>*low.rbegin()) high.insert(a[i]);
    else low.insert(a[i]);
    if(low.size()>high.size()+1){
        int p=*low.rbegin();
        high.insert(p);
        low.erase(low.find(p));
    }
    if(low.size()<high.size()){
        int k=*high.begin();
        low.insert(k);
        high.erase(high.find(k));
    }
}
if(k%2==0){
   int ans=min(*low.rbegin(),*high.begin());
   cout<<ans<<" ";
}else{
    cout<<*low.rbegin()<<" ";
}
for(int i=0;i<n-k;i++){
    if(a[i+k]>*low.rbegin()) high.insert(a[i+k]);
    else low.insert(a[i+k]);
    if(a[i]>*low.rbegin()) high.erase(high.find(a[i]));
    else low.erase(low.find(a[i]));
    if(low.size()>high.size()+1){
        int p=*low.rbegin();
        high.insert(p);
        low.erase(low.find(p));
    }
    if(low.size()<high.size()){
        int k=*high.begin();
        low.insert(k);
        high.erase(high.find(k));
    }

    if(k%2){
        cout<<*low.rbegin()<<endl;
    }else{
        int ans=min(*low.rbegin(),*high.begin());
        cout<<ans<<" ";
    }
}
cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}