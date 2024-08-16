#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m,vector<vector<char>> &grid){
    vector<vector<int> > visited(n,vector<int> (m,0));
   vector<vector<int> > mon_dist(n,vector<int> (m,INT_MAX));
   queue<vector<int> > q;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int x;
    int y;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='M'){
            q.push({i,j,0});
        }
        if(grid[i][j]=='A'){
            x=i;
            y=j;
        }
    }
   }
   while(!q.empty()){
    int r=q.front()[0];
    int c=q.front()[1];
    int step=q.front()[2];
    q.pop();
    for(int i=0;i<4;i++){
        int nrow=dx[i]+r;
        int ncol=dy[i]+c;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='.' && step+1<mon_dist[nrow][ncol]){
            q.push({nrow,ncol,step+1});
            mon_dist[nrow][ncol]=step+1;

        }
    }
    
   }
   char dir[4]={'U','R','D','L'};
  
   queue<vector<int> > q2;
   q2.push({x,y,0});
    vector<vector<int> > dist(n,vector<int> (m,INT_MAX));
    dist[x][y]=0;
    vector<vector<pair<int,int> > > parent(n,vector<pair<int,int> > (m,{-1,-1}));
   while(!q2.empty()){
    int r=q2.front()[0];
    int c=q2.front()[1];
    int step=q2.front()[2];
    q2.pop();
    if(r==0 ||r==n-1 || c==0||c==m-1){
        string path;
        int cr=r;
        int cc=c;
        while(!(cr==x && cc==y)){
            int pr=parent[cr][cc].first;
            int pc=parent[cr][cc].second;
            for(int i=0;i<4;i++){
                if(cr==pr+dx[i] && cc==pc+dy[i]){
                    path.push_back(dir[i]);
                    break;
                }
            }
            cr=pr;
            cc=pc;
        }
        reverse(path.begin(),path.end());
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        cout<<path<<endl;
        return;

    }
    for(int i=0;i<4;i++){
        int nrow=dx[i]+r;
        int ncol=dy[i]+c;

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='.' && step+1<mon_dist[nrow][ncol] && step+1<dist[nrow][ncol]){
            q2.push({nrow,ncol,step+1});
            dist[nrow][ncol]=step+1;
            parent[nrow][ncol]={r,c};

        }
    }

   }
   
   
    cout<<"NO";

  




}
int main(){
    int n,m;
    cin>>n >>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> grid[i][j];
        }
    }
    solve(n,m,grid);
    return 0;
}