#include<bits/stdc++.h>
using namespace std;
string check_palindrome(string s){
    map<char,int>mpp;
    for(int i=0;s[i]!='\0';i++){
        mpp[s[i]]++;
    }
    string s_odd_freq="";
    string s_even_freq="";
    if(mpp.size()==1){
        return s;
    }else{
        int cnt=0;
        for(auto x:mpp){
            if(x.second%2!=0){
                while(x.second--){
                    s_odd_freq+=x.first;
                }
                cnt++;
            }else{
                int k=x.second/2;
                while(k--){
                    s_even_freq+=x.first;
                }
            }
           
        }
    }
   string str=s_even_freq;
   reverse(s_even_freq.begin(),s_even_freq.end());
   
   string ans="";
   ans=ans+s_even_freq+s_odd_freq+str;
   string ans1=ans;
   reverse(ans.begin(),ans.end());
   if(ans==ans1){
    return ans1;
   }else{
    return "NO SOLUTION";
   }

}
void solve(){
    string s;
    cin>>s;
  string ans=check_palindrome(s);
  if(ans=="NO SOLUTION"){
    cout<<"NO SOLUTION"<<endl;
  }else{
    cout<<ans<<endl;
  }

}
int main(){
   solve();
}