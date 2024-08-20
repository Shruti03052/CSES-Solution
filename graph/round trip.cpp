#include<bits/stdc++.h>
using namespace std;


  bool dfs(int node,vector<int> &visited,vector<int> adj[],int parent,vector<int> &path){
        visited[node]=1;
        path.push_back(node);
        for(auto i:adj[node]){
             if(visited[i]==1 && parent!=i){
                return true;
            }
            else if(!visited[i]){
                if(dfs(i,visited,adj,node,path)){
                    return true;
                }
            }
            
        }
        
       
        path.pop_back();
        return false;
        
    }
void solve(int n,int m,vector<pair<int,int> > &conn){
     vector<int> adj[n+1];
    for(auto it:conn){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int> parent(n+1,-1);
    vector<int> visited(n+1,0);
   
   
   for(int i=1;i<=n;i++){
    if(!visited[i]){
        vector<int> path;
        if(dfs(i,visited,adj,-1,path)){
            cout<<path.size();
            return;
        }
    }
   }
   cout<<"IMPOSSIBLE";
       
    
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