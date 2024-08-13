#include<bits/stdc++.h>
using namespace std;
long long int maxSum(int n,vector<int> &arr){
    long long int sum=0;
    long long int ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }

    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<< maxSum(n,arr);
    return 0;
}