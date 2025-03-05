#include<iostream>
using namespace std;
int main(){
    long n;
    cin>>n;
    if(n==1){
         cout<<"1"<<endl;
       return 0;
    }
    if(n==2||n==3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    int*a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    for(int i=1;i<n;i=i+2){
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n;i=i+2){
        cout<<a[i]<<" ";
    }
}