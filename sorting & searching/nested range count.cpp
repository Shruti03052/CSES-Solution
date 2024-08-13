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
vector<int> ifContains(int n,vector<pair<int,int>> arr){
    vector<int> ends;
    map<pair<int, int>, int> m;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        m[arr[i]] = i;
        ends.push_back(arr[i].second);
    }
    
    sort(arr.begin(), arr.end(), comp());
    sort(ends.begin(), ends.end());

    for (int i = n - 1; i >= 0; i--) {
        int end = arr[i].second;
        int count = distance(ends.begin(), upper_bound(ends.begin(), ends.end(), end));
        ans[m[arr[i]]] = count;
    }
    
    return ans;
}
vector<int> ifcontained(int n,vector<pair<int,int>> arr){
    multiset<int> s;
     map<pair<int,int>,int>m;
   for(int i=0;i<n;i++){
    m[arr[i]]=i;
   }
   vector<int> ans(n);
   int maxi=INT_MIN;
   sort(arr.begin(),arr.end(),comp());
   for(int i=0;i<n;i++){
    int cnt=distance(s.lower_bound(arr[i].second),s.end());
    ans[m[arr[i]]]=cnt;
   
    s.insert(arr[i].second);
   }
   return ans;
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