#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(int n,int m,vector<vector<ll> > conn){
    vector<ll> dist(n+1,LLONG_MAX);
    priority_queue<pair<ll,ll> , vector<pair<ll,ll> > ,greater<pair<ll,ll> > >q;
    vector<pair<ll,ll>> adj[n+1];
    for(auto it:conn){
        ll u=it[0];
        ll v=it[1];
        ll t=it[2];
        adj[u].push_back({v,t});
    }
    q.push({0,1});
    dist[1]=0;
    while(!q.empty()){
       ll node=q.top().second;
        ll tim=q.top().first;
        q.pop();
         if (tim > dist[node]) continue;
        for(auto it:adj[node]){
            if(tim+it.second<dist[it.first]){
                q.push({tim+it.second,it.first});
                dist[it.first]=tim+it.second;
            }

        }
    }
    for(ll i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

}
int main(){
   ll n,m;
    cin>>n>>m;
    vector<vector<ll> > conn(m,vector<ll> (3));
    int u,v,t;
    for(ll i=0;i<m;i++){
        cin>>u>>v>>t;
        conn[i]={u,v,t};
    }
    solve(n,m,conn);
    return 0;

}