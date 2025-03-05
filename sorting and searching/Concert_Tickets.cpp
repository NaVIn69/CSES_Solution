#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int mod=1e9+7;
void solve(){
    int n,m;
    cin>>n>>m;
    int p[n],c[m];
    multiset<int>mt;
    for(int i=0;i<n;i++){
        cin>>p[i];
        mt.insert(p[i]);
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    //sort(p,p+n);
    for(int i=0;i<m;i++){
    
        int k=c[i];
        auto it=mt.lower_bound(k);
        if(it!=mt.end()&&*it==k){
            cout<<k<<endl;
            mt.erase(mt.find(k));
        }else if(it!=mt.end()&&it!=mt.begin()){
            it--;
            cout<<*it<<endl;
            mt.erase(it);
        }else if(mt.size()!=0&&it==mt.end()&&c[i]>*mt.rbegin()){
            cout<<*mt.rbegin()<<endl;
            int p=*mt.rbegin();
            mt.erase(mt.find(p));

        }else {
            cout<<"-1"<<endl;
        }
    }


}
signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
   // cin>>t;
    while (t--)
    {
        solve();
        /* code */
    }
    
}