#include<bits/stdc++.h>
using namespace std;
// int main(){
//     long long int n,number,sum=0;
//     cin>>n;
//     for(int i=0;i<n-1;i++){
//         cin>>number;
//    sum+=number;
//     }
//     cout<<n*(n+1)/2-sum<<" ";
//     return 0;
// }
 int missingnumber(vector<int>&arr){
     sort(arr.begin(),arr.end());
     int s=1 ;
     int e=arr.size();
     while(s<=e){
        int mid=(s+e)/2;
         if(arr[mid]==mid){
             s=mid+1;
         }else{
             e=mid-1;
         }
     }
     return s;
 }
 int main(){
     int n;
     cin>>n;
     int*arr=new int[n-1];
     for(int i=0;i<n-1;i++){
         cin>>arr[i];
    }
     int m=missingnumber(arr);
     cout<<m;

 }