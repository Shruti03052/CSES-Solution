#include<bits/stdc++.h>
using namespace std;
vector<int> findPossible(int n,int m,vector<int> &price,vector<int> &cand_price){
    map<int,int> mpp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        mpp[price[i]]++;
    }
    for(int i=0;i<m;i++){
        auto idx=mpp.upper_bound(cand_price[i]);
        if(idx==mpp.begin()){
            ans.push_back(-1);
        }
        else{
            idx--;
            ans.push_back(idx->first);
            idx->second--;
            if(idx->second==0){
                mpp.erase(idx->first);

            }
        }
    }
    return ans;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> price(n);
    vector<int> cand_price(m);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        cin>> cand_price[i];
    }
    vector<int> ans=findPossible(n,m,price,cand_price);
    
    for(int i=0;i<m;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}