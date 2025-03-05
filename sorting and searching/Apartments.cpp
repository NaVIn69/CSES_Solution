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
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
         v.push_back({a[i]-k,a[i]+k});
    }
   sort(b,b+m);
    int ans=0;
    int count=0;
    int s=0;
    int check=-1;
    for(int i=0;i<m;i++){
        int target=b[i];
        s=check+1;
        int e=v.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
        if(target>=v[mid].first&&target<=v[mid].second){
            e=mid-1;
            ans=1;
            check=mid;
        }else if(target>v[mid].second){
            s=mid+1;
        }else if(target<v[mid].first){
            e=mid-1;
        }
        }
        count+=ans;
        ans=0;
    }
    cout<<count<<endl;

}
int main(){
    int t=1;
    while(t--){
    solve();
    }
}