#include<bits/stdc++.h>
using namespace std;
int cnt_rooms(int n,vector<pair<int,int>> arr){
    sort(arr.begin(),arr.end());
    
    int cnt=1;
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(arr[0].second);
    for(int i=1;i<n;i++){
        if(arr[i].first >pq.top()){
            pq.pop();
            pq.push(arr[i].second);
            
        }
        else{
            cnt++;
            pq.push(arr[i].second);
        }

    }
    return cnt;
}
vector<int> room_allocated(int n,vector<pair<int,int>> arr){
        
        vector<int> ans(n);
       vector<vector<int> > vec(n,vector<int>(3));
       for(int i=0;i<n;i++){
        vec[i][0]=arr[i].first;
        vec[i][1]=arr[i].second;
        vec[i][2]=i;
       }
        sort(vec.begin(),vec.end());


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int room_no=1;
        pq.push({vec[0][1],room_no});
        ans[vec[0][2]]=room_no;
        for(int i=1;i<n;i++){
            if(vec[i][0]>pq.top().first){
               int avail_room=pq.top().second;
               ans[vec[i][2]]=avail_room;
                pq.pop();
                pq.push({vec[i][1],avail_room});

            }
            else{
                room_no+=1;
                ans[vec[i][2]]=room_no;
                pq.push({vec[i][1],room_no});

            }
        }
        return ans;
}

int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        arr[i]={x,y};
    }
    cout<<cnt_rooms(n,arr);
    cout<<"\n";
    vector<int> ans=room_allocated(n,arr);
     for(int i=0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    return 0;
}