#include<bits/stdc++.h>
using namespace std;

long long int subarray_sum(int n,vector<long long int> arr,int x){
    map<long long int,long long int> m;
    long long int presum=0;
    m[0]=1;
    long long int cnt=0;
    for(long long int i=0;i<n;i++){
        presum+=arr[i];
        long long int rem=presum-x;
        cnt+=m[rem];
        m[presum]+=1;

    }
    return cnt;
}
int main(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int> arr(n);
    for(long long int i=0;i<n;i++){
        cin>> arr[i];
    }
    cout<< subarray_sum(n,arr,x);
    return 0;
    
}