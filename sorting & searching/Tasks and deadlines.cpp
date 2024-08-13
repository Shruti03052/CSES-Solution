#include<bits/stdc++.h>
using namespace std;
long long int reward(int n,vector<pair<int,int> > arr){
    sort(arr.begin(),arr.end());
    long long int tim=0;
   long long int ans=0;
    for(int i=0;i<n;i++){
        tim+=arr[i].first;
        ans+=(arr[i].second-tim);

    }
    return ans;

}
int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++){
       cin>>x;
       cin>>y;
       arr[i]={x,y};
    }
    cout<< reward(n,arr);
    return 0;
}