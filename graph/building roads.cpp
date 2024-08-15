#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &visited,vector<int> adj[]){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj);
        }
    }
    

}
void solve(int n,int m,vector<pair<int,int>> &roads){
    vector<int> visited(n+1);
    int comp=0;
    vector<int> adj[n+1];
    for(auto it:roads){
        int u=it.first;
        int v=it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
   
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ans.push_back(i);
            
          
            comp+=1;
            dfs(i,visited,adj);
            
        }

    }
    cout << comp-1<<endl;
    for(int i=1;i<comp;i++){
        cout<< ans[i-1]<<" "<< ans[i]<<endl;
    }
   

}
int main(){
    int n, m;
    cin>>n >> m;
    int x,y;
    vector<pair<int,int>> roads(m);
    for(int i=0;i<m;i++){
        cin>>x >>y;
        roads[i]={x,y};
    }
    solve(n,m,roads);
    return 0;

}