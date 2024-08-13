#include<bits/stdc++.h>
using namespace std;
vector<int> four_sum(int n,int x,vector<int> arr){
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++){
        vec[i]={arr[i],i};
    }
    vector<int> ans;
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++){
        while(i!=0 and vec[i].first ==vec[i-1].first){
            continue;
        }
        for(int j=i+1;j<n;j++){
             while(j>i+1 and vec[j].first ==vec[j-1].first){
            continue;
            
        }
            int k=j+1;
            int m=n-1;
            while(k<m){
                int sum=vec[i].first+vec[j].first+vec[k].first+vec[m].first;
                if(sum>x){
                    m--;
                    
                }
                else if(sum<x){
                    k++;
                   
                }
                else{
                    ans.push_back(vec[i].second+1);
                    ans.push_back(vec[j].second+1);
                    ans.push_back(vec[k].second+1);
                    ans.push_back(vec[m].second+1);
                    return ans;

                }
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

    vector<int>  ans=four_sum(n,x,arr);
    if(ans.size()==0){
       cout<<"IMPOSSIBLE";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
  
    return 0;
}