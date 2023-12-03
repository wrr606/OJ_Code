//i399. 1. 數字遊戲
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    map<int,int> x;
    set<int> y;
    int n;
    for(int i=0;i<3;i++){
        cin>>n;
        x[n]++;
    }
    for(const auto &i:x)
        y.insert(i.second);
    auto iter=x.rbegin();
    cout<<*y.rbegin()<<" ";
    for(iter;iter!=x.rend();iter++){
        cout<<iter->first<<" ";
    }
}