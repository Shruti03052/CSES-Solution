#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF LLONG_MAX
void solve(int n,int m,vector<vector<int> > &conn){
   vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford algorithm to find the longest path from node 1
    for (int i = 0; i < n - 1; i++) {
        for (auto& it : conn) {
            int u = it[0];
            int v = it[1];
            ll d = it[2];
            if (dist[u] != -INF && dist[u] + d > dist[v]) {
                dist[v] = dist[u] + d;
            }
        }
    }

    // Now check for positive-weight cycles
    vector<bool> visited(n + 1, false);
    queue<int> q;

    // Relax one more time to find the affected nodes
    for (auto& it : conn) {
        int u = it[0];
        int v = it[1];
        ll d = it[2];
        if (dist[u] != -INF && dist[u] + d > dist[v]) {
            dist[v] = dist[u] + d;
            q.push(v);
            visited[v] = true;
        }
    }

    // Spread the effect of a positive cycle to all reachable nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto& it : conn) {
            int u = it[0];
            int v = it[1];
            if (u == node && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // If node `n` is affected by a positive cycle, return -1
    if (visited[n]) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }


}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > conn(m,vector<int> (3));
    int x,y,z;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        conn[i]={x,y,z};

    }
    solve(n,m,conn);
    return 0;

}