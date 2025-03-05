#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> calculateZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            Z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                Z[i] = R-L; R--;
            }
        }
    }
    return Z;
}
void solve(){
    string s;
    cin>>s;
    vector<int>ans=calculateZ(s);
    int n=s.size();
    vector<int>v;
    int cmp=0;
    for(int i=ans.size()-1;i>=0;i--){
      if(ans[i]==(n-i)){
        cout<<ans[i]<<" ";
      }

    }
    cout<<endl;
    
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;


}
signed main(){
    solve();
}