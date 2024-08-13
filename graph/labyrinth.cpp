#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m,vector<vector<char> > &grid){
    vector<vector<int> > visited(n,vector<int> (m,0));
    queue<pair<int,pair<int,int> > > q;
    int startrow=-1;
    int startcol=-1;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                q.push({0,{i,j}});
                visited[i][j]=1;
                startrow=i;
                startcol=j;
            }

        }
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dir[4]={'U','R','D','L'};
    vector<vector<pair<int,int> > > parent(n,vector<pair<int,int> > (m,{-1,-1}));
    while(!q.empty()){
        int row=q.front().second.first;
        int col=q.front().second.second;
        int d=q.front().first;
        q.pop();
        if(grid[row][col]=='B'){
            cout<<"YES"<<endl;
            cout<<d<<endl;
            vector<char> ans;
            while(row!=startrow || col!=startcol){
                int prevr=parent[row][col].first;
                int prevc=parent[row][col].second;
                for(int i=0;i<4;i++){
                    int nr=prevr+dx[i];
                    int nc=prevc+dy[i];
                    if(nr==row && nc==col){
                        ans.push_back(dir[i]);
                    }

                }
                row=prevr;
                col=prevc;
            }
            reverse(ans.begin(),ans.end());
            for(auto it:ans){
                cout<<it;
            }
            

            return;
        }
        for (int i = 0; i < 4; i++) {
             int nrow = row + dx[i];
              int ncol = col + dy[i];
             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
                if(grid[nrow][ncol]=='.' || grid[nrow][ncol]=='B'){
                    q.push({d+1,{nrow,ncol}});
                    visited[nrow][ncol]=1;
                    parent[nrow][ncol]={row,col};
                   
                }

             }
        }
    }
    cout<<"NO"<<endl;
    
}
int main(){
    int n,m;
    cin>>n >> m;
    vector<vector<char> > grid(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];

        }
    }
    solve(n,m,grid);
    
    return 0;
}