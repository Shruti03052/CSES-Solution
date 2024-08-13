#include<bits/stdc++.h>
using namespace std;
long long int divisible_subarray(long long int n,vector<long long int> arr){
    
    long long int j=0;
    long long int sum=0;
    long long int cnt=0;
    map<int,int> m;
    m[0]=1;
    while(j<n){
       sum+=arr[j];
       int rem=sum%n;
       if(rem<0){
        rem=rem+n;
       }
       if(m.find(rem)==m.end()){
        m[rem]=1;


       }
       else{
        cnt+=m[rem];
        m[rem]+=1;
       }
       j++;


    }
    return cnt;
}
int main(){
    long long int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< divisible_subarray(n,arr);

    return 0;
}
