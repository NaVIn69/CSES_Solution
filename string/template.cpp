#include<bits/stdc++.h>
using namespace std;
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
// here it is the kmp algo
vector<int> computePrefixFunction(string pattern) {
    int m = pattern.length();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k-1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}
struct manacher{
    vector<int>p;
     void run_manacher(string s){
        int n=s.length();
        p.assign(n,1);
        int l=1,r=1;
        // both l and r is exclusive 
        for(int i=1;i<n;i++){
            p[i]=max(0,min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i-p[i]]==s[i+p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
            l=i-p[i];
            r=i+p[i];
            }
        }
        for(auto v:p){
            cout<<v<<" ";
        }
        cout<<endl;
     }
    void build(string s){
        string t;
        for(auto v:s){
            t+=string("#")+v;
        }
        run_manacher(t+"#");
    }
    // abbabba
    // char odd centred
    // char ke bich even centred

    int getlongest(int cen,bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos]-1;
    }
  // both l and r have same parity then odd length
  // both l and r have differnt parity then even length
    bool checkpalin(int l,int r){
        if(r+l-1<=getlongest((r+l)/2,r%2==l%2)){
            return 1;
        }else{
            return 0;
        }
    }
}m;
struct hasher{
    int n, _k, _p;
    vector<int> powk,base,rev;
 
    void init(string s,int k,int p){
        _k = k, _p = p;
        n = s.length();
        powk.resize(n+1);
        base.resize(n+1);
        // precompute
        base[0] = 0;
        powk[0] = 1;
        for(int i=0;i<n;i++){
            int num = (s[i]-'a'+1 )%p;
            base[i+1] = (1LL *base[i] * k + num)%p;
            powk[i+1] = (1LL* k * powk[i]) %p;
        }
        //rev;
        rev.resize(n+1);
        rev[n]=0;
        for(int i=n-1;i>=0;i--){
            int num = (s[i]-'a'+1 )%p;
            rev[i] = (1LL *rev[i+1] * k + num)%p;
        }

    }  
    int gethash(int l,int r){ // 0 index
        int ans = (base[r+1] - 1LL *base[l]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
    int getrevhash(int l,int r){ // 0 based index
         int ans = (rev[l] - 1LL *rev[r+1]*powk[(r-l+1)])%_p;
        return (ans+_p)%_p;
    }
};
 
 struct double_hash{
    hasher a,b;
    void init(string s){
        a.init(s,37,1e9+21);
        b.init(s,39,1e9+7);
    }
    pair<int,int>gethash(int l,int r){
        return {a.gethash(l,r),b.gethash(l,r)};
    }
    pair<int,int>getrevhash(int l,int r){
        return {a.getrevhash(l,r),b.getrevhash(l,r)};
    }
    bool is_palin(int l,int r){
        return gethash(l,r)==getrevhash(l,r);
    }

 };

signed main(){
  
}