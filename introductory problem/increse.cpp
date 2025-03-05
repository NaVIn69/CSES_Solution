#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int*a=new int[n];
   long long m=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
         if(i==0){ continue;}
        if(a[i]>a[i-1]){
            continue;;
        }else{
         long long k=a[i-1]-a[i];
           m=m+k;
           a[i]=a[i-1];

        }
    }
    cout<<m<<endl;
}