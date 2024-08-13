#include<bits/stdc++.h>
using namespace std;
int numberofApplicant(int n,int m,int k,vector<int> &desire,vector<int> &available){
    sort(desire.begin(),desire.end());
    sort(available.begin(),available.end());
    int i=0;
    int cnt=0;
    int j=0;
    while(i<n && j<m){
        if(desire[i]-k <=available[j] && available[j]<=desire[i]+k){
            cnt++;
            i++;
            j++;
        }
        else if(desire[i]-k <available[j] && desire[i]+k < available[j]){
            i++;

        }
        else {
            j++;
        }
    }
    return cnt;

}
int main(){
    int n,m,k;
    cin>>n;
    cin>> m;
    cin>>k;
    vector<int> desire(n);
    vector<int> available(m);
    for(int i=0;i<n;i++){
        cin>> desire[i];
    }
    for(int i=0;i<m;i++){
        cin>> available[i];
    }
    cout<< numberofApplicant(n,m,k,desire,available);
    return 0;
    
}