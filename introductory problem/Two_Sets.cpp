#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main(){
    int n;
    cin>>n;
    set<int>st;
    int ans=n*(n+1)/2;
    if(ans%2!=0){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int sum=0;
        int target=ans/2;
        int i=n;
        while(sum<target){
            sum+=i;
            st.insert(i);
            i--;
        }
        if(sum>target){
            sum-=*st.begin();
            st.erase(*st.begin());
            int find=target-sum;
            st.insert(find);
       
        }
        cout<<st.size()<<endl;
        for(auto it=st.begin();it!=st.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        cout<<n-st.size()<<endl;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                cout<<i<<" ";
            }
        }
        cout<<endl;

    }
   
}