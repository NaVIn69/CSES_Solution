#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    for(auto&i:a)cin>>i;
    int b[m];
    for(auto&i:b)cin>>i;
    sort(a,a+n);
   sort(b,b+m);
   int i=0;
   int j=0;
   int ans=0;
   while(i<n&&j<m){
    if(abs(a[i]-b[j])<=k){
        i++;
        j++;
        ans++;
    }else {
        if(a[i]-b[j]>k){
            j++;
        }else{
            i++;
        }
    }
   }
   cout<<ans<<endl;
    
}
int main(){
    int t=1;
    while(t--){
    solve();
    }
}