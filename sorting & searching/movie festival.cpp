#include<bits/stdc++.h>
using namespace std;

class comp{
    public:
    bool operator()(pair<int,int> a,pair<int,int>b){
        return b.second>a.second;

    }
};
int findmaxMovie(int n,vector<pair<int,int>> &arr){
    sort(arr.begin(),arr.end(),comp());
    int cnt=1;
    int last=arr[0].second;
    for(int i=1;i<n;i++){
        if(arr[i].first >= last){
            last=arr[i].second;

            cnt++;
        }
    }
    return cnt;
}
int main(){
    int n,start,end;
    cin>> n;
    vector<pair<int,int> > arr(n);
    for(int i=0;i<n;i++){
        cin>>start >> end;
        arr[i]={start,end};
    }
    cout<< findmaxMovie(n,arr);
    return 0;

}