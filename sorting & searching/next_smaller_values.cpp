#include<bits/stdc++.h>
using namespace std;
vector<int> next_smaller_values(int n,vector<int> arr){
   stack<pair<int,int>> st;
   vector<int> ans(n);
   for(int i=0;i<n;i++){
    if(st.empty()){
        ans[i]=0;
        st.push({arr[i],i});
    }
    else if(st.top().first < arr[i]){
        ans[i]=st.top().second+1;
        st.push({arr[i],i});
    }
    else{
        while(!st.empty()){
            if(st.top().first >=arr[i]){
                st.pop();

            }
            else{
                break;
            }
        }
        if(st.empty()){
            ans[i]=0;
        }
        else{
            ans[i]=st.top().second+1;
        }
        st.push({arr[i],i});

    }  
    
   }
   return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    vector<int> ans=next_smaller_values(n,arr);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}