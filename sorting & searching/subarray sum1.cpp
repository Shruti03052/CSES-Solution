#include<bits/stdc++.h>
using namespace std;
int subarray_sum(int n,vector<int> arr,int x){
    int i=0;
    int j=0;
    long long int sum=0;
    int cnt=0;
    while(j<n){
        sum+=arr[j];
        while(sum>x && i<j){
            sum-=arr[i];
            i++;
        }
        if(sum==x){
            cnt++;
        }
        j++;
    }
    return cnt;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    cout<< subarray_sum(n,arr,x);
    return 0;
}