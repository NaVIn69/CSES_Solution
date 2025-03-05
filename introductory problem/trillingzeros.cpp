#include<iostream>
// #include<gmpxx.h>
long long int factorial(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*factorial(n-1);
}
using namespace std;
int main(){
    int  n;
    cin>>n;
    int count=0;
    long long int k=factorial(n);
    cout<<k<<endl;
    while(k!=0){
        // int count=0;
        if(k%10==0){
         count++;
        }else{
            break;
        }
        k=k/10;
    }
    cout<<count<<endl;

}