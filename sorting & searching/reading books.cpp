#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll time_taken(ll n,vector<ll> arr){
    sort(arr.begin(),arr.end());
    ll sum=accumulate(arr.begin(),arr.end()-1,0ll);
    ll maxi=arr[n-1];
    if(sum< maxi){
        return 2*maxi;
    }
    else{
        return maxi+accumulate(arr.begin(),arr.end()-1,0ll);
    }

}
int main(){
   ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>> arr[i];

    }
    cout<<time_taken(n,arr);
    return 0;
}