#include<bits/stdc++.h>
using namespace std;
long long int divisible_subarray(long long int n,vector<long long int> arr){
    long long int i=0;
    long long int j=0;
    long long int sum=0;
    long long int cnt=0;
    while(j<n){
        sum+=arr[j];
        while(i<j && sum>n && sum%n!=0){
            sum-=arr[i];
            i++;
        }
        if(sum%n==0){
            cnt++;
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