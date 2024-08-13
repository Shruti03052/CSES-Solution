#include<bits/stdc++.h>
using namespace std;
void print_order(int n,int k){
    set<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);

    }
    int it=0;
    int cnt=n;

    while(arr.size()){
        it=(it+k)%cnt;
        
        cout<<*(it+arr.begin()) << " ";
        arr.erase(it+arr.begin());
        
        cnt--;

    }
}
int main(){
    int n,k;
    cin>>n>>k;
    print_order(n,k);

    return 0;

}