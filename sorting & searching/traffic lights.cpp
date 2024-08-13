#include<bits/stdc++.h>
using namespace std;
vector<int> maxLen(int n,int x,vector<int> &arr){
    set<pair<int,int> >s;
    s.insert({0,x});
    multiset<int> len_range;
    vector<int> ans;
    len_range.insert(x);
    for(int i=0;i<n;i++){
        auto idx=s.upper_bound({arr[i],0});
        idx--;
        int start=idx->first;
        int end=idx->second;
        s.erase(idx);
        s.insert({start,arr[i]});
        s.insert({arr[i],end});
        len_range.erase(len_range.find(end-start));
        len_range.insert(arr[i]-start);
        len_range.insert(end-arr[i]);
        ans.push_back(*len_range.rbegin());

    }
    return ans;


}
int main(){
    int n,x;
    cin>>x >>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans=maxLen(n,x,arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";

    }

    return 0;
}