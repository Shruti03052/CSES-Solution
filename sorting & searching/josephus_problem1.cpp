#include<bits/stdc++.h>
using namespace std;
void print_order(int n){
   queue<int> q;
   for(int i=1;i<=n;i++){
    q.push(i);
   }
   int flag=0;
   while(!q.empty()){
    if(q.size()==1){
        cout<<q.front();
        break;
    }
    int front_ele=q.front();
    q.pop();
    flag=!flag;
    if(flag==true){
        cout<<q.front()<<" ";
        q.pop();
        q.push(front_ele);
        flag=!flag;
    }
   }
}

int main(){
    int n;
    cin>>n;
    print_order(n);
    return 0;
}