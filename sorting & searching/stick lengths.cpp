#include<bits/stdc++.h>
using namespace std;
long long int minCost(int n,vector<int> &arr){
    long long int mid=n/2;
    sort(arr.begin(),arr.end());
    long long int cost=0;
    
    for(long long int i=0;i<n;i++){
        cost+=abs(arr[i]-arr[mid]);

    }
    
    return cost;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    cout<< minCost(n,arr);
    return 0;
}