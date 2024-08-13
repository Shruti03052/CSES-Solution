#include<bits/stdc++.h>
using namespace std;
long long int missingSum(int n,vector<int> &arr){
    sort(arr.begin(),arr.end());
    long long int sum=1;
    for(int i=0;i<n;i++){
        if(arr[i]>sum){
            return sum;

        }
        else{
            sum+=arr[i];
        }
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< missingSum(n,arr);
    return 0;
}