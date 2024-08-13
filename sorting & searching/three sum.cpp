#include<bits/stdc++.h>
using namespace std;
vector<int>  three_sum(int n,int x,vector<int> arr){
   
    vector<int> ans;
    vector<pair<int,int> > vec(n);
    for(int i=0;i<n;i++){
        vec[i]={arr[i],i};
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=vec[i].first+vec[j].first+vec[k].first;
            if(sum>x){
                k--;
                while(vec[k].first==vec[k+1].first){
                    k--;
                }
            }
            else if(sum<x){
                j++;
            }
            else {
                ans.push_back(vec[i].second+1);
                ans.push_back(vec[j].second+1);
                ans.push_back(vec[k].second+1);
                return ans;
            }
        }
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int>  ans=three_sum(n,x,arr);
    if(ans.size()==0){
       cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0 ;
}