#include<bits/stdc++.h>
using namespace std;
int findMaxRounds(int n,vector<int> &arr){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]=i;
    }
    int cnt=1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(m[i]<m[i+1] ){
            continue;

        }
        else{
            cnt++;

        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< findMaxRounds(n,arr);
    return 0;
}