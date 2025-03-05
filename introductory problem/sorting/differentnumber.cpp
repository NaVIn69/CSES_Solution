#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int count=1;
    for(int i=0;i<n;i++){
        if(i==0) continue;
        if(a[i]==a[i-1]) continue;
        else count++;
    }
    cout<<count<<endl;
}