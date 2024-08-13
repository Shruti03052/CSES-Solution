#include<bits/stdc++.h>
using namespace std;
int numberOfGandolas(int n,int w,vector<int> &wt){
    int cnt=0;
    sort(wt.begin(),wt.end());
    int i=0;
    int j=n-1;
    while(i<j){
        if(wt[i]+wt[j]<=w){
            cnt++;
            i++;
            j--;
        }
        else if(wt[j]<=w){
            j--;
            cnt++;
        }
        else if(wt[i]<=w){
            i++;
            cnt++;

        }
    }
    if(i==j){
 cnt=cnt+1;
    }
   
    return cnt;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<< numberOfGandolas(n,x,wt);
    return 0;
}