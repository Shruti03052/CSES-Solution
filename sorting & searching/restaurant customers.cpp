#include<bits/stdc++.h>
using namespace std;
int findMaxCustomer(int n,vector<pair<int,int> > &arr){
    vector<int> arrival(n);
    vector<int> depart(n);
    for(int i=0;i<n;i++){
        arrival[i]=arr[i].first;
        depart[i]=arr[i].second;
    }
    sort(arrival.begin(),arrival.end());
    sort(depart.begin(),depart.end());
    int i=1;int j=0;
    int cnt=1;
    int ans=1;
    while(i<n && j<n){
        if(arrival[i]<=depart[j]){
            cnt++;
            ans=max(ans,cnt);
            i++;
        }
        else{
            cnt--;
            j++;
        }
    }
    return ans;
}
int main(){
    int n, arriv, dept;
    cin>>n;
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++){
        cin >> arriv >> dept;
        arr[i] = {arriv,dept};
    }
    cout<< findMaxCustomer(n,arr);
    return 0;
}