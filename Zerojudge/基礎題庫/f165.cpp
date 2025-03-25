//f165. 棒棒糖事件
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x,y;
    cin>>x>>y;
    if(!y||x%y==0){
        cout<<"OK!\n";
    }
    else{
        cout<<x%y<<endl;
    }
}