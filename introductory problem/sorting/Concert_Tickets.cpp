#include<bits/stdc++.h>
using namespace std;
int price_get(int*a,int n,int k){
    int l=0;
    int h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]<=k){
          ans=mid;
          l=mid+1;
        }else{
            h=mid-1;
        }
    }
    if(ans!=-1){
        return a[ans];
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    //price of ticket
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    //maximum price wiiling to pay by coustmer
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        cout<<price_get(a,n,b[i])<<endl;
    }

}
int main(){
    solve();
}