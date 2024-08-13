#include<bits/stdc++.h>
using namespace std;
pair<int,int > check(int n,int x,vector<pair<int,int>>& arr){
    
    sort(arr.begin(),arr.end());
    int i=0;
    int j=n-1;
    pair<int,int>ans;
    while(i<j){
        if(arr[i].first+arr[j].first==x){
            return {arr[i].second+1,arr[j].second+1};
        }
        else if(arr[i].first+arr[j].first<x){
            i++;
        }
        else{
            j--;
        }
    }
    return {-1,-1};
}
int main(){
    int n,x;
    cin>>n>>x;
    int ele;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>ele;
        arr[i]={ele,i};
    }
    pair<int,int> ans=check(n,x,arr);
    if(ans.first==-1 && ans.second==-1){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<ans.first<< " "<<ans.second;
    }
    return 0;
}