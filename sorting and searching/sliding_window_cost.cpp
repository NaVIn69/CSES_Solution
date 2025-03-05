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
vector<int>v;
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
   v.push_back(ans);
}else{
    int l=*low.rbegin();;
    v.push_back(l);
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
        v.push_back(*low.rbegin());
    }else{
        int ans=min(*low.rbegin(),*high.begin());
        v.push_back(ans);
    }
    int cost=0;
     for(int j=i;j<i+k;j++){
        cost+=abs(a[j]-v[i]);
    }
    cout<<cost<<" ";
}
int ans=0;
for(int i=n-1;i>=(n-k);i--){
    ans+=abs(a[i]-v[v.size()-1]);
}
cout<<ans<<endl;
//int cost=0;

/*for(int i=0;i<n-k+1;i++){
    int cost=0;
    for(int j=i;j<i+k;j++){
        cost+=abs(a[j]-v[i]);
    }
    cout<<cost<<" ";
}*/



}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}