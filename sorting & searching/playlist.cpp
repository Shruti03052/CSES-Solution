#include<bits/stdc++.h>
using namespace std;
int maxuniquePlaylist(int n,vector<int> &arr){
    map<int,int> m;
    int start=0;
    int end=0;
    int ans=0;
    while(end<n){
       m[arr[end]]++;
       while(m[arr[end]]>1){
        m[arr[start]]--;
        start++;
       }
       ans=max(ans,end-start+1);
       end++;

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
    cout<< maxuniquePlaylist(n,arr);
    return 0;
}