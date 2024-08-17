#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 void solve( vector<vector<ll> > &conn,int n,vector<vector<ll> >&dist){
    
   
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }
    for(ll via=1;via<=n;via++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(dist[i][via]!=LLONG_MAX && dist[via][j]!=LLONG_MAX){
                     dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);

                }
               
            }

        }
    }
   

}
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll> > conn(m,vector<ll>(3,0));
    vector<pair<ll,ll> >query(q);
    ll x,y,z;
    for(ll i=0;i<m;i++){
        cin>>x>>y>>z;
        conn[i]={x,y,z};

    }
    for(ll i=0;i<q;i++){
        cin>>x>>y;
        query[i]={x,y};
    }
     vector<vector<ll> >adj(n+1,vector<ll> (n+1,LLONG_MAX));
    for(auto it:conn){
        ll u=it[0];
        ll v=it[1];
        ll t=it[2];
        adj[u][v]=min(adj[u][v],t);
        adj[v][u]=min(adj[v][u],t);
    }
    vector<vector<ll> >dist=adj;
    solve(conn,n,dist);

    for(ll i=0;i<q;i++){
        ll u=query[i].first;
        ll v=query[i].second;
        if(dist[u][v]<LLONG_MAX){
            cout<<dist[u][v]<<endl;

        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}