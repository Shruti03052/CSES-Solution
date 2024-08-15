#include<bits/stdc++.h>
using namespace std;



void solve(int n,int m, vector<pair<int,int>> &msg){
    vector<int> adj[n+1];
    vector<int> visited(n+1);
    vector<int> parent(n+1,-1);
    for(auto it:msg){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int> dist(n+1,INT_MAX);
    queue<pair<int,int> > q;
    q.push({0,1});
    visited[1]=1;
    dist[1]=0;

    while(!q.empty()){
        int d=q.front().first;
        int node=q.front().second;
        
        q.pop();
        if(node==n){
            vector<int> path;
            for(int i=n;i!=-1;i=parent[i]){
                path.push_back(i);           
            }
            reverse(path.begin(),path.end());
            cout<<path.size()<<endl;
            for(auto it:path){
                cout<<it<<" ";
            }
            return;
        }
        
        for(auto it:adj[node]){
            if(!visited[it] && d+1<dist[it]){
                q.push({d+1,it});
                dist[it]=d+1;
                visited[it]=1;
                parent[it]=node;

            }
        }
    


    }
   
    
        cout<<"IMPOSSIBLE"<<endl;
    

}
int main(){
    int n, m;
    cin>>n >> m;
    int x,y;
    vector<pair<int,int>> msg(m);
    for(int i=0;i<m;i++){
        cin>>x >>y;
       msg[i]={x,y};
    }
    solve(n,m,msg);
    return 0;

}