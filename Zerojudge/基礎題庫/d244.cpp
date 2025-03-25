//d244. 一堆石頭
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int>
#define all(x) x.begin(),x.end() 
#define ll long long

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    unordered_map<int,int> dict;
    int n;
    while(cin>>n){
        dict[n]++;
    }
    for(const auto &i:dict){
        if(i.second%3!=0){
            cout<<i.first;
            return 0;
        }
    }
}