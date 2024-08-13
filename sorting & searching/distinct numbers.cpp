#include <bits/stdc++.h>
using namespace std;

int distinctNumbers(int n,vector<int> &arr){
    int cnt=1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            cnt=cnt+1;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>> n;
    vector<int> v(n);
   
    for(int i=0;i<n;i++){
         cin >> v[i];
    }
    cout<< distinctNumbers(n,v);
    return 0;
}