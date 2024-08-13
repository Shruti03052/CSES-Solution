#include<bits/stdc++.h>
using namespace std;
class comp{
    public:
    bool operator()(pair<int,int> a,pair<int,int>b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        else{
            return a.first<b.first;
        }


    }
};
vector<int>  ifContains(int n,vector<pair<int,int>> arr){
   vector<int> contains(n);
   
   map<pair<int,int>,int>m;
   for(int i=0;i<n;i++){
    m[arr[i]]=i;
   }
   int mini=INT_MAX;
   sort(arr.begin(),arr.end(),comp());
   for(int i=n-1;i>=0;i--){
    if(arr[i].second>=mini){
        contains[m[arr[i]]]=1;
    }
    mini=min(mini,arr[i].second);
   }
   return contains;
   
}
vector<int> ifcontained(int n,vector<pair<int,int>> arr){
    vector<int> contained(n);
   
   map<pair<int,int>,int>m;
   for(int i=0;i<n;i++){
    m[arr[i]]=i;
   }
   int maxi=INT_MIN;
   sort(arr.begin(),arr.end(),comp());
   for(int i=0;i<n;i++){
    if(arr[i].second<=maxi){
        contained[m[arr[i]]]=1;
    }
    maxi=max(maxi,arr[i].second);
   }
   return contained;
   
}
int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        arr[i]={x,y};
    }
    vector<int> ans=ifContains(n,arr);
    for(int i=0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    cout<<"\n";
    vector<int> ans2=ifcontained(n,arr);
     for(int i=0;i<n;i++){
        cout<<ans2[i] <<" ";
    }


    return 0;
}