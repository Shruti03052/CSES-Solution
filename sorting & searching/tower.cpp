#include<bits/stdc++.h>
using namespace std;
int maxTowers(int n,vector<int> &arr){
    multiset<int>s;
    s.insert(arr[0]);
    int cnt=1;
    for(int i=1;i<n;i++){
        auto upper_bnd=s.upper_bound(arr[i]);
        if(upper_bnd==s.end()){
            s.insert(arr[i]);
            cnt++;
        }
        else{
            s.erase(s.find(*upper_bnd));
            s.insert(arr[i]);

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
    cout<<maxTowers(n,arr);
    return 0;
}