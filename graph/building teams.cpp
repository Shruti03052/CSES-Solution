#include<bits/stdc++.h>
using namespace std;
  bool dfs(int node,vector<int> adj[], int clr,vector<int> &color){
    
    color[node]=clr;
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,adj,!clr,color)==false){
                return false;
            }
        }
        else{
            if(color[it]==clr){
                return false;
            }

        }
        
    }
    return true;
  }
void solve(int n,int m,vector<pair<int,int> > &conn){
    
    vector<int> adj[n+1];
    for(auto it:conn){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int> color(n+1,-1);
   for(int i=1;i<=n;i++){
    if(color[i]==-1){
        if(dfs(i,adj,0,color)==false){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
   }
   
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            cout<<2<<" ";
        }
        else{
            cout<<color[i]<<" ";
        }
    }
   
    

    

}
int main(){
    int n,m;
    cin>>n >>m;
    vector<pair<int,int> > conn(m);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        conn[i]={x,y};

    }
    solve(n,m,conn);
    return 0;
}